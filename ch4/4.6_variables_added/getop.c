#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "calc.h"

int getop(char s[]){
	int i,c,t;

	while((s[0] = c = getch()) == ' '||c == '\t')
		;
	s[1] = '\0'; /* correct string ending for "default" case in switch*/
	i=0;
	if(islower(c)){
		while(islower(s[++i] = c = getch()))
			;
		ungetch(c);
		s[i]='\0';
		if(strcmp(s,"sin") == 0 || strcmp(s,"pow") == 0 ||strcmp(s,"exp") == 0)
			return FUNC;
		else
			--i;
			while(i>=0){
			ungetch(s[i--]);
			}
			return (c = getch());
	}

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

