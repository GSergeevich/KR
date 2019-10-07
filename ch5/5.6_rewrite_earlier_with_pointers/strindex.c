#include <stdio.h>
#define MAXLINE 1000


char *strrindex(char *, char *);

char *strindex(char *, char *);
int str_length(char s[]);

int main(){
	char s[MAXLINE]="Thi";
 	char t[MAXLINE]="This";
        printf("First entry of \"%s\" start in \"%s\" at %#010x\n",t,s,strindex(s,t));
        printf("Rightest entry of \"%s\" start in \"%s\" at %#010x\n",t,s,strrindex(s,t));

}

/* first entry */
char *strindex(char *s, char *t){
	int i;

	while(*s != '\0'){
		i = 0;
		while(s[i] == t[i] && s[i] != '\0'){ /* avoid errors if string s is shorter then t*/
			if(t[i++] == '\0') /* achieve end of test string*/	
				return s; 
		}
		if(t[i] == '\0') /* achieve end of test string*/	
			return s; 
		else 
			++s;
	} 


	return 0;

}

/* old version*/
/*      int i,j,k;	
 	for(i=0; s[i]!='\0' ;++i){
		for(j=i,k=0;s[j]==t[k] && t[k] != '\0';++k,++j)
			;
		if(t[k]=='\0')
			return i+1; 
		}
	return -1;
}
*/


/*rightmost entry*/

char *strrindex(char *s, char *t){
	char *s_start,*t_start;
	int i;

	s_start=s;
	t_start=t;

	/* go to the end of strings ,not need to use str_length() */	
	while(*s != '\0')
		s++;
	while(*t != '\0')
		t++;

	while(s >= s_start){
		i=0;
		while(t[i] == s[i] && (s + i--) >= s_start){
			if(t == t_start) /* achieve start of test string */
				return s;
		}

		--s;
	}

	return 0;

}

/* old version*/
/*	
	for(i=str_length(s)-1; i >= 0 ;--i){
		for(j=i,k = tl;s[j]==t[k] && k >= 0;--k,--j)
			;
		if(k < 0)
			return i + 1 - tl; 
		}
	return -1;
	*/



int str_length(char *s){
	/* return length of string wo "\0" */
        int i;
	for(i=0; s[i] != '\0'; ++i)
		; 	
	return i;

}

