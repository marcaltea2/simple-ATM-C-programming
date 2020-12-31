#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#define MAX 100

float balance = 0;
int amountTowithdraw;
int amountTodeposit;
int choice;
void anothertransaction();
int transaction();
void deposit();
void withdraw();
void wreceipt();
void dreceipt();
int main()
{
    insertcard();
    while (1)
    {
    switch(transaction())
    {
    case 1: system("cls"); withdraw(); anothertransaction(); break;
    case 2: system("cls"); deposit(); anothertransaction(); break;
    case 3: system("cls"); printf("your account balance is: %6.2f pesos\n\n",balance); anothertransaction(); break;
    default: printf("Invalid choice.");
    getch();

    }
    }
}
int transaction()
{
    system("cls");
    printf("Choose services you want \n\n");
    printf("1.)Withdraw \n");
    printf("2.)Deposit \n");
    printf("3.)Balance \n");
    printf("select a transaction:");
    scanf("%d",&choice);
    return choice;
}
void insertcard()
{
     FILE *fp;
     printf("WELCOME TO MY BANK \n\n");
     printf("To begin your transaction \nPlease insert your card...");
        do
        {
        fp=fopen("G:\pin.txt","r");
        }
        while (fp==NULL);
        fclose(fp);
}

void withdraw()
{
    printf("Enter specific amount:");
    scanf("%d",&amountTowithdraw);


    if(amountTowithdraw %100 != 0)
    {
        printf("please enter the amount in multiples of 100 \n\n");
    }
    else if(amountTowithdraw>balance)
    {
        printf("sorry, you don't have insufficient balance \n\n ");
    }
    else if(amountTowithdraw<=0)
    {
        printf("invalid amount");

    }
    else
    {
        balance=balance-amountTowithdraw;
        printf("\n\n\nThank you\nTransaction completed\nPlease take your receipt");
        printf("\n\nPress enter to continue");
        getch();
        wreceipt();
    }


}
void deposit()
{
    printf("Enter specific amount:");
    scanf("%d",&amountTodeposit);


    if(amountTodeposit %100 !=0)
    {
        printf("please enter the amount in multiples of 100");
    }
    else if(amountTodeposit<=0)
    {
        printf("invalid amount");

    }
    else
    {
    balance = balance + amountTodeposit;
    printf("\n\n\nThank you\nTransaction completed\nPlease take your receipt");
    printf("\n\nPress enter to continue");
    getch();
    dreceipt();
    }

}
void anothertransaction()
{
    int transaction1;
    printf("\n\nDo you wish to have another transaction? press 1 to continue and 2 to exit:");
    scanf("%d",&transaction1);

    if(transaction1 == 1);
    {
        transaction();
    }
}
void wreceipt()
{
    time_t t;
    time(&t);
    system("cls");
    printf("ATM TRANSACTION RECORD \n");
    printf("Date and Time: %s \n",ctime(&t));
    printf("Transaction: Withdraw \n");
    printf("amount: %d pesos \n",amountTowithdraw);
    printf("Current Balance: %6.2f pesos \n",balance);
    printf("Available balance: %6.2f pesos \n",balance);
}
void dreceipt()
{
    time_t t;
    time(&t);
    system("cls");
    printf("ATM TRANSACTION RECORD \n");
    printf("Date and Time: %s \n",ctime(&t));
    printf("Transaction: Deposit \n");
    printf("amount: %d \n",amountTodeposit);
    printf("Current Balance: %6.2f pesos \n",balance);
    printf("Available balance: %6.2f pesos \n",balance);
}
