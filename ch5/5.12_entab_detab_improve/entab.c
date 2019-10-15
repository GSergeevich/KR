#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define TABSTITUTE 4 /* default number of spaces for substitute 1 tab */
#define MAXLINE 100 

int mygetline(char string[]); /* function save current line in array */
int entab(char string[], int tabs, int from , int number); /* function for substitute spaces to tabs in given array*/	 

int main(int argc , char *argv[]){
	char line[MAXLINE],c;
	int len,tabs,from,number;
	tabs=TABSTITUTE; /* default */	

	if(argc > 1){

		while(--argc >0 && (c = (*++argv)[0]) == '-' || c == '+' ){
			c=*++argv[0];
			switch(c){
				case 'n':
					if(isdigit(*++argv[0]))
						tabs=atoi(argv[0]);
					break;
				case '1': case '2' : case '3' : case '4':
				case '5': case '6' : case '7' : case '8':
				case '9':
					if(*--argv[0] == '-')			
						from = atoi(++argv[0]); 
					else
						number = atoi(++argv[0]); 

					break;			
				default:
					printf("Error,use -n option, example: entab -n4");	
			
			}

		}
	}

	while((len = mygetline(line)) > 0 ){
		entab(line, tabs,from,number);
	}
	return 0;
}	


int entab( char string[], int tabs, int from, int number){
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
	else if( number > 0 && from >=0){
			for(i = 0; (c = string[i]) != '\0'; i++){
				if(i == from || (i > from && (i - from) % number == 0)){
					putchar('\t');
	       				putchar(c);
				}
				else
	       				putchar(c);

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
