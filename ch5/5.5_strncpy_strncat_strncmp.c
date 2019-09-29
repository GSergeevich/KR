#include <stdio.h>
#define MAXLINE 100

char *my_strncat(char *,char *, size_t n);
char *my_strncpy(char *,char *,size_t n);
int my_strncmp(char *,char *,size_t n);

int main(){
	char s[MAXLINE]="source string";
	char t[MAXLINE]="";
	char r[MAXLINE]="catenated";
	
	printf("%s\n",t);
	my_strncpy(s,t,6);
	printf("%s\n",t);
/*	my_strncat(r,t,18);
	printf("%s\n",t); */
	printf("%d\n",my_strncmp(t,s,5));
	printf("%d\n",my_strncmp(r,s,6));

		
}

int my_strncmp(char *s1,char *s2, size_t n ){
	
	size_t i;

	for(i = 0;i < n && *s1 != '\0' && *s2 != '\0' && (*s1 == *s2) ;i++,s1++,s2++) 
		;
	
	if(*s1 == '\0' && *s2 == '\0') /* strings are equal */
		return 0;

	else if(*s1 == '\0') /* s1 is a prefix of s2,therefore lexicography s1 > s2 */
		return 1;

	else if(*s2 == '\0') /* s2 is prefix of the s1 ,therefore lexicography s2 > s1 */
		return 	-1;	

	return *s1 - *s2;
}

char *my_strncpy(char *source,char *dest,size_t n){ /* copy n symbols from "source" to "dest" */

	size_t i;

	for(i=0; i < n && (*dest = *source); dest++,source++,i++) /* break if get "\0" in source array or n symbols copied*/
		;	
	while(i++ < n)
		*++dest = '\0';
	
	if(*dest) /* already '\0' */
		;
	else
		*++dest= '\0';

	return dest;
}

char *my_strncat(char *source,char *dest, size_t n ){
	
	size_t i;

	while(*dest) /* seek end of string */
		++dest;

	for(i = 0;i++ < n && (*dest++ = *source++) ;) 
		;

	while(i++ < n)
		*dest++ = '\0';

	if(*dest) /* already '\0' */
		;
	else
		*++dest= '\0';

	return dest;
}
