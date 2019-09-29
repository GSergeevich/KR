#include <stdio.h>
#define MAXLINE 100

char *my_strcat(char *,char *);
int my_strend(char *,char *);

int main(){
	char s[MAXLINE]="source string";
	char t[MAXLINE]="added text";
	
	printf("%s\n",s);
	printf("Search t in s(\"0\" mean fail) : %d\n",my_strend(s,t));
	my_strcat(s,t);
	printf("%s\n",s);
	printf("Search t in s : %d\n",my_strend(s,t));
		
}

int my_strend(char *s,char *t){
	int i;

	while(*s) /* go to the end of string ('\0',which equal zero )*/
		++s;
	
	for(i=0;*t != '\0';t++,i++);/* same :) and counting "t" string*/

	while(*s-- == *t-- && i-- >= 0);
		;
	if(i >=0) /* mean string "s"  not contain substring "t" */
		return 0;
	else 
		return 1;
		
}

char *my_strcat(char *s,char *t ){
	while(*s)
		++s; 
	while( *s++ = *t++)
		;
	return s;
}
