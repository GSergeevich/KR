#include "calc.h"
#include <stdio.h>

void setvar(void){
	int index,i;
	double op2;
	op2 = pop();/* assume that "A 10 =" */
	index=((int) pop()); 
	vars[index] = op2;
	varset[index] = 1;/* variable is setted */
	push(0);/* to avoid error "stack is empty" */
	printf("Var %c is set\n", index + 'A');
}	

