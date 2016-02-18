/* Created by Ganesh Sawhney       **
** Email: ganeshsawhney@gmail.com  **
** Github Username: ganeshsawhney  */

#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct linklist
{
int coeff;
int power;
struct linklist *next;
};
typedef struct linklist node;

int main()
{
node *start,*start2,*start3,*temp,*ptr,*ptr1,*ptr2,*prev,*start4;
int i,flag;
char ch='y';
start=(node *) malloc(sizeof(node));
temp=start;
i=0;
printf("\n\nEnter Polinomial 1 : ");

do
{
printf("\n\n\tEnter Power of x : ");
scanf("%d",&temp->power);
printf("\n\n\tEnter Coeff of x^%d : ",temp->power);
scanf("%d",&temp->coeff);
printf("\n\n\tWant to enter more [y/n] : ");
fflush(stdin);
scanf("%c",&ch);
if(ch=='y')
{
temp->next=(node *) malloc(sizeof(node));
temp=temp->next;
}
}while(ch=='y');

temp->next=NULL;
start2=(node *) malloc(sizeof(node));
temp=start2;
printf("\n\nEnter Poly2 : ");
i=0;

do
{
printf("\n\n\tEnter Power of x : ");
scanf("%d",&temp->power);
printf("\n\n\tEnter Coeff of x^%d : ",temp->power);
scanf("%d",&temp->coeff);
printf("\n\n\tWant to enter more [Y/N] : ");
fflush(stdin);
scanf("%c",&ch);
if(ch=='y')
{
temp->next=(node *) malloc(sizeof(node));
temp=temp->next;
}
}while(ch=='y');

temp->next=NULL;
temp=start;
printf("\n\n\tPress Enter to Continue.");
printf("\n\n\tPolynomial 1 is :\n\n\t\t");

do
{
if(temp->power!=0)
printf("(%d)x^%d + ",temp->coeff,temp->power);
else
printf("(%d) + ",temp->coeff);
temp=temp->next;
}while(temp!=NULL);

printf("\b\b ");
temp=start2;
printf("\n\n\tPolynomial 2 is :\n\n\t\t");

do
{
if(temp->power!=0)
printf("(%d)x^%d + ",temp->coeff,temp->power);
else
printf("(%d) + ",temp->coeff);
temp=temp->next;
}while(temp!=NULL);

printf("\b\b ");
temp=start,ptr=start2;
start3=(node *) calloc(1,sizeof(node));
prev=start3;

while(temp!=NULL&&ptr!=NULL)
{
if(temp->power>ptr->power)
{
prev->coeff=temp->coeff;
prev->power=temp->power;
temp=temp->next;
}
else if(temp->power<ptr->power)
{
prev->coeff=ptr->coeff;
prev->power=ptr->power;
ptr=ptr->next;
}
else
{
prev->coeff=temp->coeff+ptr->coeff;
prev->power=temp->power;
temp=temp->next;
ptr=ptr->next;
}
if(temp!=NULL&&ptr!=NULL)
{
prev->next=(node *) calloc(1,sizeof(node));
prev=prev->next;
}
}

while(temp!=NULL||ptr!=NULL)
{
prev->next=(node *) calloc(1,sizeof(node));
prev=prev->next;
if(temp!=NULL)
{
prev->coeff=temp->coeff;
prev->power=temp->power;
temp=temp->next;
}
else if(ptr!=NULL)
{
prev->coeff=ptr->coeff;
prev->power=ptr->power;
ptr=ptr->next;
}
}

prev->next=NULL;
temp=start3;
printf("\n\n\tSum is is :\n\n\t\t");

do
{
if(temp->power!=0)
printf("(%d)x^%d + ",temp->coeff,temp->power);
else
printf("(%d) + ",temp->coeff);
temp=temp->next;
}while(temp!=NULL);

printf("\b\b ");
temp=start;
ptr=start2;
start4=(node *)calloc(1,sizeof(node));
prev=start4;

while(temp!=NULL)
{
ptr=start2;
while(ptr!=NULL)
{
flag=0;
if(temp==start)
{
prev->coeff=temp->coeff*ptr->coeff;
prev->power=temp->power+ptr->power;
}
else
{
ptr1=start4;
while(ptr1!=NULL)
{
if(temp->power+ptr->power==ptr1->power)
{
ptr1->coeff+=temp->coeff*ptr->coeff;
flag=1;
}
ptr1=ptr1->next;
}
if(flag==0)
{
prev->coeff=temp->coeff*ptr->coeff;
prev->power=temp->power+ptr->power;
}
}
if(flag==0)
if(temp->next!=NULL||ptr->next!=NULL)
{
prev->next=(node *) calloc(1,sizeof(node));
prev=prev->next;
}
ptr=ptr->next;
}
temp=temp->next;
}

temp=start4;
printf("\n\n\tProduct is is :\n\n\t\t");

do
{
if(temp->power!=0)
printf("(%d)x^%d + ",temp->coeff,temp->power);
else
printf("(%d) + ",temp->coeff);
temp=temp->next;
}while(temp!=NULL);

printf("\b\b ");
while(start!=NULL)
{
temp=start;
start=start->next;
free(temp);
}
while(start2!=NULL)
{
temp=start2;
start2=start2->next;
free(temp);
}
while(start3!=NULL)
{
temp=start3;
start3=start3->next;
free(temp);
}
while(start4!=NULL)
{
temp=start4;
start4=start4->next;
free(temp);
}
return 0;
}
/* Created by Ganesh Sawhney       **
** Email: ganeshsawhney@gmail.com  **
** Github Username: ganeshsawhney  */
