#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include"structs.h"
#include"writeread.h"
#include"addsubfine.h"

int main(void)
{
	//Copying file's data to struct
	FILE* readbook;
	readbook = fopen("books.txt", "r");

	if(readbook == NULL){
		FILE* temp;
		temp = fopen("books.txt", "a");
		fclose(temp);

		readbook = fopen("books.txt", "r");
	}

	books book[5000];
	//The number of lines presently there in the structure, it should be updated as soon as length increases
	int nb = numoflines(readbook);
	writetobs(book, nb, readbook);
	fclose(readbook);
	// printf("%d\n", nb);

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

	// printf("%d\n", ni);





	///////////
	// addbook(book, &nb, 103, "RD", "Sharma", "Maths");
	///////////

	///////////
	// delbookbyid(book, &nb, 1);
	///////////

	// addissuer(irecord, book, &ni, &nb, "Sukhamjot", "IMT2019344", 111, 5, 6, 2016);
	// addissuer(irecord, book, &ni, &nb, "Sukhampreet", "IMT2019152", 114, 4, 10, 2016);
	// addissuer(irecord, book, &ni, &nb, "Balkaran", "IMT2019343", 112, 15, 7, 2016);
	// addissuer(irecord, book, &ni, &nb, "Das", "IMT2019456", 116, 3, 6, 2016);
	// addissuer(irecord, book, &ni, &nb, "Bakshi", "IMT2019120", 117, 6, 3, 2016);

	addreturndate(irecord, book, "IMT2019152", &ni, &nb, 30, 10, 2016);


	FILE *writebook;
	writebook = fopen("books.txt", "w");

	writetobf(book, nb, writebook);

	fclose(writebook);

	fine(irecord, ni);

	FILE *writeissue;
	writeissue = fopen("issue.txt", "w");

	writetoif(irecord, ni, writeissue);

	fclose(writeissue);

}
