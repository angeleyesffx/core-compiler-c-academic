#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokens.h"
#include "lexer.h"
#include "buffer.h"
#include "symtable.h"
#include "parser.h"

#define MAX_LINE 512   /* maximum source line length */

int main(int argc, char *argv[]) {
    const char *input_path  = (argc > 1) ? argv[1] : "program.txt";
    const char *output_path = "output.txt";

    FILE *source   = fopen(input_path,  "r");
    FILE *output = fopen(output_path, "w");

    if (!source) {
        fprintf(stderr, "Error: cannot open input file '%s'\n", input_path);
        return 1;
    }
    if (!output) {
        fprintf(stderr, "Error: cannot open output file '%s'\n", output_path);
        fclose(source);
        return 1;
    }

    /* -------------------------------------------------------------- */
    /* Phase 1 — Lexical Analysis                                     */
    /* Tokenize input using whitespace as delimiter.                  */
    /* -------------------------------------------------------------- */
    Token buffer_head_node = {0};
    Token *buf = &buffer_head_node;
    buffer_init(buf);

    char line[MAX_LINE];    /* fixed: original had char[80] with fgets(...,500) */
    int  line_num     = 0;
    int  token_count  = 0;
    int  lexer_ok     = 1;

    while (fgets(line, sizeof(line), source) && lexer_ok) {
        line_num++;

        /* Tokenize the line by whitespace (handles spaces, tabs, newlines) */
        char *tok = strtok(line, " \t\n\r");
        while (tok && lexer_ok) {
            /* Append trailing space so the DFA acceptance states trigger */
            char tok_buf[MAX_LINE + 1];
            int  tok_len = (int)strlen(tok);
            if (tok_len >= (int)sizeof(tok_buf) - 1) {
                fprintf(stderr, "Lexical error at line %d: token too long\n", line_num);
                lexer_ok = 0;
                break;
            }
            memcpy(tok_buf, tok, tok_len);
            tok_buf[tok_len]     = ' ';
            tok_buf[tok_len + 1] = '\0';

            int pos  = -1;
            int code = lexer_scan(tok_buf, &pos);

            if (code == 0) {
                fprintf(stderr, "Lexical error at line %d: unrecognized token '%s'\n",
                        line_num, tok);
                lexer_ok = 0;
            } else if (code != 1 && code != -1) {
                buffer_enqueue(buf, code, tok, line_num);
                fprintf(output, "<%d, %s>\n", code, tok);
                token_count++;
            }

            tok = strtok(NULL, " \t\n\r");
        }
    }

    fclose(source);
    fclose(output);

    if (!lexer_ok) {
        buffer_free(buf);
        return 1;
    }

    printf("Lexical analysis complete: %d tokens found.\n", token_count);

    /* -------------------------------------------------------------- */
    /* Phase 2 — Syntactic Analysis + Symbol Table                    */
    /* -------------------------------------------------------------- */
    SymTable sym;
    symtable_init(&sym);

    parser_run(buf, &sym);

    /* -------------------------------------------------------------- */
    /* Cleanup                                                        */
    /* -------------------------------------------------------------- */
    symtable_free(&sym);
    buffer_free(buf);
    return 0;
}
