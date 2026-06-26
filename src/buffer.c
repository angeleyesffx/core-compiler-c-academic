#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "buffer.h"

void buffer_init(Token *head) {
    head->next = NULL;
}

int buffer_empty(const Token *head) {
    return head->next == NULL;
}

static Token *token_alloc(int code, const char *lexeme, int line) {
    Token *t = malloc(sizeof(Token));
    if (!t) {
        fprintf(stderr, "Out of memory\n");
        exit(1);
    }
    t->code = code;
    t->line = line;
    strncpy(t->lexeme, lexeme, MAX_LEXEME - 1);
    t->lexeme[MAX_LEXEME - 1] = '\0';
    t->next = NULL;
    return t;
}

void buffer_enqueue(Token *head, int code, const char *lexeme, int line) {
    Token *novo = token_alloc(code, lexeme, line);
    if (buffer_empty(head)) {
        head->next = novo;
        return;
    }
    Token *cur = head->next;
    while (cur->next) cur = cur->next;
    cur->next = novo;
}

Token *buffer_dequeue(Token *head) {
    if (buffer_empty(head)) {
        fprintf(stderr, "Syntax error: unexpected end of input\n");
        exit(1);
    }
    Token *t  = head->next;
    head->next = t->next;
    return t;
}

Token *buffer_head(Token *head) {
    if (buffer_empty(head)) {
        fprintf(stderr, "Syntax error: unexpected end of input\n");
        exit(1);
    }
    return head->next;
}

int buffer_lookahead(Token *head) {
    return buffer_head(head)->code;
}

void buffer_match(Token *head, int expected_code) {
    if (buffer_lookahead(head) != expected_code) {
        Token *t = buffer_head(head);
        fprintf(stderr, "Syntax error at line %d: expected token %d, found '%s' (%d)\n",
                t->line, expected_code, t->lexeme, t->code);
        exit(1);
    }
    Token *t = buffer_dequeue(head);
    free(t);
}

void buffer_free(Token *head) {
    Token *cur = head->next;
    while (cur) {
        Token *next = cur->next;
        free(cur);
        cur = next;
    }
    head->next = NULL;
}

void buffer_print(const Token *head) {
    const Token *cur = head->next;
    printf("TOKENS IN BUFFER:\n");
    while (cur) {
        printf("  <%d, '%s'> line %d\n", cur->code, cur->lexeme, cur->line);
        cur = cur->next;
    }
}
