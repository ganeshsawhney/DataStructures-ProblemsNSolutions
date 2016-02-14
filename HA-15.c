/* Created by Ganesh Sawhney       **
** Email: ganeshsawhney@gmail.com  **
** Github Username: ganeshsawhney  */

#include<stdio.h>
#include<stdlib.h>

int main()
{
int top=-1,n,stack[20],i;
int ch=0;
printf("\n\n\tEnter Maximum Stack Size : ");
scanf("%d",&n);
while(ch!=4)
{
printf("\n\n\t\tArray Stack Menu");
printf("\n\n\t1. Push Element");
printf("\n\n\t2. Pop Element");
printf("\n\n\t3. Display Stack");
printf("\n\n\t4. Exit");
printf("\n\n\tEnter you choice [1-4] : ");
scanf("%d",&ch);
switch(ch)
{

case 1 :
{
if(top<n)
{
printf("\n\n\tEnter Element to push : ");
scanf("%d",&stack[++top]);
printf("\n\n\tElement Pushed.");
}
else
printf("\n\n\tCannot push element.\n\n\t\tStack Overflow");
break;
}

case 2 :
{
if(top<0)
printf("\n\n\tCannot pop elements\n\n\t\tStack underflow");
else
{
top--;
printf("\n\n\tTop element deleted.");
}
break;
}

case 3 :
{
if(top<0)
printf("\n\n\tCannot pop elements\n\n\t\tStack underflow");
else
{
printf("\n\n\tStack is :  \n\n\t\t");
for(i=0;i<=top;i++)
printf("%d -> ",stack[i]);
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
/* Created by Ganesh Sawhney       **
** Email: ganeshsawhney@gmail.com  **
** Github Username: ganeshsawhney  */
