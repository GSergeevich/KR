#include <math.h>
#include <string.h>
#include "calc.h"

void mathf(char s[]){
		double op2;
		if(strcmp(s,"sin") == 0){
			push(sin(pop()));
		}
		else if(strcmp(s,"pow") == 0){
			op2=pop();
			push(pow(pop(),op2));
		}
		else if(strcmp(s,"exp") == 0){
			push(exp(pop()));
		}
}
