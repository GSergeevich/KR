#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define DTAIL 2
#define MAXLENGTH 1000
#define MAXLINES 1000

int mypgetline(char *lineptr[]);
char *alloc(int len);
void writeout(char *lineptr[],int tail,int linecount);


char allocbuf[MAXLENGTH * MAXLINES];
char *allocp = allocbuf; /* next free pos */

int main(int argc , char *argv[]){
	/* char *strings[]={"String1","String2","string3"}; */
	char *lineptr[MAXLINES];
	int c,tail,linecount;

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

	while(mypgetline(lineptr) >= 0 ){
		++linecount;
		++lineptr;
	}
	printf("debug ");
	writeout(lineptr,tail,linecount);

	return 0;
}	

int mypgetline( char *lineptr[] ){
	int c; /* for ccurrent char */
	int i; /* iterator */
	char lbuff[MAXLENGTH];

 	i=0;
        while((c = getchar()) != EOF && c != '\n'){
		lbuff[i] = c;
		++i;
       	}
       	if(c == '\n'){
		lbuff[i] = c;
       		++i;
                lbuff[i] = '\0';
		*lineptr = strcpy(alloc(i+1),lbuff);
      		return i;
	}else
		return -1;
}


char *alloc(int len){
	if(allocbuf + (MAXLENGTH * MAXLINES) - allocp >= len){
		allocp += len;
		return allocp - len;
	}
	else
		return 0;
}
	

void writeout(char *lineptr[],int tail,int linecount){
	while(tail>0 && linecount >0)
		printf("%s\n",*lineptr--);
}
