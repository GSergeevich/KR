/* Let us write a Version of squeeze(s1,s2) that deletes each character in the string 1 that matches any character in 
    the string s2 */

#include <stdio.h>
#define MAXLINE 1000

char s1[MAXLINE],s2[MAXLINE],temp[MAXLINE];
int i,c;


int first_occurance(char string1[],char string2[]){
	for(i=0;(c = string2[i]) != '\0';++i){ /*accumulate chars from string2 in tem array (char code use as index)*/
		++temp[c];	
	}
	
	i=0;
	while((c = string1[i]) != '\0'){ /*check if current char was in string2*/
		if(temp[c] != 0){
			printf("First occurance of str2 in str1 is %d\n",i); /*return posititon*/
			return 0;
		}
		else
			++i;

	}

	if(c == '\0')
		return -1;

}

int main(){
	char s1[]="abcdefgh\0";
	char s2[]="zh\0";	
	first_occurance(s1,s2);
	return 0;
}
