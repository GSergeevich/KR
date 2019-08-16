/* Modified version of itoa; to handle the situation of MIN_INT of limits.h
in the previous number = -2147483648 would fail at n =-n,because the max value of integer is 2147483647

modifying itoa to handle these situations. 
sign is stored as  the number itself, absolute value of each digit is stored in the string and 
while loop is tested not for 0

itoa: convert an integer to string */
#include <stdio.h>
#include <string.h>
#include <limits.h>
#define abs(x) ( (x) > 0 ? (x): -(x))

void myitoa_old(int n, char s[]);
void myitoa(int n, char s[]);
void reverse(char s[]);

int main(){
	char s[1000];
	myitoa_old(INT_MIN,s);
	printf("%s\n",s);
	myitoa(INT_MIN,s);
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

void myitoa(int n, char s[]){
	int i,sign;
	sign = (n>0)? 1 : -1;
	i=0;
	do{
		s[i++] = abs(n % 10) + '0';
	} while ((n /= 10 ) != 0);

	if(sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s); 
}

void myitoa_old(int n, char s[]){
	int i,sign;
	if((sign = n)<0)
		n=-n;
	i=0;
	do{
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);

	if(sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse(s); 
}
