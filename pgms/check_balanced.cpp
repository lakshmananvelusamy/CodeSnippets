#include<iostream>

using namespace std;

class Node
{
public:
	int data;
	Node *left, *right;
};

Node * AddNode(Node *root, int d)
{
	if (root == NULL)
	{
		Node *p = new Node();
		p->data = d;
		p->left = p->right = NULL;
		return p;
	}
	
	if (root->data > d)
	{
		Node *t = AddNode(root->left, d);
		if (root->left == NULL)
		{
			root->left = t;
		}
		return root;
	}
	else 
	{
		Node *t = AddNode(root->right, d);
		if (root->right == NULL)
		{
			root->right = t;
		}
		return root;
	}
}

int checkIfBalanced(Node *root)
{
	int llen, rlen;
	if(root == NULL)
	{
		return 0;
	}
	llen = checkIfBalanced(root->left);
	if (llen == -1)
		return -1;
	rlen = checkIfBalanced(root->right);
	if (rlen == -1)
		return -1;
	int diff = llen - rlen;
	if (diff < -1 || diff > 1)
	{
		cout<<"\nThe tree is not balanced!!\n";
		return -1;
	}
	return (llen > rlen ? llen : rlen) + 1;
}

void inorder(Node *root)
{
	if (root == NULL)
	{
		cout<< "* ";	
		return;
	}
	cout<<"(";
	inorder(root->left);
	cout<<")";
	cout<<root->data<<" ";
	cout<<"{";
	inorder(root->right);
	cout<<"}";
}


main()
{
	Node *root = NULL;
	
	int data;
	while(1)
	{
		cout<<"Enter data (-100 to check if the tree is balanced: -200 to quit) : ";
		cin>>data;
		if (data == -200)
		{
			return 0;
		}
		else if (data == -100)
		{
			if (root != NULL)
				if (checkIfBalanced(root) != -1)
				{
					cout<<"The tree is Balanced!\n";
				}
		}
		else
		{
			root = AddNode(root, data);
			inorder(root);
			cout<<endl;
		}
	}	
}
