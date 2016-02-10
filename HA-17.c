/* Created by Ganesh Sawhney       **
** Email: ganeshsawhney@gmail.com  **
** Github Username: ganeshsawhney  */

#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct linklist
{
char data;
struct linklist *next;
};
typedef struct linklist node;

int main()
{
node *top1,*top2,*ptr1,*ptr2;
char ch='y';
int i=0,flag=1;
top1=(node *)malloc(sizeof(node));
top1->next=NULL;
printf("\n\n\tEnter string character by character : ");

while(ch=='y'||ch=='Y')
{
printf("\n\n\t\tEnter %dth character : ",++i);
fflush(stdin);
scanf("%c",&top1->data);
printf("\n\n\tEnter more characters [Y/N] : ");
fflush(stdin);
scanf("%c",&ch);
if(ch=='y'||ch=='Y')
{
ptr1=(node *)malloc(sizeof(node));
ptr1->next=top1;
top1=ptr1;
}
}

top2=NULL;
ptr1=top1;

while(ptr1!=NULL)
{
if(top2==NULL)
{
top2=(node *)malloc(sizeof(node));
top2->next=NULL;
}
else
{
ptr2=(node *) malloc(sizeof(node));
ptr2->next=top2;
top2=ptr2;
}
top2->data=ptr1->data;
ptr1=ptr1->next;
}

ptr1=top1;
ptr2=top2;
printf("\n\n\tString is : ");

while(ptr2!=NULL)
{
printf("%c",ptr2->data);
ptr2=ptr2->next;
}
ptr2=top2;

while(ptr1!=NULL)
{
if(ptr1->data!=ptr2->data&&ptr1->data!=ptr2->data-32&&ptr1->data!=ptr2->data+32)
{
flag=0;
break;
}
ptr1=ptr1->next;
ptr2=ptr2->next;
}

if(flag==0)
printf("\n\n\t\tString not palindrome.");
else
printf("\n\n\t\tGiven string is palindrome.");
return 0;
}
