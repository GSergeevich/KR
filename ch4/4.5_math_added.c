#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define FUNC 'f'
#define MAXVARS ('Z'-'A') + 1


int getop();
void push(double f);
double pop(void);
double glance(void); /* take a look at stack*/
void dup(void);/* create duplicate upper element in stack*/
void swap(void);/* swap two upper elements in stack*/
void flush(void);/* clear stack*/
void setvar(void);/* set variable */
int isupper(int);
int strcmp(char s[],char p[]);
void mathf(char s[]);

double vars[MAXVARS];
int varset[MAXVARS];/* array for "variable setted flags" */


int main(){
	int type,index;
	double op2,recent;
	char s[MAXOP];
	int i;

	for(i=0;i<= MAXVARS;++i){ /* zeroing array*/
		varset[i]=0;
	}

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
			printf("\t%.8g\n",(recent = pop())); /* print and record value*/
			break;
		case '=':
			setvar();
			break;
		case 'r':
			printf("recent value %g\n",recent);/* recent printed value*/ 
			push(0);/* to avoid error "stack is empty" */
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

#define MAXVAL 100 /*stack maximum value*/

int sp = 0;
double val[MAXVAL]; /*stack*/
/* stack ops*/
void push(double f){
	if(sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full,can't push %g\n", f);
}

double pop(void){
	if(sp>0)
		return val[--sp];
	else{
		printf("error: stack is empty\n");
		return 0.0;
	}
}

/* operations with variables*/

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

/* math functions */
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
/* take a look at top of a stack*/
double glance(void){
	int t;
	if(sp>0){
		t=sp;
		return val[--t];
	}
	else{
		printf("error: stack is empty\n");
		return 0.0;
	}
}

/* create duplicate upper element in stack*/
void dup(void){
	int t;
	if(sp>0){
		t=sp;
		push(val[--t]);
	}
	else{
		printf("error: stack is empty\n");
	}
}
/* swap two upper elements in stack*/
void swap(void){
	int t1,t2;
	if(sp>1){
		t1=val[--sp];/* upper */
		t2=val[--sp];/* lower */
		push(t1);/* lower now */
		push(t2);/* put on */
	}
	else{
		printf("error: nothing swap in stack\n");
	}
}
	
/* clear stack*/
void flush(void){
	int i;
	i = sp;
	while(i>=0)
		val[i]=0;
	sp=0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[]){
	int i,c,t;

	while((s[0] = c = getch()) == ' '||c == '\t')
		;
	s[1] = '\0'; /* correct string ending for "default" case in switch*/
	i=0;
	if(islower(c)){
		while(islower(s[++i] = c = getch()))
			;
		ungetch(c);
		s[i]='\0';
		if(strcmp(s,"sin") == 0 || strcmp(s,"pow") == 0 ||strcmp(s,"exp") == 0)
			return FUNC;
		else 
			return c;
	}

	if(!isdigit(c) && c != '.' && c != '-'){
		return c; /* not a digit: math operator (except '-'), variable or crap*/
	}

	if(c == '-'){
		if(!isdigit(t = getch())){ /* check if next char is not a digit: that assume it's not a negative number */
			ungetch(t); /* return next char in buffer */
			return c; /* sometimes minus is a simple minus (math operator) */
		}
		else {
			ungetch(t); /* we have a digit in a next char,return it in buffer */
		}
	}

	if(isdigit(c) || c == '-')
		while(isdigit(s[++i] = c = getch()))
			;
	if(c == '.')
		while(isdigit(s[++i] = c = getch()))
			;
	s[i]='\0';
	if(c != EOF)
		ungetch(c);
	return NUMBER;
}

#define BUFFSIZE 100

char buffer[BUFFSIZE];
int bufpt = 0;


void ungetch(int c){
	(bufpt< BUFFSIZE) ? buffer[bufpt++] = c : printf("error: ungetch : buffer is full"); 
}

int getch(void){
	return (bufpt > 0) ? buffer[--bufpt] : getchar();
}

