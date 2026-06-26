#ifndef PARSER_H
#define PARSER_H

#include "buffer.h"
#include "symtable.h"

/*
 * Recursive descent parser for Mini Pascal.
 *
 * Grammar:
 *   <program>      ::= program <id> ; <block> .
 *   <block>        ::= [<var-decl-part>] [<proc-decl-part>] <compound>
 *   <var-decl-part>::= var <var-decl> { ; <var-decl> } ;
 *   <var-decl>     ::= <id-list> : <type>
 *   <id-list>      ::= <id> { , <id> }
 *   <proc-decl-part>::= { <proc-decl> ; }
 *   <proc-decl>    ::= procedure <id> [ <formal-params> ] ; <block>
 *   <formal-params>::= ( <formal-section> { ; <formal-section> } )
 *   <formal-section>::= [var] <id-list> : <type>
 *   <type>         ::= integer | boolean
 *   <compound>     ::= begin <cmd> { ; <cmd> } end
 *   <cmd>          ::= <assign> | <proc-call> | <compound>
 *                    | <if-cmd> | <while-cmd> | write ( <id> )
 *   <assign>       ::= <var> := <expr>
 *   <proc-call>    ::= <id> [ ( <param-list> ) ]
 *   <if-cmd>       ::= if ( <expr> ) then <cmd> [ else <cmd> ]
 *   <while-cmd>    ::= while ( <expr> ) do <cmd>
 *   <expr>         ::= <simple-expr> [ <relop> <simple-expr> ]
 *   <relop>        ::= = | <> | < | <= | >= | >
 *   <simple-expr>  ::= [+ | -] <term> { (+ | -) <term> }
 *   <term>         ::= <factor> { (* | div) <factor> }
 *   <factor>       ::= <var> | <number> | <bool> | ( <simple-expr> )
 *   <var>          ::= <id>
 *   <bool>         ::= true | false
 */

void parser_run(Token *buf, SymTable *sym);

#endif /* PARSER_H */
