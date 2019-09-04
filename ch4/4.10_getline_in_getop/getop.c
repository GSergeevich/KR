#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "calc.h"

int getop(char s[]){
	extern int pos;/* position in line[] */
	int i,j,c,t;

	/* get string from input */
	if(line[pos]== '\0'){
		if(mygetline(line,MAXOP) == 0){
			return EOF;
		} 
		else
			pos = 0;
	}

	while((c = s[0] = line[pos++]) == ' '||c == '\t') /* skip spaces */
		;
	j = 0;
	s[1] = '\0'; /* correct string ending for "default" case in switch*/
	if(islower(c)){
		while(islower(s[++j] = line[pos++]))
			;
		s[j] = '\0';
		if(j == 1){ /* only one char */
			return s[0];
		}
		else if(strcmp(s,"sin") == 0 || strcmp(s,"pow") == 0 ||strcmp(s,"exp") == 0){
			return FUNC;
		}
		else{  /* unrecognized string */
			return ERR; /* 'default' section in switch now */
		}
	}

	if(!isdigit(c) && c != '.' && c != '-'){
		return c; /* not a digit: math operator (except '-') or crap*/
	}
	if(c == '-'){
		if(!isdigit(s[i+1])){ /* check if next char is digit that assume it's a negative number */
			return c; /* sometimes minus is a simple minus (math operator) */
		}
	}

	if(isdigit(c) || c == '-')
		while(isdigit(c = s[++j] = line[pos++]))
			;
	if(c == '.')
		while(isdigit(c = s[++j] = line[pos++]))
			;
	s[j]='\0';
	pos--;
	return NUMBER;
}
