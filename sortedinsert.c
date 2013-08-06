#include<stdio.h>

struct node {
        int             data;
        struct  node*   next;
};

void makenode(struct node** head, int value)
{
        struct node *current =(struct node *)malloc(sizeof(struct node));
        current->data = value;
        current->next = *head;
        *head = current;
}

void print_list(struct node* head)
{
        printf("{");
        for(; head !=0; head = head->next){
                printf(" %d,",head->data);
        }
        printf("\b}\n");
}

void makelist(struct node** head)
{
        int i = 9;
        *head = 0;
	makenode(head,i);
	makenode(head,6);
	makenode(head,4);
	makenode(head,0);
        print_list(*head);

}

int sortedInsert(struct node** hedref, struct node* newnode)
{
	struct node* current = *hedref;
	if ((*hedref==NULL)||current->data > newnode->data){
		newnode->next = *hedref;
		*hedref = newnode;
		return 0;
	}
	while (current->next && (current->next)->data < newnode->data){
		current = current->next;
	}
	newnode->next = current->next;
	current->next = newnode;
	return 0;
}	
main(){
	struct node* head;
	struct node* new;
        makelist(&head);
	makenode(&new,10);
	sortedInsert(&head,new);
	print_list(head);
}
