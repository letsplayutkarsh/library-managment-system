#include<stdio.h>
#include"structs.h"


void search_by_issuedate(int ni, issuer issue_rec[])
{
	int d,m,y;
	scanf("%d %d %d%*c",&d,&m,&y);
	int count =0;
	for(int i = 0 ; i < ni ;i++)
	{
		if(i==0)
		{
            printf("\n\n%-25s %-15s %-8s %-30s %-22s %-20s %-5s \n\n","ISSUER NAME","ISSUER ID","BOOK ID","BOOK NAME","ISSUE DATE","RETURN DATE","FINE");

		}
		if( d == issue_rec[i].idate.d && m == issue_rec[i].idate.m && y == issue_rec[i].idate.y)
		{
			printf("%-25s %-15s %-8d %-30s %5d-%d-%d %15d-%d-%-15d %d\n",issue_rec[i].iname, issue_rec[i].iid, issue_rec[i].bid,issue_rec[i].bname, issue_rec[i].idate.d,issue_rec[i].idate.m,issue_rec[i].idate.y,issue_rec[i].rdate.d,issue_rec[i].rdate.m,issue_rec[i].rdate.y,issue_rec[i].fine);
			count++;

		}
	}
	if(count==0)
    {
        printf("NO DATA FOUND\n");
    }

}
void search_by_returndate(int ni, issuer issue_rec[])
{
	int d,m,y;
	scanf("%d %d %d%*c",&d,&m,&y);

	int count =0;
	for(int i = 0 ; i < ni ;i++ )
	{
		if(i==0)
		{
            printf("\n\n%-25s %-15s %-8s %-30s %-22s %-20s %-5s \n\n","ISSUER NAME","ISSUER ID","BOOK ID","BOOK NAME","ISSUE DATE","RETURN DATE","FINE");

		}
		if( d == issue_rec[i].rdate.d && m == issue_rec[i].rdate.m && y == issue_rec[i].rdate.y)
		{
			printf("%-25s %-15s %-8d %-30s %5d-%d-%d %15d-%d-%-15d %d\n",issue_rec[i].iname,issue_rec[i].iid,issue_rec[i].bid,issue_rec[i].bname, issue_rec[i].idate.d,issue_rec[i].idate.m,issue_rec[i].idate.y,issue_rec[i].rdate.d,issue_rec[i].rdate.m,issue_rec[i].rdate.y,issue_rec[i].fine);
			count++;

		}
	}
	if(count == 0)
    {
		printf("NO DATA FOUND\n");
    }

}
void returned_books(issuer issue_rec[],int ni)
{
	for(int i = 0 ; i < ni ; i++)
	{
		if(i==0)
		{
            printf("\n\n%-25s %-15s %-8s %-30s %-22s %-20s %-5s \n\n","ISSUER NAME","ISSUER ID","BOOK ID","BOOK NAME","ISSUE DATE","RETURN DATE","FINE");

		}
		if( issue_rec[i].rdate.d != 0 && issue_rec[i].rdate.m != 0 && issue_rec[i].rdate.y !=0)
		{
			printf("%-25s %-15s %-8d %-30s %5d-%d-%d %15d-%d-%-15d %d\n",issue_rec[i].iname,issue_rec[i].iid,issue_rec[i].bid,issue_rec[i].bname, issue_rec[i].idate.d,issue_rec[i].idate.m,issue_rec[i].idate.y,issue_rec[i].rdate.d,issue_rec[i].rdate.m,issue_rec[i].rdate.y,issue_rec[i].fine);

		}
	}
}
void not_returned_books(issuer issue_rec[],int ni)
{
	for(int i = 0 ; i < ni ; i++)
	{
		if(i==0)
		{
            printf("\n\n%-25s %-15s %-8s %-30s %-22s %-20s %-5s \n\n","ISSUER NAME","ISSUER ID","BOOK ID","BOOK NAME","ISSUE DATE","RETURN DATE","FINE");

		}
		if( issue_rec[i].rdate.d == 0 && issue_rec[i].rdate.m == 0 && issue_rec[i].rdate.y ==0)
		{
			printf("%-25s %-15s %-8d %-30s %5d-%d-%d %15d-%d-%-15d %d\n",issue_rec[i].iname,issue_rec[i].iid,issue_rec[i].bid,issue_rec[i].bname, issue_rec[i].idate.d,issue_rec[i].idate.m,issue_rec[i].idate.y,issue_rec[i].rdate.d,issue_rec[i].rdate.m,issue_rec[i].rdate.y,issue_rec[i].fine);

		}
	}
}
