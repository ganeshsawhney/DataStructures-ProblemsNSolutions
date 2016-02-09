/* Created by Ganesh Sawhney       **
** Email: ganeshsawhney@gmail.com  **
** Github Username: ganeshsawhney  */

#include<stdio.h>
#include<conio.h>

int main()
{
int num[20],y,maxi,i=0;
char ch;
do
{
printf("Enter element: ");
scanf("%d",&num[i]);
printf("Continue: ");
fflush(stdin);
scanf("%c",&ch);
if(ch=='y')
i++;
}while(ch=='y');

maxi=num[0];

for(y=0;y<i;y++)
{
if(num[y]>maxi)
maxi=num[y];
}

printf("Largest Element: %d",maxi);
return 0;
}
