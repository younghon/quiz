#include<stdio.h>
#include<stdlib.h>
 
/* Link list node */
struct node
{
	int data;
	struct node* next;
};

void push(struct node**, int); //add node to the head
int detectloop(struct node *); //return the begin node value of cycle if exists

 
/* Drier program to test above function*/
int main()
{
	/* Start with the empty list */
	struct node* head = NULL;
 
 	push(&head, 20);
 	push(&head, 4);
 	push(&head, 15);
	push(&head, 10);
	push(&head, 50);
 
  	/* Create a loop for testing */
	//50->10->15->4->20--->15 (cycle)
  	head->next->next->next->next = head->next->next;
	
	printf("%d",detectloop(head));
 
	getchar();
}

void push(struct node** head_ref, int new_data)
{
	/* allocate node */
	struct node* new_node =
		(struct node*) malloc(sizeof(struct node));
 
  	/* put in the data  */
  	new_node->data  = new_data;
 
  	/* link the old list off the new node */
  	new_node->next = (*head_ref);
 
  	/* move the head to point to the new node */
  	(*head_ref)    = new_node;
}
 
int detectloop(struct node *list)
{
	struct node  *slow_p = list, *fast_p = list;
 
	while(slow_p && fast_p && fast_p->next)
	{
		slow_p = slow_p->next;
		fast_p = fast_p->next->next;
		if(slow_p == fast_p)
		{
			printf("Found Loop: ");
			slow_p = list;
        		while (slow_p != fast_p)
        		{	
            			slow_p = slow_p->next;
            			fast_p = fast_p->next;
        		}
 
        		/* fast_p is now the looping point */
			return fast_p->data;
		}
	}
	return 0;
}

