#include <stdio.h>

main(){
	int c, sc, nlc, tc;
	sc = 0;
	nlc =0;
	tc = 0;
	while ((c = getchar()) != EOF) {
	     if (c == '\n')
		     ++nlc;
	     if (c == '\t')
		     ++tc;
	     if (c == ' ')
		     ++sc;
	}
        printf("Newlines: %d\nSpaces: %d\nTabs: %d\n", nlc, sc, tc);


}
