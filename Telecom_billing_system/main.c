#include<stdio.h>
#include<string.h>
struct info
{
    char name[30];
    char phonenumber[15];
    float usage;
    float totalbill;
};

struct info customer[100];
int customercount = -1;

void menu();
void addNew();
void view();
void temp();
void mod();
void amount();
void delete();

int main()
{
    
    while(1)
    {
        int choice;
        menu();
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            addNew();
            break;
        case 2:
            view();
            break;
        case 3:
            mod();
            break;
        case 4:
            amount();
            break;
        case 5:
            delete();
            break;
        case 6:
            printf("\n Thankyou!!");
            return 0;
        default:
            printf("Wrong choice!!!Please Enter correct choice!\n");
            break;
        }
    }
    return 0;
}

void menu()
{
    //Function to display the menu for user action

    printf("\n1. Add New Record.\n2. View list of Records.\n3. Modify Record.\n4. View Payment\n5. Delete Record.\n6. Exit\n");
    printf("Enter choice: ");
    return ;
}

void addNew()
{
    //Function to add new user in database

    if(customercount < 99 && customercount >= -1)
    {
        if(customercount == -1)
        {
            customercount = 0;
        }
    printf("Enter name : ");
    scanf("%s",customer[customercount].name);
    printf("\nPhone number: ");
    scanf("%s",customer[customercount].phonenumber);
    printf("\nEnter usage: ");
    scanf("%f",&customer[customercount].usage);
    customer[customercount].totalbill = (customer[customercount].usage * 0.1);
    customercount++;
    }
    else if(customercount > 99)
    {
        printf("\nCUSTOMER RECORD SIZE OVER");
    }
    else
    {
        printf("\nNO RECORD FOUND");
    }
}

void view()
{
    //Function to view a user data

    if(customercount == -1 )
    {
        printf("NO RECORD ADDED\n");
    }
    else
    {
    printf("SL.No\t Name\t Phonenumber\t Usage(in mts)\t TotalBill\t\n");
    printf("----------------------------------------------------------------------------------------------------------\n");
    for(int i = 0; i < customercount; i++)
    {
        printf("%d\t%s\t%s\t\t%.2f\t\t%.2f\n",i+1,customer[i].name,customer[i].phonenumber,customer[i].usage,customer[i].totalbill);
    }
    printf("-----------------------------------------------------------------------------------------------------------\n");
    }
}

void mod()
{
    //Function to modify a user usage time 

    char phone[15];int usg;
    printf("Enter the mobile number: ");
    scanf("%s",&phone);
    for(int i = 0; i < customercount; i++)
    {
        if(strcmp(phone,customer[i].phonenumber) == 0)
        {
            printf("Enter new usage time in mins: ");
            scanf("%d",&usg);
            customer[i].totalbill += usg * 0.1;
            return;
        }
    }
    printf("\nRECORD NOT FOUND\n");
}

void amount()
{
    //Function to show the total amount of a user of given mobile number

  char phone[15];
  printf("Enter mobile number: ");
  scanf("%s",&phone);
  for(int i = 0; i < customercount; i++)
  {
    if(strcmp(phone,customer[i].phonenumber) == 0)
    {
        printf("\n%.2f\n",customer[i].totalbill);
        return;
    }
  }
  printf("\nRECORD NOT FOUND\n");
}

void delete()
{
    //Function to delete a user with a given mobile number

    char phone[15];
    printf("Enter mobile number");
    scanf("%s",&phone);
    for(int i = 0; customercount; i++)
    {
        if(strcmp(phone,customer[i].phonenumber) == 0)
        {
            for(int j = i; j < customercount; j++)
            {
                customer[j] = customer[j+1];
            }
            customercount--;
           return;
        }

    }
    printf("\nRECORD NOT FOUND\n");
}