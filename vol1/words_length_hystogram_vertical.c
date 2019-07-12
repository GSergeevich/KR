#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX 100

main(){
	int c , i, j, cn, state, acc;
	int charcount[MAX];
        /* array init */	
	for(i=0; i <= MAX; ++i){
		charcount[i] = 0;
	}

        state =  OUT;
	cn = 0;

        /* read input and write to array*/
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

	/* Create output */
	/* search max entry number*/

	for(i = 0,acc = 0; i <= MAX; ++i){
		if(acc < charcount[i]){
			acc = charcount[i];
		}
	}

        /* vertical hystogram create */
	for(i = acc;i > 0; --i){
		for(j=0; j<=MAX; ++j){
			if( charcount[j] > 0){
				if( charcount[j] >= i)
					printf("*");
				else 
		               		printf(" ");
			}
		}
		printf("\n");
	}		
	
	for(i=0; i<=MAX; ++i){
		if( charcount[i] > 0){
			printf("%d", i);
		}
	}



}
