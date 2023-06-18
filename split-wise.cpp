#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <string.h>
#include <unordered_map>
#include <vector>
#define USER_MAX 200
using namespace std;
//This system can store up to number of users
typedef struct
{
    char name[10];
    char password[10];
} User;
User list[USER_MAX];
void writeToFile(User u)
{
    //details.txt need to create a file in your application directory
    FILE *fw = fopen("details.txt","a+");
fprintf(fw,u.name);
fprintf(fw,"\t");
fprintf(fw,u.password);
fprintf(fw,"\n");
}
void registerUser()
{
    char name[10];
    char password[10];
    User user;
    int i;
printf("Enter your name:");
scanf("%s",name);
strcpy(user.name , name);
    // Determine whether there has been a registered user
for(i=0; i<USER_MAX; i++)
    {
        if(0==strcmp(list[i].name ,name))
        {
printf("USER ALREADY EXISTS");
            return;
        }
    }
printf("Enter your password:");
scanf("%s",password);
strcpy(user.password , password);
    //Writing into a file to store details
writeToFile(user);
}
int menu()
{
    int choice;
printf("\t\t\t******************************************\n");
printf("\t\t\t\tSPLIT WISE....MONEY OR FRIENDSHIP??\n");
printf("\t\t\t******************************************\n");
printf("1.Login\n");
printf("2.Register\n");
printf("#.Exit\n");
printf("Login or register???\n");
printf("Enter your choice:\n");
scanf("%d",&choice);
    return choice;
}

User login()
{
    char name[10];
    char password[10];
    User lg;
printf("Enter Name:");
scanf("%s",name);
strcpy(lg.name , name);
printf("Enter Password:");
scanf("%s",password);
strcpy(lg.password,password);
    return lg;
}

int exist(User u)
{
    int i;
for(i=0; i<USER_MAX; i++)
    {
        if(0==strcmp(list[i].name ,u.name) && 0==strcmp(list[i].password ,u.password))
        {
           return 1;
        }
    }
    return -1;
}

unordered_map<string, int>netCash;

//to find minimum 
int min(int a , int b)
{
    if(a<b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

void minimizeCashFlow() 
{
    string maxCreditor = max_element(begin(netCash), end(netCash), [](auto& a, auto&b) { return a.second<b.second; }) -> first;
    string maxDebtor = min_element(begin(netCash), end(netCash), [](auto& a, auto&b) { return a.second<b.second; }) -> first;

    if(!netCash[maxCreditor] && !netCash[maxDebtor]) 
    {
        return;
    }

    int minAmount = min(netCash[maxCreditor], -netCash[maxDebtor]);
netCash[maxCreditor] -= minAmount;
netCash[maxDebtor] += minAmount;

const char *c1 = maxDebtor.c_str();
const char *c2 = maxCreditor.c_str();
printf("\n\n\n %s pays %d to %s",c1,minAmount,c2);
minimizeCashFlow();
}

void main1()
{
    char sender[100];
    char receiver[100];
    char choice,ch;
    unsigned int amount;
    while(true) 
    {
printf("\na: Add Entry\n");
printf ("c: Compute Statement\n"); 
printf("q: Quit\n");
        //scanf("%c",&choice);
cin>>choice;
        switch(choice) 
        {
            case 'a':

                      //  cin>>sender>>receiver;
cout<<"Enter sender name:";
cin>>sender;
cout<<"Enter receiver name:";
cin>>receiver;
cout<<"Enter amount:";
scanf("%d",&amount);
scanf("%c",&ch);
netCash[sender] -= amount;
netCash[receiver] += amount;
                        break;
            case 'c':
minimizeCashFlow();
            default:
                        return;
        }
    }
}
int main()
{
    User test[USER_MAX];
    FILE *fp = fopen("details.txt","r");
    int i=0,det;
    User u;
    char ar[30];
    int k,n,t;
    char a[10];
if(NULL == fp)
    {
printf("FILE NOT FOUND");
        return -1;
    }
for(i=0; i<USER_MAX; i++)
    {
        char uname[10];
        char upassword[10];
fscanf(fp,"%s%s",uname,upassword); 
strcpy(list[i].name ,uname);
strcpy(list[i].password , upassword);
    }

    int choice = menu();
if(1 == choice)
    {

        u=login();
if(1 == exist(u))
        {
            main1();
        }
        else
        {
printf("Wrong Username or Password");
        }
    }
    else if(2==choice)
    {

registerUser();
    }
    else
    {
        return 0;
    }
}
