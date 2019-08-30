/* Program demonstrating atof(char s[]).The function which converts the string to a floating 
   point value */
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#define MAXLINE 1000

double atof(char s[]);
double atof_exp(char s[]);
double mpower(int base,int exp);

int main(){
	double num;
	char s[MAXLINE]="1";
	num = atof_exp(s);
	printf("Numeric is %f\n", num); 
}

double atof_exp(char s[]){
	double val,power;
        int i,sign,p,p_sign;

	for(i=0;isspace(s[i]);++i)
		;
	sign = (s[i] == '-' )? -1 : 1;

	if(!isdigit(s[i])){
		++i;
	}
/* Mantiss computing */

	for(val=0.0;isdigit(s[i]);++i){
		val=10.0 * val + (s[i] - '0');
	}

	if(s[i] == '.' || s[i] == ',')
		++i;

	for(power=1.0;isdigit(s[i]);++i){
		val=10.0 * val + (s[i] - '0');
		power *= 10.0;
	}
	
/* Exponent computing */

	if(s[i] == 'e' || s[i] == 'E')
		++i;
	if(s[i] == '-'||s[i]== '+'){
		p_sign = s[i];
		++i;
	}
	
	for(p=0; isdigit(s[i]);++i){
		p=10.0 * p + (s[i] - '0');
	}
	
	if(p_sign == '-'){
		return sign * ( val / power) / mpower(10,p);
	
	}
	else
		return sign * ( val / power) * mpower(10,p);
}

double atof(char s[]){
	double val,power;
        int i,sign;
	for(i=0;isspace(s[i]);++i)
		;
	sign = s[i] == '-' ? -1 : 1;
	if(!isdigit(s[i])){
		++i;
	}
	for(val=0.0;isdigit(s[i]);++i){
		val=10.0 * val + (s[i] - '0');
	}
	if(s[i] == '.' || s[i] == ','){
		++i;
	}
	for(power=1.0;isdigit(s[i]);++i){
		val=10.0 * val + (s[i] - '0');
		power *= 10;
	}
	return sign * val / power;
}

double mpower(int base,int exp)
{
    double power;
    power=1.0;
    while(exp-- > 0)
        power *=base;

    return power;
}
