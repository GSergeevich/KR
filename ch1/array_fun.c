#include <stdio.h>

char array[10];
int i;

int main(){

	for(i=0; i<10;++i)
		array[i]='a';

			
	array[9]='\0'; 
	++array[3];
	printf("%s", array);	

}
