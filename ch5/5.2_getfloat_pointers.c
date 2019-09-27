#include <stdio.h>
#include <ctype.h>
#define SIZE 100

int getch(void);
void ungetch(int);

int main(){
	float array[SIZE];
	int n,getfloat(float *);

	for(n=0; n < SIZE && getfloat(&array[n]) != EOF ;++n)
		;
	while(n>=0){
		printf("Index : %d , Value : %f \n",n,array[n]);
		--n;
	}	

}

int getfloat(float *pn){
	int c,i,sign,power;

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

	for(*pn = 0.0; isdigit(c) ; c = getch())
		*pn = *pn * 10.0 + (c - '0');
	
	if(c == '.'|| c == ','){
		c=getch();
		for(power = 1.0; isdigit(c) ; c = getch())
			*pn = *pn * 10.0 + (c - '0');
			power *= 10.0;
	}

	*pn = *pn / power;
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
