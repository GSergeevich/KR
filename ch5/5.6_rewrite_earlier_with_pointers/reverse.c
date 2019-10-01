#include <stdio.h>
#include <string.h>
#define MAXLINE 100


void reverse(char *);


int main(){
 	char array[MAXLINE]="reverse it!";
	printf("%s ==> ",array);
	reverse(array);
	printf("%s\n",array);

}


void reverse(char *string ){
	
	char *i,*j,temp;

	i = string; /* addres of first element of string */
	j = string + (strlen(string) - 1); /* address of last element of string */

	while(i != j){
		temp = *i;
		*i++ = *j;
		*j-- = temp;
	}
}

