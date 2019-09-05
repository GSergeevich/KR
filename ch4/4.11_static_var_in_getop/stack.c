#include <stdio.h>
#define MAXVAL 100 /*stack maximum value*/

int sp = 0;
double val[MAXVAL]; /*stack*/

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
/* take a look at top of a stack*/
double look(void){
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
void clear(void){
	int i;
	i = sp;
	while(i>=0)
		val[--i]=0;
	sp=0;
}

