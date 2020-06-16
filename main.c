#include <stdio.h>
#include <stdlib.h>
#include <conio.h>                  //Sudharsan: void mv_select(), void view_all_transcation(), void insert_movie()
#include <time.h>                   //Rohith: void seat(), void cancel(), void printtickect()
#include <string.h>                 //pravek: login_admin()/login_guest()
                                    //priyavarman: welcome(),thank_u()
                                    //javin:change_price,sturcture,menu_ad(),menu_

//Define
#define ENTER 13
#define TAB 9
#define BKSP 8
#define SPACE 32

//Structures
struct ticket                    //This structure contains the ticket details and will be written to a file transactions.bin
{
    char m_name[100];
    int m_id;
    int m_noofseats;
    char m_time[50];
    int m_seats[100];
} ticket1,ticket2;              //ticket1 is for receiving info from user and to store it in bin file and ticket 2 is to read from the bin file

struct movie                  //This structure contains the movie details .For the use of admin
{
    char moviename[100];
}m1,m2;                     //m1 is for writing and m2 for reading into the file

//function prototype
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
void seat();
void printticket();


//Global Variable
time_t t;
int price=150;          //this is the predefined price and can be changed by the function change_price



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
FILE *fptr2;                                                       //this declares the file handling variable fptr2

void mv_select()
{
    int choice;
    system("cls");
    time(&t);
    printf("=====================================================================\n");
    printf("\t\t        Movie Ticket Booking\n");
    printf("=====================================================================\n\n");
    printf("\t\t\t *Movie Selection\n");
    fptr2=fopen("movielist.bin","r");//this opens the file movielist.bin and links it to file handling variable fptr2
    int i=1;
    while(fread(&m2,sizeof(struct movie),1,fptr2)==1)              //this line reads the contents of bin file movielist.bin and stores it in m2
                                                                   //the loop will be run as long the file is not over (same as !feof())
    {

        printf("\t\t Press <%d> %s\n",i,m2.moviename);              //this prints the movies in movielist.bin
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
    if (choice==100){
        system("clear");
        welcome();
    }



}
int change_price(int price)
{
    printf("\n=====================================================================\n\n");
    printf("\t\t\t *Change Price*\n");
    printf("Enter the New price: ");
    scanf("%d",&price);
    return price;
}
FILE *fptr;            //declaration for file handling variable fptr
void insert_movie()
{
    system("cls");
    printf("enter movie name:\n");
    scanf("%s",m1.moviename);
    fptr=fopen("movielist.bin","ab"); //links fptr to movielist.bin in append mode
    fwrite(&m1,sizeof(struct movie),1,fptr);//writes the contents of object m1 of structure movie to movielist.bin through fptr
    printf("movie added successfully");
    system("pause");
    fclose(fptr);         //unlinks fptr
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
    fptr=fopen("transactions.bin","r");                        //links fptr to transactions.bin
    fptr2=fopen("temp.bin","w");                               //links fptr2 to temp.bin
    int canid;
    printf("enter booking id which you wish to cancel\n");
    scanf("%d",&canid);
    while(fread(&ticket2,sizeof(struct ticket),1,fptr)==1)      //reads transactions.bin till the end
    {

       if(canid==ticket2.m_id)                                    //if a match is found it prints the match and asks for confirmation
        {


            printf("Booking ID:%d\n",ticket2.m_id);
            printf("Movie Name:%s\n",ticket2.m_name);
            printf("No of seats:%d\n",ticket2.m_noofseats);
            for(int i=0;i<ticket2.m_noofseats;i++)
                printf("seat no :%d\n",ticket2.m_seats[i]);
            printf("time of booking:%s\n",ticket2.m_time);
        }
     }


     fclose(fptr);                                             //unlinks fptr
     fptr=fopen("transactions.bin","r");                       //links fptr to transactions.bin
                                                               //the closing and opening is done to reset curson location and to read again from first(can also use seekg)

     printf("Are you sure you want to cancel?(y/n)\n");
     char c;
     c=getch();
     if(c=='y')
     {

         while(fread(&ticket2,sizeof(struct ticket),1,fptr)!=NULL)//reads till the last
         {

             if(canid==ticket2.m_id)                              //if a match is found skips the next line and goes to nect iteration
                continue;
             fwrite(&ticket2,sizeof(struct ticket),1,fptr2);      //if its not a match,writes the contents to temp.bin
         }                                                        //this allows the program to remove the ticket
     }
    else if(c=='n')

     {
         printf("operation cancelled\n");
         system("pause");
         menu_guest();
     }
                                                   //rename() can be used at this point but for some reason it didnt work
    fclose(fptr);
    fclose(fptr2);
    fptr=fopen("transactions.bin","w");                            //the next few lines are to copy the contents from temp.bin to transactions.bin
    fptr2=fopen("temp.bin","r");                                   //this had to be done because rename() didnt work
    while(fread(&ticket2,sizeof(struct ticket),1,fptr2)==1)
    {
        fwrite(&ticket2,sizeof(struct ticket),1,fptr);
    }
    fclose(fptr);
    fclose(fptr2);

    printf("ticket cancelled");
    system("pause");
     }


void printticket()                                                   //This function just stores the ticket contents in transactions.bin as soon as its been called
{
    fptr=fopen("transactions.bin","ab");
    fwrite(&ticket1,sizeof(struct ticket),1,fptr);
    system("pause");
    fclose(fptr);
}


void view_all_transactions()                                             //TO reads all the contents from transactions.bin file and to display it with proper names
{
   fptr=fopen("transactions.bin","r");                                   //links fptr to transactions.bin
   system("cls");
   time(&t);
   printf("=====================================================================\n");
   printf("\t\t        Movie Ticket Booking\n");
   printf("=====================================================================\n\n");
   while(fread(&ticket2,sizeof(struct ticket),1,fptr)==1)               //reads from transactions.bin until the file ends and stores the values in tickte2
   {

       printf("Booking ID:%d\n",ticket2.m_id);                          //the next few statements are just to print ticket2
       printf("Movie Name:%s\n",ticket2.m_name);
       printf("no of seats:%d\n",ticket2.m_noofseats);
       for(int i=0;i<ticket2.m_noofseats;i++)
        printf("seat no :%d\n",ticket2.m_seats[i]);
       printf("time of booking:%s\n",ticket2.m_time);
   }
   printf("\t\t\t  *all transactions\n");
   fclose(fptr);                                                          //unlinks fptr

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
   printf("\t\t\t  *Select seat (Max 10)*\n");
   int seats=1;
   for(i=0;i<10;i++){
    for(int j=0;j<10;j++){
        printf("%d\t",seats);
        seats++;
    }
    printf("\n\n");
   }

   for(i=0;i<ticket1.m_noofseats;i++){
       printf("Enter the seat number:");
      scanf("%d",&pos[i]);
   }
   for(i=0;i<ticket1.m_noofseats;i++){
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

       srand(time(NULL));
       printf("your ticket has been successfully booked\n");
       ticket1.m_id=rand();
       strcpy(ticket1.m_time,ctime(&t));
       printf("\n\n");
       printf("\t-----------------Movie Ticket Booking----------------\n");
       printf("=====================================================================\n\n");
       printf("Booking ID:%d\n",ticket1.m_id);
       printf("Movie Name:%s\n",ticket1.m_name);
       printf("No of seats:%d\n",ticket1.m_noofseats);
       for(int i=0;i<ticket1.m_noofseats;i++)
            printf("seat no :%d\n",ticket1.m_seats[i]);
        printf("time of booking:%s\n",ticket1.m_time);
       printticket();                                                //booking id

     }
   else if (choice==2)
       thank_u();

}
