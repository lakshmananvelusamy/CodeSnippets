#include<stdio.h>

struct node
{
	int data;
	union 
	{
		struct node *next;
		struct 
		{
			struct node *left, *right;
		};
	};
};

#define NEG_INFINITY 1<<(sizeof(int) * 8 - 1)
#define YES 0
#define NO 1

int isBST(struct node *p)
{
	static int prev = NEG_INFINITY;	
	if (p == NULL) return YES;
	if (isBST(p->left) == NO) return NO;
	if (prev > p->data)
	{
		return NO;
	}
	else prev = p->data;
	if (isBST(p->right) == NO) return NO;
	return YES;
}

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

struct node* construct_BST(struct node * p, int n)
{
	if(n < 1)
	{
		return NULL;
	}
	else if (n == 1)
	{
		p->left = p->right = NULL;
		return p;
	}
	else 
	{
		int i;
		struct node *q, *r = NULL;
		q = p;
		for (i = 1; i <= n / 2; i++)
		{
			r = q;
			q = q->next;
		}
		if (r != NULL)
		{
			r->next = NULL;
		}

		r = q->next;
		q->left = construct_BST(p, i - 1);
		q->right = construct_BST(r, n - i);
		return q;
	}
}

void inorder(struct node *p)
{
	if (p == NULL)
	{
		return;
	}
	inorder(p->left);
	printf("%d ", p->data);
	inorder(p->right);
}

void postorder(struct node *p)
{
	if (p == NULL)
	{
		return;
	}
	inorder(p->left);
	inorder(p->right);
	printf("%d ", p->data);
}

void preorder(struct node *p)
{
	if (p == NULL)
	{
		return;
	}
	printf("%d ", p->data);
	inorder(p->left);
	inorder(p->right);
}

typedef struct node NODE;

void reverse_wrap(NODE *p, NODE *q)
{
	if (p->next == NULL)
	{
		p->next = p;
	}
	else
	{
		reverse_wrap(p->next, p);
	}
	q->next = p->next;
	p->next = q;
}

NODE * reverse(NODE *p)
{
	NODE *q;
	if (p == NULL || p->next == NULL)
	{
		return p;
	}	
	reverse_wrap(p->next, p);
	q = p->next;
	p->next = NULL;
	return q;
}
main()
{
	struct node * head = NULL;
	int n;
	printf("Enter the no of elements : ");
	scanf("%d", &n);
	head = create_list(n);	
	print_list(head);
	head = reverse(head);
	print_list(head);
	head = construct_BST(head, n);
	inorder(head);
	printf("\n");
	preorder(head);
	printf("\n");
	postorder(head);
	printf("\n");
	if (isBST(head) == YES)
	{
		printf("The given tree is BST\n");
	}
	else 
	{
		printf("The given tree is not a BST\n");
	}
	return 0;
}
