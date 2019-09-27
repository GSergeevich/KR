#include <stdio.h>
#define MAXLINE 100

char *my_strcat(char *,char *);

int main(){
	char s[MAXLINE]="source string";
	char t[MAXLINE]="added text";

	my_strcat( s, t);
	printf("%s\n",s);
		
}

char *my_strcat(char *s,char *t ){
	while(*s)
		++s; 
	while( *s++ = *t++)
		;
	return s;
}
