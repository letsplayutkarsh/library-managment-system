typedef struct bookinfo{
	int bid;
	char bname[200];
	char bauthor[200];
	char bgenre[100];
	char isavailable[10];
	char delete[10];
}books;

typedef struct date{
	int d;
	int m;
	int y;
}date;

typedef struct issuerinfo{
	char iname[100];
	char iid[100];
	int bid;
	char bname[100];
	date idate;
	date rdate;
	int fine;
}issuer;