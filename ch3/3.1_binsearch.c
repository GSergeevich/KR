#include <stdio.h>
#include <time.h>

int binsearch_old(int x, int v[], int n);
int binsearch_new(int x, int v[], int n);

int main(){
	int i,j,result;
	int x = 50000;
	int n = 100000;
	int v[n];
	clock_t time;




	for(i=0,j=200; i<n;++i,++j)
		v[i]=j;

	time = clock();
	result=binsearch_new(x, v, n);
	printf("%d\n", result);
	time = clock() - time ;
        printf("binsearch_new() works %lu time \n",
             (unsigned long) time );

	sleep(10);

	time = clock();
	result=binsearch_old(x, v, n);
	printf("%d\n", result);
	time = clock() - time;
        printf("binsearch_old() works %lu time\n",
             (unsigned long) time);

}

int binsearch_new(int x, int v[], int n){
	int low,mid,high;

	low = 0;
	high = n-1;
	mid = (low + high) / 2;
	while( low <= high && x != v[mid]){
		mid = (low + high) / 2;
		if(x < v[mid]){
			high = mid - 1;
/*			printf("State %d < %d , high: %d , low: %d \n", v[mid], mid,high,low); */
		}
	        else {
			low = mid + 1 ;
/*			printf("State %d > %d , high: %d , low: %d \n", v[mid], mid,high,low); */
		}
	}

	return v[mid] == x ? x : -1;
}



int binsearch_old(int x, int v[], int n){
	int low,mid,high;

	low = 0;
	high = n-1;
        mid = (low + high) / 2;
	while( low <= high ){
		mid = (low + high) / 2;
		if(x < v[mid]){
			high = mid - 1;
		}
	        else if(x > v[mid]){
			low = mid + 1 ;
		}
	        else
			return v[mid];	
	}
}
