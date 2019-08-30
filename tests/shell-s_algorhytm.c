#include <stdio.h>
void print_arr(int v[], int n);
void shellsort(int v[], int n);
void simple_bubble(int z[], int n);

int main(){
	int n = 15;
	int v[15] = {2,6,14,8,1,13,3,4,5,11,7,9,10,0,12};
	shellsort(v,n);
	printf("----\n");
	int z[15] = {2,6,14,8,1,13,3,4,5,11,7,9,10,0,12};
	simple_bubble(z,n);
} 

void shellsort(int v[], int n){
	int gap,i,j,c,temp;

	for(gap = n/2,c = 0;gap > 0; gap /= 2){
		for(i = gap; i < n; ++i){
			for(j=i-gap; j >=0 && v[j]>v[j+gap]; j-=gap){
				print_arr(v,n);
				temp = v[j];
				v[j] = v[j+gap];
				v[j+gap] = temp;
				print_arr(v,n);
				++c;
			}
		}
	}
	printf("\n");
	printf("%d\n", c);

}
/**/
void simple_bubble(int z[], int n){
	int i,j,temp,c;

	for(j = n-1,c = 0;j >= 0;--j){
		print_arr(z,n);
		for(i = 0;i <= j;++i){ 
			if(z[i]>z[i+1]){
			print_arr(z,n);
			temp = z[i+1];
			z[i+1] = z[i];
			z[i] = temp;
			print_arr(z,n);
			++c;
			}
		}
	}
		
	
	printf("\n");
	printf("%d\n", c);
}

void print_arr(int v[], int n){
	int i;
	for(i=0;i<n;++i)
		printf("%d ", v[i]);
	printf("\n");
}

