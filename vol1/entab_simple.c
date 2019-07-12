#include <stdio.h>
#define TABS 4

main() {
	int c,i,j;
	int sc,reset;
	int spaces,tabs;

	i = 0;
	sc = 0;
	reset = 0;
	for(;(c=getchar()) != EOF;){
        /* reset counts if newline */
		if(reset==1){
			i=0;
			sc=0;
			reset=0;
		}
		/* check current char and increase spaces count */
		if(c == ' '){
			++sc;
		}

		/* check newline*/
		else if(c == '\n'){
		       if(i == sc){
				/* get tabs and spaces count*/
				tabs=(sc / TABS);
				spaces=(sc - tabs * TABS);
				/* print */
				for(j=1;j <= tabs;++j){
					putchar('#');
				}
				for(j=1;j <= spaces;++j){
					putchar('*');
				}
				/* print newline */
				putchar('\n');
		       }
		       /* set flag for reset count vars */
		       reset = 1;
		}
		++i;

	}
	return 0;
}
