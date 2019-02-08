/********************THIS IS A MINI BANKING PROJECT*************************
*******************************ON LANGUAGE 'C' ****************************/

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

 struct date
  {
   int dd,mm,yyyy;
  }today;

 struct staff
 {
  char st_name[10],pswrd[10];
 }ad,ad2;

 struct customer
  {
   char name[40], address[70], acc_type[10], citizenship[15],ph_no[15];
   int year;
   float amount;
   int age;
   long acc_no,aadharr_no;
   struct date dob,withdrwal, diposit,acc_opened;
  }add,ac,add2;

void welcome();
void about();
void admin();
void staff();
void add_account();
void trn();
void withdrwa();
void diposite();
void display();
void menu();


void main()
{
 //clrscr();
 about();
 //clrscr();
  printf("\n\n\t\t    Enter Today's Date(dd/mm/yyyy)::");
  scanf("%d/%d/%d",&today.dd, &today.mm, &today.yyyy);
 welcome();
}
void add_account()
 {
 // int i=1;
  int acn2=1;
  int D;
  FILE *fpt,*fpt2;
  name:
	//clrscr();
	printf("\n\n\n\t\t\t----Welcome to XYZ Bank----\n");
	printf("\n\n\t\t\t    ----Staff Mode----");
  printf("\n\n\n\t\t\t   ----fill details----\n\n\n");
  printf("\n\n\t\tEnter your full name::\t");
  fflush(stdin);
  scanf("%s",&add.name);
  printf("\n\n\t\tEnter your address::\t");
  fflush(stdin);
  scanf("%s",&add.address);
//  p3:
  fflush(stdin);
  printf("\n\n\t\tEnter your Date of Birth(dd/mm/yyyy)::\t");
  scanf("%d/%d/%d",&add.dob.dd,&add.dob.mm,&add.dob.yyyy);
  add.age=(today.yyyy-add.dob.yyyy);
   if(add.age<18)
   {
	 printf("\n\n\tyour are not able to creat\n\taccount yet now/type a valid age");
	 getch();
	// goto p3;
	 menu();
   }
  fflush(stdin);
  printf("\n\n\t\tEnter your phone number::\t");
  scanf("%s",&add.ph_no);
  printf("\n\n\t\tEnter your Aadharr_no::\t");
  scanf("%ld",&add.aadharr_no);
  printf("\n\n\t\tEnter your Account Type::\t");
  printf("\n\n\t\t\tPress 1 for Saveings\n\n\t\t\tPress 2 for Fix\n\n\t\t\tPress 3 for Current\n\n\t\t\tEnter Yor Choice::");
  scanf("%d",&D);
  switch(D)
   {
	 case 1:strcpy(add.acc_type,"Savings");
			break;
	 case 2:strcpy(add.acc_type,"Fix");
			break;
	 case 3:strcpy(add.acc_type,"Current");
			break;
	 default:printf("\n\n\t\t Wrong entry");
   }
  if(strcmp(add.acc_type,"Fix")==0)
	{
	 line:
	 add.year=1;
	 printf("\n\n\t\tSet years(>5)::\t");
	 scanf("%d",&add.year);
	 if(add.year<=5)
	  {
	   printf("\n\n\t\tInvalid entry");
	   goto line;
	  }
	}
   else add.year=1;
  printf("\n\n\t\tEnter your citizenship::\t");
  fflush(stdin);
  gets(add.citizenship);
  add.acc_opened=today;
 fpt2=fopen("customer.dat","rb+");
 while(!feof(fpt2))
  {
  fread(&add2,sizeof(add2),1,fpt2);
  }
  add2.acc_no=add2.acc_no+acn2;
  add.acc_no=add2.acc_no;
  fclose(fpt2);
  printf("\n\n\t\tYour Account no::\t%ld",add.acc_no);
  line2:
  printf("\n\n\t\tEnter your Amount(>=1000)::\t");
  scanf("%f",&add.amount);
  if(add.amount<1000)
  {
  printf("Minimum balence is Rs.1000 ");
  goto line2;
  }
 fpt=fopen("customer.dat","ab+");
 fwrite(&add,sizeof(add),1,fpt);
 fclose(fpt);
 fpt=fopen("customer.dat","rb+");
 fseek(fpt,0,SEEK_END);
 fread(&add,sizeof(add),1,fpt);
 printf("\n\n\t\t\t----Customer Details----");
  printf("\n\n\t\tCustomer's Name::\t%s",add.name);
  printf("\n\n\t\tCustomer's Address::\t%s",add.address);
  printf("\n\n\t\tCustomer's Age::\t%d",add.age);
  printf("\n\n\t\tCustomer's Phone no::\t%s",add.ph_no);
  printf("\n\n\t\tCustomer's Account Type::\t%s",add.acc_type);
  printf("\n\n\t\tCustomer's Citizenship::\t%s",add.citizenship);
  printf("\n\n\t\tCustomer's Account No::\t%ld",add.acc_no);
  printf("\n\n\t\tCustomer's Aadharr No::\t%ld",add.aadharr_no);
  printf("\n\n\t\tCustomer's Balence::\t%f",add.amount);
  printf("\n\n\t\tCustomer's Date of Birth::\t%d/%d/%d",add.dob.dd,add.dob.mm,add.dob.yyyy);
  printf("\n\n\t\tAccount opening date::\t%d/%d/%d",add.acc_opened.dd,add.acc_opened.mm,add.acc_opened.yyyy);
 if(strcmp(add.acc_type,"Fix")==0)
  {
  printf("\n\n\t\tAccount Fixed for years::\t%d",add.year);
  }
 else
  {
  printf("\n\n\t\tAccount Fixed for years::\tNot applicable");
 }
 fclose(fpt);
 //fclose(fpt2);
}
void menu()
 {
  int x;
  char ans,ans0;
// do
//  {
 //  clrscr();
   printf("\n\n\n\t\t\t----Welcome to XYZ Bank----\n");
   printf("\n\n\t\t\t    ----Staff Mode----");
   printf("\n\n\n\t\t\t1. Add Account");
   printf("\n\n\t\t\t2. Display Information");
   printf("\n\n\t\t\t3. Transaction");
   printf("\n\n\t\t\t4. Log out");
   printf("\n\n\t\t\t5. Exit");
   printf("\n\n\n\tEnter your choice\t");
   scanf("%d",&x);
   switch(x)
	{
	 case 1:p01:
			add_account();
			printf("\n\n\t\t\t\t----Successfull----");
			printf("\n\n\t\tDo you want to continue Y/N\t");
			fflush(stdin);
			scanf("%s",&ans0);
			if(ans0=='Y'||ans0=='y')
			{ goto p01;}
			else menu();
		  break;
	 case 2:p02:
			display();
			printf("\n\n\t\t\t\t----Successfull----");
			printf("\n\n\t\tDo you want to continue Y/N\t");
			fflush(stdin);
			scanf("%s",&ans0);
			if(ans0=='Y'||ans0=='y')
			{ goto p02; }
			else menu();
		  break;
	 case 3:trn();
		  break;
	 case 4:welcome();
	 case 5:exit(0);
		  break;
	 default:printf("\n\n\t\t Wrong entry");
	}
//   printf("\n\n\t\t\t\t----Successfull----");
//   printf("\n\n\t\tDo you want to continue Y/N\t");
   fflush(stdin);
   scanf("%s",&ans);
//  }
// while(ans=='y'||ans=='Y');
}
void display()
{
  long acnt_no;
  int l=0;
  FILE *fpt1;
 // clrscr();
  fpt1=fopen("customer.dat","rb+");
  rewind(fpt1);
	printf("\n\n\n\t\t\t----Welcome to XYZ Bank----\n");
	printf("\n\n\t\t\t    ----Staff Mode----");
  //	printf("\n\n\t\t\t----Customer Details----");
 printf("\n\n\tEnter Account no::\t");
 scanf("%ld",&acnt_no);
 do
 {
  fread(&add,sizeof(add),1,fpt1);
  if(add.acc_no==acnt_no)
  {
  l=1;
 // clrscr();
  printf("\n\n\t\t\t----Customer Details----");
  printf("\n\n\t\tCustomer's Name::\t%s",add.name);
  printf("\n\n\t\tCustomer's Address::\t%s",add.address);
  printf("\n\n\t\tCustomer's Age::\t%d",add.age);
  printf("\n\n\t\tCustomer's Phone no::\t%s",add.ph_no);
  printf("\n\n\t\tCustomer's Account Type::\t%s",add.acc_type);
  printf("\n\n\t\tCustomer's Citizenship::\t%s",add.citizenship);
  printf("\n\n\t\tCustomer's Account No::\t%ld",add.acc_no);
  printf("\n\n\t\tCustomer's Aadharr No::\t%ld",add.aadharr_no);
  printf("\n\n\t\tCustomer's Balence::\t%f",add.amount);
  printf("\n\n\t\tCustomer's Date of Bisth::\t%d/%d/%d",add.dob.dd,add.dob.mm,add.dob.yyyy);
  printf("\n\n\t\tAccount opening date::\t%d/%d/%d",add.acc_opened.dd,add.acc_opened.mm,add.acc_opened.yyyy);
   if(strcmp(add.acc_type,"Fix")==0)
  {
  printf("\n\n\t\tAccount Fixed for years::\t%d",add.year);
  }
  else printf("\n\n\t\tAccount Fixed for years::\tNot applicable");
  //fclose(fpt1);
  break;
  }
  }
  while(!feof(fpt1));
  fclose(fpt1);
 if(l==0)
 {
  printf("\n\n\t\t\t\tAcc.no don't exist");
  getch();
  menu();

 }
}
void welcome()
{
 int c;
 char ans2,ans5;
 char us_name[30];
 char pass[30];
 //clrscr();
 printf("\n\n\n\t\t\t Enter A to login as Admin \n\n\t\t\t or S to login as Staff \n\n\t\t\t or E to Exit\t");
 scanf("%s",&ans5);
  if(ans5=='A'||ans5=='a')
  {
	printf("\n\n\t\tEnter password\t");
	scanf("%d",&c);
   if(c==1234)
	{
   admin();
	}
   else printf("\n\t\twrong entry");
   getch();
   welcome();
  }
  else if(ans5=='S'||ans5=='s')
  {
   staff();
  }
  else if(ans5=='E')
  {
   exit(0);
  }
}
void trn()
{
 int z;
	//clrscr();
	printf("\n\n\n\t\t\t----Welcome to XYZ Bank----\n");
	printf("\n\n\t\t\t    ----Staff Mode----");
	printf("\n\n\n\t\t\t1. Withdraw");
	printf("\n\n\t\t\t2. Diposit");
	printf("\n\n\t\t\t3. Back to Main menu");
	printf("\n\n\t\t\t4. Exit");
	printf("\n\n\n\t\tEnter your choice\t");
 scanf("%d",&z);
 switch(z)
  {
	case 1:withdrwa();
		   break;
	case 2:diposite();
		   break;
	case 3:menu();
		   break;
	case 4:exit(0);
   default :printf("\n\n\t\t Wrong entry");
  }
}
void withdrwa()
{
 FILE *fpt3;
 int m=0;
 char ans4;
 long acnt_no2;
 float amount2;
//	clrscr();
	rewind(fpt3);
	printf("\n\n\n\t\t\t----Welcome to XYZ Bank----\n");
	printf("\n\n\t\t\t    ----Staff Mode----");
  fpt3=fopen("customer.dat","ab+");
  rewind(fpt3);
	printf("\n\n\tEnter Account no::\t");
	fflush(stdin);
	scanf("%ld",&acnt_no2);

 while(!feof(fpt3))
 {
   fread(&ac,sizeof(ac),1,fpt3);
   if(ac.acc_no==acnt_no2)
  {
	m=1;
	printf("\n\n\t\tCustomer's name::\t%s",ac.name);
	printf("\n\n\t\tCurrent balance:\t%f",ac.amount);
	if(strcmp(ac.acc_type,"Fix")==0)
	{
	  if((today.yyyy-ac.acc_opened.yyyy)==ac.year && (today.dd-ac.acc_opened.dd)>=0 && (today.mm-ac.acc_opened.mm)>=0)
	  {
		goto line4;
	  }
	 else
	  {
	  printf("\n\n\t\tAccess is denied ");
	  getch();
	  trn();
	  }
  }
	line3:
	line4:
	printf("\n\n\n\t\t\tEnter amount::\t");
	scanf("%f",&amount2);
	if(amount2>ac.amount)
	{
	 printf("\n\n\t\tEnter valid amount");
	 goto line3;
	}
   ac.amount=(ac.amount-amount2);
   if(ac.amount<1000)
   {
	 printf("\n\n\t\tEnter valid amount");
	 goto line3;
   }
	printf("\n\n\t\t\t\t----Successfull----");
	printf("\n\n\t\tYour current balance is=%f",ac.amount);
	printf("\n\n\t\tYour account no. is=%d",ac.acc_no);
   //	fwrite(&ac,sizeof(ac),1,fpt3);
	fprintf(fpt3,"%f",ac.amount);
	break;
  }
 }
//  else
   if(m==0)
   {
	printf("\n\n\t\t\tAccount number don't match");
   }
	printf("\n\n\t\tDo you want to continue ? (Y/N)\t");
	scanf("%s",&ans4);
  if(ans4=='y'||ans4=='Y')
  {
	withdrwa();
  }
  else
  {
	trn();
  }
fclose(fpt3);
}
void diposite()
{
 FILE *fpt4;
// fpos_t filepos;
 char ans3;
 int n6=0;
 long acnt_no3;
 float amount3;
 //clrscr();
	printf("\n\n\n\t\t\t----Welcome to XYZ Bank----\n");
	printf("\n\n\t\t\t    ----Staff Mode----");
  fpt4=fopen("customer.dat","ab+");
  rewind(fpt4);
	printf("\n\n\tEnter Account no::\t");
	scanf("%ld",&acnt_no3);
  while(!feof(fpt4))
{
  fread(&ac,sizeof(ac),1,fpt4);
  if(ac.acc_no==acnt_no3)
 {
  // fgetpos(fpt4,&filepos);
	n6=1;
	printf("\n\n\t\tCustomer's name::\t%s",ac.name);
	printf("\n\n\t\tCurrent balance:\t%f",ac.amount);
	printf("\n\n\n\t\tEnter amount::\t");
	scanf("%f",&amount3);
  ac.amount=(ac.amount+amount3);
	printf("\n\n\t\t\t\t----Successfull----");
	printf("\n\n\t\tYour current balance is=%f",ac.amount);
//  fwrite(&ac,sizeof(ac),1,fpt4);
	fprintf(fpt4,"%f",&ac.amount);
   break;
  }
 }
  if(n6==0)
   {
   printf("\n\n\t\t\tAccount no don't match");
   }
   printf("\n\n\t\tDo you want to continue ? (Y/N)\t");
   scanf("%s",&ans3);
  if(ans3=='y'||ans3=='Y')
  {
   diposite();
  }
  else
  {
   trn();
  }
fclose(fpt4);
}
void staff()
{
 char ans2;
 int c=0;
 char us_name[30];
 char pass[30];
 FILE *fp;
 pass2:
//	clrscr();
	printf("\n\n\n\t\t\t----Welcome to XYZ Bank----\n");
	printf("\n\n\t\t\t    ----Staff Mode----");
	printf("\n\n\t\tEnter your user name::\t");
	fflush(stdin);
	scanf("%s",&us_name);
	printf("\n\t\tEnter your Password::\t");
	fflush(stdin);
	scanf("%s",&pass);
  fp=fopen("staff.dat","r");
   do
   {
	 fscanf(fp,"%s\t%s\n",&ad.st_name,&ad.pswrd);
	 if(strcmp(us_name,ad.st_name)==0 && strcmp(pass,ad.pswrd)==0)
	 {
	   c=1;
	   menu();
	   break;
	 }
   }
   while(!feof(fp));
	  if(c==0)
	  {
	  printf("\n\n\tUser Name & Password dosn't matches\n");
	  printf("\n\tPress 'a' to continue/others to exit\t");
	  fflush(stdin);
	  scanf("%s",&ans2);
	  if(ans2=='a'||ans2=='A')
		{
		 goto pass2;
		}
	  else
	   {
	   exit(0);
	   }
	  }

   fclose(fp);
}
void admin()
{
  int ans6;
  char a,q[10],u[10],g[10],h[10];
  FILE *fp1,*fp2,*fp3,*fpt3;
 // clrscr();
  printf("\n\n\n\t\t\t----Welcome to XYZ Bank----\n");
 // s1:
  printf("\n\n\t\t\t    ----ADMIN Mode----");
  printf("\n\n\t\t1 Add Staff Account.\n\n\t\t2 Del Staff Account.\n\n\t\t3 View all staff.\n\n\t\t4 View all customer\n\n\t\t5 Log out.\n\n\t\t6 Exit");
  printf("\n\n\n\t\tEnter your choice\t");
  scanf("%d",&ans6);
  switch(ans6)
   {
	case 1:s1:
		   fp1=fopen("staff.dat","a+");
		   printf("\n\n\t\tEnter Staff name::\t");
		   fflush(stdin);
		   scanf("%s",&ad2.st_name);
		   printf("\n\n\t\tEnter Password::\t");
		   scanf("%s",&ad2.pswrd);
		   fprintf(fp1,"%s\t%s\n",ad2.st_name,ad2.pswrd);
		   fclose(fp1);
		   printf("\n\n\t\t\t\t----Successfull----");
	   //  printf("\n\n\t\t\t\t----Successfull----");
		   printf("\n\n\t\tDo you want to continue Y/N\t");
			fflush(stdin);
			scanf("%s",&a);
			if(a=='Y'||a=='y')
			{ goto s1; }
			else admin();
	 //	   goto s1;
	 case 2:
		   fp2=fopen("staff.dat","r+");
		   rewind(fp2);
		   printf("\n\t\t\tEnter staff name::\t");
		   scanf("%s",&q);
		   printf("\n\t\t\tEnter the password::\t");
		   scanf("%s",&u);
		   fp3=fopen("te2.dat","a+");
		   rewind(fp3);
		   while(!feof(fp2))
			{
			  fscanf(fp2,"%s\t%s\n",&g,&h);
			  if(strcmp(q,g)!=0 && strcmp(u,h)!=0)
			  {
			   fprintf(fp3,"%s\t%s\n",g,h);
			  }
			}
		   remove("staff.dat");
		   rename("te2.dat","staff.dat");
		   fclose(fp3);
		   fclose(fp2);
		   break;
	case 3:
			 printf("\n\t\t\t\5name\5\t\5password\5\n");
			 fp3=fopen("staff.dat","r");
			 rewind(fp3);
			 while(!feof(fp3))
			 {
			   fscanf(fp3,"%s\t%s\n",&g,&h);

			   printf("\n\t\t\t%s\t%s\n",g,h);
			   getche();
			 }
			 fclose(fp3);
			admin();
	case 4: printf("\n\t\t\t\5name\5\t\5ph.number\5\t\5balance\5\n");
			 fpt3=fopen("customer.dat","rb");
			 rewind(fpt3);
			 while(!feof(fpt3))
			 {
			   fread(&add,sizeof(add),1,fpt3);

			   printf("\n\t\t\t%s \t%s \t%f\n",add.name,add.ph_no,add.amount);
			   getche();
			 }
			 fclose(fpt3);
			 admin();
	case 5:welcome();
	case 6:exit(0);
   //	default:printf("\n\t\ttype a valid key");admin();
	}
   if(ans6!=1||ans6!=2||ans6!=3||ans6!=4||ans6!=5||ans6!=6)
	{
	  printf("\n\t\ttype a valid key");
	  getch();
	  admin();
	 }
  }
void about()
{
 int o=0;
 while(o!=2)
{
// clrscr();
 printf("\n\n\t\t\t\tProcessing...");
 printf("\n\n\n\t\t\t\t| | | | | | | ");
 printf("\n\n\n\n\t\t\tPlease wait...");
// delay(250);
// clrscr();
 printf("\n\n\t\t\t\tProcessing...");
 printf("\n\n\n\t\t\t\t/ / / / / / / ");
 printf("\n\n\n\n\t\t\tPlease wait...");
// delay(250);
// clrscr();
 printf("\n\n\t\t\t\tProcessing...");
 printf("\n\n\n\t\t\t\t- - - - - - - ");
 printf("\n\n\n\n\t\t\tPlease wait...");
// delay(250);
// clrscr();
 printf("\n\n\t\t\t\tProcessing...");
 printf("\n\n\n\t\t\t\t\\ \\ \\ \\ \\ \\ \\ ");
 printf("\n\n\n\n\t\t\tPlease wait...");
// delay(250);
// clrscr();
 printf("\n\n\t\t\t\tProcessing...");
 printf("\n\n\n\t\t\t\t| | | | | | | ");
 printf("\n\n\n\n\t\t\tPlease wait...");
 o++;
 }
// clrscr();
 printf("\n\n\n\n\n\n\t\tTHIS IS A MINI BANKING PROJECT ON LANGUAGE C");
 printf("\n\n\n\n\t\t\t      :: Project Guied ::");
 printf("\n\n\t\t            __Moushumii Pramanik__");
 printf("\n\n\n\n\t\t\t       :: Institute ::");
 printf("\n\n\t\t        __APTECH COMPUTER EDUCATION__");
 printf("\n\n\n\n\t\t\t     __All Right Recived__");
 printf("\n\n\n\n\n\n\t\t Press any key to continue....");
 getch();
}


