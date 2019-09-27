#include <stdio.h>
#include <ctype.h>
#define SIZE 100

int getch(void);
void ungetch(int);

int main(){
	int array[SIZE],n,getint(int *);

	for(n=0; n < SIZE && getint(&array[n]) != EOF ;++n)
		;
	while(n>=0){
		printf("Index : %d , Value : %d \n",n,array[n]);
		--n;
	}	

}

int getint(int *pn){
	int c,i,sign;

	while(isspace(c = getch()))
		       ;	
	if( !isdigit(c) && c != '-' && c != '+' && c != EOF ){
		ungetch(c); /* warning,loop*/
		return 0;
	}
	
	sign = ( c == '-' )? -1 : 1;
	if( c == '-' || c == '+' )
		c = getch();
        
	if(!isdigit(c)){
		ungetch(c);
		return c;
	}

	for(*pn = 0; isdigit(c) ; c = getch())
		*pn = *pn * 10 + (c - '0');
	
	*pn *= sign;
	
	if(c != EOF)
		ungetch(c);
	
	return c;	

}


#define BUFFSIZE 100

char buffer[BUFFSIZE];
int bufpt = 0;/* next free index in buffer[] */


void ungetch(int c){
	(bufpt< BUFFSIZE) ? buffer[bufpt++] = c : printf("error: ungetch : buffer is full"); 
}

int getch(void){
	return (bufpt > 0) ? buffer[--bufpt] : getchar();
}
