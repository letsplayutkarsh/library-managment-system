#include<stdio.h>
#include<stdlib.h>

typedef struct date{
	int d;
	int m;
	int y;
}date;

int isleapyear(int y)
{
	return (y % 100 != 0)? !(y%4) : !(y%400);
}

date aftertwoweek(date idate)
{
	date res = idate;
	if(idate.m == 1 || idate.m == 3 || idate.m == 5 || idate.m == 7 || idate.m == 8|| idate.m == 10 || idate.m == 12){
		res.d += 14;
		if(res.d > 31)
		{
			res.d = res.d % 31;
			res.m += 1;
		}
	}
	else if(idate.m == 2){
		res.d += 14;
		if(isleapyear(idate.y)){
			if(res.d > 29)
			{
				res.d = res.d % 29;
				res.m += 1;
			}
		}
		else{
			if(res.d > 28)
			{
				res.d = res.d % 28;
				res.m += 1;
			}

		}
	}
	else{
		res.d += 14;
		if(res.d > 30)
		{
			res.d = res.d % 30;
			res.m += 1;
		}
	}

	if(res.m == 13){
		res.m = 1;
		res.y += 1;
	}

	return res;
}

int main(void)
{
	date d;
	scanf("%d %d %d", &d.d, &d.m, &d.y);
	date r = aftertwoweek(d);

	printf("%d %d %d", r.d, r.m, r.y);
}