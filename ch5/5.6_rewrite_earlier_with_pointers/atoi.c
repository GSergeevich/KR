#include <stdio.h>

int atoi(char *);

int main(){
	char s[]="128";
	
	printf("%d\n", atoi(s));
	
}

int atoi( char *s){
	int n;
	n = 0;

	while(*s != '\0'){
		n = n * 10 + ( *s - '0');
		++s;
	}
	return n;
	
}
