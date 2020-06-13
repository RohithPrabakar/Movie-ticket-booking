#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include<string.h>

//Define
#define ENTER 13
#define TAB 9
#define BKSP 8
#define SPACE 32
struct ticket
{
    char m_name[100];
    int m_id;
    int m_noofseats;
    char m_time[50];
    int m_seats[100];
} ticket1,ticket2;
struct movie
{
    int number;
    char moviename[100];
    int price;
}m1,m2;

//function declaration
void welcome();
void login_admin();
void login_guest();
void thank_u();
void menu_ad();
void menu_guest();
void mv_select();
int change_price(int price);
void insert_movie();
void view_all_transection();


//Global Variable
time_t t;
int price=150;



int main()
{
    welcome();
    return 0;
}

void welcome()
{
    time(&t);
    char choice;
    printf("=====================================================================\n");
    printf("\t\t  Welcome to Movie Ticket Booking\n");
    printf("=====================================================================\n\n");
    printf("\t\t  Press <1> Admin\n");
    printf("\t\t  Press <2> Guest\n");
    printf("\t\t  Press <3> Exit\n\n\n");
    printf("---------------------------------------------------------------------\n");
    printf("%s",ctime(&t));
    printf("---------------------------------------------------------------------\n");
    choice=getch();

    switch(choice)
    {
    case '1':
        login_admin();
        break;
    case '2':
        login_guest();
        break;
    case '3':
        thank_u();
        break;
    default:
        system("cls");
        printf("\n\n=================================================================\n");
        printf("/**INVALID KEYWORD. PLEASE ENTER A VALID KEYWORD TO CHOOSE.**/ \n");
        printf("PRESS ANY KEY\n");
        getch();
        system("cls");
        welcome();
    }
}

void login_admin()
{
    system("cls");
    char User_name[100], password[100],ch,usr_nm[100]="Admin",pass_wd[100]="pass";
    int pos;
    time(&t);
    printf("=====================================================================\n");
    printf("\t\t  Welcome to Movie Ticket Booking\n");
    printf("=====================================================================\n\n");
    printf("\t\t\t  *Login Admin*\n\n");
    printf("\tUser Name: ");
    scanf("%s",User_name);
    printf("\tPassword: ");
    while(1)
    {
        ch=getch();
        if(ch==ENTER)
        {
            password[pos]='\0';
            break;
        }
        else if(ch==BKSP)
        {
            if(pos>0)
            {
              pos--;
              printf("\b \b");
            }
        }
        else if(ch==TAB||ch==SPACE)
        {
            continue;
        }
        else
        {
            password[pos]=ch;
            pos++;
            printf("*");
        }
    }
    if(strcmp(usr_nm,User_name)==0 && strcmp(pass_wd,password)==0)
    {
        system("cls");
        printf("=====================================================================\n");
        printf("\t\t            Movie Ticket Booking\n");
        printf("=====================================================================\n\n");
        printf("\t            You have Successfully logged in\n");
        printf("\t                    PRESS ANY KEY\n\n\n");
        printf("---------------------------------------------------------------------\n");
        printf("%s",ctime(&t));
        printf("---------------------------------------------------------------------\n");
        getch();
        menu_ad();
    }
    else
    {
        system("cls");
        printf("=====================================================================\n");
        printf("\t\t            Movie Ticket Booking\n");
        printf("=====================================================================\n\n");
        printf("\t\tSorry, Password or User name is incorrect\n");
        printf("\t\t           PRESS ANY KEY\n\n\n");
        printf("---------------------------------------------------------------------\n");
        printf("%s",ctime(&t));
        printf("---------------------------------------------------------------------\n");
        getch();
        login_admin();
    }

}

void login_guest()
{
    system("cls");
    char User_name[100], password[100],ch,usr_nm[100]="Guest",pass_wd[100]="pass";
    int pos;
    time(&t);
    printf("=====================================================================\n");
    printf("\t\t  Welcome to Movie Ticket Booking\n");
    printf("=====================================================================\n\n");
    printf("\t\t\t  *Login Guest*\n\n");
    printf("\tUser Name: ");
    scanf("%s",User_name);
    printf("\tPassword: ");
    while(1)
    {
        ch=getch();
        if(ch==ENTER)
        {
            password[pos]='\0';
            break;
        }
        else if(ch==BKSP)
        {
            if(pos>0)
            {
              pos--;
              printf("\b \b");
            }
        }
        else if(ch==TAB||ch==SPACE)
        {
            continue;
        }
        else
        {
            password[pos]=ch;
            pos++;
            printf("*");
        }
    }
    if(strcmp(usr_nm,User_name)==0 && strcmp(pass_wd,password)==0)
    {
        system("cls");
        printf("=====================================================================\n");
        printf("\t\t            Movie Ticket Booking\n");
        printf("=====================================================================\n\n");
        printf("\t            You have Successfully logged in\n");
        printf("\t                    PRESS ANY KEY\n\n\n");
        printf("---------------------------------------------------------------------\n");
        printf("%s",ctime(&t));
        printf("---------------------------------------------------------------------\n");
        getch();
        menu_guest();
    }
    else
    {
        system("cls");
        printf("=====================================================================\n");
        printf("\t\t            Movie Ticket Booking\n");
        printf("=====================================================================\n\n");
        printf("\t\tSorry, Password or User name is incorrect\n");
        printf("\t\t           PRESS ANY KEY\n\n\n");
        printf("---------------------------------------------------------------------\n");
        printf("%s",ctime(&t));
        printf("---------------------------------------------------------------------\n");
        getch();
        login_guest();
    }
}

void thank_u()
{
    system("cls");
    printf("\n\n\n");
    printf("=========================================================================\n");
    printf("\t\t Thanks For Visiting\n");
    printf("\t     Movie Ticket Booking System\n");
    printf("=========================================================================\n");
}

void menu_ad()
{
    system("cls");
    time(&t);
    char choice;
    printf("=====================================================================\n");
    printf("\t\t        Movie Ticket Booking\n");
    printf("=====================================================================\n\n");
    printf("\t\t\t *Menu for Admin*\n\n");
    printf("\t\t  Press <1> Insert Movie\n");
    printf("\t\t  Press <2> Change Price\n");
    printf("\t\t  Press <3> View all Transection\n");
    printf("\t\t  Press <4> Exit\n\n");
    printf("---------------------------------------------------------------------\n");
    printf("%s",ctime(&t));
    printf("---------------------------------------------------------------------\n");
    choice=getch();

    switch(choice)
    {
    case '1':
        insert_movie();
        break;
    case '2':
        price=change_price(price);
        menu_ad();
        break;
    case '3':
        view_all_transactions();
        break;
    case '4':
        thank_u();
        break;
    default:
        system("cls");
        printf("\n\n=================================================================\n");
        printf("/**INVALID KEYWORD. PLEASE ENTER A VALID KEYWORD TO CHOOSE.**/ \n");
        printf("PRESS ANY KEY\n");
        getch();
        system("cls");
        menu_ad();
    }


}


void menu_guest()
{
    system("cls");
    time(&t);
    char choice;
    printf("=====================================================================\n");
    printf("\t\t        Movie Ticket Booking\n");
    printf("=====================================================================\n\n");
    printf("\t\t\t *Menu for Guest*\n\n");
    printf("\t\t  Press <1> Purchase ticket\n");
    printf("\t\t  Press <2> Cancel ticket\n");
    printf("\t\t  Press <3> View all Transection\n");
    printf("\t\t  Press <4> Exit\n\n");
    printf("---------------------------------------------------------------------\n");
    printf("%s",ctime(&t));
    printf("---------------------------------------------------------------------\n");
    choice=getch();

    switch(choice)
    {
    case '1':
        purchase();
        break;
    case '2':
        cancel();
        break;
    case '3':
        view_all_transactions();
        break;
    case '4':
        thank_u();
        break;
    default:
        system("cls");
        printf("\n\n=================================================================\n");
        printf("/**INVALID KEYWORD. PLEASE ENTER A VALID KEYWORD TO CHOOSE.**/ \n");
        printf("PRESS ANY KEY\n");
        getch();
        system("cls");
        menu_guest();
    }
}
FILE *fptr2;

void mv_select()
{
    int choice;
    system("cls");
    time(&t);
    printf("=====================================================================\n");
    printf("\t\t        Movie Ticket Booking\n");
    printf("=====================================================================\n\n");
    printf("\t\t\t *Movie Selection\n");
    fptr2=fopen("movielist.bin","r");
    int i=1;
    while(!feof(fptr2))
    {
        fread(&m2,sizeof(struct movie),1,fptr2);
        printf("\t\t Press <%d> %s\n",i,m2.moviename);
        i++;
    }
    fclose(fptr2);
    printf("\t\t  Press <100> Exit\n\n");
    printf("---------------------------------------------------------------------\n");
    printf("%s",ctime(&t));
    printf("---------------------------------------------------------------------\n");
    printf("enter your choice:");
    fptr2=fopen("movielist.bin","r");
    scanf("%d",&choice);
    if(choice!=100)
    { for(i=0;i<choice;i++)
        {
           fread(&m2,sizeof(struct movie),1,fptr2);
        }
        strcpy(ticket1.m_name,m2.moviename);
        printf("enter no of tickets");
        scanf("%d",&ticket1.m_noofseats);
        seat();
    }
    if (choice==100)
        welcome();




/*    scanf("%d",&choice);
    if(choice==1)
       {
           strcpy(ticket1.m_name,"Master");
           printf("enter mumber of tickets");
           scanf("%d",&ticket1.m_noofseats);
           seat();
        }
    else if(choice==2)
        {
            strcpy(ticket1.m_name,"Soorarai pottru");
            printf("enter mumber of tickets");
            scanf("%d",&ticket1.m_noofseats);
            seat();
        }
    else if(choice==100)
        welcome();

}
*/
}
int change_price(int price)
{
    printf("\n=====================================================================\n\n");
    printf("\t\t\t *Change Price*\n");
    printf("Enter the New price: ");
    scanf("%d",&price);
    return price;
}
FILE *fptr;
void insert_movie()
{
    system("cls");
    printf("enter movie name:\n");
    scanf("%s",m1.moviename);
    fptr=fopen("movielist.bin","ab");
    fwrite(&m1,sizeof(struct movie),1,fptr);
    printf("movie added successfully");
    system("pause");
    fclose(fptr);
    menu_ad();
}



void purchase()
{
    system("cls");
    mv_select();
}

void cancel()
{
    system("cls");
    printf("this is to cancel ticket");
}

void printticket()
{
fptr=fopen("transactions.bin","ab");
fwrite(&ticket1,sizeof(struct ticket),1,fptr);
printf("transaction successfull");
system("pause");
fclose(fptr);
}


void view_all_transactions()
{
   fptr=fopen("transactions.bin","r");
   system("cls");
   time(&t);
   printf("=====================================================================\n");
   printf("\t\t        Movie Ticket Booking\n");
   printf("=====================================================================\n\n");
   while(!feof(fptr))
   {
       fread(&ticket2,sizeof(struct ticket),1,fptr);
       printf("Booking ID:%d\n",ticket2.m_id);
       printf("Movie Name:%s\n",ticket2.m_name);
       printf("no of seats:%d\n",ticket2.m_noofseats);
       for(int i=0;i<ticket2.m_noofseats;i++)
        printf("seat no :%d\n",ticket2.m_seats[i]);
       printf("time of booking:%s\n",ticket2.m_time);
   }
   printf("\t\t\t  *all transactions\n");
   fclose(fptr);

}
void seat()
{
   int choice;
   int pos[10],i;
   system("cls");
   time(&t);
   printf("=====================================================================\n");
   printf("\t\t        Movie Ticket Booking\n");
   printf("=====================================================================\n\n");
   printf("\t\t\t  *select seat\n");
   for(i=0;i<ticket1.m_noofseats;i++){
      scanf("%d",&pos[i]);
   }
   for(i=0;i<ticket1.m_noofseats;i++){
      printf("%d",pos[i]);
      ticket1.m_seats[i]=pos[i];
   }
   {
        printf("you have selected the seats:\n");
        for(i=0;i<ticket1.m_noofseats;i++)
        printf("seat no :%d\n",ticket1.m_seats[i]);
        printf("do you wish to confirm?\n");
        printf("\t\t press <1> yes\n");
        printf("\t\t press <2> no\n");
   }
    scanf("%d",&choice);
   if(choice==1)
   {

       printf("your ticket has been successfully booked");
       ticket1.m_id=rand();
       printf("your booking id is: %d",ticket1.m_id);
       strcpy(ticket1.m_time,ctime(&t));
       printticket();                                                //booking id
          thank_u();

     }
   else if (choice==2)
       thank_u();

}
