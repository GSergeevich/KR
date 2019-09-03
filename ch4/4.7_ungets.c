#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define FUNC 'f'
#define MAXVARS ('Z'-'A') + 1

#define BUFFSIZE 100

char buffer[BUFFSIZE];
int bufpt = 0;


void ungetch(int c){
	(bufpt< BUFFSIZE) ? buffer[bufpt++] = c : printf("error: ungetch : buffer is full"); 
}

int getch(void){
	return (bufpt > 0) ? buffer[--bufpt] : getchar();
}

void ungets(char s[]){
	int i,c;
	for(i=0;(c = s[i]) != '\0';++i)
		ungetch(c);
}
