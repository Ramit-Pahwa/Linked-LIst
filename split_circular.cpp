#include <stdio.h>
#include <stdlib.h>


struct node
{
	int data;
	struct node*next;
};


void printList(struct node** head_ref)
{
	struct node* temp=(*head_ref);

	do
	{
		printf("--->%d--->%d",temp->data,(temp->next)->data);
		temp=temp->next;
	}while(temp!=(*head_ref));

	//	printf("--->%d--->%d",temp->data,(temp->next)->data);
			printf("\n");
}


void deleteKey(struct node**head_ref,int key)
{
	struct node*temp=*head_ref;
	struct node*prev=NULL;
	while(temp!=NULL && temp->data!=key)
	{	
		prev=temp;
		temp=temp->next;
	}
	prev->next=temp->next;
	free(temp);
}

void split(struct node** head_ref,struct node**a,struct node**b)
{

	struct node* fast=*head_ref;
	struct node* slow=*head_ref;

	while(fast->next!=*head_ref)
	{
		fast=fast->next;
		if(fast->next!=*head_ref)
		{
			fast=fast->next;
			slow=slow->next;
		}
	}
	*a=*head_ref;
	*b=slow->next;
	fast->next=*b;
	slow->next=*a;
}

void push(struct node **head_ref,int key)
{
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=key;
	newnode->next=*head_ref;
	if (*head_ref==NULL)
	{
		*head_ref=newnode;
		newnode->next=*head_ref;
		return;
	}
	struct node*temp=(*head_ref);
	//*head_ref gives us the first node while head give pointer to first node
	while(temp->next!=*head_ref)
	{
		temp=temp->next;
	}
	temp->next=newnode;
}

int main()
{

	struct node* head=NULL;
	struct node*a=NULL;
	struct node*b=NULL;
	push(&head,10);
	push(&head,20);
	push(&head,30);
	push(&head,40);
	push(&head,50);
	push(&head,60);
	push(&head,70);
	printList(&head);
	deleteKey(&head,30);
	printList(&head);
	split(&head,&a,&b);
	printf("LIST A:\n");
	printList(&a);
	printf("LIST B:\n");
	printList(&b);
	return 0;



}