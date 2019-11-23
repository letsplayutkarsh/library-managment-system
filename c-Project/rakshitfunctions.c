#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

void string_lower(char *s1)
{
        for (int j = 0; j < strlen(s1); j++)
        {
                if (s1[j] >= 'A' && s1[j] <= 'Z')
                {
                        s1[j] = s1[j] + 32;
                }
        }
}



void no_of_books(int nb, books book[]){
        int book_count=0;
        char bookname[150];


        scanf("%[^\n]%*c",bookname);
        string_lower(bookname);

        for(int i=0; i<nb; i++) {

                if(strcmp(bookname,book[i].bname)==0) {
                        book_count+=1;

                }
        }

        printf("\n\n%s : %d\n",bookname,book_count+1);
}
void swap(int *xp, int *yp)
{
        int temp = *xp;
        *xp = *yp;
        *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
        int i, j;
        for (i = 0; i < n-1; i++)

                // Last i elements are already in place
                for (j = 0; j < n-i-1; j++)
                        if (arr[j] > arr[j+1])
                                swap(&arr[j], &arr[j+1]);
}
void Display_all_books(int nb, books book[])
{
        int arr[nb];
        for(int j=0; j<nb; j++) {
                arr[j]=book[j].bid;

        }

        bubbleSort(arr,nb);
        printf("\n\n%-10s %-30s %-30s %-20s %-5s \n\n","BOOK ID","BOOK NAME","BOOK AUTHOR","BOOK GENRE","BOOK AVAILABILITY");
        for (int i = 0; i < nb; i++)
        {
                for(int j=0; j<nb; j++)
                {
                        if (arr[i]==book[j].bid && strcmp(book[j].delete,"no") == 0)
                        {
                                printf("%-10d %-30s %-30s %-20s %-5s ",book[j].bid,book[j].bname,book[j].bauthor,book[j].bgenre,book[j].isavailable);
                                    printf("\n");
                        }

                }

        }
}
