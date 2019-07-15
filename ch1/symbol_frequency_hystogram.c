#include <stdio.h>

#define MAX 256

main(){
	int c, i, j;
	int symbcount[MAX];
	
	for(i=0; i <= MAX; ++i){
		symbcount[i] = 0;
	}

	while((c = getchar()) != EOF ){
		++symbcount[c];
	}

	for(i = 0; i <= MAX; ++i){
			if(symbcount[i] >0){
					printf("Freq  \%c:\t", i);
				        for(j = 1; j <= symbcount[i]; ++j){
						printf("x");
					}
					printf("\n");
			}
	}

}
