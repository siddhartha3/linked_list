
/* 
* C program to implement link list
* Author : Siddhartha Giri
* Date : 07/28/2016
* Ref : Data Structure using c and c++, chapter 4
*/

#include<stdio.h>
#include<stdlib.h>


struct node{
    int info;
    struct node *next;
};

typedef struct node *nodeptr;

nodeptr getnode();
void insert(nodeptr*,int);
int removes(nodeptr*);
void freenode(nodeptr);
void displaylist(nodeptr);
int removes(nodeptr*);

int main()
{
    nodeptr p;
    p=NULL;
    insert(&p,5);
    insert(&p,6);
    insert(&p,7);  
    displaylist(p);
	printf("\n--------------------------------\n");
	printf("Removed:%d\n",removes(&p));
	printf("\n--------------------------------\n");
	printf("Removed:%d\n",removes(&p));
	printf("\n--------------------------------\n");
	printf("Removed:%d\n",removes(&p));
	printf("\n--------------------------------\n");
	printf("Removed:%d\n",removes(&p));	  
    displaylist(p); 
     
}

nodeptr getnode()
{
    return (nodeptr)malloc(sizeof(nodeptr));
}

void freenode(nodeptr p)
{
    free(p);
}

void insert(nodeptr* p,int x)
{
    nodeptr q;
    q= getnode();
    q->info =x;
    q->next = *p;
    *p=q;
    
}
//---------------------------------------------//
void displaylist(nodeptr p)
{
    nodeptr ptr= p;
    while(ptr!=NULL)
  {
      printf("List:%d\n",ptr->info);
      ptr = ptr->next;
  }
    
}

int removes(nodeptr *p)
{    
	int x;
	if (*p==NULL)
	{
		printf("List Underflow\n");
		exit(0);
	}else
	{
		nodeptr q;
	    q=*p;
	    *p=q->next;
	    x=q->info;
	    freenode(q);
		return x;    
	}	
}

