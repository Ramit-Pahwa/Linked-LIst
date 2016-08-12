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
void move(struct node **x,struct node **y )
{
	struct node * temp=*y;
	*y=temp->next;
	temp->next=*x;
	*x=temp;

}
struct node *merge(struct node*a,struct node*b)
{
	struct node *dummy=(struct node*)malloc(sizeof(struct node));
	struct node *temp=dummy;
	dummy->next=NULL;
	//temp->next=NULL;
	while(1)
	{	
	if(a==NULL)
	{
		temp->next=b;
		break;

	}
	else if(b==NULL)
	{
		temp->next=a;
		break;
		
	}
	if (a->data>=b->data)
		move(&temp->next,&b);
	else
		move(&temp->next,&a);
	temp=temp->next;
	}
	return dummy->next;

}


void push(struct node** head_ref,int data)
{
	struct node* newnode=(struct node* )malloc(sizeof(struct node));
	newnode->data=data;
	newnode->next=*head_ref;
	(*head_ref)=newnode;
}

int main()
{	struct node*a=NULL;
	struct node *b=NULL;
	struct node *final=NULL;
	push(&a,10);
	push(&b,2);
	push(&a,32);
	push(&b,5);
	push(&a,67);
	push(&b,5);
	push(&a,6);
	final=merge(a,b);
	//printLi++ st(&head);
	//swap(&head,1,8);
	printList(&final);
	return 0;

}