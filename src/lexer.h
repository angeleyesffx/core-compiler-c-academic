#ifndef LEXER_H
#define LEXER_H

/*
 * Lexical analyzer based on a Deterministic Finite Automaton (DFA).
 *
 * The caller appends a trailing space to each token before passing it,
 * since DFA acceptance states check for ' ' as the terminal delimiter.
 *
 * Parameters:
 *   str  - null-terminated string: the token with a trailing space appended
 *   p    - index initialized to -1; updated internally by acceptance states
 *
 * Returns:
 *   token code (see tokens.h)  on success
 *   -1   whitespace-only input (skip)
 *    1   newline (skip)
 *    0   unrecognized / invalid token
 */
int lexer_scan(const char *str, int *p);

#endif /* LEXER_H */
