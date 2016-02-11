/* Created by Ganesh Sawhney       **
** Email: ganeshsawhney@gmail.com  **
** Github Username: ganeshsawhney  */

#include<stdio.h>
#include<stdlib.h>
struct linklist
{
int info;
struct linklist *next;
};

typedef struct linklist node;
node *start=NULL,*ptr1,*ptr2,*ptr;

int main()
{
char ch;
ptr=start=(node*)malloc(sizeof(node));

do
{
printf("Enter Info :\t");
scanf("%d",&ptr->info);
printf("Continue(y/n):\t");
fflush(stdin);
scanf("%c",&ch);
if(ch=='y')
{
ptr->next=(node*)malloc(sizeof(node));
ptr=ptr->next;
}
}while(ch=='y');

ptr->next=NULL;
ptr1=start;
ptr2=start;
ptr=start;

while(ptr)
{
if(ptr1->info<ptr->info)
ptr1=ptr;
ptr=ptr->next;
}

ptr=start;
while(ptr)
{
if(ptr2!=ptr1&&ptr2->info<ptr->info)
ptr2=ptr;
ptr=ptr->next;
}
printf("Second largest Element :\t%d",ptr2->info);
return 0;
}
