#include <stdio.h>

#define IN 1
#define OUT 0

main(){
	int c, wn, ln, cn , state;
	wn = ln = cn = 0;
	state =  OUT;
	while((c = getchar()) != EOF ){
		++cn;
		if(c == '\n'){
			++ln;
		}
		if(c == ' ' || c == '\t'|| c == '\n'){
			state = OUT;
		}
		else if(state == OUT){
			state = IN;
			++wn;
		}	
	}

	printf("Words: %d\nLines: %d\nChars: %d\n", wn, ln , cn);

}
