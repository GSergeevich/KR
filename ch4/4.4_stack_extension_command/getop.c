#include <ctype.h>
#include <stdio.h>
#include "calc.h"

int getop(char s[]){
	int i,c,t;

	while((s[0] = c = getch()) == ' '||c == '\t')
		;
	s[1] = '\0'; /* correct string ending for "default" case in switch*/
	if(!isdigit(c) && c != '.' && c != '-'){
		return c; /* not a digit: math operator (except '-') or crap*/
	}
	if(c == '-'){
		if(!isdigit(t = getch())){ /* check if next char is digit that assume it's a negative number */
			ungetch(t); /* return next char in buffer */
			return c; /* sometimes minus is a simple minus (math operator) */
		}
		else {
			ungetch(t); /* return next char in buffer */
		}
	}

	i=0;
	if(isdigit(c) || c == '-')
		while(isdigit(s[++i] = c = getch()))
			;
	if(c == '.')
		while(isdigit(s[++i] = c = getch()))
			;
	s[i]='\0';
	if(c != EOF)
		ungetch(c);
	return NUMBER;
}

