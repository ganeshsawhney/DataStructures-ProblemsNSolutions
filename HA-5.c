/* Created by Ganesh Sawhney       **
** Email: ganeshsawhney@gmail.com  **
** Github Username: ganeshsawhney  */

#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct linklist
{
int num;
struct linklist *next;
};

typedef struct linklist node;
node *pointcycle(node *start);

int main()
{
node *start1,*temp,*ptr;
int i=0;
char ch='y';
start1=(node *) malloc(sizeof(node));
temp=start1;
i=0;
printf("\n\n\tEnter List 'X' : ");
do
{
printf("\n\n\t\tEnter %d node : ",++i);
scanf("%d",&temp->num);
printf("\n\n\tWant to enter more? : ");
fflush(stdin);
scanf("%c",&ch);
if(ch=='y')
{
temp->next=(node *) malloc(sizeof(node));
temp=temp->next;
}
}while(ch=='y');
start1->next->next->next->next->next=start1->next->next;
ptr=pointcycle(start1);
printf("\n\n\n\tCyclicity cause by : %d",ptr->num);
return 0;
}

node *pointcycle(node *start)
{
node *temp,*temp1;
temp=start;
temp1=start->next;
while(temp1!=NULL)
{
temp=start;
while(temp!=temp1)
{
if(temp1->next==temp)
return temp1;
temp=temp->next;
}
temp1=temp1->next;
}
return NULL;
}
