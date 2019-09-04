#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "calc.h"

int pos; /* position in s[] */

int main(){
	int type,index;
	double op2,recent;
	char s[MAXOP];
	line[0] = '\0';
	pos = 0;

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
			printf("\t%.8g\n",recent=(pop()));
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
		case 'r':
			printf("recent value %g\n",recent);/* recent printed value*/
			push(0);/* to avoid error "stack is empty" */
		case '=':
			setvar();
			break;
		default:
			if(isupper(type)){
				index = (type - 'A');
				if(varset[index] !=1){ /* variable empty */
					push(index); /* put numerical representation of letter in stack */
				}
				else{
					push(vars[index]); /* put value of letter in stack */
				}
				break;
			}
			else{
				printf("error: unknown command %s\n", s);
				break;
			}
		}

	}

	return 0;
}

