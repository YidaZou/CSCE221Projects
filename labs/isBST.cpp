// C++ program to check if a given tree is BST.
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to
left child and a pointer to right child */
struct Node
{
	int data;
	struct Node* left, *right;
};

// Returns true if given tree is BST.
bool isBST(Node* root, Node* l=NULL, Node* r=NULL)
{
	// Base condition : What happens if the root is NULL? 


	// Check if left and right child exist. 
	// Left node's data should be less than root's data
	// Right node's data should be more than root's data


	// Check recursively for every node.

}

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
	struct Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}


int main()
{
	struct Node *root = newNode(5);
	root->left	 = newNode(3);
	root->right	 = newNode(6);
	root->left->left = newNode(1);
	root->left->right = newNode(4);

	if (isBST(root,NULL,NULL))
		cout << "Is BST";
	else
		cout << "Not a BST";

	return 0;
}
