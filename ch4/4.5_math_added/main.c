#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

#define MAXOP 100

int main(){
	int type;
	double op2;
	char s[MAXOP];

	while((type=getop(s)) != EOF){
		switch(type){
		case NUMBER:
			push(atof(s));
			break;
		case FUNC:
			mathf(s);
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2=pop();
			push(pop() - op2);
			break;
		case '/':
			op2=pop();
			if(op2 != 0.0){
				push(pop() / op2);
			}
			else{
				printf("error: zero divisor\n");
			}
			break;
		case '%':
			op2=pop();
			if(op2 != 0){
				push((int)pop() % (int)op2);
			}	
			else{
				printf("error: zero divisor\n");
			}
			break;	
		case '\n':
			printf("\t%.8g\n",pop());
			break;
		case 'l':
			printf("Upper element in stack is %g\n",look());
			break;
		case 's':
			swap();
			printf("Last elements in stack are swapped\n");
			break;
		case 'd':
			dup();
			printf("Last element in stack is duplicated\n");
			break;
		case 'c':
			clear();
			printf("Stack cleared\n");
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;	
		}		
	}

	return 0;
}

