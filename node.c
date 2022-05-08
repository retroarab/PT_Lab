#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define N 1799



struct movies{
	unsigned int release;
	char title[101];
	unsigned budget;
};

typedef struct movies easy;
struct node{
	easy info;
	struct node* next;
};



typedef struct node list;
void printList(list *start)
{
    list *temp = start;
    printf("\n");
    while (temp!=NULL)
    {
        printf("Release year is : %d\n Title is : %s \n Budget was : %u \n -------\n ", temp->info.release,temp->info.title,temp->info.budget);
        temp = temp->next;
    }
}
void swap(list *a, list *b)
{
    easy temp = a->info;
    a->info = b->info;
    b->info = temp;
}
void bubbleSort(list *start)
{
    int swapped, i;
    list *ptr1;
    list *lptr = NULL;
  
    /* Checking for empty list */
    if (start == NULL)
        return;
  
    do
    {
        swapped = 0;
        ptr1 = start;
  
        while (ptr1->next != lptr)
        {
            if (ptr1->info.release > ptr1->next->info.release)
            { 
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}
int main(int argc,char** argv)
{
	easy infom[N];
	list *current,*head;
	head=current=NULL;
	if(argc<2)
	{
		printf("More arguments are required sir \n");
		return 0;
	}
	FILE* f=fopen(argv[1],"r");
	if(!f)
	{
		printf("File is not able to open \n");
		return 0;
	}
	char junk[301];
	fgets(junk,300,f);
	int k=0;
	int i=0;
	while(fscanf(f,"%[^,],",junk)==1)
	{
		if(junk[0]=='\"')
		{
			char extra[101];
			fscanf(f,"%[^\"]",extra);
			strcat(junk,extra);
			strcat(junk,"\"");

			//printf("%s\n",junk);
			fgetc(f);
			fgetc(f);
		}
		if(k==7)
		{


			//printf("Budget is : %s\n",junk);
			fgets(junk,300,f);
			infom[i++].budget=atoi(junk);
			k=-1;

		}
		if(k==0)
		{
			infom[i].release=atoi(junk);
			
			//printf("Year is : %s\n",junk);
		}
		if(k==2)
		{

			//printf("Title is : %s\n",junk);
			strcpy(infom[i].title,junk);
		}

		k++;
	}
	for(int i=0;i<N;i++)
	{
		list* node=(list*)malloc(sizeof(list));
		node->info=infom[i];
		node->next=NULL;
		if(head==NULL)
		{
			current=head=node;
		}
		else
		{
			current=current->next=node;
		}
	}
	bubbleSort(head);
    printList(head);
	return 0;
}
