#include<stdio.h>
#include<conio.h>
dust=0;
int j=0;
struct bank
{
    char fname[100];
    char mname[100];
    char lname[100];
    long int phone;
    long int accountno;
    int bal;
    int dob[3];
    int password;
} b[100];
void addbank()
{
    printf("----WELCOME TO STATE BANK OF INDIA----\n");
    printf("\n\n");
    printf("Enter First Name\n");
    scanf("%s",&b[j].fname);
    printf("Enter Second Name\n");
    scanf("%s",&b[j].mname);
    printf("Enter Last Name\n");
    scanf("%s",&b[j].lname);
    printf("Enter Date of Birth\n");
    scanf("%d%d%d",&b[j].dob[0],&b[j].dob[1],&b[j].dob[2]);
    printf("Enter Phone Number\n");
    scanf("%ld",&b[j].phone);
    printf("Enter Account Number\n");
    scanf("%ld",&b[j].accountno);
    printf("Enter Account Opening Balance\n");
    scanf("%d",&b[j].bal);
    printf("Create A Password Only In Numbers\n");
    scanf("%d",&b[j].password);
    clrscr();
}
void search()
{
    int k,accountno,pass,f;
    printf("Enter Customer Account Number\n");
    scanf("%d",&accountno);
    printf("Enter Password\n");
    scanf("%d",&pass);
    clrscr();
    for(k=0; k<100; k++)
    {
        if(accountno==b[k].accountno)
        {
            if(pass==b[k].password)
            {
                printf("NAME            %s %s %s\n",b[k].fname,b[k].mname,b[k].lname);
                printf("Contact         %ld\n",b[k].phone);
                printf("Date Of Birth   %d-%d-%d\n",b[k].dob[0],b[k].dob[1],b[k].dob[2]);
                printf("Account Number  %ld\n",b[k].accountno);
                printf("Account Balance %d\n",b[k].bal);
                f=1;
            }
            else
            {
                printf("Wrong Password\n");
                break;
            }

        }

    }
    if(f!=1)
    {
        printf("Wrong Account Number\n");
    }
}
void credit()
{
    int amount,n;
    printf("Enter Account Number\n");
    scanf("%d",&n);
    printf("Enter Amount To Add\n");
    scanf("%d",&amount);
    clrscr();
    for(int j=0; j<100; j++)
    {
        if(n==b[j].accountno)
        {
            b[j].bal=b[j].bal+amount;
            printf("\a");
        }
    }
}
void debit()
{
    int amount,n,found;
    printf("Enter Account Number\n");
    scanf("%d",&n);
    printf("Enter Amount To Withdraw\n");
    scanf("%d",&amount);
    clrscr();
    for(int j=0; j<100; j++)
    {

        if(n==b[j].accountno)
        {
            if(b[j].bal>0&&b[j].bal>=amount)
            {
                b[j].bal=b[j].bal-amount;
                printf("\a");
            }
            else
            {
                found=0;
            }
        }

    }
    if(found==0)
    {
        printf("Not Enough Balance\n");
    }
}
void change()
{
    int account,k,pass,new;
    long int phone;
    printf("Enter Account Number\n");
    scanf("%d",&account);
    printf("Enter Your Mobile Number\n");
    scanf("%ld",&phone);
    for(k=0; k<100; k++)
    {
        if(account==b[k].accountno && phone==b[k].phone)
        {
            printf("Enter Your Old Password\n");
            scanf("%d",&pass);
            if(pass==b[k].password)
            {
                printf("Enter New Password");
                scanf("%d",&new);
                printf("Conform Your password");
                scanf("%d",&new);
                b[k].password=new;
            }
            else
            {
                printf("Invalid Password Try Again");
            }
        }
    }
}



void main()
{
    do
    {
        int n;
        printf("\n\n");
        printf("Select An Option\n");
        printf("1.Add Bank Account\n");
        printf("2.Search Customer\n");
        printf("3.Credit System\n");
        printf("4.Withdrawl System\n");
        printf("5.Change Password\n");
        scanf("%d",&n);
        clrscr();
        switch(n)
        {
        case 1:
            addbank();
            break;
        case 2:
            search();
            break;
        case 3:
            credit();
            break;
        case 4:
            debit();
            break;
        case 5:
            change();
            break;
            }
        j++;
    } while(dust==0);
}