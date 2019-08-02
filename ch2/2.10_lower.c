#include <stdio.h>

char lower(char c);

int main(){
	int c;
	while((c=getchar()) != EOF){
		c=lower(c);
		putchar(c);
	}
}

char lower(char c){
	int diap = 'A' - 'a';
	c = (c >='A' && c <= 'Z') ? c - diap : c;
	return c;
}
