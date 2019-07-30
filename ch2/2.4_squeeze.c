/* Let us write a Version of squeeze(s1,s2) that deletes each character in the string 1 that matches any character in 
    the string s2 */

#include <stdio.h>
#define MAXLINE 1000

char s1[MAXLINE],s2[MAXLINE],temp[MAXLINE],result[MAXLINE];
int i,j,c;


void squeeze(char string1[],char string2[]){
	for(i=0;(c = string2[i]) != '\0';++i){ /*accumulate chars from string2 in tem array (char code use as index)*/
		++temp[c];	
	}
	for(i=j=0;(c = string1[i]) != '\0';++i){ /*check if current char was in string2*/
		if(temp[c] == 0)
			result[j++]=c;

	}
	printf("%s",result);

}

int main(){
	char s1[]="abcdefgh\0";
	char s2[]="abcd\0";	
	squeeze(s1,s2);
	return 0;
}
