#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<process.h>
#include<ctype.h>
#include<dos.h>
#include<time.h>

// Global Variables //
////////////////////////////////////////////////////////////////////////////////

float optimal=0.0;
float temp[]={24.67,26.67,24.00,23.00};
float rain[]={7.57,52.69,76.46,55.34};

// Function Declaration //
////////////////////////////////////////////////////////////////////////////////

void eout();

// Classes //
////////////////////////////////////////////////////////////////////////////////

class user
{
public:
	char name[20];
	char dob[15];
	char addr[100];
	char gender[15];
	char aadhar[15];
	char phno[12];
	float loan;
	void input();
	void disp();
	user()
		{
		strcpy(name,"user");
		strcpy(dob,"01-01-2000");
		strcpy(addr,"Unknown");
		strcpy(gender,"Unspecified");
		strcpy(aadhar,"Unknown");
		strcpy(phno,"9XXXXXXXX9");
		loan=0.0;
		}

}u;

class data
{
public:
	float rice;
	float maize;
	float sugarcane;
	data()
		{
		rice=39510.32;
		maize=32906.51;
		sugarcane=115280.86;
		}

}d;

class farm
{
public:
	int quarter;
	float lsize;
	float yield;
	float rate;
	int crop;
	float calc(int ,float ,float,float ,float );
	int comparison(float ,float );
	void input();
	void disp();
	farm()
		{
		quarter=1;
		lsize=12.0;
		yield=100.0;
		rate=0.0;
		crop=1;
		}
}f;

// Graphic Functions //
////////////////////////////////////////////////////////////////////////////////

void gtype(char string[200],int color,int x=wherex(),int y=wherey())
{
gotoxy(x,y);textcolor(color);cprintf(string);
}

void frame(char title[],int c,int x,int y)
{
clrscr();
for(int a=2;a<80;a++)
		{
		gtype("\261",4,a,2);
		gtype("\261",4,a,24);
		gtype("\261",4,a,4);
		}
for(int b=2;b<25;b++)
		{
		gtype("\261",4,1,b);
		gtype("\261",4,80,b);
		}
	gtype("\261",4,14,3);
	gtype("AgriCredit",3,3,3);
	gtype(title,c,x,y);
}

void bgrnd(int c)
{
for(int x=1;x<81;x++)
	{
	for(int y=2;y<25;y++)
		{
		gtype("\260",x,x,y);
		gtype("\333",c,1,y);
		gtype("\333",c,80,y);
		}
	gtype("\333",c,x,2);
	gtype("\333",c,x,24);
	}
}

void b1()
{
for(int x=20;x<59;x++)
	{
	for(int y=9;y<18;y++)
		{
		gtype(" ",7,x,y);
		gtype("\333",4,20,y);
		gtype("\333",4,58,y);
		}
	gtype("\333",4,x,9);
	gtype("\333",4,x,17);
	}
}

void text()
{
char title[11]={'A','G','R','I',' ','C','R','E','D','I','T'};
gotoxy(34,11);
for(int x=0;x<11;x++)
	{
	delay(50);
	textcolor(15);cprintf("%c",title[x]);
	}
delay(20);gtype("By",15,38,13);
delay(20);gtype("Gaurav   Divya   Dhan   Dheeraj",15,24,15);
}

void cover()
{
clrscr();
bgrnd(4);
b1();
text();
getch();
}

void loading(int t)
{
clrscr();
for(int x=11;x<71;x++)
	{
	for(int y=12;y<15;y++)
		{
		gtype(" ",7,x,y);
		gtype("\333",4,11,y);
		gtype("\333",4,70,y);
		}
	gtype("\333",4,x,12);
	gtype("\333",4,x,14);
	}
if(t==1)
	{
	gtype("Getting Things Ready !",15,31,16);
	}
if(t==2)
	{
	gtype("Creating Database",15,31,16);
	}
if(t==3)
	{
	gtype("Fetching Details",15,31,16);
	}
if(t==5)
	{
	gtype("Saving and Closing Program ...",15,27,16);
	}

for(x=12;x<70;x++)
	{
	delay(15);
	gotoxy(63,14);
	cout<<" "<<x+31<<" % ";
	gtype("\333",15,x,13);
	}
delay(350);
}

void miniload(int z)
{
clrscr();
for(int x=31;x<49;x++)
	{
	gtype("\334",4,x,12);
	gtype("\337",4,x,14);
	}
gtype("\334",4,31,13);
gtype("\337",4,48,13);
if(z==1)
	{
	gtype("Loading",15,37,15);
	}
if(z==2)
	{
	gtype("Saving",15,37,15);
	}
for(x=32;x<48;x++)
	{
	delay(25);
	gotoxy(37,11);
	cout<<" "<<x+53<<" % ";
	gtype("\333",15,x,13);
	}
delay(250);
}

void menu()
{
bgrnd(4);
for(int x=21;x<61;x++)
	{
	for(int y=3;y<6;y++)
		{
		gtype(" ",7,x,y);
		gtype("\333",4,21,y);
		gtype("\333",4,60,y);
		}
	gtype("\333",4,x,6);
	}
for(x=29;x<53;x++)
	{
	for(int y=9;y<20;y++)
		{
		gtype(" ",7,x,y);
		gtype("\333",4,29,y);
		gtype("\333",4,52,y);
		}
	gtype("\333",4,x,8);
	gtype("\333",4,x,19);
	gtype("\333",4,x,6);
	}
gtype("\4 Menu \4",15,37,4);
}

// Farming Functions //
////////////////////////////////////////////////////////////////////////////////////

float farm :: calc(int crop,float ls,float y,float t,float r)
{
switch(crop)
	{
	case 1:
		f.rate=(1092.67/y)*ls*(100.0/r)*(25.66/t)*d.rice;
		optimal=1.1975*ls*d.rice;
		break;
	case 2:
		f.rate=(2104.4/y)*ls*(65.0/r)*(23.00/t)*d.maize;
		optimal=1.1975*ls*d.maize;
		break;
	case 3:
		f.rate=(34399.0/y)*ls*(89.0/r)*(28.00/t)*d.sugarcane;
		optimal=1.1975*ls*d.sugarcane;
		break;
	}
return f.rate;
}

int farm :: comparison(float o,float r)
{
	if(r<o)
		{
		return 'a';
		}
	else if(r>o)
		{
		return 'n';
		}
	else
		{
		return 'a';
		}
}

void eligibility()
{
float r;
r=f.calc(f.crop,f.lsize,f.yield,temp[f.quarter-1],rain[f.quarter-1]);
//e=f.comparison(optimal,r);
if(optimal>=r)
	{
	 if(u.loan>r)
		{
		eout();
		gtype(" Providable Loan : ",9,3,13);cout<<r;
		gtype(" Loan Cannot Be Sanctioned because you are asking for too much ",6,3,16);
		gtype(" Crop Growth And Harvest.",6,3,17);
		gtype(" Eligibility : ",15,3,20);
		gtype(" Not Eligible ",4,17,20);

	 }
       else
       {
	eout();
	gtype(" Providable Loan : ",9,3,13);cout<<u.loan;
	gtype(" Loan Can Be Sanctioned Since The Conditions Are Suitable For Good Crop",6,3,16);
	gtype(" Growth And Harvest.",6,3,17);
	gtype(" Eligibility : ",15,3,20);
	gtype(" Eligible ",2,17,20);
	}
 }
if(optimal<r)
	{
	eout();
	gtype(" Providable Loan : ",9,3,13);cout<<optimal;
	gtype(" Loan Cannot Be Sanctioned Since The Conditions Are Not Suitable For Good ",6,3,16);
	gtype(" Crop Growth And Harvest.",6,3,17);
	gtype(" Eligibility : ",15,3,20);
	gtype(" Not Eligible ",4,17,20);
	}
}

// ip & op //
///////////////////////////////////////////////////////////////////////////////////

void user :: input()
{
frame("\4 Farmer Details \4",9,33,3);
gtype(" Name : ",10,3,8);gets(name);
gtype(" Gender : ",10,3,10);gets(gender);
gtype(" Date Of Birth : ",10,3,12);gets(dob);
gtype(" Address : ",10,3,14);gets(addr);
gtype(" Phone Number : ",10,3,16);gets(phno);
gtype(" Aadhar Number : ",10,3,18);gets(aadhar);
gtype(" Loan Request Amount : ",15,3,21);cin>>loan;
}

void farm :: input()
{
frame("\4 Crop Details \4",9,33,3);
gtype(" Land Size ( In Acres ) : ",10,3,7);cin>>lsize;
gtype(" Previous Year Yield ( Kg/Acre ) : ",10,3,9);cin>>yield;
gtype(" Quarter :- ",9,3,11);
gtype("   1. Q1 ( January - March )",10,3,13);
gtype("   2. Q2 ( April - June )",10,3,14);
gtype("   3. Q3 ( July - September )",10,3,15);
gtype("   4. Q4 ( October - December )",10,3,16);
gtype(" Enter Quarter (1-4) : ",15,43,16);cin>>quarter;
gtype(" Crop To Harvest :- ",9,3,18);
gtype("   1. Rice",10,2,20);
gtype("   2. Maize",10,2,21);
gtype("   3. Sugarcane",10,2,22);
gtype(" Enter Crop (1-3) : ",15,43,22);cin>>crop;
}
void user :: disp()
{
frame("\4 Farmer Details \4",9,33,3);
gtype(" Name : ",10,3,8);puts(name);
gtype(" Gender : ",10,3,10);puts(gender);
gtype(" Date Of Birth : ",10,3,12);puts(dob);
gtype(" Address : ",10,3,14);puts(addr);
gtype(" Phone Number : ",10,3,16);puts(phno);
gtype(" Aadhar Number : ",10,3,18);puts(aadhar);
gtype(" Loan Request Amount : ",15,3,21);cout<<loan;
gtype(" Press Any Key For Farmer Details ... ",3,42,24);
}

void farm :: disp()
{
frame("\4 Crop Details \4",9,33,3);
gtype(" Land Size ( In Acres ) : ",10,3,7);cout<<lsize;
gtype(" Previous Year Yield ( Kg/Acre ) : ",10,3,9);cout<<yield;
gtype(" Quarter :- ",9,3,11);
gtype("   1. Q1 ( January - March )",10,3,13);
gtype("   2. Q2 ( April - June )",10,3,14);
gtype("   3. Q3 ( July - September )",10,3,15);
gtype("   4. Q4 ( October - December )",10,3,16);
gtype(" Quarter : ",15,43,16);cout<<quarter;
gtype(" Crop To Harvest :- ",9,3,18);
gtype("   1. Rice",10,2,20);
gtype("   2. Maize",10,2,21);
gtype("   3. Sugarcane",10,2,22);
gtype(" Crop : ",15,43,22);cout<<crop;
}

void eout()
{
frame("\4 Loan Eligibility \4",15,33,3);
gtype(" Farmer Name : ",12,3,8);puts(u.name);
gtype(" Requested Loan Amount : ",10,3,11);cout<<u.loan;
}


void m()
{
char ch;
clrscr();
menu();
gtype("\20 1.Create Account",15,31,10);
delay(350);
gtype("\20 2.Loan Details",15,31,12);
delay(350);
gtype("\20 3.Loan Eligibility",15,31,14);
delay(350);
gtype("\20 4.Account Details",15,31,16);
delay(350);
gtype(" 'E'- Exit ",15,35,19);
gotoxy(16,6);
ch=getch();
switch(ch)
	{
	case '1':
		loading(2);
		u.input();
		miniload(2);
		break;
	case '2':
		loading(2);
		f.input();
		miniload(2);
		break;
	case '3':
		loading(3);
		eligibility();
		getch();
		miniload(1);
		break;
	case '4':
		loading(3);
		u.disp();
		getch();
		miniload(1);
		f.disp();
		getch();
		miniload(1);
		break;
	case 'e':
		loading(5);
		exit(0);
		break;
	}
m();
}

///////////////////////////////////////////////////////////////////////////////////

void main()
{
clrscr();
//cover();
//loading(1);
//m();
f.input();
u.input();
eligibility();
getch();
}