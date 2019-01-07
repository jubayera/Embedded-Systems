/* Method 3 (Correct and Efficient):
	Method 2 above runs slowly since it traverses some parts of the tree many times. A better solution looks at each node only once.
The trick is to write a utility helper function isBSTUtil(struct node* node, int min, int max) that traverses down the tree keeping track
of the narrowing min and max allowed values as it goes, looking at each node only once. The initial values for min and max should be INT_MIN
and INT_MAX - they narrow from there.*/
//Returns true if the given tree is a binary search tree (efficient version)
/*int isBST(struct node* node)
{
	return(isBSTUtil(node, INT_MIN, INT_MAX));
}

//Returns true if the given tree is a BST and its values are >= min and <=max
int isBSTUtil(struct node* node, int min, int max)*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

//A binary tree node has data, pointer to left child and a pointer to right child

struct node
{
	int data;
	struct node* left;
	struct node* right;
};

int isBSTUtil(struct node* node, int min, int max);

//Returns true if the given tree is a binary search tree
int isBST(struct node* node)
{
	return(isBSTUtil(node, INT_MIN, INT_MAX));
}

/* Returns true if the given tree is a BST and its values are >= min and <= max. */
int isBSTUtil(struct node* node, int min, int max)
{
	//an empty tree is a BST
	if(node == NULL)
		return 1;

	//false if this node violates the min/max constraint
	if(node->data < min || node->data > max)
		return 0;

	//otherwise check the subtrees recursively, tightening the min or max constraint.
	return
		isBSTUtil(node->left, min, node->data-1) && //Allow only distinct values
		isBSTUtil(node->right, node->data+1, max); //Allow only distinct values
}

/* Helper function that allocates a new node with the given data and NULL left and right pointers. */
struct node* newNode(int data)
{
	struct node* node = (struct node*) malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

int main()
{
	struct node *root = newNode(4);
	root->left 	  = newNode(2);
	root->right	  = newNode(5);
	root->left->left  = newNode(1);
	root->left->right = newNode(3);

	if(isBST(root))
		printf("Is BST");
	else
		printf("Not a BST");

	return 0;
}

/* Output: Is BST
   Time Complexity: O(n)
   Auxiliary Space: O(1) if function call stack size is not considered, otherwise O(n)*/
