#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define TABSTITUTE 4 /* default number of spaces for substitute 1 tab */
#define MAXLINE 100 

int mygetline(char string[]); /* function save current line in array */
int entab(char string[], int tabs); /* function for substitute spaces to tabs in given array*/	 

int main(int argc , char *argv[]){
	char line[MAXLINE],c;
	int len,tabs;

	if(argc > 1){

		while(--argc >0 && (*++argv)[0] == '-'){
			c=*++argv[0];
			switch(c){
				case 'n':
					if(isdigit(*++argv[0]))
						tabs=atoi(argv[0]);
					break;
				default:
					printf("Error,use -n option, example: entab -n4");	
			
			}

		}
	}
	else
		tabs=TABSTITUTE;	

	while((len = mygetline(line)) > 0 ){
		entab(line, tabs);
	}
	return 0;
}	


int entab( char string[], int tabs){
	int c,i,j; /* iterators */
	int sc; /* spaces count */ 
	int ns; /* number of spaces */
	int nt; /* number of tabs */

	for(i = 0,sc = 0; (c = string[i]) != '\n'; i++){
			if(c == ' ')
				++sc;
	}
	
	if(i == sc){  /* empty string */	
        	nt = ( sc / tabs );
		ns = ( sc % tabs );
		  	for(j = 0 ; j < nt; j++){
				putchar('t');
			}
		  	for(j = 0 ; j < ns; j++){
				putchar('s');
			}
	}
	else 
		printf("%s",string);

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
