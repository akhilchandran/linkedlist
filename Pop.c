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

int Pop(struct node** headRef) {
	struct node* head;
	int result;
	head = *headRef;
	if (head == NULL)
		exit(1);
	result = head->data;
	*headRef = head->next;
	free(head);
	return(result);
}
main(){
        struct node* head;
	int pop;
        makelist(&head);
        pop = Pop(&head);
	print_list(head);
}

