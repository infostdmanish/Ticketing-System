#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <dos.h>

	//prototype declaration
void makeBox(int,int,int,int);
void splashscreen();
void authentication(); //it checks username and password
void menu();// it is a main menu

void mem_reg();//1. member registration


	void addmember();
	void listmember();
	void modifymember();
	void deletemember();
//a.structure
struct member
 {
      int mem_id;
      char fullname[30];
      char address[30];
      int phoneNo;
      char issueDate[30];
      char validTill[30];
 }qfx;

void Dissue_Ticket();//2.Direct Issue ticket.

	void calculate();

void  Booking_Ticket();// 3. Booking Ticket.

	void addcustomer();
	void listcustomer();
	void deletecustomer();

//b.Structure
struct customer
{
	int bok_id;
	char cus_name[30];
	char movie[50];
	char show_time[20];
	char show_date[20];
}cqfx;


	// some user defined Function

	char getYN();

	int autoId();// helps to auto generate mem_id.
	int autobok_id();// helps to auto generate bok_id

 void scanString(char *);
 void scanPassword( char *);


 void main()
 {
	splashscreen();
	authentication();
	getch();
 }



void splashscreen()
	{
	 textbackground(CYAN);
	 clrscr();
	 textcolor(WHITE);
	 makeBox(5,5,65,40);

	 textcolor(BLUE);
	 makeBox(8,8,60,10);

	 textcolor(BROWN);
	 gotoxy(32,13);
	 cprintf("A PROJECT ON");


	 textcolor(RED);
	 gotoxy(25,15);
	 cprintf("QFX CINEMA TICKETING SYSTEM");

	 textcolor(WHITE);
	 gotoxy(20,20);
	 cprintf("NAME");

	 textcolor(WHITE);
	 gotoxy(20,22);
	 cprintf("ID");

	 textcolor(WHITE);
	 gotoxy(20,24);
	 cprintf("MODULE NAME");

	 textcolor(WHITE);
	 gotoxy(20,26);
	 cprintf("MODULE CODE");

	 textcolor(WHITE);
	 gotoxy(20,28);
	 cprintf("CENTER");

	 gotoxy(20,30);
	 cprintf("LECTURER");

	 // NEXT
	 textcolor(BLUE);
	 gotoxy(35,20);
	 cprintf(":MANISH SHAKYA");

	 textcolor(BLUE);
	 gotoxy(35,22);
	 cprintf(":1801T3100068");

	 textcolor(BLUE);
	 gotoxy(35,24);
	 cprintf(":C-PROGRAMING");

	 textcolor(BLUE);
	 gotoxy(35,26);
	 cprintf(":CPG-102");

	 textcolor(BLUE);
	 gotoxy(35,28);
	 cprintf(":1801");

	 textcolor(BLUE);
	 gotoxy(35,30);
	 cprintf(":PRAKASH SHRESTHA");


	 textcolor(RED);
	 gotoxy(25,35);
	 cprintf("Press any key to continue");
	 _setcursortype(_NOCURSOR);

	 getch();


 }

void authentication()
{
	char username[30]="admin";  //actual username
	char password[30]="pAss";   // actual password

	char inputuser[30], inputpass[30], string1[30], temp;
	int attempts;

	for(attempts=5;attempts>1;attempts--)
	{
		textbackground(CYAN);
		clrscr();

		textcolor(BLUE);
		makeBox(10,10,50,5);

		gotoxy(30,12);
		cprintf("Authentication");

		gotoxy(12,14);
		cprintf("Enter Username and password to Access System");

		textcolor(WHITE);
		makeBox(20,20,30,10);

		gotoxy(22,22);
		cprintf("Username: ");

		gotoxy(22,24);
		cprintf("Password: ");

		gotoxy(32,22);
		fflush(stdin);
		textcolor(WHITE);
		//gets(inputuser);
		scanString(inputuser);

		gotoxy(32,24);
		scanPassword(inputpass);


		gotoxy(32,28);
		//cprintf("usrname: %s, password: %s",inputuser,inputpass);

		if(stricmp(username,inputuser)==0 && strcmp(password,inputpass)==0)
		{
			gotoxy(32, 35);
			textcolor(GREEN);
			cprintf("Username and password authenticated. Welcome..");
			getch();
			menu();
		}

		else
		{
			gotoxy(32,35);
			textcolor(RED);
			cprintf("Username or password invalid. Try again.");
			gotoxy(32,32);
			cprintf("Attempts Left: %i",attempts-1);
			getch();

		}
	}
	clrscr();
	gotoxy(10,10);
	cprintf("You are not authenticated. You will now exit.");
	getch();
	exit(0);
}





void menu()
{
	char input;
	do{
		textbackground(CYAN);
		clrscr();
		textcolor(WHITE);
		makeBox(20,15,40,30);

		gotoxy(25,17);
		cprintf("WELLCOME TO MAIN MENU");

		gotoxy(22,26);
		cprintf("\n1.Member Registration   |Press[1]|");

		gotoxy(22,28);
		cprintf("\n2.Direct issue Ticket   |Press[2]| ");

		gotoxy(22,30);
		cprintf("\n3.Booking Ticket        |Press[3]|");

		gotoxy(22,32);
		cprintf("\n4.Exit                  |Press[4]|");



		fflush(stdin);
		input=getche();

	} while(input!='1' && input!='2' && input!='3' && input!='4' && input!='5');




	switch(input)
	{
		case '1':
		{

		       mem_reg();
		}break;

		case '2':
		{

		       Dissue_Ticket();
		}break;

		case '3':
		{

		       Booking_Ticket();
		}break;


		case '4':
		{
			clrscr();
			gotoxy(10,10);
			cprintf("Thanks for using our system.... You will now exit.");
			getch();
			exit(0);
		}
	}

}

void mem_reg()
{
      char ginput;


      do{	textbackground(CYAN);
		clrscr();

		textcolor(MAGENTA);
		makeBox(15,10,50,40);


		gotoxy(22,17);
		cprintf(" ---MEMBER REGISTRATION---");

		gotoxy(22,20);
		cprintf("-----------------------------");
		gotoxy(22,26);
		cprintf("\n 1.Add Member");
		gotoxy(22,28);
		cprintf("\n 2.List Member");
		gotoxy(22,30);
		cprintf("\n 3.Modify Member");

		gotoxy(22,32);
		cprintf("\n 4.Delete Member" );

		gotoxy(22,34);
		cprintf("\n 5.Exit");

		gotoxy(22,36);
		cprintf("\n ***** Choose 1|2|3|4|5*****");

		fflush(stdin);
		ginput=getche();

	} while(ginput!='1' && ginput!='2' && ginput!='3' && ginput!='4' && ginput!='5');




	switch(ginput)
	{
		case '1':
		{

		       addmember();

		}break;

		case '2':
		{
			listmember();
		}break;

		case '3':
		{
			modifymember();
		}break;

		case '4':
		{
			deletemember();
		}break;

		case '5':
		{
			menu();
		}break;
	}
     getch();

}

void addmember()

{     FILE *fp;

      textbackground(CYAN);
      clrscr();
      textcolor(BROWN);
      makeBox(10,1,40,3);
      gotoxy(20,2);
      cprintf("ADD MEMBER");



      textcolor(WHITE);
      makeBox(10,5,40,20);


		gotoxy(12,10);
		cprintf("Enter mem_id:");

		gotoxy(12,12);
		cprintf("Enter fullname:");

		gotoxy(12,14);
		cprintf("Enter address:");

		gotoxy(12,16);
		cprintf("Enter phoneNo:");

		gotoxy(12,18);
		cprintf("Enter issueDate:");

		gotoxy(12,20);
		cprintf("Enter validTill:");

		// for user input

		gotoxy(30,10);
		fflush(stdin);
		qfx.mem_id=autoId();
		cprintf("%i",qfx.mem_id);

		gotoxy(30,12);
		fflush(stdin);
		scanString(qfx.fullname);

		gotoxy(30,14);
		fflush(stdin);
		scanString(qfx.address);

		gotoxy(30,16);
		fflush(stdin);
		scanf("%i",&qfx.phoneNo);

		gotoxy(30,18);
		fflush(stdin);
		scanString(qfx.issueDate);

		gotoxy(30,20);
		fflush(stdin);
		scanString(qfx.validTill);

	//now writing in the file
	fp = fopen("member.dat","ab+");

	if(fp == NULL)
	{
		gotoxy(10,40);
		cprintf("File couldn't be opened..");
		getch();
		mem_reg();
	}

	fwrite(&qfx,sizeof(qfx),1,fp);
	fclose(fp); //you should always close the file after writing a record.

	gotoxy(10,35);
	textcolor(GREEN);
	cprintf("Record was written successfully!");
	gotoxy(10,38);
	cprintf("Do you want to add another record?");

	if(getche()=='y')
	{
		addmember();
	}
	else
	{
		mem_reg();
	}


}

void listmember()
{
	FILE *fl;
	int y=8;
	textbackground(CYAN);
	clrscr();

	fl=fopen("member.dat","rb+");

	if(fl== NULL) // if the file couldn't open
	{
		gotoxy(10,40);
		textcolor(RED);
		cprintf("Error in listing");
		getch();
		mem_reg();
	}

	gotoxy(5,3);
	textcolor(WHITE);
	cprintf("LIST OF MEMBERS");

	gotoxy(5,5);
	cprintf("Mem_id");

	gotoxy(14,5);
	cprintf("Fullname");

	gotoxy(30,5);
	cprintf("Address");

	gotoxy(45,5);
	cprintf("PhoneNo");

	gotoxy(55,5);
	cprintf("IssueDate");

	gotoxy(65,5);
	cprintf("ValidTill");

	gotoxy(5,7);
	cprintf("_________________________________________________________________________");

	textcolor(WHITE);

	while(fread(&qfx,sizeof(qfx),1,fl)!=0)
	{

		gotoxy(5,y);
		cprintf("%i",qfx.mem_id);

		gotoxy(10,y);
		cprintf("%s",qfx.fullname);

		gotoxy(30,y);
		cprintf("%s",qfx.address);

		gotoxy(45,y);
		cprintf("%i",qfx.phoneNo);

		gotoxy(55,y);
		cprintf("%s",qfx.issueDate);

		gotoxy(68,y);
		cprintf("%s",qfx.validTill);

		y+=2;
	}


	fclose(fl);

	gotoxy(10,40);
	cprintf("Press any key to return to menu");

	getch();
	mem_reg();
    }

void modifymember()
{

	int id,y=14;
	int size=sizeof(qfx);

	char yesno;

	FILE *fp;
	textbackground(CYAN);
	clrscr();

	//1. choose what record to modify.

	textcolor(BLACK);
	gotoxy(5,5);
	cprintf("Enter Mem_id to modify:");
	fflush(stdin);
	scanf("%i",&id);


	//2. Now to open and search

	fp=fopen("member.dat","rb+");

	if(fp==NULL)// if file is not there.
	{
		gotoxy(10,30);
		textcolor(RED);
		cprintf("Error in  opening the file");
		getch();
		mem_reg();
	}

	// printing  the heading for modificaiton


	gotoxy(20,7);
	textcolor(WHITE);
	cprintf("********MODIFY MEMBERS*********");


	gotoxy(5,8);
	cprintf("Mem_id");

	gotoxy(14,8);
	cprintf("Fullname");

	gotoxy(30,8);
	cprintf("Address");

	gotoxy(45,8);
	cprintf("PhoneNo");

	gotoxy(55,8);
	cprintf("IssueDate");

	gotoxy(65,8);
	cprintf("ValidTill");

	gotoxy(5,10);
	cprintf("______________________________________________");


       // 3.search the record

       while(fread(&qfx,size,1,fp)!=0)
       {
	 if(id==qfx.mem_id)
	 {
		gotoxy(5,y);
		cprintf("%i",qfx.mem_id);

		gotoxy(10,y);
		cprintf("%s",qfx.fullname);

		gotoxy(30,y);
		cprintf("%s",qfx.address);

		gotoxy(45,y);
		cprintf("%i",qfx.phoneNo);

		gotoxy(55,y);
		cprintf("%s",qfx.issueDate);

		gotoxy(65,y);
		cprintf("%s",qfx.validTill);

		break;
	 }
       }

	//4. Ask for the confirmation

	gotoxy(5,20);
	textcolor(WHITE);
	cprintf("Are you sure to modify this record.||press Y or press N||");
	yesno=getYN();

	if(yesno=='y')
	{
	//5. seek the file cursor one record up.

	fseek(fp,-size,SEEK_CUR);

	//6. Ask user to enter new values for modification

	gotoxy(5,22);
	textcolor(WHITE);
	cprintf("Press 'M' to modify the record");




		gotoxy(5,25);
		cprintf("Enter New fullname:");
		fflush(stdin);
		if(getch()=='m')
		 {
			scanf("%s",&qfx.fullname);
		 }
		else
		 {
			cprintf("%s",qfx.fullname);
		 }


		gotoxy(5,27);
		cprintf("Enter New address:");
		fflush(stdin);
		if(getch()=='m')
		 {
			scanf("%s",&qfx.address);
		 }
		else
		 {
			cprintf("%s",qfx.address);
		 }

		gotoxy(5,29);
		cprintf("Enter New phoneNo:");
		fflush(stdin);
		if(getch()=='m')
		 {
			scanf("%i",&qfx.phoneNo);
		 }
		else
		 {
			cprintf("%i",qfx.phoneNo);
		 }

		gotoxy(5,31);
		cprintf("Enter New issueDate:");
		fflush(stdin);
		if(getch()=='m')
		 {
			scanf("%s",&qfx.issueDate);
		 }
		else
		 {
			cprintf("%s",qfx.issueDate);
		 }

		gotoxy(5,33);
		cprintf("Enter New validTill:");
		fflush(stdin);
		if(getch()=='m')
		 {
			scanf("%s",&qfx.validTill);
		 }
		else
		 {
			cprintf("%s",qfx.validTill);
		 }

		 // now write a new record

		 fwrite(&qfx,size,1,fp);
		 fclose(fp);

		 gotoxy(5,40);
		 textcolor(WHITE);
		 cprintf("Record was successfully Modified");
		 getch();
		 mem_reg();
	}
	else
	{
		fclose(fp);
		mem_reg();
	}

}


void deletemember()
{
	int id,y=15;
	int size= sizeof(qfx);
	char yesno;
	FILE *fp,*ft;

	textbackground(BROWN);
	clrscr();

	//1. System will ask what record to delete.


	textcolor(WHITE);

	gotoxy(5,5);
	cprintf("Enter Member Id to Delete:");
	fflush(stdin);
	scanf("%i",&id);

	//2. Open  file and search the record.

	fp=fopen("member.dat","rb++");

	if(fp== NULL) // if file could not be open or found.
	{
		gotoxy(8,30);
		textcolor(RED);
		cprintf("File you want to delete couldn't be found");
		getch();
		mem_reg();
	}


	// printing heading....

	gotoxy(20,7);
	textcolor(WHITE);
	cprintf("DELETE MEMBERS");


	gotoxy(5,10);
	cprintf("Mem_id");

	gotoxy(14,10);
	cprintf("Fullname");

	gotoxy(30,10);
	cprintf("Address");

	gotoxy(45,10);
	cprintf("PhoneNo");

	gotoxy(55,10);
	cprintf("IssueDate");

	gotoxy(65,10);
	cprintf("ValidTill");

	gotoxy(5,11);
	cprintf("____________________________________________________________________________");

	// search the record reading each file

	while(fread(&qfx,size,1,fp)!=0)
	{
		if (id==qfx.mem_id)
		{

			gotoxy(5,y);
			cprintf("%i",qfx.mem_id);

			gotoxy(11,y);
			cprintf("%s",qfx.fullname);

			gotoxy(30,y);
			cprintf("%s",qfx.address);

			gotoxy(45,y);
			cprintf("%i",qfx.phoneNo);

			gotoxy(55,y);
			cprintf("%s",qfx.issueDate);

			gotoxy(68,y);
			cprintf("%s",qfx.validTill);

			break;
		}
	}

	//4. Ask for the user comformation.


	gotoxy(5,25);
	textcolor(WHITE);
	cprintf("Are you sure to delete this record..Press Y for yes and N for no");
	yesno=getYN();





	if(yesno=='y')
	{
		ft= fopen("temp.dat","ab+");

		// rewind will copy all the record to temp

		rewind(fp);

		// copy all the record from main file to temp

		while(fread(&qfx,sizeof(qfx),1,fp)!=0)
		{
			if(qfx.mem_id!=id)//  except the record to be delete
			{
				//write in temp file(ft)
				fwrite(&qfx,sizeof(qfx),1,ft);
			}
		}

		fclose(fp);
		fclose(ft);

		// delete the original file as record is already copy to temp
		remove("member.dat");

		// now rename the temp file as orginal file
		rename("temp.dat","member.dat");

		gotoxy(5,40);
		textcolor(WHITE);
		cprintf("Record was successfully deleted from the system");
		getch();
		mem_reg();
	}

	else
	{
		gotoxy(5,40);
		textcolor(WHITE);
		cprintf("Unsuccessfull to delete record");
		getch();
		mem_reg();
	}


}

void Dissue_Ticket()
{
  char input;

       do{	textbackground(CYAN);
		clrscr();

		textcolor(WHITE);
		makeBox(15,10,40,20);

		textcolor(BLACK);
		gotoxy(16,11);
		cprintf("DIRECT ISSUE TICKET");

		gotoxy(16,15);
		cprintf("1. Calculate   |Press[1]|");

		gotoxy(16,17);
		cprintf("2. Exit        |Press[2]|");

		fflush(stdin);
		input=getche();


	 }while(input!='1' && input!='2');

		 switch(input)
		 {
			 case '1':
			 {
				calculate();
			 }break;

			 case '2':
			 {
				menu();
			 }
		 }



  getch();
}

void calculate()

{     	char movieName[100],type,input;

	float price,cost,qnty,vat,total;

	textbackground(CYAN);
	clrscr();

	textcolor(WHITE);
	makeBox(5,5,70,25);


		gotoxy(15,6);
		cprintf("QFX CINEMA TICKETING ISSUING");

		gotoxy(6,10);
		cprintf("Enter Movie Name:");

		gotoxy(6,12);
		cprintf("Enter Ticket quantity:");

		gotoxy(6,14);
		cprintf("Enter Type(1.Gold,2.Platinum,3.Premium):");

		gotoxy(6,16);
		cprintf("Price per ticket:Rs");

		gotoxy(6,18);
		cprintf("Cost:Rs");

		gotoxy(6,20);
		cprintf("VAT:Rs");

		gotoxy(6,22);
		cprintf("Total Cost:Rs");

		//User input



		gotoxy(30,10);
		fflush(stdin);
		scanf("%c",&movieName);

		gotoxy(30,12);
		fflush(stdin);
		scanf("%f",&qnty);

		gotoxy(50,14);
		fflush(stdin);
		type=getch();

		if(type=='1')
		{
			gotoxy(51,14);
			cprintf("Gold");
		}

		else if( type=='2')
		{

			gotoxy(51,14);
			cprintf("Platinum");

		}

		else if(type=='3')
		{

			gotoxy(51,14);
			cprintf("Premium");
		}
		else
		{
			gotoxy(51,14);
			cprintf("Invalid Type");

		}

		gotoxy(26,16);
		scanf("%f",&price);


		gotoxy(15,18);
		cost=(qnty*price);
		cprintf("%.2f",cost);

		gotoxy(14,20);
		vat=(cost*13/100);
		cprintf("%.2f",vat);

		gotoxy(20,22);
		total=(cost+vat);
		cprintf("%.2f",total);

		//Out of Box

		textcolor(BLUE);

	       gotoxy(5,35);
	       cprintf(" Print Ticket Sucessfull");

	       gotoxy(5,40);
	       cprintf("Do you want to Issue ticket. Again! Then Press [A]:");

	       input=getch();


		if(input=='a'| input=='A')
		{
		       calculate();
		}
		else
		{
			Dissue_Ticket();
		}

getch();



}


// Booking Ticket.
void Booking_Ticket()
{
      char ginput;


      do{	textbackground(CYAN);
		clrscr();

		textcolor(WHITE);
		makeBox(15,10,40,30);


		gotoxy(22,17);
		cprintf("-----TICKET BOOKING-----");

		gotoxy(22,20);
		cprintf("-----------------------------");
		gotoxy(22,26);
		cprintf("\n 1.Add Customer");
		gotoxy(22,28);
		cprintf("\n 2.List Customer");


		gotoxy(22,30);
		cprintf("\n 3.Delete Member" );

		gotoxy(22,32);
		cprintf("\n 4.Exit");

		gotoxy(22,34);
		cprintf("\n .***** Choose 1|2|3|4|*****");

		fflush(stdin);
		ginput=getche();

	} while(ginput!='1' && ginput!='2' && ginput!='3' && ginput!='4');




	switch(ginput)
	{
		case '1':
		{
			addcustomer();

		}break;

		case '2':
		{
			listcustomer();
		}break;


		case '3':
		{
			deletecustomer();
		}break;

		case '4':
		{
			menu();
		}break;
	}
     getch();

}

void addcustomer()

{     FILE *fpc;

      textbackground(CYAN);
      clrscr();

      textcolor(WHITE);
      makeBox(10,8,40,20);

		gotoxy(12,10);
		cprintf("Enter bok_id:");

		gotoxy(12,12);
		cprintf("Enter cus_name:");

		gotoxy(12,14);
		cprintf("Enter movie:");

		gotoxy(12,16);
		cprintf("Enter show_time:");

		gotoxy(12,18);
		cprintf("Enter show_date:");

		// for user input

		gotoxy(30,10);
		fflush(stdin);
		cqfx.bok_id=autobok_id();
		cprintf("%i",cqfx.bok_id);

		gotoxy(30,12);
		fflush(stdin);
		scanString(cqfx.cus_name);

		gotoxy(30,14);
		fflush(stdin);
		scanString(cqfx.movie);


		gotoxy(30,16);
		fflush(stdin);
		scanString(cqfx.show_time);

		gotoxy(30,18);
		fflush(stdin);
		scanString(cqfx.show_date);

	//now writing in the file
	fpc = fopen("customer.dat","ab+");

	if(fpc == NULL)
	{
		gotoxy(10,40);
		cprintf("File couldn't be opened..");
		getch();
		menu();
	}

	fwrite(&cqfx,sizeof(cqfx),1,fpc);
	fclose(fpc); //you should always close the file after writing a record.

	gotoxy(10,35);
	textcolor(GREEN);

	cprintf("Record was written successfully!");
	gotoxy(10,38);
	cprintf("Do you want to add another record?");

	if(getche()=='y')
	{
		addcustomer();
	}
	else
	{
		Booking_Ticket();
	}
}


void listcustomer()
{
	FILE *flc;
	int y=10;
	textbackground(CYAN);
	clrscr();

	flc=fopen("customer.dat","rb+");

	if(flc== NULL) // if the file couldn't open
	{
		gotoxy(10,40);
		textcolor(RED);
		cprintf("Error in listing");
		getch();
		Booking_Ticket();
	}

	gotoxy(5,3);
	textcolor(WHITE);
	cprintf("BOOKING LISTS OF CUSTOMER ");

	gotoxy(5,5);
	cprintf("bok_id");

	gotoxy(14,5);
	cprintf("cus_name");

	gotoxy(30,5);
	cprintf("movie");

	gotoxy(45,5);
	cprintf("show_time");

	gotoxy(58,5);
	cprintf("show_date");

	gotoxy(5,7);
	cprintf("_________________________________________________________________________");

	textcolor(WHITE);

	while(fread(&cqfx,sizeof(cqfx),1,flc)!=0)
	{

		gotoxy(5,y);
		cprintf("%i",cqfx.bok_id);

		gotoxy(14,y);
		cprintf("%s",cqfx.cus_name);

		gotoxy(30,y);
		cprintf("%s",cqfx.movie);

		gotoxy(45,y);
		cprintf("%s",cqfx.show_time);

		gotoxy(58,y);
		cprintf("%s",cqfx.show_date);


		y+=2;
	}


	fclose(flc);

	gotoxy(10,35);
	cprintf("Press any key to return to Booking ticket menu");

	getch();
	Booking_Ticket();
}

void deletecustomer()
{
	int id,y=15;
	int size= sizeof(cqfx);
	char yesno;
	FILE *fpc,*ftc;

	textbackground(BROWN);
	clrscr();

	//1. System will ask what record to delete.


	textcolor(WHITE);

	gotoxy(5,5);
	cprintf("Enter booking Id to Delete:");
	fflush(stdin);
	scanf("%i",&id);

	//2. Open  file and search the record.

	fpc=fopen("customer.dat","rb++");

	if(fpc== NULL) // if file could not be open or found.
	{
		gotoxy(8,30);
		textcolor(RED);
		cprintf("File you want to delete couldn't be found");
		getch();
		Booking_Ticket();
	}


	// printing heading....

	gotoxy(20,7);
	textcolor(WHITE);
	cprintf("DELETE CUSTOMERS");


	gotoxy(5,10);
	cprintf("bok_id");

	gotoxy(14,10);
	cprintf("cus_name");

	gotoxy(30,10);
	cprintf("movie");

	gotoxy(45,10);
	cprintf("show_time");

	gotoxy(55,10);
	cprintf("show_Date");


	gotoxy(5,11);
	cprintf("____________________________________________________________________________");

	// search the record reading each file

	while(fread(&cqfx,size,1,fpc)!=0)
	{
		if (id==cqfx.bok_id)
		{

			gotoxy(5,y);
			cprintf("%i",cqfx.bok_id);

			gotoxy(14,y);
			cprintf("%s",cqfx.cus_name);

			gotoxy(30,y);
			cprintf("%s",cqfx.movie);

			gotoxy(45,y);
			cprintf("%s",cqfx.show_time);

			gotoxy(55,y);
			cprintf("%s",cqfx.show_date);


			break;
		}
	}

	//4. Ask for the user comformation.


	gotoxy(5,25);
	textcolor(WHITE);
	cprintf("Are you sure to delete this record..Press Y for yes and N for no");
	yesno=getYN();





	if(yesno=='y')
	{
		ftc= fopen("temp.dat","ab+");

		// rewind will copy all the record to temp

		rewind(fpc);

		// copy all the record from main file to temp

		while(fread(&cqfx,sizeof(cqfx),1,fpc)!=0)
		{
			if(cqfx.bok_id!=id)//  except the record to be delete
			{
				//write in temp file(ftc)
				fwrite(&cqfx,sizeof(cqfx),1,ftc);
			}
		}

		fclose(fpc);
		fclose(ftc);

		// delete the original file as record is already copy to temp
		remove("customer.dat");

		// now rename the temp file as orginal file
		rename("temp.dat","customer.dat");

		gotoxy(5,40);
		textcolor(WHITE);
		cprintf("Record was successfully deleted from the system");
		getch();
		Booking_Ticket();
	}

	else
	{
		gotoxy(5,40);
		textcolor(WHITE);
		cprintf("Unsuccessfull to delete record");
		getch();
		Booking_Ticket();
	}


}



// it generates a rectangle box

void makeBox(int x,int y,int width,int height)
{
       int i,j;
	//top left conner
	gotoxy(x,y);
	cprintf("%c",201);


	//top right conner
	 gotoxy(x+width,y);
	 cprintf("%c",187);

	 //bottom left conner
	 gotoxy(x,y+height);
	 cprintf("%c",200);


	 //bottom right conner
	 gotoxy(x+width,y+height);
	 cprintf("%c",188);

	    //horizontal line
	for(i=x+1;i<x+width;i++)

	{
		//top line
		gotoxy(i,y);
		cprintf("%c",205);

		//bottom line
		gotoxy(i,y+height);
		cprintf("%c",205);
	}
		//vertical line
	for(j=y+1;j<y+height;j++)
	{
		//left line
		gotoxy(x,j);
		cprintf("%c",186);

		//right line
		gotoxy(x+width,j);
		cprintf("%c",186);

	}

}





 // start of user defined Function.

int autoId()
{
	int num=0;
	FILE *fl;

	fl = fopen("member.dat","rb+");

	if(fl == NULL)  //if the file couldn't be opened.
	{
		return 1;
	}
	else
	{

		while(fread(&qfx,sizeof(qfx),1,fl)!=0)
		{
			if(qfx.mem_id>num)
			{
				num = qfx.mem_id;
			}
		}
		fclose(fl);

		return num+1;
	}
}
int autobok_id()
{	int num=0;
	FILE *flc;

	flc = fopen("customer.dat","rb+");

	if(flc == NULL)  //if the file couldn't be opened.
	{
		return 1;
	}
	else
	{

		while(fread(&cqfx,sizeof(cqfx),1,flc)!=0)
		{
			if(cqfx.bok_id>num)
			{
				num = cqfx.bok_id;
			}
		}
		fclose(flc);

		return num+1;
	}
}
char getYN()
{
	char yn;

	do{
		yn=getch();
		yn=tolower(yn);
	}while(yn!='y' && yn!='n');

	return yn;
}



void scanPassword(char *pointervar)
{
	int i;
	char temp;
	char string1[30];

	for(i=0;i<30;i++)
	{
	     temp=getch();

	     if(temp==27)  // if the user presses escape
	     {
		//menu();

			splashscreen();
	     }
	     else if(temp==13) //if the user presses enter
	     {
		break;
	     }
	     else if(temp==8) // if the user presses backspace
	     {
		printf("%c%c%c",8,32,8);  // print backspace space and then backspace again
		i-=2;
	     }
	     else
	     {

			 string1[i]=temp;
			 //printf("%c",string1[i]);
			 printf("*");
	     }
	}

	string1[i]='\0'; // put null at the end of the array

	strcpy(pointervar,string1);
}


void scanString(char *pointervar)
{
	int i;
	char temp;
	char string1[30];

	for(i=0;i<30;i++)
	{
	     temp=getch();


	     if(temp==27)  // if the user presses escape
	     {
		//menu();

			splashscreen();
	     }
	     else if(temp==13) //if the user presses enter
	     {
		break;
	     }
	     else if(temp==8) // if the user presses backspace
	     {
		printf("%c%c%c",8,32,8);  // print backspace space and then backspace again
		i-=2;
	     }
	     else
	     {

			 string1[i]=temp;
			 //printf("%c",string1[i]);
			 printf("%c",temp);
	     }
	}

	string1[i]='\0'; // put null at the end of the array

	strcpy(pointervar,string1);
}











