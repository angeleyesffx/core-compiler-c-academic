/*
 * Lexical analyzer — DFA implementation for Mini Pascal.
 *
 * Each state Qn corresponds to a node in the finite automaton that
 * recognizes reserved words, operators, literals, and identifiers.
 *
 * Reserved words recognized:
 *   and  begin  boolean  div  do  else  end  false  if  integer
 *   not  or  procedure  program  then  true  var  while  write
 *
 * Operators:
 *   +  -  *  =  :=  :  <  <=  <>  >  >=
 *
 * Delimiters: . , ; ( )
 */

#include "lexer.h"
#include "tokens.h"

int lexer_scan(const char *str, int *p) {
    int i = *p;

    goto Q0;

    /* ------------------------------------------------------------------ */
    /* Q0 — initial state: dispatch on first character                     */
    /* ------------------------------------------------------------------ */
    Q0:
        i++;
        if (str[i] == ' ')  return -1;
        if (str[i] == '\n') return  1;

        if (str[i] >= '0' && str[i] <= '9') goto Q90;

        if (str[i] == 'a') goto Q42;
        if (str[i] == 'b') goto Q59;
        if (str[i] == 'd') goto Q72;
        if (str[i] == 'e') goto Q1;
        if (str[i] == 'f') goto Q45;
        if (str[i] == 'i') goto Q28;
        if (str[i] == 'n') goto Q39;
        if (str[i] == 'o') goto Q74;
        if (str[i] == 'p') goto Q15;
        if (str[i] == 't') goto Q8;
        if (str[i] == 'v') goto Q36;
        if (str[i] == 'w') goto Q50;
        if (str[i] == '<') goto Q76;
        if (str[i] == '>') goto Q79;
        if (str[i] == ':') goto Q81;
        if (str[i] == ',') goto Q83;
        if (str[i] == '(') goto Q84;
        if (str[i] == ';') goto Q85;
        if (str[i] == ')') goto Q86;
        if (str[i] == '*') goto Q87;
        if (str[i] == '-') goto Q88;
        if (str[i] == '+') goto Q89;
        if (str[i] == '=') goto Q93;   /* equality operator — was missing */
        if (str[i] == '.') goto Q92;
        goto Q91;   /* generic identifier / unknown */

    /* ------------------------------------------------------------------ */
    /* else  (Q1..Q4)                                                      */
    /* ------------------------------------------------------------------ */
    Q1: i++;
        if (str[i] == 'n') goto Q5;
        if (str[i] == 'l') goto Q2;
        return _LETTER;

    Q2: i++;
        if (str[i] == 's') goto Q3;
        goto Q91;

    Q3: i++;
        if (str[i] == 'e') goto Q4;
        goto Q91;

    Q4: i++;
        if (str[i] == ' ') { *p = i; return _ELSE; }
        goto Q91;

    /* ------------------------------------------------------------------ */
    /* end  (Q5..Q7)                                                       */
    /* ------------------------------------------------------------------ */
    Q5: i++;
        if (str[i] == 'd') goto Q6;
        goto Q91;

    Q6: i++;
        if (str[i] == ' ') { *p = i; return _END; }
        goto Q91;

    /* ------------------------------------------------------------------ */
    /* true / then  (Q8..Q14)                                             */
    /* ------------------------------------------------------------------ */
    Q8: i++;
        if (str[i] == 'r') goto Q9;
        if (str[i] == 'h') goto Q12;
        goto Q91;

    Q9: i++;
        if (str[i] == 'u') goto Q10;
        goto Q91;

    Q10: i++;
        if (str[i] == 'e') goto Q11;
        goto Q91;

    Q11: i++;
        if (str[i] == ' ') { *p = i; return _TRUE; }
        goto Q91;

    Q12: i++;
        if (str[i] == 'e') goto Q13;
        goto Q91;

    Q13: i++;
        if (str[i] == 'n') goto Q14;
        goto Q91;

    Q14: i++;
        if (str[i] == ' ') { *p = i; return _THEN; }
        goto Q91;

    /* ------------------------------------------------------------------ */
    /* program / procedure  (Q15..Q27)                                    */
    /* ------------------------------------------------------------------ */
    Q15: i++;
        if (str[i] == 'r') goto Q16;
        goto Q91;

    Q16: i++;
        if (str[i] == 'o') goto Q17;
        goto Q91;

    Q17: i++;
        if (str[i] == 'g') goto Q18;
        if (str[i] == 'c') goto Q22;
        goto Q91;

    Q18: i++;
        if (str[i] == 'r') goto Q19;
        goto Q91;

    Q19: i++;
        if (str[i] == 'a') goto Q20;
        goto Q91;

    Q20: i++;
        if (str[i] == 'm') goto Q21;
        goto Q91;

    Q21: i++;
        if (str[i] == ' ') { *p = i; return _PROGRAM; }
        goto Q91;

    Q22: i++;
        if (str[i] == 'e') goto Q23;
        goto Q91;

    Q23: i++;
        if (str[i] == 'd') goto Q24;
        goto Q91;

    Q24: i++;
        if (str[i] == 'u') goto Q25;
        goto Q91;

    Q25: i++;
        if (str[i] == 'r') goto Q26;
        goto Q91;

    Q26: i++;
        if (str[i] == 'e') goto Q27;
        goto Q91;

    Q27: i++;
        if (str[i] == ' ') { *p = i; return _PROCEDURE; }
        goto Q91;

    /* ------------------------------------------------------------------ */
    /* if / integer  (Q28..Q35)                                           */
    /* ------------------------------------------------------------------ */
    Q28: i++;
        if (str[i] == 'f') goto Q29;
        if (str[i] == 'n') goto Q30;
        goto Q91;

    Q29: i++;
        if (str[i] == ' ') { *p = i; return _IF; }
        goto Q91;

    Q30: i++;
        if (str[i] == 't') goto Q31;
        goto Q91;

    Q31: i++;
        if (str[i] == 'e') goto Q32;
        goto Q91;

    Q32: i++;
        if (str[i] == 'g') goto Q33;
        goto Q91;

    Q33: i++;
        if (str[i] == 'e') goto Q34;
        goto Q91;

    Q34: i++;
        if (str[i] == 'r') goto Q35;
        goto Q91;

    Q35: i++;
        if (str[i] == ' ') { *p = i; return _INTEGER; }
        goto Q91;

    /* ------------------------------------------------------------------ */
    /* var  (Q36..Q38)                                                    */
    /* ------------------------------------------------------------------ */
    Q36: i++;
        if (str[i] == 'a') goto Q37;
        goto Q91;

    Q37: i++;
        if (str[i] == 'r') goto Q38;
        goto Q91;

    Q38: i++;
        if (str[i] == ' ') { *p = i; return _VAR; }
        goto Q91;

    /* ------------------------------------------------------------------ */
    /* not  (Q39..Q41)                                                    */
    /* ------------------------------------------------------------------ */
    Q39: i++;
        if (str[i] == 'o') goto Q40;
        goto Q91;

    Q40: i++;
        if (str[i] == 't') goto Q41;
        goto Q91;

    Q41: i++;
        if (str[i] == ' ') { *p = i; return _NOT; }
        goto Q91;

    /* ------------------------------------------------------------------ */
    /* and  (Q42..Q44)                                                    */
    /* ------------------------------------------------------------------ */
    Q42: i++;
        if (str[i] == 'n') goto Q43;
        goto Q91;

    Q43: i++;
        if (str[i] == 'd') goto Q44;
        goto Q91;

    Q44: i++;
        if (str[i] == ' ') { *p = i; return _AND; }
        goto Q91;

    /* ------------------------------------------------------------------ */
    /* false  (Q45..Q49)                                                  */
    /* ------------------------------------------------------------------ */
    Q45: i++;
        if (str[i] == 'a') goto Q46;
        goto Q91;

    Q46: i++;
        if (str[i] == 'l') goto Q47;
        goto Q91;

    Q47: i++;
        if (str[i] == 's') goto Q48;
        goto Q91;

    Q48: i++;
        if (str[i] == 'e') goto Q49;
        goto Q91;

    Q49: i++;
        if (str[i] == ' ') { *p = i; return _FALSE; }
        goto Q91;

    /* ------------------------------------------------------------------ */
    /* write / while  (Q50..Q58)                                          */
    /* ------------------------------------------------------------------ */
    Q50: i++;
        if (str[i] == 'r') goto Q51;
        if (str[i] == 'h') goto Q55;
        goto Q91;

    Q51: i++;
        if (str[i] == 'i') goto Q52;
        goto Q91;

    Q52: i++;
        if (str[i] == 't') goto Q53;
        goto Q91;

    Q53: i++;
        if (str[i] == 'e') goto Q54;
        goto Q91;

    Q54: i++;
        if (str[i] == ' ') { *p = i; return _WRITE; }
        goto Q91;

    Q55: i++;
        if (str[i] == 'i') goto Q56;
        goto Q91;

    Q56: i++;
        if (str[i] == 'l') goto Q57;
        goto Q91;

    Q57: i++;
        if (str[i] == 'e') goto Q58;
        goto Q91;

    Q58: i++;
        if (str[i] == ' ') { *p = i; return _WHILE; }
        goto Q91;

    /* ------------------------------------------------------------------ */
    /* begin / boolean  (Q59..Q69)                                        */
    /* ------------------------------------------------------------------ */
    Q59: i++;
        if (str[i] == 'e') goto Q60;
        if (str[i] == 'o') goto Q64;
        goto Q91;

    Q60: i++;
        if (str[i] == 'g') goto Q61;
        goto Q91;

    Q61: i++;
        if (str[i] == 'i') goto Q62;
        goto Q91;

    Q62: i++;
        if (str[i] == 'n') goto Q63;
        goto Q91;

    Q63: i++;
        if (str[i] == ' ') { *p = i; return _BEGIN; }
        goto Q91;

    Q64: i++;
        if (str[i] == 'o') goto Q65;
        goto Q91;

    Q65: i++;
        if (str[i] == 'l') goto Q66;
        goto Q91;

    Q66: i++;
        if (str[i] == 'e') goto Q67;
        goto Q91;

    Q67: i++;
        if (str[i] == 'a') goto Q68;
        goto Q91;

    Q68: i++;
        if (str[i] == 'n') goto Q69;
        goto Q91;

    Q69: i++;
        if (str[i] == ' ') { *p = i; return _BOOLEAN; }
        goto Q91;

    /* ------------------------------------------------------------------ */
    /* div / do  (Q70..Q73)                                               */
    /* ------------------------------------------------------------------ */
    Q70: i++;
        if (str[i] == 'v') goto Q71;
        goto Q91;

    Q71: i++;
        if (str[i] == ' ') { *p = i; return _DIV; }
        goto Q91;

    Q72: i++;
        if (str[i] == 'o') goto Q73;
        if (str[i] == 'i') goto Q70;
        goto Q91;

    Q73: i++;
        if (str[i] == ' ') { *p = i; return _DO; }
        goto Q91;

    /* ------------------------------------------------------------------ */
    /* or  (Q74..Q75)                                                     */
    /* Bug fix: Q74 previously jumped to Q73 (_DO), now correctly to Q75  */
    /* ------------------------------------------------------------------ */
    Q74: i++;
        if (str[i] == 'r') goto Q75;   /* fixed: was goto Q73 */
        goto Q91;

    Q75: i++;
        if (str[i] == ' ') { *p = i; return _OR; }
        goto Q91;

    /* ------------------------------------------------------------------ */
    /* Relational and assignment operators                                 */
    /* ------------------------------------------------------------------ */

    /* <  |  <=  |  <> */
    Q76: i++;
        if (str[i] == '>') goto Q77;
        if (str[i] == '=') goto Q78;
        if (str[i] == ' ') { *p = i; return _LT; }
        return 0;

    Q77: i++;
        if (str[i] == ' ') { *p = i; return _NEQ; }
        return 0;

    Q78: i++;
        if (str[i] == ' ') { *p = i; return _LEQ; }
        return 0;

    /* >  |  >= */
    Q79: i++;
        if (str[i] == '=') goto Q80;
        if (str[i] == ' ') { *p = i; return _GT; }
        return 0;

    Q80: i++;
        if (str[i] == ' ') { *p = i; return _GEQ; }
        return 0;

    /* :  |  := */
    Q81: i++;
        if (str[i] == '=') goto Q82;
        if (str[i] == ' ') { *p = i; return _COLON; }
        return 0;

    Q82: i++;
        if (str[i] == ' ') { *p = i; return _ASSIGN; }
        return 0;

    /* ------------------------------------------------------------------ */
    /* Delimiters                                                          */
    /* ------------------------------------------------------------------ */
    Q83: i++; if (str[i] == ' ') { *p = i; return _COMMA;   } return 0;
    Q84: i++; if (str[i] == ' ') { *p = i; return _LPAREN;  } return 0;
    Q85: i++; if (str[i] == ' ') { *p = i; return _SEMICOLON;} return 0;
    Q86: i++; if (str[i] == ' ') { *p = i; return _RPAREN; } return 0;
    Q87: i++; if (str[i] == ' ') { *p = i; return _STAR; } return 0;
    Q88: i++; if (str[i] == ' ') { *p = i; return _MINUS;  } return 0;
    Q89: i++; if (str[i] == ' ') { *p = i; return _PLUS;  } return 0;

    /* ------------------------------------------------------------------ */
    /* Numeric literal  0-9 {0-9}  (Q90)                                 */
    /* ------------------------------------------------------------------ */
    Q90: i++;
        if (str[i] == ' ')                        { *p = i; return _NUMBER; }
        if (str[i] >= '0' && str[i] <= '9') goto Q90;
        return 0;

    /* ------------------------------------------------------------------ */
    /* Equality operator  =  (Q93) — was missing from the original        */
    /* ------------------------------------------------------------------ */
    Q93: i++;
        if (str[i] == ' ') { *p = i; return _EQ; }
        return 0;

    /* . */
    Q92: i++;
        if (str[i] == ' ') { *p = i; return _DOT; }
        return 0;

    /* ------------------------------------------------------------------ */
    /* Generic identifier fallback  (Q91)                                 */
    /* Reached when a word does not match any reserved word.              */
    /* ------------------------------------------------------------------ */
    Q91: i++;
        if (str[i] == ' ') { *p = i; return _LETTER; }
        goto Q91;

    return 1;
}
