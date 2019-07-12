#include <stdio.h>

#define TABSTITUTE 4 /* number of spaces for substitute 1 tab */
#define MAXLINE 100 

int mygetline(char string[]); /* function save current line in array */
int entab(char string[], int tabs); /* function for substitute spaces to tabs in given array*/	 

int main(){
	char line[MAXLINE];
	int len;

	while((len = mygetline(line)) > 0 ){
		entab(line, TABSTITUTE);
	}
	return 0;
}	


int entab( char string[], int tabs){
	int c,i,j; /* iterators */
	int sc; /* spaces count */ 
	int ns; /* number of spaces */
	int nt; /* number of tabs */

	for(i = 0,sc = 0; (c = string[i]) != '\n'; i++){
			if(c == ' '){
				++sc;
			}
	}
		      	
        if( sc == i ){
      		  nt = ( i / tabs );
		  ns = (i - nt * TABSTITUTE );
		  for(j = 0 ; j < nt; j++){
			putchar('*');
			}
		  for(j = 0 ; j < ns; j++){
			putchar('#');
			}
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
