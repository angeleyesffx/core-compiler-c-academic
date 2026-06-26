/*
 * Unit tests for the DFA-based lexical analyzer.
 *
 * ISTQB test design techniques applied:
 *   EP1  Equivalence Partitioning — reserved words (all 19 keywords)
 *   EP2  Equivalence Partitioning — operators (all 10 single/multi-char)
 *   EP3  Equivalence Partitioning — delimiters (all 6)
 *   EP4  Equivalence Partitioning — integer literals
 *   EP5  Equivalence Partitioning — identifiers
 *   EP6  Equivalence Partitioning — invalid / unrecognized tokens
 *   BVA  Boundary Value Analysis  — keyword-prefix identifiers (DFA boundaries)
 *   ST   State Transition         — each DFA acceptance path exercised
 *   REG  Regression               — one test per bug fixed in the refactor
 *
 * No external framework needed — a single function check() drives all assertions.
 * The binary exits 0 if all pass, 1 if any fail.
 */

#include <stdio.h>
#include <string.h>
#include "lexer.h"
#include "tokens.h"

static int g_pass = 0;
static int g_fail = 0;

/* Append a trailing space so DFA acceptance states can trigger, then classify. */
static int lex(const char *tok) {
    char buf[128];
    int len = (int)strlen(tok);
    if (len >= 126) return 0;
    memcpy(buf, tok, len);
    buf[len]     = ' ';
    buf[len + 1] = '\0';
    int p = -1;
    return lexer_scan(buf, &p);
}

static void check(const char *id, const char *desc, int got, int expected) {
    if (got == expected) {
        printf("  PASS  [%s] %s\n", id, desc);
        g_pass++;
    } else {
        printf("  FAIL  [%s] %s  —  expected %d, got %d\n", id, desc, expected, got);
        g_fail++;
    }
}

/* ------------------------------------------------------------------ */
/* EP1 — Reserved words                                               */
/* Every keyword has its own DFA path; all 19 must be tested.         */
/* ------------------------------------------------------------------ */
static void ep1_reserved_words(void) {
    printf("\n[EP1] Reserved words\n");
    check("EP1-01", "and",       lex("and"),       _AND);
    check("EP1-02", "boolean",   lex("boolean"),   _BOOLEAN);
    check("EP1-03", "begin",     lex("begin"),     _BEGIN);
    check("EP1-04", "div",       lex("div"),       _DIV);
    check("EP1-05", "do",        lex("do"),        _DO);
    check("EP1-06", "else",      lex("else"),      _ELSE);
    check("EP1-07", "end",       lex("end"),       _END);
    check("EP1-08", "false",     lex("false"),     _FALSE);
    check("EP1-09", "if",        lex("if"),        _IF);
    check("EP1-10", "integer",   lex("integer"),   _INTEGER);
    check("EP1-11", "not",       lex("not"),       _NOT);
    check("EP1-12", "or",        lex("or"),        _OR);
    check("EP1-13", "procedure", lex("procedure"), _PROCEDURE);
    check("EP1-14", "program",   lex("program"),   _PROGRAM);
    check("EP1-15", "then",      lex("then"),      _THEN);
    check("EP1-16", "true",      lex("true"),      _TRUE);
    check("EP1-17", "var",       lex("var"),       _VAR);
    check("EP1-18", "while",     lex("while"),     _WHILE);
    check("EP1-19", "write",     lex("write"),     _WRITE);
}

/* ------------------------------------------------------------------ */
/* EP2 — Operators                                                    */
/* ------------------------------------------------------------------ */
static void ep2_operators(void) {
    printf("\n[EP2] Operators\n");
    check("EP2-01", "= (equality)",    lex("="),  _EQ);
    check("EP2-02", "* (multiply)",    lex("*"),  _STAR);
    check("EP2-03", "+ (add)",         lex("+"),  _PLUS);
    check("EP2-04", "- (subtract)",    lex("-"),  _MINUS);
    check("EP2-05", "> (greater)",     lex(">"),  _GT);
    check("EP2-06", "< (less)",        lex("<"),  _LT);
    check("EP2-07", ">= (greater-eq)", lex(">="), _GEQ);
    check("EP2-08", "<= (less-eq)",    lex("<="), _LEQ);
    check("EP2-09", ":= (assign)",     lex(":="), _ASSIGN);
    check("EP2-10", "<> (not-equal)",  lex("<>"), _NEQ);
}

/* ------------------------------------------------------------------ */
/* EP3 — Delimiters                                                   */
/* ------------------------------------------------------------------ */
static void ep3_delimiters(void) {
    printf("\n[EP3] Delimiters\n");
    check("EP3-01", ". (dot)",       lex("."), _DOT);
    check("EP3-02", ", (comma)",     lex(","), _COMMA);
    check("EP3-03", "; (semicolon)", lex(";"), _SEMICOLON);
    check("EP3-04", ": (colon)",     lex(":"), _COLON);
    check("EP3-05", "( (open)",      lex("("), _LPAREN);
    check("EP3-06", ") (close)",     lex(")"), _RPAREN);
}

/* ------------------------------------------------------------------ */
/* EP4 — Integer literals                                             */
/* ------------------------------------------------------------------ */
static void ep4_numbers(void) {
    printf("\n[EP4] Integer literals\n");
    check("EP4-01", "single digit 0",    lex("0"),   _NUMBER);
    check("EP4-02", "single digit 5",    lex("5"),   _NUMBER);
    check("EP4-03", "single digit 9",    lex("9"),   _NUMBER);
    check("EP4-04", "two digits 10",     lex("10"),  _NUMBER);
    check("EP4-05", "three digits 123",  lex("123"), _NUMBER);
    check("EP4-06", "large number 9999", lex("9999"),_NUMBER);
}

/* ------------------------------------------------------------------ */
/* EP5 — Identifiers                                                  */
/* ------------------------------------------------------------------ */
static void ep5_identifiers(void) {
    printf("\n[EP5] Identifiers\n");
    check("EP5-01", "single letter a",   lex("a"),    _LETTER);
    check("EP5-02", "single letter z",   lex("z"),    _LETTER);
    check("EP5-03", "multi-char abc",    lex("abc"),  _LETTER);
    check("EP5-04", "alphanum x1",       lex("x1"),   _LETTER);
    check("EP5-05", "mixed myVar123",    lex("myVar123"), _LETTER);
}

/* ------------------------------------------------------------------ */
/* EP6 — Invalid tokens                                               */
/* The DFA must return 0 for tokens it cannot accept.                 */
/* ------------------------------------------------------------------ */
static void ep6_invalid(void) {
    printf("\n[EP6] Invalid / unrecognized tokens\n");
    check("EP6-01", "<x (bad operator)",  lex("<x"),  0);
    check("EP6-02", ":x (bad colon seq)", lex(":x"),  0);
    check("EP6-03", ">=x (no space)",     lex(">=x"), 0);
}

/* ------------------------------------------------------------------ */
/* BVA + ST — Keyword-prefix identifiers (DFA boundary transitions)  */
/*                                                                     */
/* These words share a DFA prefix with a keyword but diverge before   */
/* the acceptance state. The DFA must fall back to _LETTER.           */
/* Failure here means a keyword was over-matched.                     */
/* ------------------------------------------------------------------ */
static void bva_st_keyword_prefixes(void) {
    printf("\n[BVA+ST] Keyword-prefix identifiers\n");
    check("BVA-01", "orb      (prefix of 'or')",        lex("orb"),      _LETTER);
    check("BVA-02", "endi     (prefix of 'end')",        lex("endi"),     _LETTER);
    check("BVA-03", "begins   (prefix of 'begin')",      lex("begins"),   _LETTER);
    check("BVA-04", "els      (prefix of 'else')",       lex("els"),      _LETTER);
    check("BVA-05", "whiled   (prefix of 'while')",      lex("whiled"),   _LETTER);
    check("BVA-06", "prog     (prefix of 'program')",    lex("prog"),     _LETTER);
    check("BVA-07", "iff      (prefix of 'if')",         lex("iff"),      _LETTER);
    check("BVA-08", "trueblue (prefix of 'true')",       lex("trueblue"), _LETTER);
    check("BVA-09", "notok    (prefix of 'not')",        lex("notok"),    _LETTER);
    check("BVA-10", "doit     (prefix of 'do')",         lex("doit"),     _LETTER);
    check("BVA-11", "variavel (prefix of 'var')",        lex("variavel"), _LETTER);
    check("BVA-12", "android  (prefix of 'and')",        lex("android"),  _LETTER);
    check("BVA-13", "divide   (prefix of 'div')",        lex("divide"),   _LETTER);
    check("BVA-14", "booleans (prefix of 'boolean')",    lex("booleans"), _LETTER);
    check("BVA-15", "integer2 (prefix of 'integer')",    lex("integer2"), _LETTER);
}

/* ------------------------------------------------------------------ */
/* REG — Regression tests                                             */
/*                                                                     */
/* One test per bug fixed. These tests must NEVER be removed;         */
/* they guard against the same defects recurring.                     */
/* ------------------------------------------------------------------ */
static void reg_regressions(void) {
    printf("\n[REG] Regression tests — one per bug fixed\n");

    /* Bug 1: Q74 jumped to Q73 (_DO) instead of Q75 (_OR)
       'or' was tokenized as _DO, silently corrupting any program using 'or'. */
    check("REG-01a", "or -> _OR",       lex("or"), _OR);
    check("REG-01b", "or != _DO",       lex("or") != _DO, 1);

    /* Bug 4: No DFA state for '='; fell through to Q91 as _LETTER.
       The equality operator was completely unusable. */
    check("REG-04a", "= -> _EQ",     lex("="),  _EQ);
    check("REG-04b", "= != _LETTER",    lex("=")  != _LETTER, 1);

    /* Bug 6: ':=' (assignment) was listed as relational operator in RELACAO().
       Verify ':=' and '=' produce DISTINCT token codes. */
    check("REG-06",  ":= != =",         lex(":=") != lex("="), 1);

    /* Verify '<=' is correctly tokenized (was missing from Expr loop in parser). */
    check("REG-05",  "<= -> _LEQ", lex("<="), _LEQ);

    /* Verify 'do' and 'or' are distinct (direct consequence of REG-01). */
    check("REG-01c", "do -> _DO",       lex("do"), _DO);
    check("REG-01d", "do != _OR",       lex("do") != _OR, 1);
}

/* ------------------------------------------------------------------ */
int main(void) {
    printf("Mini Pascal Lexer — Unit Test Suite\n");
    printf("=====================================\n");

    ep1_reserved_words();
    ep2_operators();
    ep3_delimiters();
    ep4_numbers();
    ep5_identifiers();
    ep6_invalid();
    bva_st_keyword_prefixes();
    reg_regressions();

    printf("\n=====================================\n");
    printf("Results: %d passed, %d failed\n", g_pass, g_fail);
    return (g_fail > 0) ? 1 : 0;
}
