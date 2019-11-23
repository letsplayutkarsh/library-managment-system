#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"structs.h"



void stringlower2(char *s1)
{
    for (int j = 0;j < strlen(s1) ;j++)
	{
		if (s1[j] >= 'A' && s1[j] <= 'Z')
		{
			s1[j] = s1[j] + 32;
		}
	}
}

int stringcompare2(char *s1, char *s2)
{
    if (strlen(s1) <= strlen(s2))
    {
        for (int i = 0;i < strlen(s1);i++)
        {
            if (s1[i] != s2[i])
            {
                return 1;
            }
        }
        return 0;
    }
    return 1;
}

void search_by_issuername(int ni, issuer issue_rec[])
{
    int count =0;

    char issuername[140];
	scanf("%[^\n]%*c",issuername);
    stringlower2(issuername);

	for(int i = 0 ; i < ni ;i++)
	{
		if(i==0)
		{
            printf("\n\n%-25s %-15s %-8s %-30s %-22s %-20s %-5s \n\n","ISSUER NAME","ISSUER ID","BOOK ID","BOOK NAME","ISSUE DATE","RETURN DATE","FINE");

		}
        if (stringcompare2(issuername,issue_rec[i].iname) == 0 )
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

void search_by_bookname(int ni, issuer issue_rec[],int nb ,  books book[])
{

    char bookname[140];
	scanf("%[^\n]%*c",bookname);
    stringlower2(bookname);

    int count =0;
	for(int i = 0 ; i < ni ;i++)
	{
		if(i==0)
		{
            printf("\n\n%-25s %-15s %-8s %-30s %-22s %-20s %-5s \n\n","ISSUER NAME","ISSUER ID","BOOK ID","BOOK NAME","ISSUE DATE","RETURN DATE","FINE");

		}

        if (stringcompare2(bookname,issue_rec[i].bname)==0)
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

void search_by_book_id(int ni, issuer issue_rec[])
{

    int book_id;
	scanf("%d%*c",&book_id);

    int count =0;

	for(int i = 0 ; i < ni ;i++)
	{
		if(i==0)
		{
            printf("\n\n%-25s %-15s %-8s %-30s %-22s %-20s %-5s \n\n","ISSUER NAME","ISSUER ID","BOOK ID","BOOK NAME","ISSUE DATE","RETURN DATE","FINE");

		}

        if (book_id == issue_rec[i].bid)
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
void search_by_issuer_id(int ni, issuer issue_rec[])
{

    char issuer_id[150];
    scanf("%[^\n]%*c",issuer_id);
    stringlower2(issuer_id);


    int count =0;

	for(int i = 0 ; i < ni ;i++)
	{
		if(i==0)
		{
            printf("\n\n%-25s %-15s %-8s %-30s %-22s %-20s %-5s \n\n","ISSUER NAME","ISSUER ID","BOOK ID","BOOK NAME","ISSUE DATE","RETURN DATE","FINE");

		}

        if (strcmp(issuer_id , issue_rec[i].iid)==0)
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
