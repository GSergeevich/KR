#include <stdio.h>

main() {

	int c, lastc; 
	lastc = 'a';
	while (( c = getchar()) != EOF){ 
		if(c == ' '){
			if(lastc != ' ')
		           putchar(c);
		}
		else
		        putchar(c);
				
	            
		lastc = c;	
	/*	printf("\n---\n");
		printf("%d\n", c);
		printf("\n---\n"); */
}
}
