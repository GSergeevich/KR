#include <stdio.h>
#include <limits.h>
#define YEAR 2019
#define MONTH 13
#define DAY 110
#define YDAY 28344

int day_of_year(int,int,int);/* recieve year,month and day ,return number of day in the year */
int month_day(int,int,int*,int*); /* recieve year and day,  return day and month */

char daytab[2][13]={
	{0,31,28,31,30,31,30,31,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,31,30,31,30,31},
	};

int main(){
	int pmonth,pday;
	printf("number of day in the year: %d\n",day_of_year(YEAR,MONTH,DAY));
        printf("return code : %d ",month_day(YEAR,YDAY,&pmonth,&pday));
        printf("month :%d ,day :%d\n",pmonth,pday);


}

int	day_of_year(int year, int month, int day){
		int i,leap;

		if(year < 0||year > INT_MAX || month <= 0|| month > 12 || day <= 0 || day > 31)
			return -1;
		leap = year%4 == 0 && year%100 !=0 || year%400 == 0;
		for(i=1; i<month; ++i)
			day += daytab[leap][i];
		
		return day;
	}

int	month_day(int year,int yday,int *pmonth, int *pday){
		int i,leap;

		if(year < 0||year > INT_MAX)
			return -1;

		leap = year%4 == 0 && year%100 !=0 || year%400 == 0;

		if( yday <= 0 || yday > 365 + leap)
			return -1;

		for(i=1; yday > daytab[leap][i]; ++i)
			yday -= daytab[leap][i];
		*pmonth=i;
		*pday=yday;

		return 0;
	}




