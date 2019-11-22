#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
#include"structs.h"
#include"writeread.h"
#include"addsubfine.h"
#include"Srivishnu_headerfiles.h"
#include"sukhamfunctions.h"
#include"Utkarshfunction.h"
#include "rakshitfunctions.h"

int main(void)
{
	//Copying file's data to struct

	//opening file in read mode
	FILE* readbook;
	readbook = fopen("books.txt", "r");

	if(readbook == NULL)
	{
		FILE* temp;
		temp = fopen("books.txt", "a");
		fclose(temp);

		readbook = fopen("books.txt", "r");
	}

	//array of book type variables to store book and its info
	books book[5000];

	//reading data from file and storing it in array of structs
	int nb = numoflines(readbook);
	writetobs(book, nb, readbook);
	fclose(readbook);



	//reading issue records simlar to reading books
	FILE* readissue;
	readissue = fopen("issue.txt", "r");

	if(readissue == NULL){
		FILE* temp;
		temp = fopen("issue.txt", "a");
		fclose(temp);

		readbook = fopen("issue.txt", "r");
	}

	issuer irecord[5000];
	int ni = numoflines(readissue);
	writetois(irecord, ni, readissue);
	fclose(readissue);
	fine(irecord, ni);



	//The interface comes here
	printf("WELCOME TO LIBRARY MANAGEMENT SYSTEM\n");




	printf("\n1.  Issue a book\n");
	printf("2.  Return a book\n");
	printf("3.  Display all issue records\n");
	printf("4.  Search records\n");
	printf("5.  Display all books\n");
	printf("6.  Display books by availaibility\n");
	printf("7.  Search books\n");
	printf("8.  Add book\n");
	printf("9.  Delete Book\n");
	printf("0.  Save and Quit\n");


	int o = -1;
	while(o != 0)
	{
		printf("\n(-1.) DISPLAY MENU\n");

		printf("\nType an option: ");
		scanf("%d%*c", &o);

		if(o == -1)
		{
			printf("\n1.  Issue a book\n");
			printf("2.  Return a book\n");
			printf("3.  Display all issue records\n");
			printf("4.  Search records\n");
			printf("5.  Display all books\n");
			printf("6.  Display books by availaibility\n");
			printf("7.  Search books\n");
			printf("8.  Add book\n");
			printf("9.  Delete Book\n");
			printf("0.  Save and Quit\n");

		}

		else if(o == 1)
		{
			char iname[100], iid[100];
			int bid, d, m, y;

			printf("\nGive issuer's name : ");
			scanf("%[^\n]%*c", iname);

			printf("\nGive issuer's roll number : ");
			scanf("%[^\n]%*c", iid);

			printf("\nGive book id : ");
			scanf("%d%*c", &bid);

			lower(iid);

			if(!available(book, bid, &nb)){
				printf("Book not available\n\n");
			}
			else
			{
				printf("\nGive issue date in format d m y : ");
				scanf("%d %d %d%*c", &d, &m, &y);

				addissuer(irecord, book, &ni, &nb, iname, iid, bid, d, m, y);
			}
		}


		else if(o == 2)
		{
			char iid[100]; int d, m, y;

			printf("\nGive the returner's Roll Number : ");
			scanf("%[^\n]%*c", iid);

			if(!ridpresent(irecord, iid, &ni))
			{
				printf("Roll Number not present or book returned already\n");
			}
			else
			{
				printf("\nGive the return date in format d m y: ");
				scanf("%d %d %d%*c", &d, &m, &y);
				addreturndate(irecord, book, iid, &ni, &nb, d, m, y);
			}
		}



		else if(o == 3)
		{
			//use display all function
			Display_all_records(ni, irecord);
		}



		else if(o == 4)
		{
			int k;
			printf("1. Search by Book Name\n");
			printf("2. Search by Book ID\n");
			printf("3. Search by Issue Date\n");
			printf("4. Search by Return Date\n");
			printf("5. Search by Issuer Name\n");
			printf("6. Search by Issuer Id\n");
			printf("7. Display returned books\n");
			printf("8. Display not returned books\n");

			printf("\nGive option number : ");
			scanf("%d%*c", &k);

			if(k == 1)
			{
				printf("Give the Book name: ");
				search_by_bookname(ni,irecord, nb , book);
			}
			else if(k == 2)
			{
				printf("Give the Book ID: ");
 				search_by_book_id(ni, irecord);
			}
			else if(k == 3)
			{
				printf("\nGive the issue date in format d m y: ");
				search_by_issuedate(ni,irecord);
			}
			else if(k == 4)
			{
				printf("\nGive the return date in format d m y: ");
				search_by_returndate(ni,irecord);

			}
			else if(k == 5)
			{
				printf("Give the issuer name: ");
 				search_by_issuername(ni, irecord);
			}
			else if(k == 6)
			{
				printf("Give the issuer ID: ");
				search_by_issuer_id(ni,irecord);

			}
			else if(k == 7)
			{
				returned_books(irecord,ni);

			}
			else if(k == 8)
			{
				not_returned_books(irecord,ni);

			}
			else{
				printf("option not valid");
			}


		}



		else if(o == 5)
		{
			//use display all function
			Display_all_books(nb, book);
		}



		else if(o == 6)
		{
			printf("\n1. Display available books");
			printf("\n2. Display issued books\n");

			int g;
			printf("\nGive option number : ");
			scanf("%d%*c", &g);

			if(g == 1)
			{
				Search_by_availability(nb, book, "yes");
			}
			else if(g == 2)
			{
				Search_by_availability(nb, book, "no");
			}
			else{
				printf("option not valid");
			}
		}




		else if(o == 7)
		{
			int k;

			printf("1. Search by Book Name\n");
			printf("2. Search by Author\n");
			printf("3. Search by Genre\n");
			printf("4. Search by Book ID\n");
			printf("5. Display no of copies by Book\n");

			printf("\nGive option number : ");

			scanf("%d%*c", &k);

			if(k == 1)
			{
				printf("Give the book name: ");
				Search_by_name(nb, book);
			}
			else if(k == 2)
			{
				printf("Give the book author: ");
				Search_by_author(nb, book);
			}
			else if(k == 3)
			{
				printf("Give the book genre: ");
				Search_by_genre(nb, book);
			}
			else if(k == 4)
			{
				printf("Give the book id: ");
				Search_by_bookid(nb, book);
			}
			else if(k == 5)
			{
				printf("Give name of book:");
				no_of_books(nb, book);
			}
			else{
				printf("option not valid");
			}
		}



		else if(o == 8)
		{
			int bid; char bname[100], bauthor[100], bgenre[100];


			printf("\nGive book ID : ");
			scanf("%d%*c", &bid);

			while(!validbid(book, bid, &nb))
			{
				printf("\nBook ID Exists\n");
				printf("\nGive book ID : ");
				scanf("%d%*c", &bid);
			}

			printf("\nGive the book name : ");
			scanf("%[^\n]%*c", bname);

			printf("\nGive the book author : ");
			scanf("%[^\n]%*c", bauthor);

			printf("\nGive the book genre : ");
			scanf("%[^\n]%*c", bgenre);

			addbook(book, &nb, bid, bname, bauthor, bgenre);
		}


		else if(o == 9)
		{
			int bid;
			printf("\nGive the bookid: ");

			scanf("%d%*c",&bid);

			if(available(book, bid, &nb)){
				delbookbyid(book, &nb, bid);
			}
			else{
				printf("\nBook not returned or not available\n");
			}
		}

		else
		{
			if(o != 0)
				printf("\nEnter valid option\n");
		}

	}

	fine(irecord, ni);



	//Saving all the data to the files
	FILE *writebook;
	writebook = fopen("books.txt", "w");

	writetobf(book, nb, writebook);

	fclose(writebook);


	FILE *writeissue;
	writeissue = fopen("issue.txt", "w");

	writetoif(irecord, ni, writeissue);

	fclose(writeissue);

}
