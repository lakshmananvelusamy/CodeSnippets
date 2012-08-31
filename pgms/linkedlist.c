#include<stdio.h>
struct node
{
	int data;
	struct node* next;
};


struct node* create_list(int n)
{
	int i;
	struct node *head, *p;
	if (n < 1)
		return NULL;
	
	p = head = (struct node*) malloc(sizeof(struct node));
	for(i = 0; i < n - 1; i++)
	{
		printf("Enter the node %d date : ", i+1);
		scanf("%d", &p->data);
		p->next = (struct node*) malloc(sizeof(struct node));	
		p = p->next;
	}
	printf("Enter the node %d date : ", n);
	scanf("%d", &p->data);
	p->next = NULL;
	return head;
}

void print_list(struct node *p)
{
	while(p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int construct_BST(struct node * p, int n)
{
	

}

main()
{
	struct node * head = NULL;
	int n;
	printf("Enter the no of elements : ");
	scanf("%d", &n);
	head = create_list(n);	
	print_list(head);
	construct_BST(head, n);
	return 0;
}
