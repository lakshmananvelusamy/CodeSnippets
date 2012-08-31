/*
 ============================================================================
 Name        : reverse.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node * next;
};
struct node * construct_list(int n)
{
	struct node *t, *t1, *head;
	int i;
	printf("Enter the valu1 1 : ");
	fflush(stdout);
	head = t = (struct node*)malloc(sizeof(struct node));
	scanf("%d", &t->data);

	for(i = 1; i< n; i++)
	{
		printf("Enter the value %d : ", i+1);
		fflush(stdout);
		t1 = (struct node*)malloc(sizeof(struct node));
		scanf("%d", &t1->data);
		t->next = t1;
		t = t1;
	}
	t->next = NULL;
	return head;
}

void print_list(struct node* p)
{
	while(p)
	{
		printf("%d ", p->data);
		fflush(stdout);
		p = p->next;
	}
}

struct node * reverse_list(struct node *p)
{
	struct node *t;
	if (p == NULL)
	{
		return NULL;
	}
	if(p->next==NULL)
	{
		p->next = p;
		return p;
	}

	t = reverse_list(p->next);
	p->next = t->next;
	t->next = p;
	return p;

}

int main(void) {
	int n;
	struct node *head, *new_head;
	printf("Enter the no of elements : ");
	fflush(stdout);
	scanf("%d", &n);

	head = construct_list(n);
	print_list(head);
	printf("\n");
	reverse_list(head);
	new_head = head->next;
	head->next = NULL;
	print_list(new_head);

}
