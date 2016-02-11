/* Created by Ganesh Sawhney       **
** Email: ganeshsawhney@gmail.com  **
** Github Username: ganeshsawhney  */

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct linklist
{
int data;
struct linklist *next;
};

typedef struct linklist node;
node *start,*start1,*ans,*ptr=NULL,*ptr1=NULL,*ptr2=NULL,*temp=NULL;

int main()
{
char ch;
start=(node*)malloc(sizeof(node));
ptr=start;
printf("Enter 1st linklist: \n");
do
{
printf("Enter Info: ");
scanf("%d",&ptr->data);
printf("Continue(y/n): ");
fflush(stdin);
scanf("%c",&ch);
if(ch=='y')
{
ptr->next=(node*)malloc(sizeof(node));
ptr=ptr->next;
}
}while(ch=='y');

ptr->next=NULL;
start1=(node*)malloc(sizeof(node));
ptr=start1;
printf("Enter 2nd linklist: \n");

do
{
printf("Enter Info: ");
scanf("%d",&ptr->data);
printf("Continue(y/n): ");
fflush(stdin);
scanf("%c",&ch);
if(ch=='y')
{
ptr->next=(node*)malloc(sizeof(node));
ptr=ptr->next;
}
}while(ch=='y');

ptr->next=NULL;
ans=(node*)malloc(sizeof(node));
ptr=ans;
ptr1=start;
ptr2=start1;
ptr->data=ptr1->data;
ptr1=ptr1->next;

while(ptr1!=NULL&&ptr2!=NULL)
{
if(ptr2!=NULL)
{
ptr->next=(node*)malloc(sizeof(node));
ptr=ptr->next;
ptr->data=ptr2->data;
temp=ptr2;
ptr2=ptr2->next;
free(temp);
}
if(ptr1!=NULL)
{
ptr->next=(node*)malloc(sizeof(node));
ptr=ptr->next;
ptr->data=ptr1->data;
temp=ptr1;
ptr1=ptr1->next;
free(temp);
}
}

while(ptr1!=NULL||ptr2!=NULL)
{
if(ptr1==NULL)
{
ptr->next=(node*)malloc(sizeof(node));
ptr=ptr->next;
ptr->data=ptr2->data;
temp=ptr2;
ptr2=ptr2->next;
free(temp);
}
else
{
ptr->next=(node*)malloc(sizeof(node));
ptr=ptr->next;
ptr->data=ptr1->data;
temp=ptr1;
ptr1=ptr1->next;
free(temp);
}
}

ptr->next=NULL;
ptr=ans;
printf("linklists Merged: ");

while(ptr!=NULL)
{
printf("%d ",ptr->data);
ptr=ptr->next;
}
return 0;
}
