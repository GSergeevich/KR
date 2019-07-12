#include <stdio.h>

int mygetline( char line[] );

int main() {
	int len; /* for length jf string */
	char line[1000]; /* array with current string */
	
        while((len = mygetline(line)) > 0){
		printf("%s", line);
	}

	return 0;
}	

int mygetline( char line[] ){
       int c; /* for ccurrent char */
       int i; /* iterator */
       int tc; /* temp char */

       i=0;
       while((c = getchar()) != EOF && c != '\n'){
		line[i] = c;
		++i;
       }

       if(c == '\n'){
	       /* search "empty" symbols in the end of line */
	        while((tc = line[i - 1]) == ' ' || tc == '\t'){
			--i;
       		}

		line[i] = c;
       		++i;
                line[i] = '\0';
		}	
       return i;
}
