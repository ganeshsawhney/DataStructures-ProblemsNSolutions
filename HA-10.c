/* Created by Ganesh Sawhney       **
** Email: ganeshsawhney@gmail.com  **
** Github Username: ganeshsawhney  */

#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct linklist
{
int data;
struct linklist *next;
};
typedef struct linklist node;
node *sortlist(node *source);

int main()
{
node *start,*temp,*ptr;
int i;
char ch='y';
start=(node *) malloc(sizeof(node));
start->next=NULL;
i=0;

do
{
printf("\n\n\tEnter %d node : ",++i);
scanf("%d",&start->data);
printf("\n\n\tWant to enter more? : ");
fflush(stdin);
scanf("%c",&ch);
if(ch=='y')
{
ptr=(node *) malloc(sizeof(node));
ptr->next=start;
start=ptr;
}
}while(ch=='y');

temp=start;
printf("\n\n\tList is :\n\n\t\t");
while(temp!=NULL)
{
printf("%d -> ",temp->data);
temp=temp->next;
}
printf("\b\b \b\b ");
temp=sortlist(start);
printf("\n\n\tSorted List is :\n\n\t\t");
while(temp!=NULL)
{
printf("%d -> ",temp->data);
temp=temp->next;
}
printf("\b\b \b\b ");
}

node *sortlist(node *source)
{
node *temp,*sort,*loser;
static int i=0;
if(i==0)
sort=NULL;
i++;
loser=NULL;
if(sort==NULL)
{
sort=source;
source=source->next;
sort->next=NULL;
}
else
{
temp=source;
source=source->next;
temp->next=sort;
sort=temp;
}

while(source!=NULL)
{
if(source->data>sort->data)
{
if(loser==NULL)
{
loser=sort;
sort=sort->next;
loser->next=NULL;
}
else
{
temp=sort;
sort=sort->next;
temp->next=loser;
loser=temp;
}
if(sort==NULL)
{
sort=source;
source=source->next;
sort->next=NULL;
}
else
{
temp=source;
source=source->next;
temp->next=sort;
sort=temp;
}
}
else if(source->data<sort->data)
{
if(loser==NULL)
{
loser=source;
source=source->next;
loser->next=NULL;
}
else
{
temp=source;
source=source->next;
temp->next=loser;
loser=temp;
}
}
else
{
temp=source;
source=source->next;
temp->next=sort;
sort=temp;
}
}
if(loser!=NULL)
sortlist(loser);
else
return sort;
}

