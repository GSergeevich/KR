#include <stdio.h>
#include <float.h>
#include <limits.h>
#include <stdint.h>

main() {
	/* bitwise calc */
	printf("Unsigned char max:\n calculated: %d\n constant  : %d\n", (unsigned char) ~0 ,UCHAR_MAX);
	printf("Unsigned char min:\n calculated: %d\n constant  : 0\n", (unsigned char) 0);
	printf("Signed char max:\n calculated: %d\n constant  : %d\n", (char)((unsigned char) ~0 >>1),SCHAR_MAX);
	printf("Signed char min:\n calculated: %d\n constant  : %d\n", -(char)((unsigned char) ~0 >>1)-1,SCHAR_MIN);
	printf("\n");

	printf("Unsigned int max:\n calculated: %u\n constant  : %u\n", (unsigned int)~0,UINT_MAX);
	printf("Unsigned int min:\n calculated: %u\n constant  : 0\n", (unsigned int)0);
	printf("Signed int max:\n calculated: %d\n constant  : %d\n", (signed int)((unsigned int) ~0 >> 1),INT_MAX);
	printf("Signed int min:\n calculated: %d\n constant  : %d\n", -(signed int)((unsigned int) ~0 >>1)-1,INT_MIN);
	printf("\n");

	printf("Unsigned short max:\n calculated: %d\n constant  : %d\n", (unsigned short) ~0,USHRT_MAX);
	printf("Unsigned short min:\n calculated: %d\n constant  : 0\n", (unsigned short) 0);
	printf("Signed short max:\n calculated: %d\n constant  : %d\n", (signed short)((unsigned short) ~0 >>1),SHRT_MAX);
	printf("Signed short min:\n calculated: %d\n constant  : %d\n", -(signed short)((unsigned short) ~0 >>1)-1,SHRT_MIN);
	printf("\n");


	printf("Unsigned long max:\n calculated: %lu\n constant  : %lu\n", (unsigned long)~0,ULONG_MAX);
	printf("Unsigned long min:\n calculated: %lu\n constant  : 0\n", (unsigned long)0);
	printf("Signed long max:\n calculated: %ld\n constant  : %ld\n", (signed long)((unsigned long) ~0>>1),LONG_MAX);
	printf("Signed long min:\n calculated: %ld\n constant  : %ld\n", -(signed long)((unsigned long) ~0>>1)-1,LONG_MIN);
	printf("\n");

	/* aryphmetic calc */

	float i,prev;
	for (i=1; i > i/2; i *=1.000001){
		        prev = i;
	};
	printf("Float max:\n calculated: %g\n constant  : %g\n", prev, FLT_MAX);


	uint_least64_t  bits = *((uint_least64_t*)&prev);
	uint64_t exponent = ((bits >> 52) & 0x7FF) - 1023 + 127;
	uint64_t significand = (bits >> 29) & 0x7fffff;
	uint32_t float_bits = ((bits >> 32) & 0x80000000u)| (exponent << 23)| significand;
        float f = *((float*)&float_bits); 	

	printf("Float min:\n bitwise calculated: %lld\n constant  : %g\n", bits, FLT_MIN);

	printf("\n");

	double d,dprev;
	for (d=1; d > d/2; d *= 1.000001 ){
		       /* printf("%g\n", d); */
		        dprev = d;

	};
	printf("Double max:\n calculated: %g\n constant  : %g\n", dprev,DBL_MAX);

	dprev=0;
	for (d=1; d> d/2; d *= -1.000001){
		        dprev = d;

	};
	printf("Double min:\n calculated: %g\n constant  : %g\n", dprev,DBL_MIN);
	printf("\n");

	long double ld,ldprev;
	ldprev=0;
	for (ld=1; ld> ld/2; ld *= -1.000001){
		        ldprev = ld;

	};
	printf("Long double min:\n calculated: %g\n constant  :  %g\n", ldprev,LDBL_MIN);

	for (ld=1; ld > ld/2; ld *= 0.000001){
		        ldprev = ld;

	};
	printf("Long double max:\n calculated: %ld\n constant  :  %ld\n", ldprev,LDBL_MAX);


	printf("\n");
}
