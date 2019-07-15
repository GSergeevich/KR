#include <stdio.h>

#define IN 1
#define OUT 0

main(){
	int prev;
	int c;
	int qstate,cstate;

        qstate=cstate=OUT;
	prev=0;

	while((c=getchar()) != EOF){
		
		if( c == '"' && qstate == IN){
			qstate = OUT;
		}
		else if( c == '"' && qstate == OUT){
			qstate = IN;
		}


			if( c == '*' && prev == '/'){	
				state = IN;			        
				prev=c;	
			}

			else if(c == '/' && prev == '*'){
				state = OUT;
				prev=0;
			}

			else if( state == OUT ){ 
				putchar(prev);
			        prev=c;
			}
			
	}
}	
			
			




