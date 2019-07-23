#include <stdio.h>
#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 128 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 

unsigned int power(int base, int n){
	int i, p;

	p = 1;
	for (i = 1; i <= n; ++i)
		p = p * base;
	return p;
}

int main(){ 
  int byte=1234;	
  int i;


/*  printf(""BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(byte) ); */

  int size=(sizeof(byte) * 8);
  printf("DEC: %d \n",byte); 
  printf("Size: %d bit \n",size); 
  int bits[size];
  printf("BIN:");
  for(i=size-1;i>=0;--i){
	  bits[i]=(byte & power(2,i))? 1 : 0;
	  printf("%d",bits[i]);
  };
  printf("\n");


}



