#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"structs.h"



void stringlower(char *s1)
{
    for (int j = 0;j < strlen(s1) ;j++)
	{
		if (s1[j] >= 'A' && s1[j] <= 'Z')
		{
			s1[j] = s1[j] + 32;
		}
	}
}

int stringcompare(char *s1, char *s2)
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

void Search_by_name(int nb,books book[])
{
    char bookname[140],bookname_1;
	scanf("%[^\n]%*c",bookname);
    stringlower(bookname);
    int count =0;

    for (int i = 0;i < nb;i++)
	{
        if (i == 0)
        {
            printf("\n\n%-10s %-30s %-30s %-20s %-5s \n","BOOK ID","BOOK NAME","BOOK AUTHOR","BOOK GENRE","BOOK AVAILABILITY\n");
        }
        if (strcmp(book[i].delete,"no") == 0)
        {
            if (stringcompare(bookname,book[i].bname) == 0 )
                {
                    printf("%-10d %-30s %-30s %-20s %-5s ",book[i].bid,book[i].bname,book[i].bauthor,book[i].bgenre,book[i].isavailable);
    		        printf("\n");
                    count++;
                }
        }
    }
    if(count==0)
    {
        printf("no data found \n");
    }
}

void Search_by_author(int nb,books book[])
{
    char bookauthor[140];
	scanf("%[^\n]%*c",bookauthor);
    stringlower(bookauthor);
    int count =0;

    for (int i = 0;i < nb;i++)
	{
        if (i == 0)
        {
            printf("\n\n%-10s %-30s %-30s %-20s %-5s \n","BOOK ID","BOOK NAME","BOOK AUTHOR","BOOK GENRE","BOOK AVAILABILITY");
        }
        if (strcmp(book[i].delete,"no") == 0)
        {
            if (stringcompare(bookauthor,book[i].bauthor) == 0 )
            {
                printf("%-10d %-30s %-30s %-20s %-5s ",book[i].bid,book[i].bname,book[i].bauthor,book[i].bgenre,book[i].isavailable);
		        printf("\n");
                count++;
            }
        }
    }
    if(count==0)
    {
        printf("no data found \n");
    }
}

void Search_by_genre(int nb,books book[])
{
    char bookgenre[140];
	scanf("%[^\n]%*c",bookgenre);
    stringlower(bookgenre);
    int count =0;

    for (int i = 0;i < nb;i++)
	{
        if (i == 0)
        {
            printf("\n\n%-10s %-30s %-30s %-20s %-5s \n","BOOK ID","BOOK NAME","BOOK AUTHOR","BOOK GENRE","BOOK AVAILABILITY");
        }
        if (strcmp(book[i].delete,"no") == 0)
        {
            if (stringcompare(bookgenre,book[i].bgenre) == 0 )
            {
                printf("%-10d %-30s %-30s %-20s %-5s ",book[i].bid,book[i].bname,book[i].bauthor,book[i].bgenre,book[i].isavailable);
		        printf("\n");
                count++;
            }
        }
    }
    if(count==0)
    {
        printf("no data found \n");
    }
}

void Search_by_availability(int nb,books book[], char *bookavailability)
{
    stringlower(bookavailability);
    for (int i = 0;i < nb;i++)
	{
        if (i == 0)
        {
            printf("\n\n%-10s %-30s %-30s %-20s \n","BOOK ID","BOOK NAME","BOOK AUTHOR","BOOK GENRE");
        }
        if (strcmp(book[i].delete,"no") == 0)
        {
            if (strcmp(bookavailability,book[i].isavailable) == 0)
            {
                printf("%-10d %-30s %-30s %-20s ",book[i].bid,book[i].bname,book[i].bauthor,book[i].bgenre);
		        printf("\n");
            }
        }
    }
}

void Search_by_bookid(int nb, books book[])
{
    int bookid;
    scanf("%d%*c",&bookid);
    int count =0;

    for (int i = 0;i < nb;i++)
	{
        if (i == 0)
        {
            printf("\n\n%-10s %-30s %-30s %-20s %-5s \n","BOOK ID","BOOK NAME","BOOK AUTHOR","BOOK GENRE","BOOK AVAILABILITY");
        }
        if (strcmp(book[i].delete,"no") == 0)
        {
            if (bookid == book[i].bid)
            {
                printf("%-10d %-30s %-30s %-20s %-5s ",book[i].bid,book[i].bname,book[i].bauthor,book[i].bgenre,book[i].isavailable);
		        printf("\n");
                count++;

            }
        }
    }
    if(count==0)
    {
        printf("no data found \n");
    }
}

void Display_all_records(int ni, issuer irecord[])
{
    for (int i = 0; i < ni; i++)
    {
        if (i == 0)
        {
            printf("\n\n%-25s %-15s %-8s %-30s %-22s %-20s %-5s \n","ISSUER NAME","ISSUER ID","BOOK ID","BOOK NAME","ISSUE DATE","RETURN DATE","FINE");
        }
        printf("\n%-25s %-15s %-8d %-30s %5d-%d-%d %15d-%d-%-15d %d ",irecord[i].iname,irecord[i].iid,irecord[i].bid,irecord[i].bname,irecord[i].idate.d,irecord[i].idate.m,irecord[i].idate.y,irecord[i].rdate.d,irecord[i].rdate.m,irecord[i].rdate.y,irecord[i].fine);

    }
    printf("\n");
}
