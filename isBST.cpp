/* A program to check if a binary tree is BST or not.
   A binary search tree (BST) is a node based binary tree data structure which has the following properties:
    -> The left subtree of a node contains only nodes with keys less than the node's key.
    -> The right subtree of a node contains only nodes with keys greater than the node's key.
    -> Both the left and right subtrees must also be binary search trees.
    
    From the above properties it naturally follows that:
    -> Each node (item in the tree) has a distinct key.
    
                4
                   / \
                  2   5
                 / \
                1   3

Method 1 (Simple but wrong): 
    Following is a simple program. For each node, check if left node of it is smaller than the node and right node of it is greater than the node. */

int isBST(struct node* node)
{
    if(node == NULL)
        return 1;

    //false if left is > than node
    if(node->left != NULL && node->left->data > node->data)
        return 0;

    //false if right is < than node
    if(node->right != NULL && node->right->data < node->data)
        return 0;

    //false if, recursively, the left or right is not a BST
    if(!isBST(node->left) || !isBST(node->right))
        return 0;

    //passing all that, it is a BST
    return 1;
}
/*
This approach is wrong as this will return true for below binary tree (and below tree is not a BST because 4 is in left subtree of 3)
        3
           / \
          2   5
             / \
            1   4

Method 2 (Correct but not efficient)
    For each node, check if max value in left subtree is smaller than the node and min value in right subtree greater than the node.*/

/* Returns true if a binary tree is a binary search tree */
int isBST(struct node* node)
{
    if(node == NULL)
        return true;

    //false if the max of the left is > than current node
    if(node->left != NULL && maxValue(node->left) > node->data)
        return false;

    //false if the min of the right is < than current node
    if(node->right != NULL && minValue(node->right) < node->data)
        return false;

    //false if, recursively, the left or right is not a BST
    if(!isBST(node->left) || !isBST(node->right))
        return false;

    //passing all that, it's a BST
    return true;
}

/* It is assumed that we have helper functions minValue() and maxValue() that returns the min or max int value from a non-empty tree*/

/* Method 3 (Correct and Efficient):
    Method 2 above runs slowly since it traverses some parts of the tree many times. A better solution looks at each node only once.
The trick is to write a utility helper function isBSTUtil(struct node* node, int min, int max) that traverses down the tree keeping track
of the narrowing min and max allowed values as it goes, looking at each node only once. The initial values for min and max should be INT_MIN
and INT_MAX - they narrow from there.*/
//Returns true if the given tree is a binary search tree (efficient version)
int isBST(struct node* node)
{
    return(isBSTUtil(node, INT_MIN, INT_MAX));
}

//Returns true if the given tree is a BST and its values are >= min and <=max
int isBSTUtil(struct node* node, int min, int max)
