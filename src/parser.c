#include <stdio.h>
#include <stdlib.h>
#include "tokens.h"
#include "buffer.h"
#include "symtable.h"
#include "parser.h"

/* ------------------------------------------------------------------ */
/* Forward declarations                                                */
/* ------------------------------------------------------------------ */
static void parse_type       (Token *buf, SymTable *sym, int scope);
static void parse_id         (Token *buf, SymTable *sym, int scope);
static void parse_number     (Token *buf, SymTable *sym, int scope);
static void parse_bool       (Token *buf, SymTable *sym, int scope);
static void parse_variable   (Token *buf, SymTable *sym, int scope);
static void parse_factor      (Token *buf, SymTable *sym, int scope);
static void parse_term      (Token *buf, SymTable *sym, int scope);
static void parse_simple_expr(Token *buf, SymTable *sym, int scope);
static void parse_relop    (Token *buf, SymTable *sym, int scope);
static void parse_expr       (Token *buf, SymTable *sym, int scope);
static void parse_id_list    (Token *buf, SymTable *sym, int scope);
static void parse_formal_section(Token *buf, SymTable *sym, int scope);
static void parse_var_decl    (Token *buf, SymTable *sym, int scope);
static void parse_var_decl_part(Token *buf, SymTable *sym, int scope);
static void parse_formal_params  (Token *buf, SymTable *sym, int scope);
static void parse_proc_decl(Token *buf, SymTable *sym, int scope);
static void parse_subr_decl(Token *buf, SymTable *sym, int scope);
static void parse_assignment      (Token *buf, SymTable *sym, int scope);
static void parse_proc_call      (Token *buf, SymTable *sym, int scope);
static void parse_param_list     (Token *buf, SymTable *sym, int scope);
static void parse_if_cmd  (Token *buf, SymTable *sym, int scope);
static void parse_else_cmd  (Token *buf, SymTable *sym, int scope);
static void parse_while_cmd    (Token *buf, SymTable *sym, int scope);
static void parse_statement        (Token *buf, SymTable *sym, int scope);
static void parse_compound(Token *buf, SymTable *sym, int scope);
static void parse_block      (Token *buf, SymTable *sym, int scope);
static void parse_program    (Token *buf, SymTable *sym, int scope);

/* ------------------------------------------------------------------ */
/* Helper: report a syntax error with line number and exit             */
/* ------------------------------------------------------------------ */
static void syntax_error(Token *buf, const char *expected) {
    const Token *t = buffer_head(buf);
    fprintf(stderr, "Syntax error at line %d: expected %s, found '%s'\n",
            t->line, expected, t->lexeme);
    exit(1);
}

/* ------------------------------------------------------------------ */
/* parse_type -> integer | boolean                                           */
/* ------------------------------------------------------------------ */
static void parse_type(Token *buf, SymTable *sym, int scope) {
    (void)sym; (void)scope;
    switch (buffer_lookahead(buf)) {
        case _INTEGER: buffer_match(buf, _INTEGER); break;
        case _BOOLEAN: buffer_match(buf, _BOOLEAN); break;
        default:       syntax_error(buf, "<integer> or <boolean>");
    }
}

/* ------------------------------------------------------------------ */
/* parse_id -> LETTER {LETTER | DIGIT}                                      */
/* Inserts the identifier into the symbol table.                      */
/* ------------------------------------------------------------------ */
static void parse_id(Token *buf, SymTable *sym, int scope) {
    if (buffer_lookahead(buf) != _LETTER)
        syntax_error(buf, "<identifier>");
    symtable_insert(sym, buffer_head(buf)->lexeme, scope);
    buffer_match(buf, _LETTER);
}

/* ------------------------------------------------------------------ */
/* parse_number -> DIGIT {DIGIT}                                            */
/* ------------------------------------------------------------------ */
static void parse_number(Token *buf, SymTable *sym, int scope) {
    if (buffer_lookahead(buf) != _NUMBER)
        syntax_error(buf, "<number>");
    symtable_insert(sym, buffer_head(buf)->lexeme, scope);
    buffer_match(buf, _NUMBER);
}

/* ------------------------------------------------------------------ */
/* parse_bool -> true | false                                               */
/* ------------------------------------------------------------------ */
static void parse_bool(Token *buf, SymTable *sym, int scope) {
    (void)sym; (void)scope;
    switch (buffer_lookahead(buf)) {
        case _TRUE:  buffer_match(buf, _TRUE);  break;
        case _FALSE: buffer_match(buf, _FALSE); break;
        default:     syntax_error(buf, "<true> or <false>");
    }
}

/* ------------------------------------------------------------------ */
/* parse_variable -> parse_id                                                      */
/* ------------------------------------------------------------------ */
static void parse_variable(Token *buf, SymTable *sym, int scope) {
    parse_id(buf, sym, scope);
}

/* ------------------------------------------------------------------ */
/* parse_factor -> parse_variable | parse_number | parse_bool | ( parse_simple_expr )               */
/* ------------------------------------------------------------------ */
static void parse_factor(Token *buf, SymTable *sym, int scope) {
    switch (buffer_lookahead(buf)) {
        case _LETTER: parse_variable(buf, sym, scope);  break;
        case _NUMBER: parse_number(buf, sym, scope);    break;
        case _TRUE:
        case _FALSE:  parse_bool(buf, sym, scope);      break;
        case _LPAREN:
            buffer_match(buf, _LPAREN);
            parse_simple_expr(buf, sym, scope);
            if (buffer_lookahead(buf) != _RPAREN)
                syntax_error(buf, "<)>");
            buffer_match(buf, _RPAREN);
            break;
        default: syntax_error(buf, "<factor>");
    }
}

/* ------------------------------------------------------------------ */
/* parse_term -> parse_factor { (* | div) parse_factor }                                */
/* ------------------------------------------------------------------ */
static void parse_term(Token *buf, SymTable *sym, int scope) {
    parse_factor(buf, sym, scope);
    while (buffer_lookahead(buf) == _STAR ||
           buffer_lookahead(buf) == _DIV) {
        buffer_match(buf, buffer_lookahead(buf));
        parse_factor(buf, sym, scope);
    }
}

/* ------------------------------------------------------------------ */
/* parse_simple_expr -> [+ | -] parse_term { (+ | -) parse_term }                   */
/* ------------------------------------------------------------------ */
static void parse_simple_expr(Token *buf, SymTable *sym, int scope) {
    if (buffer_lookahead(buf) == _PLUS ||
        buffer_lookahead(buf) == _MINUS) {
        buffer_match(buf, buffer_lookahead(buf));
    }
    parse_term(buf, sym, scope);
    while (buffer_lookahead(buf) == _PLUS ||
           buffer_lookahead(buf) == _MINUS) {
        buffer_match(buf, buffer_lookahead(buf));
        parse_term(buf, sym, scope);
    }
}

/* ------------------------------------------------------------------ */
/* parse_relop -> = | <> | < | <= | >= | >                               */
/* Bug fix: original used _ASSIGN (:=) instead of _EQ (=).   */
/* ------------------------------------------------------------------ */
static void parse_relop(Token *buf, SymTable *sym, int scope) {
    (void)sym; (void)scope;
    switch (buffer_lookahead(buf)) {
        case _EQ:      buffer_match(buf, _EQ);      break;
        case _GT:      buffer_match(buf, _GT);      break;
        case _LT:      buffer_match(buf, _LT);      break;
        case _GEQ: buffer_match(buf, _GEQ); break;
        case _LEQ: buffer_match(buf, _LEQ); break;
        case _NEQ:  buffer_match(buf, _NEQ);  break;
        default:          syntax_error(buf, "<relational operator>");
    }
}

/* ------------------------------------------------------------------ */
/* parse_expr -> parse_simple_expr [ parse_relop parse_simple_expr ]                       */
/* Bug fix: _LEQ was missing; _ASSIGN replaced by _EQ. */
/* ------------------------------------------------------------------ */
static void parse_expr(Token *buf, SymTable *sym, int scope) {
    parse_simple_expr(buf, sym, scope);
    while (buffer_lookahead(buf) == _EQ      ||
           buffer_lookahead(buf) == _GT      ||
           buffer_lookahead(buf) == _LT      ||
           buffer_lookahead(buf) == _GEQ ||
           buffer_lookahead(buf) == _LEQ ||
           buffer_lookahead(buf) == _NEQ) {
        parse_relop(buf, sym, scope);
        parse_simple_expr(buf, sym, scope);
    }
}

/* ------------------------------------------------------------------ */
/* parse_id_list -> parse_id { , parse_id }                                             */
/* ------------------------------------------------------------------ */
static void parse_id_list(Token *buf, SymTable *sym, int scope) {
    parse_id(buf, sym, scope);
    while (buffer_lookahead(buf) == _COMMA) {
        buffer_match(buf, _COMMA);
        parse_id(buf, sym, scope);
    }
}

/* ------------------------------------------------------------------ */
/* parse_formal_section -> [var] parse_id_list : parse_type                              */
/* ------------------------------------------------------------------ */
static void parse_formal_section(Token *buf, SymTable *sym, int scope) {
    if (buffer_lookahead(buf) == _VAR)
        buffer_match(buf, _VAR);
    parse_id_list(buf, sym, scope);
    if (buffer_lookahead(buf) != _COLON)
        syntax_error(buf, "<:>");
    buffer_match(buf, _COLON);
    parse_type(buf, sym, scope);
}

/* ------------------------------------------------------------------ */
/* parse_var_decl -> parse_id_list : parse_type                                         */
/* ------------------------------------------------------------------ */
static void parse_var_decl(Token *buf, SymTable *sym, int scope) {
    parse_id_list(buf, sym, scope);
    if (buffer_lookahead(buf) != _COLON)
        syntax_error(buf, "<:>");
    buffer_match(buf, _COLON);
    parse_type(buf, sym, scope);
}

/* ------------------------------------------------------------------ */
/* parse_var_decl_part -> var parse_var_decl { ; parse_var_decl } ;                        */
/* ------------------------------------------------------------------ */
static void parse_var_decl_part(Token *buf, SymTable *sym, int scope) {
    while (buffer_lookahead(buf) == _VAR) {
        buffer_match(buf, _VAR);
        parse_var_decl(buf, sym, scope);
        if (buffer_lookahead(buf) != _SEMICOLON)
            syntax_error(buf, "<;>");
        buffer_match(buf, _SEMICOLON);
    }
}

/* ------------------------------------------------------------------ */
/* parse_formal_params -> ( parse_formal_section { ; parse_formal_section } )                  */
/* ------------------------------------------------------------------ */
static void parse_formal_params(Token *buf, SymTable *sym, int scope) {
    buffer_match(buf, _LPAREN);
    parse_formal_section(buf, sym, scope);
    while (buffer_lookahead(buf) == _SEMICOLON) {
        buffer_match(buf, _SEMICOLON);
        parse_formal_section(buf, sym, scope);
    }
    if (buffer_lookahead(buf) != _RPAREN)
        syntax_error(buf, "<)>");
    buffer_match(buf, _RPAREN);
}

/* ------------------------------------------------------------------ */
/* parse_proc_decl -> procedure parse_id [parse_formal_params] ; parse_block                 */
/* ------------------------------------------------------------------ */
static void parse_proc_decl(Token *buf, SymTable *sym, int scope) {
    buffer_match(buf, _PROCEDURE);
    scope++;
    parse_id(buf, sym, scope);
    if (buffer_lookahead(buf) == _LPAREN)
        parse_formal_params(buf, sym, scope);
    if (buffer_lookahead(buf) != _SEMICOLON)
        syntax_error(buf, "<;>");
    buffer_match(buf, _SEMICOLON);
    parse_block(buf, sym, scope);
}

/* ------------------------------------------------------------------ */
/* parse_subr_decl -> { parse_proc_decl ; }                          */
/* ------------------------------------------------------------------ */
static void parse_subr_decl(Token *buf, SymTable *sym, int scope) {
    if (buffer_lookahead(buf) != _PROCEDURE)
        syntax_error(buf, "<procedure>");
    parse_proc_decl(buf, sym, scope);
    if (buffer_lookahead(buf) != _SEMICOLON)
        syntax_error(buf, "<;>");
    buffer_match(buf, _SEMICOLON);
}

/* ------------------------------------------------------------------ */
/* parse_assignment -> parse_variable := EXPR                                          */
/* ------------------------------------------------------------------ */
static void parse_assignment(Token *buf, SymTable *sym, int scope) {
    parse_variable(buf, sym, scope);
    if (buffer_lookahead(buf) != _ASSIGN)
        syntax_error(buf, "<:=>");
    buffer_match(buf, _ASSIGN);
    parse_expr(buf, sym, scope);
}

/* ------------------------------------------------------------------ */
/* parse_param_list -> (parse_id | parse_number | parse_bool) { , (parse_id | parse_number | parse_bool) }        */
/* ------------------------------------------------------------------ */
static void parse_param_list(Token *buf, SymTable *sym, int scope) {
    do {
        switch (buffer_lookahead(buf)) {
            case _LETTER: parse_id(buf, sym, scope);     break;
            case _NUMBER: parse_number(buf, sym, scope); break;
            case _TRUE:
            case _FALSE:  parse_bool(buf, sym, scope);   break;
            default:      syntax_error(buf, "<identifier>, <number>, or <bool>");
        }
        if (buffer_lookahead(buf) == _COMMA)
            buffer_match(buf, _COMMA);
        else
            break;
    } while (1);
}

/* ------------------------------------------------------------------ */
/* parse_proc_call -> parse_id [ ( parse_param_list ) ]                                        */
/* ------------------------------------------------------------------ */
static void parse_proc_call(Token *buf, SymTable *sym, int scope) {
    parse_id(buf, sym, scope);
    if (buffer_lookahead(buf) == _LPAREN) {
        buffer_match(buf, _LPAREN);
        parse_param_list(buf, sym, scope);
        if (buffer_lookahead(buf) != _RPAREN)
            syntax_error(buf, "<)>");
        buffer_match(buf, _RPAREN);
    }
}

/* ------------------------------------------------------------------ */
/* parse_else_cmd -> else parse_statement                                              */
/* ------------------------------------------------------------------ */
static void parse_else_cmd(Token *buf, SymTable *sym, int scope) {
    if (buffer_lookahead(buf) != _ELSE)
        syntax_error(buf, "<else>");
    buffer_match(buf, _ELSE);
    parse_statement(buf, sym, scope);
}

/* ------------------------------------------------------------------ */
/* parse_if_cmd -> if ( parse_expr ) then parse_statement [ else parse_statement ]                    */
/* ------------------------------------------------------------------ */
static void parse_if_cmd(Token *buf, SymTable *sym, int scope) {
    buffer_match(buf, _IF);
    if (buffer_lookahead(buf) != _LPAREN)
        syntax_error(buf, "<(>");
    buffer_match(buf, _LPAREN);
    parse_expr(buf, sym, scope);
    if (buffer_lookahead(buf) != _RPAREN)
        syntax_error(buf, "<)>");
    buffer_match(buf, _RPAREN);
    if (buffer_lookahead(buf) != _THEN)
        syntax_error(buf, "<then>");
    buffer_match(buf, _THEN);
    parse_statement(buf, sym, scope);
    if (buffer_lookahead(buf) == _ELSE)
        parse_else_cmd(buf, sym, scope);
}

/* ------------------------------------------------------------------ */
/* parse_while_cmd -> while ( parse_expr ) do parse_statement                                  */
/* ------------------------------------------------------------------ */
static void parse_while_cmd(Token *buf, SymTable *sym, int scope) {
    buffer_match(buf, _WHILE);
    if (buffer_lookahead(buf) != _LPAREN)
        syntax_error(buf, "<(>");
    buffer_match(buf, _LPAREN);
    parse_expr(buf, sym, scope);
    if (buffer_lookahead(buf) != _RPAREN)
        syntax_error(buf, "<)>");
    buffer_match(buf, _RPAREN);
    if (buffer_lookahead(buf) != _DO)
        syntax_error(buf, "<do>");
    buffer_match(buf, _DO);
    parse_statement(buf, sym, scope);
}

/* ------------------------------------------------------------------ */
/* parse_statement -> parse_assignment | parse_proc_call | parse_compound | parse_if_cmd | parse_while_cmd         */
/*      | write ( parse_id )                                                */
/* ------------------------------------------------------------------ */
static void parse_statement(Token *buf, SymTable *sym, int scope) {
    switch (buffer_lookahead(buf)) {
        case _WRITE:
            buffer_match(buf, _WRITE);
            if (buffer_lookahead(buf) != _LPAREN) syntax_error(buf, "<(>");
            buffer_match(buf, _LPAREN);
            parse_id(buf, sym, scope);
            if (buffer_lookahead(buf) != _RPAREN) syntax_error(buf, "<)>");
            buffer_match(buf, _RPAREN);
            break;
        case _LETTER: {
            /* Peek at the second token to decide assignment vs procedure call.
               After <id>, if the next token is <(> it is a procedure call;
               otherwise it is an assignment.  The linked list lets us inspect
               buf->next->next without consuming any token. */
            const Token *second = buffer_head(buf)->next;
            if (second && second->code == _LPAREN)
                parse_proc_call(buf, sym, scope);
            else
                parse_assignment(buf, sym, scope);
            break;
        }
        case _BEGIN:
            parse_compound(buf, sym, scope);
            break;
        case _IF:
            parse_if_cmd(buf, sym, scope);
            break;
        case _WHILE:
            parse_while_cmd(buf, sym, scope);
            break;
        default:
            break;   /* empty command — allowed by grammar */
    }
}

/* ------------------------------------------------------------------ */
/* parse_compound -> begin parse_statement { ; parse_statement } end                             */
/* Scope is incremented on entry and all symbols in it are removed    */
/* from the hash table when end is reached.                           */
/* ------------------------------------------------------------------ */
static void parse_compound(Token *buf, SymTable *sym, int scope) {
    if (buffer_lookahead(buf) != _BEGIN)
        syntax_error(buf, "<begin>");
    scope++;
    buffer_match(buf, _BEGIN);
    parse_statement(buf, sym, scope);
    while (buffer_lookahead(buf) == _SEMICOLON &&
           buffer_lookahead(buf) != _END) {
        buffer_match(buf, _SEMICOLON);
        parse_statement(buf, sym, scope);
    }
    if (buffer_lookahead(buf) != _END)
        syntax_error(buf, "<end>");

    /* Remove all symbols declared in this scope (CLRS §11.2 DELETE) */
    symtable_remove_scope(sym, scope);
    buffer_match(buf, _END);
}

/* ------------------------------------------------------------------ */
/* parse_block -> [parse_var_decl_part] [parse_subr_decl] parse_compound            */
/* ------------------------------------------------------------------ */
static void parse_block(Token *buf, SymTable *sym, int scope) {
    while (buffer_lookahead(buf) == _VAR)
        parse_var_decl_part(buf, sym, scope);
    while (buffer_lookahead(buf) == _PROCEDURE)
        parse_subr_decl(buf, sym, scope);
    parse_compound(buf, sym, scope);
}

/* ------------------------------------------------------------------ */
/* parse_program -> parse_id ; parse_block .                                            */
/* ------------------------------------------------------------------ */
static void parse_program(Token *buf, SymTable *sym, int scope) {
    parse_id(buf, sym, scope);
    if (buffer_lookahead(buf) != _SEMICOLON)
        syntax_error(buf, "<;>");
    buffer_match(buf, _SEMICOLON);
    parse_block(buf, sym, scope);
    if (buffer_lookahead(buf) != _DOT)
        syntax_error(buf, "<.>");
    buffer_match(buf, _DOT);
}

/* ------------------------------------------------------------------ */
/* Entry point                                                         */
/* ------------------------------------------------------------------ */
void parser_run(Token *buf, SymTable *sym) {
    int scope = 0;
    if (buffer_lookahead(buf) != _PROGRAM)
        syntax_error(buf, "<program>");
    buffer_match(buf, _PROGRAM);
    parse_program(buf, sym, scope);
    printf("Syntactic analysis complete — no errors.\n");
    symtable_print(sym);
}
