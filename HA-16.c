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

int main()
{
int ch=0;
node *top,*ptr;
top=NULL;
while(ch!=4)
{
printf("\n\n\t\tDynamic Stack Menu");
printf("\n\n\t1. Push Element");
printf("\n\n\t2. Pop Element");
printf("\n\n\t3. Display Stack");
printf("\n\n\t4. Exit");
printf("\n\n\tEnter you choice [1-4] : "); scanf("%d",&ch);
switch (ch)
{

case 1 :
{
if(top==NULL)
{
top=(node *) malloc(sizeof(node));
top->next=NULL;
}
else
{
ptr=(node *) malloc(sizeof(node));
ptr->next=top;
top=ptr;
}
printf("\n\n\tEnter number to insert : ");
scanf("%d",&top->num);
break;
}

case 2 :
{
if(top==NULL)
printf("\n\n\tCannot pop elements\n\n\t\tStack underflow");
else
{
ptr=top;
top=top->next;
free(ptr);
printf("\n\n\tTop element deleted.");
}
break;
}

case 3 :
{
if(top==NULL)
printf("\n\n\tCannot pop elements\n\n\t\tStack underflow");
else
{
printf("\n\n\tStack is :  \n\n\t\t");
ptr=top;
while(ptr!=NULL)
{
printf("%d -> ",ptr->num);
ptr=ptr->next;
}
printf("\b\b \b\b ");
}
break;
}

case 4 :
{
exit(0);
}

default :
{
printf("\n\n\tEnter Valid Choice.");
}
}
}
return 0;
}

