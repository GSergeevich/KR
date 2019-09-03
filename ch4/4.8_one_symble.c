#include <stdio.h>

int buf = 0;

void ungetch(int c){
	if(buf != 0){
		printf("error: ungetch : buffer is full");
	}
	else{
		buf = c;  
}

int getch(void){
	int c;
	if(buf != 0){
		c = buf;
		buf = 0;
	}
	else
		c = getchar();

	return c;
}
