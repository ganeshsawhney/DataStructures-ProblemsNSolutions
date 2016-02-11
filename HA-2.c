/* Created by Ganesh Sawhney       **
** Email: ganeshsawhney@gmail.com  **
** Github Username: ganeshsawhney  */

#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct linklist
{
int info;
struct linklist *next;
};

typedef struct linklist node;
node *start,*ptr,*ptr1;

int main()
{
int k=0,temp,i,j;
char ch;
start=ptr=ptr1=NULL;
start=ptr=ptr1=(node*)malloc(sizeof(node*));

do
{
k++;
printf("enter the node ");
scanf(" %d",&ptr->info);
fflush(stdin);
printf("do u want to enter more ");
scanf(" %c",&ch);
if(ch=='y')
{
ptr->next=(node*)malloc(sizeof(node*));
ptr=ptr->next;
}
}while(ch=='y');

ptr->next=NULL;
ptr=start;
printf("the initial list is \n");
while(ptr!=NULL)
{
printf(" %d ",ptr->info);
ptr=ptr->next;
}
printf(" \n the no of nodes are %d ",k);
ptr=start;

for(i=0; i<k/2; i++)
{
ptr1=start;
for(j=0; j<k-i-1; j++)
{
ptr1=ptr1->next;
}
temp=ptr->info;
ptr->info=ptr1->info;
ptr1->info=temp;
ptr=ptr->next;
}

printf("the new list is\n");
ptr=start;
while(ptr!=NULL)
{
printf(" %d ",ptr->info);
ptr=ptr->next;
}
free(start);
free(ptr);
free(ptr1);
return 0;
}
