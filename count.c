#include<stdio.h>

struct node {
	int		data;
	struct	node*	next;
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

int Count(struct node* head, int searchFor)
{
	struct node* current = head;
	int count = 0;
	while (current != NULL){
		if (current->data == searchFor)
			count++;
		current = current->next;
	}
	return count;
}

main(){
	struct node* head;
	int count;
	makelist(&head);
	count = Count(head, 3);
	printf("%d\n",count);
}
