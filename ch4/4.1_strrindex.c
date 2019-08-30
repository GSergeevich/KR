#include <stdio.h>
#define MAXLINE 1000


int strrindex(char s[], char t[]);
int strindex(char s[], char t[]);
int str_length(char s[]);

int main(){
	char s[MAXLINE]="This is the test string";
 	char t[MAXLINE]="is";
        printf("First entry of \"%s\" start in \"%s\" at %d\n",t,s,strindex(s,t));
        printf("Rightest entry of \"%s\" start in \"%s\" at %d\n",t,s,strrindex(s,t));

}

/* first entry */
int strindex(char s[], char t[]){
	int i,j,k;

	for(i=0; s[i]!='\0' ;++i){
		for(j=i,k=0;s[j]==t[k] && t[k] != '\0';++k,++j)
			;
		if(t[k]=='\0')
			return i+1; 
		}
	return -1;
}
/*rightmost entry*/
int strrindex(char s[], char t[]){
	int i,j,k,tl;
	tl=str_length(t) -1;

	for(i=str_length(s)-1; i >= 0 ;--i){
		for(j=i,k = tl;s[j]==t[k] && k >= 0;--k,--j)
			;
		if(k < 0)
			return i + 1 - tl; 
		}
	return -1;
}


int str_length(char s[]){
	/* return length of string wo "\0" */
        int i;
	for(i=0; s[i] != '\0'; ++i)
		; 	
	return i;

}

