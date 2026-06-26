/*INCLUINDO DEBUG PARA O CÓDIGO*/
//#define DEBUG
#ifdef DEBUG
#endif
/*palavras reservadas*/ 
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
/*operadores*/
#define _IGUAL          201
#define _OPMULT         202
#define _OPADI          203
#define _OPSUB          204
#define _MAIOR          205
#define _MENOR          206
#define _MAIORIGUAL     207
#define _MENORIGUAL     208
#define _ATRIBUICAO     209
#define _DIFERENTE      210
#define _DIV            211
/*digitos*/
#define _NUMBER         300
/*letras*/
#define _LETTER         400
/*delimitadores*/
#define _PNT            501
#define _VRGL           502
#define _PNTVRGL        503
#define _DSPNT          504
#define _ABREP          505
#define _FECHAP         506

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


/*Método leitor - Automato responsável pela identificação de palavras reservadas da linguagem mini pascal
Lista de lexemas reservadas:            |  Lista de operadores:   | 
and        begin       boolean    div    |  +	-	* 	) 	;	(  |
do         else        end.       false  |    :=  :  >=	 >	<=     |  
if         integer     not        program|    <>  <   ,   :=       |
procedure  true        then       or     |  Lista de numerais:     |
var        write       while             | 0-1-2-3-4-5-6-7-8-9     |
*/
int leitor(char str[],int *p) {
  int i = *p;
	int erro = 0;

	goto Q0;

	Q0:
	    i++;
	    if(str[i] == ' ')
		    return -1;
		if(str[i] == '\n')
		    return 1;       	
	    if ((str[i] == '0')||(str[i] == '1')||(str[i] == '2')||(str[i] == '3')||(str[i] == '4')||(str[i] == '5')||(str[i] == '6')||(str[i] == '7')||(str[i] == '8')||(str[i] == '9')){
	        goto Q90;
	    } else {
	        if(str[i] == 'a'){
		       	goto Q42;
	        } else {
				if (str[i] == 'b'){
	                goto Q59;
	            } else {
	                if (str[i] == 'd'){
	                    goto Q72;
	                } else {
	                   	if (str[i] == 'e'){
	                        goto Q1;
	                    } else {
	                        if (str[i] == 'f'){
	                            goto Q45;
	                        } else {
	                            if (str[i] == 'i'){
	                                goto Q28;
	                            } else {
	                                if (str[i] == 'n'){
	                                    goto Q39;
	                                } else {
	                                    if (str[i] == 'o'){
	                                        goto Q74;
	                                    } else {
	                                        if (str[i] == 'p'){
	                                            goto Q15;
	                                        } else {
	                                            if (str[i] == 't'){
	                                                goto Q8;
	                                            } else {
	                                                if (str[i] == 'v'){
	                                                    goto Q36;
	                                                } else {
	                                                    if (str[i] == 'w'){
	                                                        goto Q50;
	                                                    } else {
	                                                        if (str[i] == '<'){
	                                                            goto Q76;
	                                                        } else {
	                                                        	if (str[i] == '>'){
	                                                                goto Q79;
	                                                            } else {
	                                                             	if (str[i] == ':'){
	                                                                    goto Q81;
	                                                                } else {
																		if (str[i] == ','){
																		    goto Q83;
																		} else {
																			if (str[i] == '('){
																		        goto Q84;
																			} else {
																			    if (str[i] == ';'){
																			        goto Q85;
																			    } else {
																			        if (str[i] == ')'){
																			            goto Q86;
																			        } else {
																			            if (str[i] == '*'){
																			                goto Q87;
																			            } else {
																			                if (str[i] == '-'){
																			                    goto Q88;
																			                } else {
																			                    if (str[i] == '+'){
																			                        goto Q89;
																			                    } else {
																			                        if (str[i] == '.'){
																			                            goto Q92;    
																			                        } else {
																			                            goto Q91;
																							 	   }
																							    }
																							 }
																						}
																					}
																				}
																		    }
																		}
																	}
																}
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
		    	}
		    }
		}
	/*else*/ /*end.*/
	Q1:
	    i++;
	    if(str[i] == 'n'){
			goto Q5;
	    } else {
	        if(str[i] == 'l'){
		       goto Q2;
		    } else {    
		        if ((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;
		        } else {
		           return _LETTER;
		        }
    	   }
        }
	Q2:
	    i++;
	    if(str[i] == 's'){
			goto Q3;
		 } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        }   
	Q3:
	    i++;
	    if(str[i] == 'e'){
			goto Q4;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        }   
	Q4:
		i++;
	    if (str[i] == ' ') {
          *p = i;
	        return _ELSE;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        }   
	Q5:
	    i++;
	    if(str[i] == 'd'){
		   *p = i;
		   goto Q6;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q6:
	    i++;
	    if(str[i] == ' '){
          *p = i;
           return _END;
        } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	/*true*/ /*then*/
	Q8:
	    i++;
	    if(str[i] == 'r'){
			goto Q9;
	    } else {
	        if(str[i] == 'h'){
		       goto Q12;
	       } else {    
			    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
		            return 0;    
		        } else {
		        	return _LETTER;
		        }
	        } 
        }
	Q9:
	    i++;
	    if(str[i] == 'u'){
			goto Q10;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q10:
	    i++;
	    if(str[i] == 'e'){
			goto Q11;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q11:
		i++;
	    if (str[i] == ' ') {
          *p = i;
	        return _TRUE;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q12:
	    i++;
	    if(str[i] == 'e'){
			goto Q13;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q13:
	    i++;
	    if(str[i] == 'n'){
			goto Q14;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q14:
		i++;
	    if (str[i] == ' ') {
          *p = i;
	        return _THEN;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	/*program*/ /*procedure*/
	Q15:
	    i++;
	    if(str[i] == 'r'){
			goto Q16;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q16:
	    i++;
	    if(str[i] == 'o'){
			goto Q17;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q17:
	    i++;
	    if(str[i] == 'g'){
			goto Q18;
	    } else {
	        if(str[i] == 'c'){
		       goto Q22;
	        } else {    
			    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
		            return 0;    
		        } else {
		        	return _LETTER;
		        }
	        }
    	}
	Q18:
	    i++;
	    if(str[i] == 'r'){
			goto Q19;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q19:
	    i++;
	    if(str[i] == 'a'){
			goto Q20;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q20:
	    i++;
	    if(str[i] == 'm'){
			goto Q21;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q21:
		i++;
	    if (str[i] == ' ') {
          *p = i;
	        return _PROGRAM;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q22:
	    i++;
	    if(str[i] == 'e'){
			goto Q23;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q23:
	    i++;
	    if(str[i] == 'd'){
			goto Q24;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q24:
	    i++;
	    if(str[i] == 'u'){
			goto Q25;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q25:
	    i++;
	    if(str[i] == 'r'){
			goto Q26;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q26:
	    i++;
	    if(str[i] == 'e'){
			goto Q27;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q27:
	    i++;
	    if (str[i] == ' ') {
          *p = i;
	        return _PROCEDURE;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	/*if*/ /*integer*/
	Q28:
	    i++;
	    if(str[i] == 'n'){
			goto Q30;
	        } else {
	           if(str[i] == 'f'){
		          goto Q29;
	            } else {    
		            if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	                  return 0;    
	                } else {
	        	        return _LETTER;
	                }
                } 
           }
	Q29:
	    i++;
	    if (str[i] == ' ') {
          *p = i;
	        return _IF;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q30:
	    i++;
	    if(str[i] == 't'){
			goto Q31;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q31:
	    i++;
	    if(str[i] == 'e'){
			goto Q32;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q32:
	    i++;
	    if(str[i] == 'g'){
			goto Q33;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q33:
	    i++;
	    if(str[i] == 'e'){
			goto Q34;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
    Q34:
	    i++;
	    if(str[i] == 'r'){
			goto Q35;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q35:
		i++;
	    if (str[i] == ' ') {
          *p = i;
	        return _INTEGER;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	/*var*/
    Q36:
	    i++;
	    if(str[i] == 'a'){
			goto Q37;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q37:
	    i++;
	    if(str[i] == 'r'){
			goto Q38;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q38:
		i++;
	    if (str[i] == ' ') {
          *p = i;
	        return _VAR;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	/*not*/
	Q39:
	    i++;
	    if(str[i] == 'o'){
			goto Q40;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q40:
	    i++;
	    if(str[i] == 't'){
			goto Q41;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q41:
		i++;
	    if (str[i] == ' ') {
           *p = i;
	        return _NOT;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	/*and*/
	Q42:
	    i++;
	    if(str[i] == 'n'){
			goto Q43;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q43:
	    i++;
	    if(str[i] == 'd'){
			goto Q44;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q44:
		i++;
	    if (str[i] == ' ') {
           *p = i;
	        return _AND;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	/*false*/
	Q45:
	    i++;
	    if(str[i] == 'a'){
			goto Q46;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q46:
	    i++;
	    if(str[i] == 'l'){
			goto Q47;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q47:
	    i++;
	    if(str[i] == 's'){
			goto Q48;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q48:
	    i++;
	    if(str[i] == 'e'){
			goto Q49;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q49:
		i++;
	    if (str[i] == ' ') {
           *p = i;
	        return _FALSE;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	/*write*/ /*while*/
	Q50:
	    i++;
	    if(str[i] == 'r'){
			goto Q51;
	    } else {
	         if(str[i] == 'h'){
		    	goto Q55;
		        } else {    
			    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
		            return 0;    
		        } else {
		        	return _LETTER;
		        }
	        }
		}
	Q51:
	    i++;
	    if(str[i] == 'i'){
			goto Q52;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q52:
	    i++;
	    if(str[i] == 't'){
			goto Q53;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q53:
	    i++;
	    if(str[i] == 'e'){
			goto Q54;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q54:
		i++;
	    if (str[i] == ' ') {
           *p = i;
	        return _WRITE;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q55:
	    i++;
	    if(str[i] == 'i'){
			goto Q56;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q56:
	    i++;
	    if(str[i] == 'l'){
			goto Q57;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q57:
	    i++;
	    if(str[i] == 'e'){
			goto Q58;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q58:
		i++;
	    if (str[i] == ' ') {
           *p = i;
	        return _WHILE;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	/*begin*/ /*boolean*/
	Q59:
	    i++;
	    if(str[i] == 'e'){
			goto Q60;
		} else{
		    if (str[i] == 'o'){
		        goto Q64;
		    } else {    
			    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
		            return 0;    
		        } else {
		        	return _LETTER;
		        }
		    } 
		}
	Q60:
	    i++;
	    if(str[i] == 'g'){
			goto Q61;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q61:
	    i++;
	    if(str[i] == 'i'){
			goto Q62;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q62:
	    i++;
	    if(str[i] == 'n'){
			goto Q63;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q63:
		i++;
	    if (str[i] == ' ') {
          *p = i;
	        return _BEGIN;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q64:
	    i++;
	    if(str[i] == 'o'){
			goto Q65;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q65:
	    i++;
	    if(str[i] == 'l'){
			goto Q66;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q66:
	    i++;
	    if(str[i] == 'e'){
			goto Q67;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q67:
	    i++;
	    if(str[i] == 'a'){
			goto Q68;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q68:
	    i++;
	    if(str[i] == 'n'){
			goto Q69;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q69:
		i++;
	    if (str[i] == ' ') {
          *p = i;
	        return _BOOLEAN;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	/*div*/ /*do*/
	Q70:
		i++;
	    if(str[i] == 'v'){
			goto Q71;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q71:
		i++;
	    if (str[i] == ' ') {
          *p = i;
	        return _DIV;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q72:
	    i++;
	    if(str[i] == 'o'){
			goto Q73;
	    } else {
	         if(str[i] == 'i'){
			    goto Q70;
	        } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        }
	}
	Q73:
		i++;
	    if (str[i] == ' ') {
          *p = i;
	        return _DO;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	 /*or*/
	Q74:
	    i++;
	    if(str[i] == 'r'){
			goto Q73;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	Q75:
		i++;
	    if (str[i] == ' ') {
          *p = i;
	        return _OR;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	            return 0;    
	        } else {
	        	return _LETTER;
	        }
        } 
	/*<*/
	Q76:
	    i++;
	    if(str[i] == '>'){
			goto Q77;
	    } else {
	        if(str[i] == '='){
		   	   goto Q78;
	        } else {
	            if(str[i] == ' '){
                   *p = i;
		   	        return _MENOR;
	            } else {
	    	        return 0;
	        }
    	}
   }
	/*<>*/
	Q77:
	    i++;
	    if(str[i] == ' '){
        *p = i;
			  return _DIFERENTE;
	    } else {
	    	return 0;
	    }
	/*<=*/
	Q78:
	    i++;
	    if(str[i] == ' '){
        *p = i;
			return _MENORIGUAL;
	    } else {
	    	return 0;
	    }
	/*>*/
	Q79:
	    i++;
	    if(str[i] == '='){
			goto Q80;
	    } else {
	        if(str[i] == ' '){
            *p = i;
		   	   return _MAIOR;
	       } else {
	    	   return 0;
	    }
	}
	/*>=*/	
	Q80:
	    i++;
	    if (str[i] == ' ') {
          *p = i;
	        return _MAIORIGUAL;
	    }  else {
	         return 0;
		}
	/*:*/
	Q81:
	    i++;
	    if(str[i] == '='){
			goto Q82;
	    } else {
	        if(str[i] == ' '){
            *p = i;
		   	   return _DSPNT;
	       } else {
	    	   return 0;
	    }
	}
	/*:=*/
	Q82:
	    i++;
	    if (str[i] == ' ') {
          *p = i;
	        return _ATRIBUICAO;
	    }  else {
	    	 return 0;
		}
	/*,*/ 	
	Q83:
	    i++;
	    if (str[i] == ' ') {
          *p = i;
	        return _VRGL;
	    }  else {
	    	 return 0;
		}
	/*(*/ 
	Q84:
	    i++;
	    if (str[i] == ' ') {
          *p = i;
	        return _ABREP;
	    }  else {
	    	 return 0;
		}
	/*;*/
	Q85:
	    i++;
	    if (str[i] == ' ') {
          *p = i;
	        return _PNTVRGL;
	    }  else {
	    	 return 0;
		}
	/*)*/ 
	Q86:
	    i++;
	    if (str[i] == ' ') {
          *p = i;
	        return _FECHAP;
	    }  else {
	    	 return 0;
		}
	/***/ 
	Q87:
	    i++;
	    if (str[i] == ' ') {
          *p = i;
	        return _OPMULT;
	      }else {
	    	 return 0;
		}
	/*-*/
	Q88:
	    i++;
	    if (str[i] == ' ') {
          *p = i;
	        return _OPSUB;
	      }else {
	    	 return 0;
		}
	/*+*/ 	
	Q89:
	    i++;
	    if (str[i] == ' ') {
          *p = i;
	        return _OPADI;
	      }else {
	    	 return 0;
		}
	/*0-1-2-3-4-5-6-7-8-9*/
	Q90:
	    i++;
	    if (str[i] == ' ') {
          *p = i;
	        return _NUMBER;
	    } else {
	        if ((str[i] == '0')||(str[i] == '1')||(str[i] == '2')||(str[i] == '3')||(str[i] == '4')||(str[i] == '5')||(str[i] == '6')||(str[i] == '7')||(str[i] == '8')||(str[i] == '9')){
	            goto Q90;
	        } else {
	   	     	return 0;
	    	}
    	}
    	 /*.*/ 	
	Q92:
	    i++;
	    if (str[i] == ' ') {
          *p = i;
	        return _PNT;
	      }else {
	    	 return 0;
		} 
    /*demais caracteres lidos*/
	Q91:
	    i++;
	    if (str[i] == ' ') {
           *p = i;
	        return _LETTER;
	    } else {    
		    if((str[i] == '.')||(str[i] == ':')||(str[i] == ';')||(str[i] == ',')||(str[i] == '<')||(str[i] == '>')||(str[i] == '=')||(str[i] == '-')||(str[i] == '+')||(str[i] == '*')||(str[i] == ')')||(str[i] == '(')){
	          return 0;    
	        } else {
	          goto Q91;
	        }
        }   
	return 1;
}

/*Buffer que irá armazenar os tokens lidos pelo analizador léxico*/
struct Node{
	int escopo;
    int num;
    char lexema[100];
 struct Node *prox;
};


typedef struct Node node;

int tam;

void inicia(node *FILA);
int vazia(node *FILA);
node *aloca(int elem,char* s);
void enqueue(node *FILA, int elem,char* s);
node *dequeue(node *FILA);
void exibe(node *FILA);
void libera(node *FILA);

//inicia o buffer
void inicia(node *FILA){
	FILA->prox = NULL;
	tam=0;
}
//verifica se o buffer está vazio
int vazia(node *FILA){
	if(FILA->prox == NULL)
		return 1;
	else
		return 0;
}
//aloca o token lido no analisador léxico
node *aloca(int elem,char* s){ 
	node *novo=(node *) malloc(sizeof(node));
	if(!novo){
		printf("Sem memoria disponivel!\n");
		exit(1);
	}else{
       novo->num = elem;
	   strcpy (novo->lexema, s);
	   return novo;
	}
}

//exibe os elementos dentro do buffer
void exibe(node *FILA){
    int count=0;
	if(vazia(FILA)){
	   printf("FILA vazia!\n\n");
    }
	node *tmp;
	tmp = FILA->prox;
	printf("TOKENS NO BUFFER:\n");
	while( tmp != NULL){
      printf("<%d,%s>\n", tmp->num,tmp->lexema);
	  tmp = tmp->prox;
	  count++;
    }
}

void debugPrintBuffer(node *FILA){
	node *tmp;
	tmp = FILA->prox;
	#ifdef DEBUG
    printf ("Lexema: <%s>\n", tmp->lexema);
    #endif
}
//libera o buffer 
void libera(node *FILA){
	if(!vazia(FILA)){
		node *proxNode,
		*atual;
		atual = FILA->prox;
		while(atual != NULL){
			proxNode = atual->prox;
			free(atual);
			atual = proxNode;
		}
	}
}

//escreve o elemento lido dentro do buffer
void enqueue(node *FILA, int elem,char* s){
    node *novo=aloca(elem,s);
   	novo->prox = NULL;
	if(vazia(FILA))
		FILA->prox=novo;
	else{
		node *tmp = FILA->prox;
		while(tmp->prox != NULL)
			tmp = tmp->prox;
		tmp->prox = novo;
	}
	tam++;
}

//retira o elemento a partir do topo do buffer
node *dequeue(node *FILA){ 
	if(FILA->prox == NULL){
		printf("Fila ja esta vazia\n");
		return NULL;
	}else{
		node *tmp = FILA->prox;
		FILA->prox = tmp->prox;
		tam--;
		return tmp;
	}
}

node *head(node *FILA){
    if(FILA->prox == NULL){
       exit(0);
    }else{
        node *tmp = FILA->prox;
		return tmp;
    }
}

int lookahead(node *FILA){
    if(FILA->prox == NULL){
       exit(0);
    }else{
        node *tmp = FILA->prox;
		return tmp->num;
    }
}


void match(node *FILA, int token){
	if(lookahead(FILA) == token){	
		dequeue(FILA);
		}else{
			printf("ERRO SINTATICO\n");
			exit(1);
		}	
}

/*TABELA DE SIMBOLOS*/

void iniciaTabelaSimbolo(node *PILHA);
void exibeTabelaSimbolo(node *PILHA);
void liberaTabelaSimbolo(node *PILHA);
node *retirarTabelaSimbolo(node *PILHA);

//inicia a Tabela de Simbolo
void iniciaTabelaSimbolo(node *PILHA)
{
 PILHA->prox = NULL;
 tam=0;
}
//verifica se a Tabela de Simbolo está vazia
int vaziaTabelaSimbolo(node *PILHA){
    if(PILHA->prox == NULL)
       return 1;
    else
       return 0;
}
//aloca o identificador lido na Tabela de Simbolo
node *alocaTabelaSimbolo(char* elem, int escopo){
    node *novo=(node *) malloc(sizeof(node));
	if(!novo){
       printf("Sem memoria disponivel!\n");
  	   exit(1);
	}else{
	   novo->escopo = escopo;
	   strcpy (novo->lexema, elem);
	   return novo;
	}
}
//exibe os elementos dentro da Tabela de Simbolo
void exibeTabelaSimbolo(node *PILHA){
    int count=0;
	if(vazia(PILHA)){
	   printf("PILHA vazia!\n\n");
    }
	node *tmp;
	tmp = PILHA->prox;
	printf("TABELA DE SIMBOLOS:\n");
	while( tmp != NULL){
	  printf("<%s,%d> escopo = %d\n", tmp->lexema,count, tmp->escopo);
	  tmp = tmp->prox;
	  count++;
    }

}
//libera a Tabela de Simbolo 
void liberaTabelaSimbolo(node *PILHA){
    if(!vazia(PILHA)){
       node *proxNode,
       *atual;
        atual = PILHA->prox;
        while(atual != NULL){
            proxNode = atual->prox;
            free(atual);
            atual = proxNode;
        }
    }
}
//escreve o elemento lido dentro da Tabela de Simbolo
void adicionaTabelaSimbolo(node *PILHA, char* elem, int escopo){
    node *novo=alocaTabelaSimbolo(elem, escopo);
    novo->prox = NULL;
    if(vazia(PILHA))
      PILHA->prox=novo;
    else{
      node *tmp = PILHA->prox;
      while(tmp->prox != NULL)
        tmp = tmp->prox;
    tmp->prox = novo; 
	}
    tam++;
}
//retira o elemento a partir do topo da Tabela de Simbolo
node *retirarTabelaSimbolo(node *PILHA){
    if(PILHA->prox == NULL){
       exit(0);
    }else{
        node *ultimo = PILHA->prox,
        *penultimo = PILHA;
        while(ultimo->prox != NULL){
            penultimo = ultimo;
            ultimo = ultimo->prox;
       }
    penultimo->prox = NULL;
    tam--;
    return ultimo;
    }
}
//verifica o topo da Tabela de Simbolo
node *topoTabelaSimbolo(node *PILHA){
    if(PILHA->prox == NULL){
       exit(0);
    }else{
        node *ultimo = PILHA->prox;
        while(ultimo->prox != NULL){
            ultimo = ultimo->prox;
       }
    return ultimo;
    }
}

/* REGRAS DO ANALISADOR SINTATICO
<programa>::= program <identificador>; <bloco>.
<bloco> ::= [<parte de declarações de variáveis>] [<parte de declarações de sub-rotinas>] <comando composto>
<parte de declarações de variáveis> ::= var<declaração de variáveis> {; <declaração de variáveis>};
<declaração de variáveis>::= <lista de identificadores>: <tipo>
<lista de identificadores> ::= <identificador> {, <identificador>}
<parte de declarações de subrotinas> ::= {declaração de procedimento>;}
<declaração de procedimento> ::= procedure <identificador>[<parâmetros formais>] ; <bloco> ;
<parâmetros formais> ::= ( <seção de parâmetros formais> { ; <seção de parâmetros formais>} )
<seção de parâmetros formais> ::= [var] <lista de identificadores>: <tipo>
<tipo> ::= integer | boolean
<comando composto ::= begin<comando> { ; <comando>} end
<comando> ::= <atribuição> | <chamada de procedimento> | <comando composto> | <comando condicional 1> | <comando repetitivo 1> | write( <identiicador> )
<atribuição>::= <variável>:= <expressão>
<chamada de procedimento> ::= <identificador> [ ( <lista de parâmetros>) ]
<lista de parâmetros> ::= [ ( <identificador> | <numero> | <bool> ) {, ( <identificador> | <numero> | <bool> ) } ]
<comando condicional 1> ::= if (<expressão>) then <comando> [else <comando>]
<comando repetitivo 1> ::= while (<expressão>) do <comando>
<expressão> ::= <expressão simples> [<relação><expressão simples>]
<relação> ::= = | <>| <| <= | >= | >
<expressão simples> ::= [+ | -] <termo> {(+ | -) <termo>}
<termo> ::= <fator> {(* | div) <fator> }
<fator> ::= <variavel> | <número> | <bool> | ( <expressãosimles> )
<variável> ::= <identificador>
<bool> ::= true | false
<número> ::= <dígito> {<dígito>}
<dígito> ::= 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
<identificador> ::= <letra> {<letra> | <dígito>}
<letra> ::= _ | a | b | ... | z| A | B | ... | Z

/* GRAMATICA
DIGITO -> 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9
LETRA -> _ | a | b | ... | z| A | B | ... | Z
*/
void TIPO(node *BUFFER, node *TSIMBOLO, int escopo); 
void ID(node *BUFFER, node *TSIMBOLO, int escopo); 
void NUMERO(node *BUFFER, node *TSIMBOLO, int escopo);
void BOOL(node *BUFFER, node *TSIMBOLO, int escopo);
void VARIAVEL(node *BUFFER, node *TSIMBOLO, int escopo);
void FATOR(node *BUFFER, node *TSIMBOLO, int escopo); 
void TERMO(node *BUFFER, node *TSIMBOLO, int escopo);
void ExprSimples(node *BUFFER, node *TSIMBOLO, int escopo);
void ATRIB(node *BUFFER, node *TSIMBOLO, int escopo);
void COMDCOND1(node *BUFFER, node *TSIMBOLO, int escopo);
void COMDCOND2(node *BUFFER, node *TSIMBOLO, int escopo);
void CMDREP1(node *BUFFER, node *TSIMBOLO, int escopo);
void CMD(node *BUFFER, node *TSIMBOLO, int escopo);
void CPROC(node *BUFFER, node *TSIMBOLO, int escopo);
void RELACAO(node *BUFFER, node *TSIMBOLO, int escopo);
void Expr(node *BUFFER, node *TSIMBOLO, int escopo);
void ListaID(node *BUFFER, node *TSIMBOLO, int escopo);
void SecParamForm(node *BUFFER, node *TSIMBOLO, int escopo);
void DeclVar(node *BUFFER, node *TSIMBOLO, int escopo);
void PartDeclVar(node *BUFFER, node *TSIMBOLO, int escopo);
void PartDeclSubRotina(node *BUFFER, node *TSIMBOLO, int escopo);
void CmdComposto(node *BUFFER, node *TSIMBOLO, int escopo);
void BLOCO(node *BUFFER, node *TSIMBOLO, int escopo);
void ParamForm(node *BUFFER, node *TSIMBOLO, int escopo);
void DeclProcedure(node *BUFFER, node *TSIMBOLO, int escopo);
void LPARAM(node * BUFFER, node *TSIMBOLO, int escopo);
void PROGRAM(node *BUFFER, node *TSIMBOLO, int escopo);

//TIPO -> integer | boolean
void TIPO(node *BUFFER, node *TSIMBOLO, int escopo){ 
    node *token;
	token = head(BUFFER);
	switch(lookahead(BUFFER)){
		case _INTEGER: 
		    debugPrintBuffer(BUFFER);
	    	match(BUFFER, _INTEGER);
			break;	
		case _BOOLEAN: 
		    debugPrintBuffer(BUFFER);
	    	match(BUFFER, _BOOLEAN);
			break;		
		default: 
		    printf("Era esperado <integer> ou <boolean>, porem foi encontrado <%s>\n", token->lexema);
			exit(1);
			break;
	}
}

//ID -> LETRA {LETRA | DIGITO} 
void ID(node *BUFFER, node *TSIMBOLO, int escopo){
    node *token;
	token = head(BUFFER);
	switch(lookahead(BUFFER)){
		case _LETTER: 
		    adicionaTabelaSimbolo(TSIMBOLO,token->lexema, escopo);
		    debugPrintBuffer(BUFFER);
			match(BUFFER, _LETTER);
			break;		
		default: 
		    printf("Era esperado <id>, porem foi encontrado <%s>\n", token->lexema);
		    exit(1);
		    break;
		    
	}
}

//NUMERO -> DIGITO {DIGITO} 
void NUMERO(node *BUFFER, node *TSIMBOLO, int escopo){ 
    node *token;
	token = head(BUFFER);
	switch(lookahead(BUFFER)){
		case _NUMBER: 
		    adicionaTabelaSimbolo(TSIMBOLO,token->lexema, escopo);
		    debugPrintBuffer(BUFFER);
		    match(BUFFER, _NUMBER);
			break;		
		default: 
		    printf("Era esperado <digito>, porem foi encontrado <%s>\n", token->lexema);
		    exit(1);
			break;	
	}
}

//BOOL -> true | false
void BOOL(node *BUFFER, node *TSIMBOLO, int escopo){
	node *token;
	token = head(BUFFER);
	switch(lookahead(BUFFER)){
		case _TRUE:    
		    debugPrintBuffer(BUFFER);
		    match(BUFFER, _TRUE);
			break;	
		case _FALSE: 
		    debugPrintBuffer(BUFFER);
		    match(BUFFER, _FALSE);
			break;		
		default: 
		    printf("Era esperado <true> ou <false>, porem foi encontrado <%s>\n", token->lexema);
		    exit(1);
			break;	
	}
}

//VARIAVEL -> ID
void VARIAVEL(node *BUFFER, node *TSIMBOLO, int escopo){
	ID(BUFFER, TSIMBOLO, escopo);
}

//FATOR -> VARIAVEL | NUMERO | BOOL | ( ExprSimples )
void FATOR(node *BUFFER, node *TSIMBOLO, int escopo){
	node *token;
	token = head(BUFFER);
	switch(lookahead(BUFFER)){
		case _LETTER: 
			 VARIAVEL(BUFFER, TSIMBOLO, escopo);
			break;
		case _NUMBER: 
			 NUMERO(BUFFER, TSIMBOLO, escopo);
			break;
		case _FALSE: 
			 BOOL(BUFFER, TSIMBOLO, escopo);
			break;	
		case _TRUE: 
			 BOOL(BUFFER, TSIMBOLO, escopo);
			break;	
		case _ABREP: 
		     debugPrintBuffer(BUFFER);
		     match(BUFFER, _ABREP);
			 ExprSimples(BUFFER, TSIMBOLO,escopo);
			 if(lookahead(BUFFER) == _FECHAP){
			 	debugPrintBuffer(BUFFER);
			 	match(BUFFER, _FECHAP);	
	       	}else{ 
			    printf("Era esperado <)>, porem foi encontrado <%s>\n", token->lexema);
				exit(1);	
         	}
			break;			
		default: 
		    printf("Era esperado <FATOR>, porem foi encontrado <%s>\n", token->lexema);
			break;	
	}
}

//TERMO -> FATOR {(* | div) FATOR} 
void TERMO(node *BUFFER, node *TSIMBOLO, int escopo){
	node *token;
	token = head(BUFFER);
	while((lookahead(BUFFER)==_FALSE)||(lookahead(BUFFER)==_TRUE)||(lookahead(BUFFER) == _LETTER)||(lookahead(BUFFER) == _NUMBER)||(lookahead(BUFFER) == _OPMULT)||(lookahead(BUFFER) == _DIV)){
		switch(lookahead(BUFFER)){
			case _OPMULT: 
			    debugPrintBuffer(BUFFER);
			    match(BUFFER, _OPMULT);
				FATOR(BUFFER, TSIMBOLO, escopo);
				break;	
			case _DIV: 
			    debugPrintBuffer(BUFFER);
			    match(BUFFER, _DIV);
				FATOR(BUFFER, TSIMBOLO, escopo);
				break;	
			case _NUMBER: 
				FATOR(BUFFER, TSIMBOLO, escopo);
				break;
			case _LETTER: 
				FATOR(BUFFER, TSIMBOLO, escopo);
				break;	
			case _TRUE: 
				FATOR(BUFFER, TSIMBOLO, escopo);
				break;
			case _FALSE: 
				FATOR(BUFFER, TSIMBOLO, escopo);
				break;				
			default: 
			    printf("Era esperado <*> ou <div>, porem foi encontrado <%s>\n", token->lexema);
				break;	
		}
	}
}
//ExprSimples -> [+ | -] TERMO {(+ | -) TERMO} 
void ExprSimples(node *BUFFER, node *TSIMBOLO, int escopo){
	node *token;
	token = head(BUFFER);
	while((lookahead(BUFFER)==_FALSE)||(lookahead(BUFFER)==_TRUE)||(lookahead(BUFFER) == _LETTER)||(lookahead(BUFFER) == _NUMBER)||(lookahead(BUFFER) == _OPADI)||(lookahead(BUFFER) == _OPSUB)){
		switch(lookahead(BUFFER)){
			case _OPADI: 
			    debugPrintBuffer(BUFFER);
			    match(BUFFER, _OPADI);
				TERMO(BUFFER, TSIMBOLO, escopo);
				break;	
			case _OPSUB: 
			    debugPrintBuffer(BUFFER);
		    	match(BUFFER, _OPSUB);
				TERMO(BUFFER, TSIMBOLO, escopo);
				break;	
			case _NUMBER: 
				TERMO(BUFFER, TSIMBOLO, escopo);
				break;
			case _LETTER: 
				TERMO(BUFFER, TSIMBOLO, escopo);
				break;	
			case _TRUE:
			    TERMO(BUFFER, TSIMBOLO, escopo);
				break;
			case _FALSE:
			    TERMO(BUFFER, TSIMBOLO, escopo);
				break;			
			default: 
			    printf("Era esperado <-> ou <+>, porem foi encontrado <%s>\n", token->lexema);
				break;	
		}
	}
}

//RELACAO -> = | <>| <| <= | >= | >
void RELACAO(node *BUFFER, node *TSIMBOLO, int escopo){
	node *token;
	token = head(BUFFER);
	switch(lookahead(BUFFER)){
		case _IGUAL:
			debugPrintBuffer(BUFFER);
			match(BUFFER, _IGUAL);
	    	break;
		case _MAIOR: 
	    	debugPrintBuffer(BUFFER);
		    match(BUFFER, _MAIOR);
	    	break;
		case _MENOR:
			debugPrintBuffer(BUFFER);
			match(BUFFER, _MENOR);	
	    	break;
		case _MAIORIGUAL:
			debugPrintBuffer(BUFFER);
			match(BUFFER, _MAIORIGUAL);
	    	break;
		case _ATRIBUICAO:
			debugPrintBuffer(BUFFER);
			match(BUFFER, _ATRIBUICAO);
	    	break;
		case _DIFERENTE:
			debugPrintBuffer(BUFFER);
	    	match(BUFFER, _DIFERENTE);
	    	break;
	    default: 
			printf("Era esperado <RELACAO>, porem foi encontrado <%s>\n", token->lexema);
			break;		
	} 	
}

//Expr -> ExprSimples [RELACAO ExprSimples]
void Expr(node *BUFFER, node *TSIMBOLO, int escopo){
	ExprSimples(BUFFER, TSIMBOLO, escopo);
	while((lookahead(BUFFER) == _IGUAL)||(lookahead(BUFFER) == _MAIOR)||(lookahead(BUFFER) == _MENOR)||(lookahead(BUFFER) == _MAIORIGUAL)||(lookahead(BUFFER) == _ATRIBUICAO)||(lookahead(BUFFER) == _DIFERENTE)){
	    RELACAO(BUFFER, TSIMBOLO, escopo);
    	ExprSimples(BUFFER, TSIMBOLO, escopo);
    }
}

//ListaID -> ID {, ID} 
void ListaID(node *BUFFER, node *TSIMBOLO, int escopo){
	ID(BUFFER, TSIMBOLO, escopo);	
    if (lookahead(BUFFER) == _VRGL) {
    	while(lookahead(BUFFER) == _VRGL) {
    		debugPrintBuffer(BUFFER);
    		match(BUFFER, _VRGL);
			ID(BUFFER, TSIMBOLO, escopo);
		}
    }
}
//SecParamForm -> [var] ListaID : TIPO
void SecParamForm(node *BUFFER, node *TSIMBOLO, int escopo){
	node *token;
	token = head(BUFFER);
	switch(lookahead(BUFFER)){
		case _VAR:
			debugPrintBuffer(BUFFER);
			match(BUFFER, _VAR);
			ListaID(BUFFER, TSIMBOLO, escopo);
			token = head(BUFFER);
	        if(lookahead(BUFFER) == _DSPNT){
	        	debugPrintBuffer(BUFFER);
	        	match(BUFFER, _DSPNT);
				TIPO(BUFFER, TSIMBOLO, escopo);		
	       	}else{ 
			    printf("Era esperado <:>, porem foi encontrado <%s>\n", token->lexema);
				exit(1);	
         	}
			break;	
		default: 
		    printf("Era esperado <VAR>, porem foi encontrado <%s>\n", token->lexema);
			break;	
	}
} 

//DeclVar -> ListaID : TIPO
void DeclVar(node *BUFFER, node *TSIMBOLO, int escopo){
	node *token;
	ListaID(BUFFER, TSIMBOLO, escopo); 
	token = head(BUFFER);
	if(lookahead(BUFFER) == _DSPNT){
		debugPrintBuffer(BUFFER);
	    match(BUFFER, _DSPNT);
		TIPO(BUFFER, TSIMBOLO, escopo);		
	}else{ 
		printf("Era esperado <:>, porem foi encontrado <%s>\n", token->lexema);
		exit(1);	
	}
}

//PartDeclVar -> var DeclVar {; DeclVar} ; 
void PartDeclVar(node *BUFFER, node *TSIMBOLO, int escopo){
	node *token;
	token = head(BUFFER);
	if(lookahead(BUFFER) == _VAR){
		while(lookahead(BUFFER) == _VAR){
			debugPrintBuffer(BUFFER);
			match(BUFFER, _VAR);
			DeclVar(BUFFER, TSIMBOLO, escopo);
			token = head(BUFFER);
			if(lookahead(BUFFER) == _PNTVRGL){
				debugPrintBuffer(BUFFER);
				match(BUFFER, _PNTVRGL);
		    }else{ 
			    printf("Era esperado <;>, porem foi encontrado <%s>\n", token->lexema);
				exit(1);	
	     	}
	    }
    }else{
        printf("Era esperado <VAR>, porem foi encontrado <%s>\n", token->lexema);
		exit(1);
	}	
} 

//PartDeclSubRotina -> {DeclProcedure;}
void PartDeclSubRotina(node *BUFFER, node *TSIMBOLO, int escopo){
	node *token;
	token = head(BUFFER);
	if(lookahead(BUFFER) == _PROCEDURE){
		DeclProcedure(BUFFER, TSIMBOLO, escopo);
		token = head(BUFFER);
		if(lookahead(BUFFER) ==_PNTVRGL){
			debugPrintBuffer(BUFFER);
			match(BUFFER, _PNTVRGL);
	    }else{ 
			printf("Era esperado1 <;>, porem foi encontrado <%s>\n", token->lexema);
			exit(1);	
	    } 
    }else{ 
		printf("Era esperado <procedure>, porem foi encontrado <%s>\n", token->lexema);
		exit(1);	
	}	
}

//CmdComposto -> begin CMD {; CMD} end
void CmdComposto(node *BUFFER, node *TSIMBOLO, int escopo){	
    node *token, *tabela;
	token = head(BUFFER);
	if (lookahead(BUFFER) == _BEGIN) {
		escopo++;
		debugPrintBuffer(BUFFER);
		match(BUFFER, _BEGIN);
		CMD(BUFFER, TSIMBOLO, escopo);    
		while((lookahead(BUFFER) == _PNTVRGL)&&(lookahead(BUFFER) != _END)){
		    	debugPrintBuffer(BUFFER);
			  	match(BUFFER, _PNTVRGL);
				CMD(BUFFER, TSIMBOLO, escopo);
	    }
	}else{ 
           printf("Era esperado <begin>, porem foi encontrado <%s>\n", token->lexema);
	       exit(1);
    	}    
	token = head(BUFFER);
    if (lookahead(BUFFER) == _END) {
    	tabela=topoTabelaSimbolo(TSIMBOLO);
    	while(tabela->escopo == escopo){
        	retirarTabelaSimbolo(TSIMBOLO);
        	tabela = topoTabelaSimbolo(TSIMBOLO);
        }
        escopo--;
		debugPrintBuffer(BUFFER);
        match(BUFFER, _END);
    }else{ 
       printf("Era esperado <end>, porem foi encontrado <%s>\n", token->lexema);
       exit(1);	
	}
}

//BLOCO -> [PartDeclVar] [PartDeclSubRotina] CmdComposto
void BLOCO(node *BUFFER, node *TSIMBOLO, int escopo){
	while(lookahead(BUFFER) == _VAR){
	    PartDeclVar(BUFFER, TSIMBOLO, escopo); 
    }
    while(lookahead(BUFFER) == _PROCEDURE){
	    PartDeclSubRotina(BUFFER, TSIMBOLO, escopo);	 
    }
	 CmdComposto(BUFFER, TSIMBOLO, escopo);
}

//ParamForm -> ( SPARAMFORM {; SPARAMFORM })
void ParamForm(node *BUFFER, node *TSIMBOLO, int escopo){
	node *token;
	switch(lookahead(BUFFER)){
		case _ABREP: 
		    debugPrintBuffer(BUFFER);
	    	match(BUFFER, _ABREP);
			SecParamForm(BUFFER, TSIMBOLO, escopo);
			while(lookahead(BUFFER) == _PNTVRGL){
				debugPrintBuffer(BUFFER);
				match(BUFFER, _PNTVRGL);
				SecParamForm(BUFFER, TSIMBOLO, escopo);
			}
			token = head(BUFFER);
			if(lookahead(BUFFER) == _FECHAP){
			   debugPrintBuffer(BUFFER);	
			   match(BUFFER, _FECHAP);
	     	} else {
	     		printf("Era esperado <)>, porem foi encontrado <%s>\n", token->lexema);
		        exit(1);
			 }
	     	break;
		default: 
		    printf("Era esperado <(>, porem foi encontrado <%s>\n", token->lexema);
			break;	
	}

}

//DeclProcedure -> procedure ID [PARAMFORM] ; BLOCO ;
void DeclProcedure(node *BUFFER, node *TSIMBOLO, int escopo){
	node *token;
	token = head(BUFFER);
	switch(lookahead(BUFFER)){
		case _PROCEDURE: 
		    escopo++;
		    debugPrintBuffer(BUFFER);
		    match(BUFFER, _PROCEDURE);
			ID(BUFFER, TSIMBOLO, escopo);
			while(lookahead(BUFFER) == _ABREP){
			   ParamForm(BUFFER, TSIMBOLO, escopo);
	     	}
	     	token = head(BUFFER);
			if(lookahead(BUFFER) == _PNTVRGL){
				debugPrintBuffer(BUFFER);
				match(BUFFER, _PNTVRGL);
		    }else{ 
		       printf("Era esperado <;>, porem foi encontrado <%s>\n", token->lexema);
		       exit(1);	
         	}
			BLOCO(BUFFER, TSIMBOLO, escopo);
			break;		
		default: 
		    printf("Era esperado <procedure>, porem foi encontrado <%s>\n", token->lexema);
		    break;	
	}	
}

//CMD -> ATRIB | CPROC | CmdComposto | COMDCOND1 | CMDREP1 | write ( ID )
void CMD(node *BUFFER, node *TSIMBOLO, int escopo){
	node *token;
	switch(lookahead(BUFFER)){
		case _WRITE:
			debugPrintBuffer(BUFFER);
			match(BUFFER, _WRITE);
			token = head(BUFFER);
        	if(lookahead(BUFFER) == _ABREP){
        		debugPrintBuffer(BUFFER);
        		match(BUFFER, _ABREP);
				ID(BUFFER, TSIMBOLO, escopo);
			}else{
				printf("Era esperado <(>, porem foi encontrado <%s>\n", token->lexema);
				exit(1);
			}
			token = head(BUFFER);
        	if(lookahead(BUFFER) == _FECHAP){
        		debugPrintBuffer(BUFFER);
        		match(BUFFER, _FECHAP);
			}else{
				printf("Era esperado <)>, porem foi encontrado <%s>\n", token->lexema);
				exit(1);
			}
		    break;	
		case _LETTER:
			if(lookahead(BUFFER) == _ABREP){
				CPROC(BUFFER, TSIMBOLO, escopo);
			}else{
				ATRIB(BUFFER, TSIMBOLO, escopo);
			}		
		    break;
		case _BEGIN:
			escopo++;
			CmdComposto(BUFFER, TSIMBOLO, escopo);	
		    break;
		case _IF:
			COMDCOND1(BUFFER, TSIMBOLO, escopo);	
		    break;
		case _WHILE:
			CMDREP1(BUFFER, TSIMBOLO, escopo);	
		    break;								
	}	
}

//ATRIB -> VARIAVEL := EXPR 
void ATRIB(node *BUFFER, node *TSIMBOLO, int escopo){
	node *token;
	VARIAVEL(BUFFER, TSIMBOLO, escopo);
	token = head(BUFFER);
	if(lookahead(BUFFER) == _ATRIBUICAO){
		debugPrintBuffer(BUFFER);
		match(BUFFER, _ATRIBUICAO);
		Expr(BUFFER, TSIMBOLO, escopo);
	}else{
		printf("Era esperado <:=>, porem foi encontrado <%s>\n", token->lexema);
		exit(1);
	}
}

//CPROC -> ID [( LPARAM )]
void CPROC(node *BUFFER, node *TSIMBOLO, int escopo){
	node *token;
	ID(BUFFER, TSIMBOLO, escopo);
    while(lookahead(BUFFER) == _ABREP){
    	debugPrintBuffer(BUFFER);
    	match(BUFFER, _ABREP);
	    LPARAM(BUFFER, TSIMBOLO, escopo);
	    token = head(BUFFER);
		if(lookahead(BUFFER) == _FECHAP){
			debugPrintBuffer(BUFFER);
			match(BUFFER, _FECHAP);
		}else{
			printf("Era esperado <)>, porem foi encontrado <%s>\n", token->lexema);
			exit(1);
		}
    }
}
//LPARAM -> [( ID | NUMERO | BOOL ) {, ( ID | NUMERO | BOOL )}]
void LPARAM(node * BUFFER, node *TSIMBOLO, int escopo) {
	node *token;
	token = head(BUFFER);
    do{
	    if(lookahead(BUFFER) == _ABREP) {
	    	debugPrintBuffer(BUFFER);
	    	match(BUFFER, _ABREP);
	        switch(lookahead(BUFFER)){
			      case _LETTER:
			        ID(BUFFER, TSIMBOLO, escopo);
			        break;
			      case _NUMBER:
			        NUMERO(BUFFER, TSIMBOLO, escopo);
			        break;
			      case _FALSE:
			        BOOL(BUFFER, TSIMBOLO, escopo);
			        break;
			      case _TRUE:
			        BOOL(BUFFER, TSIMBOLO, escopo);
			        break;
			      default:
			        printf("Era esperado <id> ou <digito> ou <bool>, porem foi encontrado <%s>\n", token->lexema);
			        break;
	        }
		    if(lookahead(BUFFER) == _FECHAP){
		    	debugPrintBuffer(BUFFER);
		        match(BUFFER, _FECHAP);
		    }else{
			   printf("Era esperado <)>, porem foi encontrado <%s>\n", token->lexema);
		       exit(1);
	    	}
	    }
    }while(lookahead(BUFFER) == _VRGL);
}

//COMDCOND1 -> if ( Expr ) then CMD {COMDCOND2}
void COMDCOND1(node *BUFFER, node *TSIMBOLO, int escopo){
	node *token;
	token = head(BUFFER);
	if(lookahead(BUFFER) == _IF){
		debugPrintBuffer(BUFFER);
		match(BUFFER, _IF);
		if(lookahead(BUFFER) == _ABREP){
			debugPrintBuffer(BUFFER);
			match(BUFFER, _ABREP);
		    Expr(BUFFER, TSIMBOLO, escopo);
			token = head(BUFFER);   
		    if(lookahead(BUFFER) == _FECHAP){
		    	debugPrintBuffer(BUFFER);
		    	match(BUFFER, _FECHAP);
		    }else{
		    	printf("Era esperado <)>, porem foi encontrado <%s>\n", token->lexema);
			    exit(1);
        	}
	    }
	    token = head(BUFFER);
		if(lookahead(BUFFER) == _THEN){
			debugPrintBuffer(BUFFER);
			match(BUFFER, _THEN);
		    CMD(BUFFER, TSIMBOLO, escopo);
	    }else{
		    printf("Era esperado <then>, porem foi encontrado <%s>\n", token->lexema);
			exit(1);
        }
	    if(lookahead(BUFFER) == _ELSE){
	    	COMDCOND2(BUFFER, TSIMBOLO, escopo);
		}
	}else{
		printf("Era esperado <if>, porem foi encontrado <%s>\n", token->lexema);
		exit(1);
	}	
}

//COMDCOND2 -> else CMD ----->>>> correção da gramatica
void COMDCOND2(node *BUFFER, node *TSIMBOLO, int escopo){
	node *token;
	token = head(BUFFER);
	if(lookahead(BUFFER) == _ELSE){
		debugPrintBuffer(BUFFER);
		match(BUFFER, _ELSE);
		CMD(BUFFER, TSIMBOLO, escopo);
	}else{
		printf("Era esperado <else>, porem foi encontrado <%s>\n", token->lexema);
		exit(1);
	}	
}
//CMDREP1 -> while ( EXPR ) do CMD
void CMDREP1(node *BUFFER, node *TSIMBOLO, int escopo){
	node *token;
	token = head(BUFFER);
	if(lookahead(BUFFER) == _WHILE){
		debugPrintBuffer(BUFFER);
		match(BUFFER, _WHILE);
		token = head(BUFFER);
		if(lookahead(BUFFER) == _ABREP){
			debugPrintBuffer(BUFFER);
			match(BUFFER, _ABREP);
		    Expr(BUFFER, TSIMBOLO, escopo);   
		    token = head(BUFFER);
		    if(lookahead(BUFFER) == _FECHAP){
		    	debugPrintBuffer(BUFFER);
		    	match(BUFFER, _FECHAP);
		    }else{
		    	printf("Era esperado <)>, porem foi encontrado <%s>\n", token->lexema);
			    exit(1);
        	}
	    }else{
		    	printf("Era esperado <(>, porem foi encontrado <%s>\n", token->lexema);
			    exit(1);
        	}
        token = head(BUFFER);	
		if(lookahead(BUFFER) == _DO){
			debugPrintBuffer(BUFFER);
			match(BUFFER, _DO);
		    CMD(BUFFER, TSIMBOLO, escopo);
	    }else{
		    printf("Era esperado <do>, porem foi encontrado <%s>\n", token->lexema);
			exit(1);
        }
	}else{
			printf("Era esperado <while>, porem foi encontrado <%s>\n", token->lexema);
			exit(1);
	}	
}

//PROGRAM  -> ID ; BLOCO .
void PROGRAM(node *BUFFER, node *TSIMBOLO, int escopo){	
    node *token;
	ID(BUFFER, TSIMBOLO, escopo);	
	token = head(BUFFER);
	switch(lookahead(BUFFER)){
		case _PNTVRGL:
			debugPrintBuffer(BUFFER);
		    match(BUFFER, _PNTVRGL);
			BLOCO(BUFFER, TSIMBOLO, escopo);
			token = head(BUFFER);
			if (lookahead(BUFFER) == _PNT) {
				debugPrintBuffer(BUFFER);
				match(BUFFER, _PNT);
			}else{
				printf("Era esperado <.>, porem foi encontrado <%s>\n", token->lexema);
			}
			break;
		default: 
		    printf("Era esperado <;>, porem foi encontrado <%s>\n", token->lexema);
			break;	
	}
}

void analisador_sintatico(node *BUFFER, int stop){
	node *token;
	token = head(BUFFER);
	node *TSIMBOLO=(node *)malloc(sizeof(node));
	int escopo = 0;
	iniciaTabelaSimbolo(TSIMBOLO);
	while(stop != -1){
		switch(lookahead(BUFFER)){
			case _PROGRAM:
				debugPrintBuffer(BUFFER);
				match(BUFFER, _PROGRAM);
				PROGRAM(BUFFER, TSIMBOLO, escopo);
				stop = 1;
				break;	
			default: 
			    printf("Era esperado <program>, porem foi encontrado <%s>\n", token->lexema);
			    stop = -1;
				break;	
		}
		exibeTabelaSimbolo(TSIMBOLO);
		printf("Analise sintatica finalizada.\n");
	}
	printf("Analise sintatica finalizada.\n"); 
}

int main(){
	char str[80], linha[80], final[80] = "", url[]="", ch;
	int i = -1, r=1, tamanho = 0, count=0, quantidade = 0;
	FILE *arq;
	FILE *saida;
	node *BUFFER=(node *)malloc(sizeof(node));
    inicia(BUFFER);
	//Definindo o arquivo a ser compilado como program.txt	
	arq = fopen("program.txt", "r");
	//Arquivo de saida.txt exibe a lista de tokens lidos pelo automato do método leitor
	//a saída é exibida no formato <token,posição>
	saida = fopen("saida.txt", "w");	
	//Condição que valida a leitura do arquivo program.txt caso não seja possível a leitura
	//a mensagem de erro será exibido	
	if(arq == NULL)
		printf("Erro, nao foi possivel abrir o arquivo\n");
	else{
		//O loop garante a leitura linha a linha do arquivo program.txt
		while((fgets(linha, 500, arq)!= NULL)&&(r!=0)){	
		    //conta a quantidade de caracteres na linha que foi lida
			tamanho = strlen(linha);
			count=0;
			//identifica cada caracter das palavras lidas
			while(count<tamanho){
				ch=linha[count];
				//condição de parada para identificar o final de um token
			   	if(ch == ' ' || ch == '\n') {
			    	strcat(final, &ch);
			    	r = leitor(final, &i);
			    	if((r!=1)&&(r!=-1)){
			    	    enqueue(BUFFER,r,final);
				    	if (r!=0){
				    		fprintf(saida, "<%d,%s>\n", r, final);
				    	    quantidade++;
				    	}else{
				    		if(r==0){
				    		       printf("Erro: Entrada nao aceita");
						           printf("\nSequencia incorreta: %s\n", final);
						    }      break;
						}           
					}else{
						if(r==-1)
						    break;
					    }
			    	i = -1;
			    	strcpy(final, "");
			    	} else {
			    		strcat(final, &ch);
			    	}
			    count++; 	
			    }
		   }  
		//exibe(BUFFER);    
		fclose(saida);
		fclose(arq);
		analisador_sintatico(BUFFER, quantidade);
		}
	libera(BUFFER);
    return 0;
}

