#include <stdio.h>
#define IN 1
#define OUT 0
#define STRMAX 1000

void expand(char str1[],char str2[]);
int ischar(int c);
int myexp(int start,int end, char str[],int pos);

int main(){
	char string1[STRMAX]="-a-z0-9A-Za-c-e-";
	char string2[STRMAX];
	expand(string1,string2);
	printf("%s",string2);
	return 0;
}


void expand(char str1[],char str2[]){
	int i,pos,start,end,state;
	for(i=pos=0;str1[i] !='\0';++i){
		/*Search "-" in string and set status IN or OUT*/
		str2[pos]=str1[i];
		++pos;
		if(str1[i] == '-' && ischar(str1[i-1])){
			state = IN;
			start = str1[i-1];
			}
		else if(ischar(str1[i]) && state == IN){
				end = str1[i];
				state = OUT;
				pos=pos-3;
				pos=myexp(start,end,str2,pos);
		}
	}
}

int ischar(int c){
	if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')||(c >= '0' && c <= '9'))
		return 1;
	else
		return 0;

}

int myexp(int start,int end, char str[],int pos){
	int i,j;
	for(i = start,j=pos;i <= end;++i,++j){
		str[j] = i; 
		
	}
	return j;
}

