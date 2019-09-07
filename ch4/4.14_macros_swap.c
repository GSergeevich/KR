#include <stdio.h>

#define swap(type,x,y) {type s;\
			s = x;\
			x = y;\
			y = s;}

int main(){
	int x,y;
	printf("x = %d,""y = %d\n",x,y);
	swap(typeof(x),x,y);
	printf("x = %d,""y = %d\n",x,y);

}
