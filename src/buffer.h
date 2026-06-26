#ifndef BUFFER_H
#define BUFFER_H

/*
 * Token buffer — FIFO queue used between the lexer and the parser.
 * Each node stores the token code, source line number, and lexeme text.
 */

#define MAX_LEXEME 100

typedef struct Token {
    int  code;
    int  line;
    char lexeme[MAX_LEXEME];
    struct Token *next;
} Token;

void   buffer_init(Token *head);
int    buffer_empty(const Token *head);
void   buffer_enqueue(Token *head, int code, const char *lexeme, int line);
Token *buffer_dequeue(Token *head);
Token *buffer_head(Token *head);
int    buffer_lookahead(Token *head);
void   buffer_match(Token *head, int expected_code);
void   buffer_free(Token *head);
void   buffer_print(const Token *head);

#endif /* BUFFER_H */
