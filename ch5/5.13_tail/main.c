#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define DTAIL 2
#define MAXLENGTH 1000
#define MAXLINES 1000

int readline(char *lineptr[],int maxlines); /* pointer on where store line */
char *alloc(int len);
void writeout(char **lineptr,int tail,int linecount);
int mygetline( char line[] );


char allocbuf[MAXLENGTH * MAXLINES];
char *allocp = allocbuf; /* next free pos */

int main(int argc , char *argv[]){
	char *lineptr[MAXLINES]; /* array of pointers */
	int c,tail,linecount,i;
	char *p;

	tail=DTAIL; /* default value */	 
	
	while(--argc >0 && (*++argv)[0] == '-' ){
		c=*++argv[0]; /* char after "-" */
		switch(c){
			case 'n':
				if(isdigit(*++argv[0]))
					tail=atoi(argv[0]);
				break;
			default:
				printf("Error,use -n option, example: tail -n2");	
			
			}

		}

	
	linecount=0;

	if((linecount = readline(lineptr,MAXLINES)) >= 0 )
		writeout(lineptr,tail,linecount);


	return 0;
}	

int readline( char *lptr[], int maxlines ){
	int c; /* for ccurrent char */
	int i,linecount,len;
	char lbuff[MAXLENGTH];
	char *p;

	linecount=0;

        while((len = mygetline(lbuff)) >= 0 && linecount < maxlines){
		lbuff[len++]='\0';
		p=alloc(len);
		strcpy(p,lbuff);
		lptr[linecount++]=p;
	}

	return linecount;
}

int mygetline( char line[] ){
       int c; /* for ccurrent char */
       int i; /* iterator */

       i=0;
       while((c = getchar()) != EOF && c != '\n'){
		line[i] = c;
		++i;
       }

       if(c == '\n')
       		return i;
	
       else 
	       return -1;

}


char *alloc(int len){
	char *tmp;
	int free;
	free = (allocbuf + (MAXLENGTH * MAXLINES) - allocp );
	if(free >= len){
		allocp += len;
		tmp=allocp - len;
		return tmp;
	}
	else{
		return 0;
	}
}
	

void writeout(char *lineptr[],int tail,int linecount){
	int max;
	max=linecount;
	linecount -= tail;
	while(linecount < max){
/*		printf("debug linecount %d\n",linecount);
		printf("debug tail %d\n",tail); */ 
		printf("%s\n",lineptr[linecount++]);
	}
}

