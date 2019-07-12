#include <stdio.h>

#define IN 1
#define OUT 0

main(){
	int c ;
	while((c = getchar()) != EOF){
		putchar(c);
		if(c == '\t' || c == '\n'|| c == ' '){
		       printf("\n");
		}
	}
}
