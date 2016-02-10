/* Created by Ganesh Sawhney       **
** Email: ganeshsawhney@gmail.com  **
** Github Username: ganeshsawhney  */

#include<stdio.h>
#include<conio.h>
#include<malloc.h>
struct linklist
{
int info;
struct linklist *down;
struct linklist *right;
};
typedef struct linklist node;

node *start, *prev, *temp, *temp1, *ptr, *ptr1, *temp2, *temp3;
int num, i=1, j=1;

int main()
{
printf("Enter number of rows you want to create= ");
scanf("%d",&num);
start=(node*)malloc(sizeof(node));
printf("Enter info of row %d column %d= ",i,j);
scanf("%d",&start->info);
start->down=NULL;
start->right=NULL;
temp=start;
prev=start;
for(j=1;j<3;j++)
{
ptr1=(node*)malloc(sizeof(node));
printf("Enter info of row %d column %d= ",i,j+1);
scanf("%d",&ptr1->info);
ptr1->down=NULL;
ptr1->right=NULL;
temp->right=ptr1;
temp=ptr1;
}
temp=start;
temp2=start;
temp3=start;
for(i=0;i<1;i++)
{
temp2=temp2->right;
}
for(i=0;i<2;i++)
{
temp3=temp3->right;
}

for(i=1;i<num;i++)
{
j=1;
ptr=(node*)malloc(sizeof(node));
printf("Enter info for row %d column %d= ",i+1,j);
scanf("%d",&ptr->info);
ptr->down=NULL;
ptr->right=NULL;
prev->down=ptr;
prev=ptr;
temp=prev;
for(j=1;j<3;j++)
{
ptr1=(node*)malloc(sizeof(node));
printf("Enter info for row %d column %d= ",i+1,j+1);
scanf("%d",&ptr1->info);
ptr1->down=NULL;
ptr1->right=NULL;
temp->right=ptr1;
if(j==1)
{
temp2->down=ptr1;
temp2=ptr1;
}
else if(j==2)
{
temp3->down=ptr1;
temp3=ptr1;
}
temp=ptr1;
}
}

printf("\n\n\tRow wise");
i=1;
temp=start;
prev=start;

while(prev!=NULL)
{
printf("\n\n\t%dth row: ",i++);
while(temp!=NULL)
{
printf(" %d ",temp->info);
temp=temp->right;
}
prev=prev->down;
temp=prev;
}

printf("\n\n\tColumn wise");
i=1;
temp=start;
prev=start;

while(temp!=NULL)
{
printf("\n\n\t%dth column: ",i++);
while(prev!=NULL)
{
printf(" %d ",prev->info);
prev=prev->down;
}
temp=temp->right;
prev=temp;
}
return 0;
}
