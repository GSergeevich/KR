#include <stdio.h>
#define MAXLINE 10

int mygetline( char *line,int limit );

int main(){
	char array[MAXLINE];
        mygetline(array , MAXLINE);
	printf("%s",array);
}

int mygetline( char *line,int limit ){
       /* limit in address representation :
 
       char *i;
       i = line + (limit -1);
     
*/	
       int i;

       for(i=0;i < limit && (*line = getchar()) != EOF && *line != '\n';line++,i++); /* save last position for NULL */

       if(*line == '\n')
       	   *++line ='\0';
      
       return i; 
}

