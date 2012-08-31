#include<iostream>
using namespace std;

class Node
{
public:
	Node *left, *right;
	int data;
	Node *  create_tree(int *a, int n);
	void inorder(Node *p);
	void preorder(Node *p);
	void postorder(Node *p);
};

Node * Node::create_tree(int *a, int n)
{
	if (n <= 0)
	{
		return NULL;
	}
	int mid;
	mid = n / 2;
	Node *l, *r;
	l = create_tree(a, mid);
	r = create_tree(a + mid + 1, n - mid - 1);
	Node *node = new Node();
	node->data = a[mid];
	node->left = l;
	node->right = r;
	return node;
}
void Node::inorder(Node *p)
{
	if (p == NULL)
	{
		return;
	}
	inorder(p->left);
	cout<<p->data<<" ";
	inorder(p->right);
}	
	
void Node::preorder(Node *p)
{
	if (p == NULL)
	{
		return;
	}
	cout<<p->data<<" ";
	preorder(p->left);
	preorder(p->right);
}	
	
void Node::postorder(Node *p)
{
	if (p == NULL)
	{
		return;
	}
	postorder(p->left);
	postorder(p->right);
	cout<<p->data<<" ";
}	
	
main()
{
	int a[]={1,2,3,4,5,6,7,8,9};
	Node obj, *root;
	cout<<sizeof(a)<<" = SIZE\n";
	root = obj.create_tree(a, sizeof(a)/sizeof(int));
	obj.inorder(root);
	cout<<endl;
	obj.preorder(root);
	cout<<endl;
	obj.postorder(root);
	cout<<endl;
}
