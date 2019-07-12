#include <stdio.h>

#define TABSTITUTE 4 /* number of spaces for substitute 1 tab */
#define MAXLINE 100 

int mygetline(char string[]); /* function save current line in array */
int detab(char string[], int tabs); /* function for substitute tabs to spaces in given array*/	 

int main(){
	char line[MAXLINE];
	int len;

	while((len = mygetline(line)) > 0 )
		detab(line, TABSTITUTE);
	return 0;
}


int detab( char string[], int tabs){
	int c,i,j;

	for(i = 0; (c = string[i]) != '\0'; i++){
			if(c == '\t'){
			        for(j = 0 ; j < tabs; j++){
					putchar('#');
					}
			}  
			else
			       putchar(c);
			

	}
			return 0;       
} 

int mygetline( char line[] ){
       int c; /* for ccurrent char */
       int i; /* iterator */

       i=0;
       while((c = getchar()) != EOF && c != '\n'){
		line[i] = c;
		++i;
       }
       if(c == '\n'){
		line[i] = c;
       		++i;
                line[i] = '\0';
		}
       return i;
}

