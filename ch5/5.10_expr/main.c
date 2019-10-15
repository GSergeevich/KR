#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "calc.h"

#define MAXOP 100

int main(int argc, char *argv[]){
	char c;
	double op2;

	while(--argc > 0 ){
		++argv;
		if(isdigit(c = *argv[0])){
			push(atof(*argv));
			continue;
		}

		switch(c){
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
		default:
			printf("error: unknown command \n, please escape '*' character!\n");
			break;	
		}		
	}

	printf("\t%.8g\n",pop());

	return 0;
}

