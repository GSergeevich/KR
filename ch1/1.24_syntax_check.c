#include <stdio.h>

int sbo,fbo,rbo,sbc,fbc,rbc; /* iterators for bracket arrays (open and closed) */
int c,incomment,quoteafter,aposafter,prev; /* */

int main(){
	incomment = quoteafter = aposafter = prev = 0;
	sbo = fbo = rbo = sbc = fbc = rbc = 0;

	while((c=getchar()) != EOF){
		/* check statuses, set flags  */
		if(incomment !=1){
			if(c == '\''){
				if(aposafter !=1 && prev !='\\')
					aposafter=1;
				else if(aposafter == 1 && prev !='\\')
					aposafter=0;

			}
			else if(c == '\"' && aposafter !=1){
				if(quoteafter !=1 && prev !='\\')
					quoteafter = 1;
				else if(quoteafter == 1 && prev !='\\')
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

		/* to count brackets if outside a comments and quotes */
		if(incomment !=1){
			if(c =='{' && quoteafter != 1 && aposafter != 1)
				++fbo;
			if(c =='(' && quoteafter != 1 && aposafter != 1)
				++rbo;
			if(c =='[' && quoteafter != 1 && aposafter != 1)
				++sbo;
			if(c =='}' && quoteafter != 1 && aposafter != 1)
				++fbc;
			if(c ==')' && quoteafter != 1 && aposafter != 1)
				++rbc;
			if(c ==']' && quoteafter != 1 && aposafter != 1)
				++sbc;

			prev=c;


		}

	}

	printf("Simple print quotes and comments: in quote %d in apos %d in comment %d \n", quoteafter, aposafter, incomment);
	printf("Simple print all brackets counters: figure open %d figure closed %d square open %d square closed %d round open %d round closed %d \n", fbo,fbc,sbo,sbc,rbo,rbc);
	return 0;
}


