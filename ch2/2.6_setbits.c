#include <stdio.h>
#define NUMBER 15 

void dec2bin(unsigned dec);
unsigned setbits(unsigned x,int p,int n,unsigned y);
unsigned int power(int base, int n);

int main(){
	int i;
	unsigned number = NUMBER;
	printf("Before: ");
	dec2bin(number);
	number=setbits(number,9,4,number);
	printf("After:  ");
	dec2bin(number);
}

unsigned long_version_setbits(unsigned x,int p,int n,unsigned y){
	unsigned mask=0;
	int lastbit=(sizeof(x) * 8) - 1; /* number of last bit from 0 */
	mask = ~((( ~mask << lastbit - p)) >> (lastbit - (n + 1)) << (p - n - 1));/*create mask for bitwise "and" */
	x = x & mask; /* zeroing n bits from "p" position */
	y = (y << lastbit - n) >> (lastbit - p - 1); /* zeroing all bits above and below last n bits and move it to "p" position */
	x = x | y; /* bitwise "or" with masked x (zeroed "n" bits from "p") and y (zeroed all bits,except those that where last "n"*/
	return x;
}

unsigned setbits(unsigned x,int p,int n,unsigned y){
	return x & ~(~(~0 << n) << (p+1-n)) | (y & ~(~0 << n)) << (p+1-n);
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
