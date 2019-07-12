#include <stdio.h>
#define EDGE 10

main(){
	int c,count,i,flag;
	int buffer[EDGE];

	count=0; /* chars counter */
	flag=0; /* */
	while((c=getchar()) != EOF){
/*		putchar(c); */
		buffer[count] = c;
		if(count == (EDGE -1 ) || c == '\n'){
			/* find position of last non blank/not newline character */
			while(flag == 0){
				if( buffer[count] == ' ' || buffer[count] == '\t' || buffer[count] == '\n' ){
					--count;
				}
				else
					/* set flag for quit, if current char not blank */
					flag = 1;
			}

                        /* print not blank chars from array */
			for(i=0;i<=count;++i){
				putchar(buffer[i]);			
			}

			/* print newline and reset counter and flag */
			putchar('\n');
			count = 0;
			flag=0;
		}
		/* if EDGE not reached, and current char is not newline */
		else
			++count;
	}
}

