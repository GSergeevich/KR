/* function itob(n,s,b), that converts the integer n into a base b character representation in 
  the string s.
*/
#include <stdio.h>
#include <string.h>
#include <limits.h>
#define abs(x) ( (x) > 0 ? (x): -(x))
#define CIFER INT_MAX

void myitob(int n, char s[],int b);
void reverse(char s[]);

int main(){
	char s[1000];
	myitob(CIFER,s,16);
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

void myitob(int n, char s[],int b){
	int i,j,sign;
	char digits[16] ="0123456789ABCDEF" ;
/*	for(i=0;i<=9;++i){
		digits[i]= i + '0';
	}
	for(j=0;i<=15;++i,++j){
		digits[i]= j + 'A';
	}
*/
	sign = (n>0)? 1 : -1;
	i=0;
	do{
		s[i++] = digits[abs(n % b)];
	} while ((n /= b ) != 0);

	if(sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s); 
}

