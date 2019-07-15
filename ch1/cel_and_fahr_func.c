#include <stdio.h>
#define LOWER 0
#define UPPER 600
#define STEP 20
#define ZERO 0

int cel2fahr(int lower, int upper , int step);

int main ()
{
        cel2fahr( LOWER, UPPER, STEP);
	printf("\n");
        return 0;	
}	

int cel2fahr(int lower, int upper, int step){
	int fahr, test;
	for ( fahr = lower, test = ZERO; fahr <= upper; fahr = fahr + step ){
		printf("%3d %6.1f\n", fahr, (5.0/9.0) * (fahr -32));
	}
}
