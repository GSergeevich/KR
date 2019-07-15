#include <stdio.h>

main(){
	int c;
	while((c = getchar()) != EOF){
	        if (c == '\b')
		     printf("backspace");
		if (c == '\t')
		     printf("\\t"); 
	        if (c == '\\')
		     printf("\\\\");
	
		
		else
		    putchar(c); 	
	}
}
