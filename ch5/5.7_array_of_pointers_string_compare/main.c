#include <stdio.h>
#include <string.h>

#define MAXLINES 100 /* number of lines */
#define DELIMITER ','
#define MAXLENGTH 100 

int readlines(char **,char *,int);
int mygetline(char *,int);
int my_parse_lines(char *,char ,char **); /* return number of lines by MYDELIMITER and fill pointers array */
int writeout(char **,char *,int ); /* print sorted strings*/
int mystrcmp(char *,char *); /* lexicographically compare the strings*/
void str_qsort(char **,int , int); /* sort array of pointers*/
void swap(char **,int,int);

int main(){
	int nlines;
/*	char lines[MAXLENGTH]="a,ab,ac,else,ADSDSAD,qwwereee,zz"; */
	char lines[MAXLENGTH];
	char * pa[MAXLINES];
/*	nlines=my_parse_lines(lines,DELIMITER,pa); */
	if((nlines=readlines(pa,lines,MAXLINES)) >= 0){        
		writeout(pa,lines,nlines);
		printf("===> \n");
		str_qsort(pa,0,nlines ); 
		writeout(pa,lines,nlines);
		return 0;
	}
	else{
		printf("Error");
		return -1;
	}

}

int readlines(char *pa[],char *lines,int maxlines){
	int len,nlines;
	char *p,line[MAXLENGTH];
	p=lines;
	nlines=0; /* number of lines */

	while((len=mygetline(line,MAXLENGTH)) >0){
		if(nlines >= maxlines )
			return -1;
		else{
			strcpy(p,line);
			pa[nlines++]=p;
			p=p+len+1;
		}
	}
	return nlines;
}

int mygetline( char *line,int limit ){
       int i;

       for(i=0;i < limit && (*line = getchar()) != EOF && *line != '\n';line++,i++); /* save last position for NULL */

       if(*line == '\n'|| *line == EOF)
       	   *line ='\0';

       return i;/* return length without ending NULL */
}

int my_parse_lines(char lines[],char delimiter,char *pa[]){
	int i,n,c;
	pa[0]=lines; /* first pointers are equal*/
	for(i=0,n=0;(c = lines[i]) != '\0';++i){
		if(c == delimiter ){
			lines[i]='\0'; /* change for correct end of string */
			pa[++n]=lines + i + 1;
		}
		
	}

	return n == 0? 1 : n; /* no delimiters found,mean 1 string */
}

int writeout(char *pa[],char lines[],int nlines){
	int i;
	char **p;
	for(i=0;i <= nlines;++i){
		p=pa+i;
		printf("%s\n",*p);
	}
	
}


int mystrcmp(char *s1,char *s2){
	
	size_t i;

	for(i = 0; *s1 != '\0' && *s2 != '\0' && (*s1 == *s2) ;i++,s1++,s2++) 
		;
	
	if(*s1 == '\0' && *s2 == '\0') /* strings are equal */
		return 0;

	else if(*s1 == '\0') /* s1 is a prefix of s2,therefore lexicography s1 > s2 */
		return 1;

	else if(*s2 == '\0') /* s2 is prefix of the s1 ,therefore lexicography s1 < s2 */
		return 	-1;	

	return *s1 < *s2 ? 1 : -1; /* lexicographically *s1 > *s2 if it verse in numerical representation */

}



void str_qsort(char **arr,int left,int right){ /* sort array of pointers*/
	int i,delimiter,last;

	if(left >= right)
		return;

	delimiter=(left + right) / 2;
	swap(arr,left,delimiter); /* */
	last=left; /* last changed index */
	for(i=left+1;i <= right;++i){
		if(mystrcmp(arr[left],arr[i]) > 0) /* if s2 < s1 */
			swap(arr,++last,i);
	}
	swap(arr,left,last);
	str_qsort(arr,left,last-1);
	str_qsort(arr,last+1,right);
}

void swap(char **arr,int i,int j){
	char *tmp;
	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

