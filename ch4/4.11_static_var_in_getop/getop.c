#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "calc.h"

int getop(char s[]){
	int i,c,t;
	static int un;
	un=0;

	if(un != 0)
		c = un;
	else
		c = getch();

	while((s[0] = c ) == ' '||c == '\t')
		c = getch(); /* skip spaces */

	s[1] = '\0'; /* correct string ending for "default" case in switch*/
	i=0;
	if(islower(c)){
		while(islower(s[++i] = c = getch()))
			;
		un = c;
		s[i]='\0';
		if(i == 1){ /* only one char */
			return s[0];
		}
		else if(strcmp(s,"sin") == 0 || strcmp(s,"pow") == 0 ||strcmp(s,"exp") == 0)
			return FUNC;
		else  /* unrecognized string */
			return ERR; /* 'default' section in switch now */
	}

	if(!isdigit(c) && c != '.' && c != '-'){
		return c; /* not a digit: math operator (except '-') or crap*/
	}
	if(c == '-'){
		if(!isdigit(t = getch())){ /* check if next char is digit that assume it's a negative number */
			un = t;	/* save next char in buffer */
			return c; /* sometimes minus is a simple minus (math operator) */
		}
		else {
			un = t;	/* save next char in buffer */
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
		un = c;
	return NUMBER;
}

