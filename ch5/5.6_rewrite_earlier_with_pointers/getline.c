#include <stdio.h>
#define MAXLINE 100

int mygetline( char *line,int limit );

int main(){
	char array[MAXLINE];
	mygetline(array , MAXLINE);
	printf("%s",array);
}

int mygetline( char *line,int limit ){
       int i; /* iterator */

       for( i=0; i<limit && (*line = getchar()) != EOF && *line != '\n';i++,line++);

       if(*line == '\n')
       	   *++line ='\0';
       
       return i; /* length of string without ending NULL */
}

