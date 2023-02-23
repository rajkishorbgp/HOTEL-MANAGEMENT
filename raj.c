#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int indx = 0;

struct room
{
    int roomNo;
    char name[15];
    char address[30];
    char date[15];
    char mob[15];
    char aadh[16];
} rb[200];

void roomBook();
int isEmpty(int);

void roomStatus();
void display(int);
void advancBook();
void information(int);
void editData(int);
void main()
{
    int clock = 0;
    do
    {
        char oldUserName[10] = "r";
        char oldPassword[10] = "r";
        char userName[10], password[10];

        printf("Enter the user name: ");
        scanf("%s", &userName);

        if (!(strcmp(oldUserName, userName)))
        {
            printf("Enter the password: ");
            scanf("%s", &password);
            if (!(strcmp(oldPassword, password)))
            {
                int option;
                do
                {

                    printf("\n\t\tWELCOME TO HOTEL MANAGEMENT PROJECT\n ");
                    printf("\t\t_______________________________________ ");
                    printf("\n\t\t1. Press 1 to book a room              ");
                    printf("\n\t\t2. Press 2 to view all rooms status    ");
                    printf("\n\t\t3. Press 3 to advance room booking    ");
                    printf("\n\t\t4. Press 4 to view customer information");
                    printf("\n\t\t5. Press 5 to edit the data            ");
                    printf("\n\t\t6. Enter 0 to exit                    ");
                    printf("\n\t\t______________________________________");
                    printf("\nChoose the option: ");
                    scanf("%d", &option);
                    switch (option)
                    {
                    case 0:
                        exit(0);
                        break;
                    case 1:
                    {
                        roomBook();
                    }
                    break;
                    case 2:
                        roomStatus();
                        break;
                    case 3:
                        advancBook();
                        break;
                    case 4:
                    {
                        int n;
                        printf("Enter the room no: ");
                        scanf("%d", &n);
                        information(n);
                    }
                    break;
                    case 5:
                    {
                        int n;
                        printf("Enter the room no: ");
                        scanf("%d", &n);
                        editData(n);
                    }
                    break;
                    default:
                        printf("\n\tEnter the correct option.!!!!!!!!\n");
                        break;
                    }
                } while (option);
            }
            else
            {
                printf("\nYour password is incorrect.!");
                clock++;
                printf("\nyour last attempt %d/3\n", clock);
            }
        }
        else
        {
            printf("\nYour UserName is incorrect.!");
            clock++;
            printf("\nyour last attempt %d/3\n", clock);
        }
    } while (!(3 == clock));
}

void roomBook()
{
    int num, c;
    printf("\nEnter room number: ");
    scanf("%d", &num);
    fflush(stdin); // clear the memory buffer
    if (isEmpty(num))
    {
        char name[20], address[30];
        char aadh[16], mob[10], date[10];
        rb[indx].roomNo = num;

        printf("Enter the name: ");
        gets(name);
        strcpy(rb[indx].name, name);

        printf("Enter the Date: ");
        gets(date);
        strcpy(rb[indx].date, date);

        printf("Enter the addresss: ");
        gets(address);
        strcpy(rb[indx].address, address);

        printf("Enter the Mobile no: ");
        gets(mob);
        strcpy(rb[indx].mob, mob);

        printf("Enter the aadhar no: ");
        gets(aadh);
        strcpy(rb[indx].aadh, aadh);

        indx++;
    }
    else
    {
        printf("\nROOM ALREADY BOOKED");
    }
}
int isEmpty(int num)
{
    for (int i = 0; i < indx; i++)
    {
        if (indx > num)
        {
            return 0;
        }
    }
    return 1;
}

void roomStatus()
{
    for (int i = 0; i < indx; i++)
    {
        display(i);
    }
}

void display(int idx)
{
    printf("\nRoom number: %d", rb[idx].roomNo);
    printf("\nName : %s", rb[idx].name);
    printf("\nMobile number: %s", rb[idx].mob);
    printf("\nAdhar card number: %s", rb[idx].aadh);
    printf("\nAddress: %s", rb[idx].address);
    printf("\nDate: %s", rb[idx].date);
    printf("\n-----------------------\n");
}

void advancBook()
{

    rb[indx].roomNo = 001;
    strcpy(rb[indx].name, "Akash");
    strcpy(rb[indx].date, "10/02/2023");
    strcpy(rb[indx].address, "MIT");
    strcpy(rb[indx].mob, "99999999999");
    strcpy(rb[indx].aadh, "00054455998");
    indx++;
    rb[indx].roomNo = 002;
    strcpy(rb[indx].name, "Iftekhar");
    strcpy(rb[indx].date, "30/01/2023");
    strcpy(rb[indx].address, "MIT college ");
    strcpy(rb[indx].mob, "99999999999");
    strcpy(rb[indx].aadh, "00054455998");
    indx++;
    rb[indx].roomNo = 003;
    strcpy(rb[indx].name, "Raj");
    strcpy(rb[indx].date, "12/02/2023");
    strcpy(rb[indx].address, "MIT college");
    strcpy(rb[indx].mob, "99999999999");
    strcpy(rb[indx].aadh, "00054455998");
    indx++;
}

void information(int num)
{
    for (int i = 0; i < indx; i++)
    {
        if (rb[i].roomNo == num)
        {
            display(i);
        }
    }
}
void editData(int num)
{
    for (int i = 0; i < indx; i++)
    {
        if (rb[i].roomNo == num)
        {
            char name[20], address[30];
            char aadh[16], mob[10], date[10];
            rb[i].roomNo = num;
            fflush(stdin);
            printf("Enter the name: ");
            gets(name);
            strcpy(rb[i].name, name);

            printf("Enter the Date: ");
            gets(date);
            strcpy(rb[i].date, date);

            printf("Enter the addresss: ");
            gets(address);
            strcpy(rb[i].address, address);

            printf("Enter the Mobile no: ");
            gets(mob);
            strcpy(rb[i].mob, mob);

            printf("Enter the aadhar no: ");
            gets(aadh);
            strcpy(rb[i].aadh, aadh);
        }
    }
}