/* Created by Ganesh Sawhney       **
** Email: ganeshsawhney@gmail.com  **
** Github Username: ganeshsawhney  */

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct linklist
{
int data;
struct linklist *next;
};

typedef struct linklist node;
node *start,*ptr1=NULL,*ptr2=NULL,*ptr;

int main()
{
char ch;
int tm=0,i=0,no=0;
ptr=start=(node*)malloc(sizeof(node));

do
{
printf("Enter info: ");
scanf("%d",&ptr->data);
i++;
printf("Continue(y/n): ");
fflush(stdin);
scanf("%c",&ch);
if(ch=='y')
{
ptr->next=(node*)malloc(sizeof(node));
ptr=ptr->next;
}
}while(ch=='y');

ptr1=start->next->next;
ptr->next=ptr1;
ptr2=start;
ptr1=start;

while(ptr1!=NULL)
{
while(ptr2!=NULL&&no<=i)
{
ptr2=ptr2->next;
no++;
if(ptr1==ptr2)
{
printf("loop Found");
printf("\nInfo at loop: %d",ptr1->data);
tm=1;
break;
}
}
if(tm==1)
break;
no=0;
ptr1=ptr1->next;
}

if(ptr1==NULL)
printf("No LOOP Found");
return 0;
}
/* Created by Ganesh Sawhney       **
** Email: ganeshsawhney@gmail.com  **
** Github Username: ganeshsawhney  */
