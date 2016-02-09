/* Created by Ganesh Sawhney       **
** Email: ganeshsawhney@gmail.com  **
** Github Username: ganeshsawhney  */

#include<conio.h>
#include<stdio.h>
#include<malloc.h>
struct student
{
char name[80];
struct student *nextstudent;
struct marks *nextmarks;
};
struct marks
{
int score;
struct marks *nextmarks;
};
typedef struct student student;
typedef struct marks marks;

int main()
{
FILE *f;
char ch;
int i,total;
student *start=NULL,*temp=NULL;
marks *m;
f=fopen("student.txt","r");

while(!feof(f))
{
ch='y';
i=1;
if(temp==NULL)
{
temp=start=(student *)malloc(sizeof(student));
fscanf(f,"%s ",temp->name);
temp->nextmarks=NULL;
printf("\n\n\tEnter Score for %s student : ",temp->name);
while(ch=='y'&&i<=4)
{
if(temp->nextmarks==NULL)
m=temp->nextmarks=(marks *) malloc(sizeof(marks));
else
{
m->nextmarks=(marks *) malloc(sizeof(marks));
m=m->nextmarks;
}
printf("\n\n\tEnter %dth Score : ",i);
scanf("%d",&m->score);
i++;
if(i<=4)
{
printf("\n\n\tEnter more score [Y/N] : ");
fflush(stdin);
scanf("%c",&ch);
}
}
m->nextmarks=NULL;
}
else
{
temp->nextstudent=(student *)malloc(sizeof(student));
temp=temp->nextstudent;
fscanf(f,"%s ",temp->name);
temp->nextmarks=NULL;
printf("\n\n\tEnter Score for %s student : ",temp->name);
while(ch=='y'&&i<=4)
{
if(temp->nextmarks==NULL)
m=temp->nextmarks=(marks *) malloc(sizeof(marks));
else
{
m->nextmarks=(marks *) malloc(sizeof(marks));
m=m->nextmarks;
}
printf("\n\n\tEnter %dth Score : ",i);
scanf("%d",&m->score);
i++;
if(i<=4)
{
printf("\n\n\tEnter more score [Y/N] : ");
fflush(stdin);
scanf("%c",&ch);
}
}
m->nextmarks=NULL;
}
}
temp->nextstudent=NULL;
temp=start;

while(temp!=NULL)
{
total=0,i=0;
printf("\n\n\tName : %s",temp->name);
m=temp->nextmarks;
while(m!=NULL)
{
printf("\n\n\t\t%dth Score : %d",++i,m->score);
total+=m->score;
m=m->nextmarks;
}
printf("\n\n\t\tTotal : %d\n\n\t\tAverage : %.2f",total,(float)total/i);
temp=temp->nextstudent;
}
return 0;
}

