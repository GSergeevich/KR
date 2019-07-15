#include <stdio.h>

#define LIMIT 1000

void reverse(char s[]);
int str_length(char line[]);
int mygetline(char line[], int limit);

int main(){
	char line[LIMIT];
	int len;

	while((len=mygetline(line,LIMIT))>0){
		reverse(line);
	}
        return 0;
}


int mygetline(char line[], int limit){
	int c,i;
	i=0;
	while((c = getchar()) != EOF && c != '\n' && i-1<= limit){
		line[i]=c;
		++i;
	}
	if(c == '\n')
		line[i]='\n';
	        ++i;
	        line[i]='\0';	

	return i;
}

void reverse(char s[]){
	int i,c;
	i=str_length(s);
	while(i >=0 ){
		putchar(s[i]);
		--i;
	}
	        putchar('\n');
}

int str_length(char s[]){
        int i;
	for(i=0; s[i] != '\n'; ++i); 	
	return i - 1;

}


