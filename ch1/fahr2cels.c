#include <stdio.h>

main ()
{
	float fahr, celsius;
	int lower, upper, step;

	lower = 0; /* lowest temperature in table */
	upper = 300; /* upper temperature in table */
	step = 20; /* step */
 
	fahr = lower;
	printf("%s\n", "Convertation table");
	printf("%s\n\n\n", "------------------");
	while (fahr <= upper ) {
	      celsius = ( 5.0 / 9.0 ) * ( fahr-32.0 ) ;
              printf("%3.0f\t%6.1f\n", fahr, celsius);
              fahr = fahr + step;
        }
}	

