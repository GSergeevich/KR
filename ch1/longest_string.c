#include <stdio.h>

#define MAXLINE 10 /* maximum length of string */
int mygetline(char line[], int maxline);
void copy(char from[], char to[]);

/* print longest string in flow */

int main(){
	int len; /* current length */
	int max; /* current maximum length */
	int c;
        char line[MAXLINE]; /* array for current line */
	char longest[MAXLINE]; /* array for current longest */

	max = 0;
	while ((len = mygetline(line, MAXLINE)) > 0)
		if (len == MAXLINE ){
		        while(( c = getchar()) != EOF && c != '\n' ){
				++len;
		       }
		}  


	        else if (len > max){
			 max = len;
			 copy(line, longest);
		}

        if (max > 0){
		printf("%s", longest);
	
	return 0;
 }
}

int mygetline(char s[], int lim){
	int c,i;

	for (i = 0; i<lim-1 && (c=getchar()) != EOF && c !='\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void copy(char from[], char to[]){
	int i;
	for(i = 0; ((to[i] = from[i]) != '\0'); ++i)
		;
}

