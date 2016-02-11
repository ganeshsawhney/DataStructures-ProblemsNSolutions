/* Created by Ganesh Sawhney       **
** Email: ganeshsawhney@gmail.com  **
** Github Username: ganeshsawhney  */

#include <stdio.h>
#include <stdlib.h>

struct linklist
{
int Data;
struct linklist *next;
}*top;

void display();
void push(int value);
void popStack();

int main()
{
int x,n,i,num=0;
printf("\nEnter a number ");
scanf("%d",&x);
printf("\n enter base\n");
scanf("%d",&n);
while(x!=0)
{
push(x%n);
x=x/n;
num++;
}
display();
for(i=0;i<num;i++)
{
popStack();
}
return 0;
}

void popStack()
{
struct linklist *temp, *var=top;
if(var==top)
{
top = top->next;
free(var);
}
}

void push(int value)
{
struct linklist *temp;
temp=(struct linklist *)malloc(sizeof(struct linklist));
temp->Data=value;
if (top == NULL)
{
top=temp;
top->next=NULL;
}
else
{
temp->next=top;
top=temp;
}
}

void display()
{
struct linklist *var=top;
if(var!=NULL)
{
printf("\n the number is :\n");
while(var!=NULL)
{
printf("\t%d\n",var->Data);
var=var->next;
}
printf("\n");
}
else
printf("\nStack is Empty");
}
