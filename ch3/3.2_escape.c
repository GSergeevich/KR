#include <stdio.h>
#define MAXLINE 1000

int mygetline( char line[] );
int escape( char s[],char t[] );
int unescape( char t[],char s[] );

int main() {
	int len; /* for length jf string */
	char line[MAXLINE]; /* array with current string */
	char escaped[MAXLINE]; /* array for escaped string */
	char unescaped[MAXLINE]; /* array for unescaped string */

	mygetline(line);
	printf("Source: %s\n", line);
	escape(line,escaped);
	printf("Escaped: %s\n", escaped);
	unescape(escaped,unescaped);
	printf("Unescaped: %s\n", unescaped);

	return 0;
}	

int escape(char s[], char t[]){
	int i;
	int j;
	int c;

	for(i = j = 0; (c=s[i]) !='\0';++i,++j){
		switch(c){
		default: 
			t[j]=c;
			break;
			 
		case '\n': 
			 t[j]='\\';
			 t[++j]='n';
		         break;	 
		case '\t': 
			 t[j]='\\';
			 t[++j]='t';
		         break;	 
		
		}
	
	}
	t[++j]='\0';
}

int unescape(char t[], char s[]){
	int i;
	int j;
	int tmp;/*prev char*/
	int c;

	
	for(i = j = tmp = 0; (c=t[i]) !='\0';++i,++j){
		switch(c){
		default: 
			s[j]=c;
			break;
		case 'n':
		         if(tmp == '\\')
				s[--j]='\n';
			 else
			 	s[j]=c;
			 break;	 
		case 't': 
		         if(tmp == '\\')
				s[--j]='\t';
			 else
				s[j]=c;
		         break;
		}
		tmp=c;
	
	}
	s[++j]='\0';
}

int mygetline( char line[] ){
       int c; /* for ccurrent char */
       int i; /* iterator */

       i=0;
       while((c = getchar()) != EOF){
		line[i] = c;
		++i;
       }
       line[++i]='\0';

       return i+1;
}
