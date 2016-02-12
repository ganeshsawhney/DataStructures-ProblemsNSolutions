/* Created by Ganesh Sawhney       **
** Email: ganeshsawhney@gmail.com  **
** Github Username: ganeshsawhney  */

#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<string.h>
struct linklist
{
	char word[80];
	struct linklist *next;
}
typedef struct linklist node;
int addword(node *start,char a[])
{
	node *temp,*back;
	temp=start;
	if(!((a[0]>='a'&&a[0]<='z')||(a[0]>='A'&&a[0]<='Z'))
		return 0;
	while(temp!=NULL)
	{
		if(strcmpi(temp->word,a)==0)
			return 0;
		back=temp;
		temp=temp->next;
	}
	temp=back->next=(node *) malloc(sizeof(node));
	strcpy(temp->word,a);
	temp->next=NULL;
	return 1;
}
