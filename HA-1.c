/* Created by Ganesh Sawhney       **
** Email: ganeshsawhney@gmail.com  **
** Github Username: ganeshsawhney  */

#include<stdio.h>
#include<string.h>
#include<malloc.h>
struct linklist
{
char name[50];
int id;
int mrk1;
int mrk2;
int mrk3;
int mrk4;
struct linklist *next;
};
typedef struct linklist node;

node *start, *temp, *ptr;
int m, n, i, j, t=1;

int main()
{
int max1,max2,max3,max4,min1,min2,min3,min4,sum1=0,sum2=0,sum3=0,sum4=0,d,w1,w2,w3,w4;
char b[40], ch;
FILE *fw,*fr;

fw=fopen("mrk1text.txt","w");
for(i=0;i<3;i++)
{
printf("Enter name of candidate %d= ",i+1);
fflush(stdin);
gets(b);
printf("\nEnter id of candidate %d= ",i+1);
scanf("%d",&d);
printf("\nEnter marks out of 25 of 4 quizes of candidate %d= ",i+1);
scanf("%d%d%d%d",&w1,&w2,&w3,&w4);
fprintf(fw,"%s %d %d %d %d %d\n",b,d,w1,w2,w3,w4);
}
fclose(fw);

fr=fopen("mrk1text.txt","r");
start=(node*)malloc(sizeof(node));
fscanf(fr,"%s ",b);
strcpy(start->name,b);
fscanf(fr,"%d ",&start->id);
fscanf(fr,"%d %d %d %d\n",&start->mrk1,&start->mrk2,&start->mrk3,&start->mrk4);
start->next=NULL;
temp=start;

while(!feof(fr))
{
ptr=(node*)malloc(sizeof(node));
fscanf(fr,"%s ",b);
strcpy(ptr->name,b);
fscanf(fr,"%d ",&ptr->id);
fscanf(fr,"%d %d %d %d\n",&ptr->mrk1,&ptr->mrk2,&ptr->mrk3,&ptr->mrk4);
ptr->next=NULL;
temp->next=ptr;
temp=ptr;
}

printf("\n\n\tEnter value of n= ");
scanf("%d",&n);
printf("S.no.\tName\t\tId\tQuiz1\tQuiz2\tQuiz3\tQuiz4\n");
temp=start;

while(temp!=NULL)
{
for(i=0;i<n;i++)
{
printf("\n%d.\t%s\t\t%d\t%d\t%d\t%d\t%d\n",t++,temp->name,temp->id,temp->mrk1,temp->mrk2,temp->mrk3,temp->mrk4);
if(temp->next==NULL)
{
temp=temp->next;
break;
}
else
{
temp=temp->next;
}
}
}

max1=start->mrk1;
max2=start->mrk2;
max3=start->mrk3;
max4=start->mrk4;
temp=start->next;

while(temp!=NULL)
{
if(temp->mrk1>max1)
max1=temp->mrk1;
if(temp->mrk2>max2)
max2=temp->mrk2;
if(temp->mrk3>max3)
max3=temp->mrk3;
if(temp->mrk4>max4)
max4=temp->mrk4;
temp=temp->next;
}

printf("\nMaximum values of mrk1= %d",max1);
printf("\nMaximum values of mrk2= %d",max2);
printf("\nMaximum values of mrk3= %d",max3);
printf("\nMaximum values of mrk4= %d",max4);
min1=start->mrk1;
min2=start->mrk2;
min3=start->mrk3;
min4=start->mrk4;
temp=start->next;

while(temp!=NULL)
{
if(temp->mrk1<min1)
min1=temp->mrk1;
if(temp->mrk2<min2)
min2=temp->mrk2;
if(temp->mrk3<min3)
min3=temp->mrk3;
if(temp->mrk4<min4)
min4=temp->mrk4;
temp=temp->next;
}

printf("\nMinimum values of mrk1= %d",min1);
printf("\nMinimum values of mrk2= %d",min2);
printf("\nMinimum values of mrk3= %d",min3);
printf("\nMinimum values of mrk4= %d",min4);
temp=start;

while(temp!=NULL)
{
sum1=sum1+temp->mrk1;
sum2=sum2+temp->mrk2;
sum3=sum3+temp->mrk3;
sum4=sum4+temp->mrk4;
temp=temp->next;
}

printf("\nAverage of mrk1 is= %0.2f",sum1/3.000000);
printf("\nAverage of mrk2 is= %0.2f",sum2/3.000000);
printf("\nAverage of mrk3 is= %0.2f",sum3/3.000000);
printf("\nAverage of mrk4 is= %0.2f",sum4/3.000000);
temp=start;

while(temp!=NULL)
{
if(temp->mrk1==max1)
{
printf("\n\tMaximum in quiz 1 is scored by= ");
printf("\n\n\tName: %s ID: %d",temp->name,temp->id);
}
temp=temp->next;
}

printf("\n\n\tMore than 70 percent in respective quizes");
printf("\n\n\tIn Quiz 1");
temp=start;

while(temp!=NULL)
{
if(temp->mrk1>22)
printf("\tName: %s ID: %d",temp->name,temp->id);
temp=temp->next;
}

printf("\n\n\tIn Quiz 2");
temp=start;

while(temp!=NULL)
{
if(temp->mrk2>22)
printf("\tName: %s ID: %d",temp->name,temp->id);
temp=temp->next;
}

printf("\n\n\tIn Quiz 3");
temp=start;

while(temp!=NULL)
{
if(temp->mrk3>22)
printf("\tName: %s ID: %d",temp->name,temp->id);
temp=temp->next;
}
printf("\n\n\tIn Quiz 4");
temp=start;

while(temp!=NULL)
{
if(temp->mrk4>22)
printf("\tName: %s ID: %d",temp->name,temp->id);
temp=temp->next;
}
t=1;
temp=start;

while(temp!=NULL)
{
sum1=temp->mrk1+temp->mrk2+temp->mrk3+temp->mrk4;
if(sum1>70)
printf("\n\t%d scored more than 70 percent",t++);
temp=temp->next;
}

printf("\n\n\tScored highest in all quizes");
temp=start;

while(temp!=NULL)
{
if(max1==temp->mrk1&&max2==temp->mrk2&&max3==temp->mrk3&&max4==temp->mrk4)
printf("\n\tName: %s ID: %d",temp->name,temp->id);
temp=temp->next;
}

fclose(fr);
return 0;
}
/* Created by Ganesh Sawhney       **
** Email: ganeshsawhney@gmail.com  **
** Github Username: ganeshsawhney  */
