#ifndef TOKENS_H
#define TOKENS_H

/* Reserved words (100-series) */
#define _AND            101
#define _BOOLEAN        102
#define _BEGIN          103
#define _DO             104
#define _END            105
#define _ELSE           106
#define _FALSE          107
#define _INTEGER        108
#define _IF             109
#define _NOT            110
#define _OR             111
#define _PROCEDURE      112
#define _PROGRAM        113
#define _THEN           114
#define _TRUE           115
#define _VAR            116
#define _WRITE          117
#define _WHILE          118

/* Operators (200-series) */
#define _EQ          201  /* =  */
#define _STAR         202  /* *  */
#define _PLUS          203  /* +  */
#define _MINUS          204  /* -  */
#define _GT          205  /* >  */
#define _LT          206  /* <  */
#define _GEQ     207  /* >= */
#define _LEQ     208  /* <= */
#define _ASSIGN     209  /* := */
#define _NEQ      210  /* <> */
#define _DIV            211  /* div */

/* Literals (300-series) */
#define _NUMBER         300

/* Identifiers (400-series) */
#define _LETTER         400

/* Delimiters (500-series) */
#define _DOT            501  /* .  */
#define _COMMA           502  /* ,  */
#define _SEMICOLON        503  /* ;  */
#define _COLON          504  /* :  */
#define _LPAREN          505  /* (  */
#define _RPAREN         506  /* )  */

#endif /* TOKENS_H */
