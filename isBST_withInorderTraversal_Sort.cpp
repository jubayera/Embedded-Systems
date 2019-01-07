/* Do in-order traversal of the given tree and store the result in a temp array.
   Check if the temp array is sorted in ascending order, if it is, then the tree is BST.
   Time complexity: O(n).
    We can avoid the use of Auxiliary Array. While doing In-Order traversal, we can track of previously visited Node.
If the value of the currently visited Node is less than the previous value, then tree is not BST. As such space optimization is obtained.*/

//C++ program to check if a given tree is BST.
#include <bits/stdc++.h>
using namespace std;

//A binary tree Node has data, pointer to left child and a pointer to right child
struct Node
{
    int data;
    struct Node *left, *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

//the use of static variable can also be avoided by using reference to prev Node as a parameter.
bool isBSTUtil(struct Node* root, Node *&prev)
{
    //traverse the tree in inorder fashion and keep track of prev Node
    if(root)
    {
        if(!isBSTUtil(root->left, prev))
            return false;
        
        //Allows only distinct valued Nodes
        if(prev != NULL && root->data <= prev->data)
            return false;

        prev = root;

        return isBSTUtil(root->right, prev);
    }

    return true;
}

bool isBST(Node *root)
{
    Node *prev = NULL;
    return isBSTUtil(root, prev);
}

bool isBST_using_static_var(struct Node* root)
{
        static struct Node *prev = NULL;

        //traverse the tree in inorder fashion and keep track of prev Node
        if(root)
        {
                if(!isBST(root->left))
                        return false;

                //Allows only distinct valued Nodes
                if(prev != NULL && root->data <= prev->data)
                        return false;

                prev = root;
         
                return isBST(root->right);
        }

        return true;
}

int main()
{
    struct Node *root = new Node(3);
    root->left      = new Node(2);
    root->right      = new Node(5);
    root->left->left  = new Node(1);
    root->left->right = new Node(4);

    if(isBST(root))
        cout << "Is BST";
    else
        cout << "Not a BST";

    return 0;
}
