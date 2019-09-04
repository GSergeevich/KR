#include <stdio.h>
#define BUFFSIZE 100

char buffer[BUFFSIZE];
int bufpt = 0;


void ungetch(int c){
	(bufpt< BUFFSIZE) ? buffer[bufpt++] = c : printf("error: ungetch : buffer is full"); 
}

int getch(void){
	return (bufpt > 0) ? buffer[--bufpt] : getchar();
}

int mygetline( char line[],int limit ){
       int c; /* for ccurrent char */
       int i; /* iterator */

       i=0;
       while(i<limit && (c = getchar()) != EOF && c != '\n'){
		line[i] = c;
		++i;
       }
       if(c == '\n')
	  line[i] = c; 	       				

       line[++i]='\0';

       return i;
}

