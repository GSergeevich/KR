#include <stdio.h>
#define MAXLINE 1000

char line[MAXLINE];


int mygetline( char line[] ){
       int c; /* for ccurrent char */
       int i; /* iterator */

       i=0;
       while((c = getchar()) != EOF && c != '\n'){
		line[i] = c;
		++i;
       }
       ++i;
       line[i]='\0'; /* add end of string */

       return 0;
}


int htoi(char line[]){
	int n,i,c,hex;
	int inhex;
	i=inhex=0;

	while(inhex == 0){	/*search hex digit headline "0X"or "0x"*/
		if( line[i] == '0'){
			++i;
			if( line[i] == 'x' || line[i] == 'X')
				inhex=1;
				++i;
	
		}
		else
			++i;
	}
	
	for(hex=0;(c=line[i]) != '\0';++i){
		if(inhex){
			if(c>='a' && c<='f') 
				n=10+(c - 'a');
                	if(c>='A' && c<='F')
				n=10+(c - 'A');
			if(c>='0' && c<='9')
				n=(c - '0');
			hex=hex * 16 + n; /*multiplication by base equals bit shift */
		}
	}
	return hex;

}
       	
	

void main(){
	mygetline(line);
        printf("%d",htoi(line));
}
