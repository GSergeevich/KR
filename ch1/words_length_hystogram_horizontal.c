#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX 100

main(){
	int c , i, j, cn, state;
	int charcount[MAX];
	
	for(i=0; i <= MAX; ++i){
		charcount[i] = 0;
	}
        state =  OUT;
	cn = 0;
	while((c = getchar()) != EOF ){
		if(c == ' ' || c == '\t'|| c == '\n'){
			state = OUT;
	                printf("%d\n", cn);
		 	++charcount[cn]; 
			cn = 0;
		}
		else if(state == OUT){
			state = IN;
			++cn;
		}	
		else {
			++cn;
		}
	}

	for(i = 0; i <= MAX; ++i){
			if(charcount[i] >0){
					printf("Length %d:\t", i);
				        for(j = 1; j <= charcount[i]; ++j){
						printf("x");
					}
					printf("\n");
			}
	}

}
