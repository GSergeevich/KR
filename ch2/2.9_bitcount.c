#include <stdio.h>
int bitcount(unsigned x);
int fast_bitcount(unsigned x);

main(){
	unsigned x =15; 
	int count;
	count = fast_bitcount(x);
        printf("count: %d\n", count);

}

int bitcount(unsigned x){
	int b;
	for(b=0; x != 0; x >>= 1){
		printf("%d\n",x);
		if(x & 01)
		      b++;
	}	
	return b;

}

int fast_bitcount(unsigned x){
      int b;
      for (b = 0; x != 0; x &= (x-1)){
	  printf("%d\n",x);
          b++;
      }
      return b;
}
