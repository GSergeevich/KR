#include <stdio.h>

int mygetline( char line[] );
int reverse( char s[],char r[] );

int main() {
	int len; /* for length jf string */
	char line[1000]; /* array with current string */
	char reversed[1000]; /* array for reversed string */
	
        while((len = mygetline(line)) > 0){
		printf("Source: %s", line);
		reverse(line,reversed);
		printf("Reversed: %s", reversed);
	}

	return 0;
}	

int reverse(char s[], char r[]){
	int i;
	int j;
	int len;

	/* determine length of argument string */
	for(i = 0; s[i] !='\n';++i);
        len = i;
	/* fill reverse array */
	for(j = 0; j <= len;){ 
		r[j]=s[i];
		++j;
		--i;
	}
	r[j] = '\n'; 
       	++j;
        r[j] = '\0'; 
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
