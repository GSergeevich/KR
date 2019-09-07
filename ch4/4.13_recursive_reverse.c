#include <stdio.h>
#include <string.h>
#include <limits.h>
#define abs(x) ( (x) > 0 ? (x): -(x))

void reverse(char s[],int i);
int i;

int main(){
	char s[]="test string";
	reverse(s,i);
}

void reverse(char s[],int i){
	if(s[i] != '\0')
		reverse(s,i+1);
	else
		return;

	putchar(s[i]);

}
