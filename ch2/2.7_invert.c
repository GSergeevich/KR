#include <stdio.h>
#define NUMBER 255

void dec2bin(unsigned dec);
unsigned int power(int base, int n);
unsigned invert(unsigned x,int p,int n);

int main(){
	int i;
	unsigned number = NUMBER;
	printf("Before: ");
	dec2bin(number);
	number=invert(number,9,4);
	printf("After (inverted):");
	dec2bin(number);
}

unsigned invert(unsigned x,int p,int n){
	return x & ~(~(~0 << n) << (p+1-n)) | (~x & (~(~0 << n) << (p+1-n)));
}

unsigned int power(int base, int n){
	int i, p;

	p = 1;
	for (i = 1; i <= n; ++i)
		p = p * base;
	return p;
}

void dec2bin(unsigned dec){
	  int i;
	  int size=(sizeof(dec) * 8);
	  char bits[size];
	  for(i=size-1;i>=0;--i){
	  	bits[i]=(dec & power(2,(i)))? 1 : 0;
		printf("%d",bits[i]);
  	  };
          printf("\n");
}
