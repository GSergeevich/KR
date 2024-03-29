#include <stdio.h>

#define MAXLINE 1000 /* maximum length of string */
#define TRIGGER 80
int mygetline(char line[], int maxline);

/* print longest string in flow */

int main(){
	int len; /* current length */
	int max; /* current maximum length */
	int c;
        char line[MAXLINE]; /* array for current line */

	max = 0;
	while ((len = mygetline(line, MAXLINE)) > 0){
		if (len >= TRIGGER ){
			printf("%s", line);
		}  
	} 


	return 0;
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
