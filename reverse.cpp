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

void reverseBatch(struct node** head_ref,int k)
{	if(k>len(*head_ref))
	{
		printf("Maximum length of list %d is reversing it \n",len(*head_ref));
	}
	struct node*current=*head_ref;
	struct node* prev=NULL;
	struct node* next=NULL;
	int i=0;
	while(current!=NULL&& i<k)
	{
		next=current->next;
		current->next=prev;
		prev=current;
		current=next;
		i++;
	}
	*head_ref=prev;
	if(next!=NULL)
	{
		struct node*temp=prev;
		while(temp->next!=NULL)
			{temp=temp->next;}
		temp->next=current;

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
{	struct node*a=NULL;
	struct node *b=NULL;
	struct node *final=NULL;
	push(&final,10);
	push(&final,2);
	push(&final,32);
	push(&final,5);
	push(&final,67);
	push(&final,5);
	push(&final,6);
	printList(&final);
	printf("enter value of k:");
	int k;
	scanf("%d",&k);
	reverseBatch(&final,k);
	//mergeSort(&final);
	//printLi++ st(&head);
	//swap(&head,1,8);
	printList(&final);
	return 0;

}