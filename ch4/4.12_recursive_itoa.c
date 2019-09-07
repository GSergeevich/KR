#include <stdio.h>
#include <string.h>
#include <limits.h>
#define abs(x) ( (x) > 0 ? (x): -(x))

void myitoa(int n);

int main(){
	myitoa(-135);
}

void myitoa(int n){
	int i,sign;
	sign = (n>0)? 1 : -1;
	n = abs (n); 
	if(sign < 0)
		putchar('-');

	if((n / 10 ) != 0)
		myitoa(n / 10);

	putchar((n % 10) + '0');
}
