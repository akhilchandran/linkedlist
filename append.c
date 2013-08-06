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

int append(struct node** a, struct node** b)
{
	struct node* current = *a;
	if (*a == 0){
		*a = *b;
		return 0;
	}
	while(current->next != 0)
		current = current->next;
	current->next = *b;
	return 0;
}	
main(){
	struct node* a;
	struct node* b;
	a = 0;
	makelist(&b);
	append(&a,&b);
        print_list(a);
        makelist(&a);
	append(&a,&b);
	print_list(b);
//	b = 0;
//        append(&a,&b);
//        print_list(a);
}
