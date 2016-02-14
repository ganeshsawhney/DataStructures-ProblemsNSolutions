/* Created by Ganesh Sawhney       **
** Email: ganeshsawhney@gmail.com  **
** Github Username: ganeshsawhney  */

#include<stdio.h>
#include<conio.h>
#include<malloc.h>

struct linklist
{
int data;
struct linklist *down;
struct linklist *next;
};

typedef struct linklist node;
node *start2, *start3, *start, *prev, *ptr, *ptr1, *x, *temp1, *ptr2, *ptr3;
int n, i=1, j=1;

int main()
{
printf("Enter number of rows you want to create= ");
scanf("%d",&n);
start=(node*)malloc(sizeof(node));
printf("Enter data of row %d column %d= ",i,j);
scanf("%d",&start->data);
start->down=start;
start->next=start;
ptr=start;
prev=start;

for(j=1;j<3;j++)
{
temp1=(node*)malloc(sizeof(node));
printf("Enter data of row %d column %d= ",i,j+1);
scanf("%d",&temp1->data);
temp1->down=temp1;
temp1->next=start;
ptr->next=temp1;
ptr=temp1;
}

ptr=start;
ptr2=start;
ptr3=start;

for(i=0;i<1;i++)
{
ptr2=ptr2->next;
}
for(i=0;i<2;i++)
{
ptr3=ptr3->next;
}

start2=ptr2;
start3=ptr3;

for(i=1;i<n;i++)
{
j=1;
x=(node*)malloc(sizeof(node));
printf("Enter data for row %d column %d= ",i+1,j);
scanf("%d",&x->data);
x->down=start;
x->next=x;
prev->down=x;
prev=x;
ptr=prev;
for(j=1;j<3;j++)
{
temp1=(node*)malloc(sizeof(node));
printf("Enter data for row %d column %d= ",i+1,j+1);
scanf("%d",&temp1->data);
temp1->next=prev;
ptr->next=temp1;
if(j==1)
{
temp1->down=start2;
ptr2->down=temp1;
ptr2=temp1;
}
else if(j==2)
{
temp1->down=start3;
ptr3->down=temp1;
ptr3=temp1;
}
ptr=temp1;
}
}

ptr2=start;
ptr3=start;

for(i=0;i<1;i++)
{
ptr2=ptr2->next;
}
for(i=0;i<2;i++)
{
ptr3=ptr3->next;
}

printf("\n\n\tRow wise");
i=1;
ptr=start;
prev=start;

while(prev->down!=start)
{
printf("\n\n\t%dth row: ",i++);
while(ptr->next!=prev)
{
printf(" %d ",ptr->data);
ptr=ptr->next;
}
printf(" %d ",ptr->data);
ptr=ptr->next;
prev=prev->down;
ptr=prev;
}

printf("\n\n\t%dth row: ",i++);
while(ptr->next!=prev)
{
printf(" %d ",ptr->data);
ptr=ptr->next;
}
printf(" %d ",ptr->data);
ptr=ptr->next;
prev=prev->down;
ptr=prev;
printf("\n\n\tColumn wise");
i=1;
ptr=start;
prev=start;

while(ptr->next!=start)
{
printf("\n\n\t%dth column: ",i++);
while(prev->down!=ptr)
{
printf(" %d ",prev->data);
prev=prev->down;
}
printf(" %d ",prev->data);
prev=prev->down;
ptr=ptr->next;
prev=ptr;
}

printf("\n\n\t%dth column: ",i++);
while(prev->down!=ptr)
{
printf(" %d ",prev->data);
prev=prev->down;
}
printf(" %d ",prev->data);
prev=prev->down;
ptr=ptr->next;
prev=ptr;
return 0;
}
/* Created by Ganesh Sawhney       **
** Email: ganeshsawhney@gmail.com  **
** Github Username: ganeshsawhney  */
