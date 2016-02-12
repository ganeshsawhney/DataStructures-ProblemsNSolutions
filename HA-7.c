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
struct linklist *prev;
};
typedef struct linklist node;
node *start;
int dll_remove(node *rootp, node *n);

int main()
{
node *temp,*ptr,*del;
char ch='y';
int i;
start=(node *) malloc(sizeof(node));
temp=start;
start->prev=NULL;
i=0;

do
{
printf("\n\n\tEnter %d node : ",++i);
scanf("%d",&temp->data);
printf("\n\n\tWant to enter more? : ");
fflush(stdin);
scanf("%c",&ch);
if(ch=='y')
{
temp->next=(node *) malloc(sizeof(node));
ptr=temp;
temp=temp->next;
temp->prev=ptr;
}
}while(ch=='y');

temp->next=NULL;
temp=start;
printf("\n\n\tList is :\n\n\t\t");
while(temp!=NULL)
{
printf("%d -> ",temp->data);
temp=temp->next;
}
printf("\b\b \b\b ");
printf("\n\n\tEnter node to delete : ");
del=(node *) malloc(sizeof(node));
scanf("%d",&del->data);
if(dll_remove(start,del)==0)
printf("\n\n\tDelete Node not found");
else
{
printf("\n\n\tList is :\n\n\t\t");
temp=start;
while(temp!=NULL)
{
printf("%d -> ",temp->data);
temp=temp->next;
}
printf("\b\b \b\b ");
}
return 0;
}

int dll_remove(node *rootp, node *n)
{
int found=0;
node *temp,*ptr;
temp=rootp;

while(temp!=NULL)
{
if(temp->data==n->data)
{
if(temp==rootp)
{
ptr=rootp;
rootp=rootp->next;
rootp->prev=NULL;
temp=rootp;
start=rootp;
free(ptr);
}
else
{
ptr=temp;
temp->prev->next=temp->next;
temp->next->prev=temp->prev;
temp=temp->next;
free(ptr);
}
found=1;
}
else
temp=temp->next;
}

return found;
}
