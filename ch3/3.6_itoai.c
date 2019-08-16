#include <stdio.h>
#include <string.h>
#include <limits.h>
#define abs(x) ( (x) > 0 ? (x): -(x))
#define CIFER 134

void myitoaw(int n, char s[],int w);
void reverse(char s[]);

int main(){
	char s[1000];
	myitoaw(CIFER,s,6);
	printf("%s\n",s);
}

void reverse(char s[]){
	int i,j,temp;
	for(i=0,j=strlen(s) -1;i<j;++i,--j){
		temp=s[i];
		s[i]=s[j];
		s[j]=temp;
	}
}

void myitoaw(int n, char s[], int w){
	int i,sign;
	sign = (n>0)? 1 : -1;
	i=0;
	do{
		s[i++] = abs(n % 10) + '0';
	} while ((n /= 10 ) != 0);
	

	if(sign < 0)
		s[i++] = '-';
	while(i<w)
		s[i++]=' ';
	s[i] = '\0';
	reverse(s); 
}

