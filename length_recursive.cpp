#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node * next;
};
int len(struct node* head_ref)
{	int l=0;
	struct node*temp=head_ref;
	while(temp!=NULL)
		{l++;
			temp=temp->next;}
			return l;
}
int lenRec(struct node* head_ref)
{	int l=0;
	struct node*temp=head_ref;
	if(temp==NULL)
		return 0;
	else
		{return 1+lenRec(temp->next);
			}

}
void printList(struct node**head_ref)
{
	struct node *temp=(*head_ref);
	printf("The list is as follows:");
	while(temp!=NULL)
	{
		printf("%d   ",temp->data);
		temp=temp->next;
	}
	printf("\n");
}
void swap(struct node** head_ref,int x,int y)
{
	struct node*currx=*head_ref,*prevx=NULL;
	struct node*curry=*head_ref,*prevy=NULL;
	int l=len(*head_ref);//printf("%d l=",l);

	int i;

	if(x==y)
	{
		printf("Same location cannot swap\n");
		return;
	}
	if((x<1)||(x>l)||(y<1)||(y>l))
	{
		printf("Out of Bounds\n");
		return;
	}
	for (i=1;i<x;i++)
	{
		prevx=currx;
		currx=currx->next;
	}
	for (i=1;i<y;i++)
	{
		prevy=curry;
		curry=curry->next;
	}
	
	if(prevx!=NULL)
		prevx->next=curry;
	else
		*head_ref=curry;	 
	if(prevy!=NULL)
		prevy->next=currx;
	else
		*head_ref=currx;

	struct node *temp=currx->next;
	currx->next=curry->next;
	curry->next=temp;			

}
void deletekey(struct node **head_ref,int data)
{	
	struct node*temp=*head_ref;
	struct node*prev=NULL;
	int l1=len(*head_ref);
	while(temp!=NULL)
	{	
		if(temp->data==data)
		{	
			prev->next=temp->next;
			temp=temp->next;
		}
		else 
			prev=temp;
			temp=temp->next;
	}
	int l2=len(*head_ref);
	if(l1==l2)
	{
		printf("KEY NOT PRESENT");
		return;
	}

}
void push(struct node** head_ref,int data)
{
	struct node* newnode=(struct node* )malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=*head_ref;
	(*head_ref)=newnode;
}

int main()
{	struct node*head=NULL;
	push(&head,10);
	push(&head,2);
	push(&head,32);
	push(&head,5);
	push(&head,67);
	push(&head,5);
	push(&head,6);
	printList(&head);
	//swap(&head,1,8);
	//deletekey(&head,5);
	//printList(&head);
	//deletekey(&head,77);
	int length=lenRec(head);
	printf("%d\n",length);
	printList(&head);
	return 0;

}