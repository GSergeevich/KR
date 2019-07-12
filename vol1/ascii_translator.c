#include <stdio.h>

main (){
	int c;
	for(c = getchar(); c != EOF; c = getchar())
		 printf("%d\n", c ); 
	/* while((c = getchar()) != EOF) { 
		 printf("%d\n", c ); 
       		 putchar(c); */

}	
