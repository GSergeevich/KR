#include <stdio.h>

int main(){
	int quoteafter,aposafter,incomment; /* after  and inside a comment */
	int c,prev; /* curent charachter, previous charachter*/

	incomment = quoteafter = aposafter = prev = 0;

	while((c=getchar()) != EOF){
		/* check statuses, set flags  */
		if(incomment !=1){
			if(c == '\''){
				if(aposafter !=1 && prev != '\\')
					aposafter=1;
				else if(aposafter == 1 && prev !='\\')
					aposafter=0;
			
			}
			else if(c == '\"' && aposafter !=1){
				if(quoteafter !=1 && prev != '\\')
					quoteafter = 1;
				else if(quoteafter == 1 && prev != '\\')	
					quoteafter = 0;
			}
			else if(c == '*' && prev == '/' && quoteafter != 1 && aposafter != 1){
				incomment=1;
			}
					
		}

		if(incomment == 1){
		/* check for end of comment */
			if(c == '/' && prev == '*'){
				incomment=0;
				prev=0;
				c=0;
		}
			else
				prev=c;
		}

		if(incomment !=1){
			putchar(prev);
			prev=c;
		}

	}
}


			

