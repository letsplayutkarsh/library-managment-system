#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include"structs.h"

int validbid(books book[], int bid, int * nb)
{
	for(int i = 0; i < * nb; i++)
	{
		if(bid == book[i].bid)
			return 0;
	}
	return 1;
}

void lower(char * st)
{
	for(int i = 0; i < strlen(st); i++)
	{
		st[i] = tolower(st[i]);
	}
}

int ridpresent(issuer irecord[], char* iid, int * ni)
{
	lower(iid);

	for(int i = 0; i < * ni; i++)
	{
		if(strcmp(iid, irecord[i].iid) == 0 && (irecord[i].rdate.d == 0))
			return 1;
	}
	return 0;
}

int available(books book[], int bid, int * nb)
{
	for(int i = 0; i < *nb; i++)
	{
		if(book[i].bid == bid)
		{
			if(strcmp(book[i].isavailable, "yes") == 0){
				return 1;
			}
			else{
				return 0;
			}
			break;
		}
	}
	return 0;
}

void addbook(books book[], int * nb, int bid, char* bname, char* bauthor, char* bgenre)
{
	lower(bname);
	lower(bauthor);
	lower(bgenre);

	book[*nb].bid = bid;
	strcpy(book[*nb].bname , bname);
	strcpy(book[*nb].bauthor , bauthor);
	strcpy(book[*nb].bgenre , bgenre);
	strcpy(book[*nb].isavailable , "yes");
	strcpy(book[*nb].delete , "no");

	*nb += 1;
}

void delbookbyid(books book[], int *nb, int bid)
{
	for(int i = 0; i < *nb; i++)
	{
		if(book[i].bid == bid)
		{
			strcpy(book[i].delete,"yes");
		}
	}
}

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

void fine(issuer irecord[], int ni)
{
	for(int i = 0; i < ni; i++)
	{
		if(irecord[i].idate.d == 0){
			continue;
		}

		else
		{
			date schdate = aftertwoweek(irecord[i].idate);
			if(schdate.y < irecord[i].rdate.y){
				irecord[i].fine = 10000;
			}

			else if(schdate.m < irecord[i].rdate.m && schdate.y == irecord[i].rdate.y)
			{
				irecord[i].fine = (irecord[i].rdate.m - schdate.m) * 500;
			}

			else if (schdate.d < irecord[i].rdate.d && schdate.m == irecord[i].rdate.m && schdate.y == irecord[i].rdate.y){
				irecord[i].fine = (irecord[i].rdate.d - schdate.d) * 15;
			}
			else
			{
				irecord[i].fine = 0;
			}
		}
	}
}

int fineonsingle(issuer record)
{
		if(record.idate.d == 0){
			return 0;
		}

		else
		{
			date schdate = aftertwoweek(record.idate);
			if(schdate.y < record.rdate.y){
				record.fine = 10000;
			}

			else if(schdate.m < record.rdate.m && schdate.y == record.rdate.y)
			{
				record.fine = (record.rdate.m - schdate.m) * 500;
			}

			else if (schdate.d < record.rdate.d && schdate.m == record.rdate.m && schdate.y == record.rdate.y){
				record.fine = (record.rdate.d - schdate.d) * 15;
			}
			else
			{
				record.fine = 0;
			}
		}

		return record.fine;
}

void addissuer(issuer irecord[], books book[], int * ni, int * nb, char * iname, char*iid, int bid, int d, int m, int y)
{
	lower(iname);
	lower(iid);

	strcpy(irecord[*ni].iname , iname);
	strcpy(irecord[*ni].iid , iid);
	irecord[*ni].bid = bid;

	for(int i = 0; i < *nb; i++)
	{
		if(book[i].bid == bid){
			strcpy(irecord[*ni].bname , book[i].bname);
			strcpy(book[i].isavailable, "no");
			break;
		}
	}

	irecord[*ni].idate.d = d;
	irecord[*ni].idate.m = m;
	irecord[*ni].idate.y = y;

	irecord[*ni].rdate.d = 0;
	irecord[*ni].rdate.m = 0;
	irecord[*ni].rdate.m = 0;

	irecord[*ni].fine = 0;

	*ni += 1;
}

void addreturndate(issuer irecord[], books book[], char* iid, int *ni, int *nb, int d, int m, int y)
{
	lower(iid);

	int i = 0;
	for(i = 0; i < *ni; i++)
	{
		if(strcmp(irecord[i].iid, iid) == 0)
		{
			irecord[i].rdate.d = d;
			irecord[i].rdate.m = m;
			irecord[i].rdate.y = y;

			for(int j = 0; j < *nb; j++)
			{
				if(irecord[i].bid == book[j].bid)
				{
					strcpy(book[j].isavailable, "yes");
					break;
				}
			}
			break;
		}
	}

	printf("\nFine : %d\n", fineonsingle(irecord[i]));
}
