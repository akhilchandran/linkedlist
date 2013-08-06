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
        int i = 0;
        *head = 0;
        for(;i<10; i++)
                makenode(head,i);
        print_list(*head);

}

void InsertNth(struct node** headRef, int index, int data) {
	struct node* current = *headRef;
	int i;
	if (index == 0)
		makenode(headRef, data);
	else{
		for (i=0; i<index-1; i++) {
			current = current->next;
		}
		makenode(&(current->next), data);
	}
}
main(){
        struct node* head;
        makelist(&head);
	InsertNth(&head, 1, 11);
	print_list(head);
}

