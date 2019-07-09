//https://practice.geeksforgeeks.org/problems/sum-tree/1
{
#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
};
bool isSumTree(struct Node* node);
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data)
{
  struct Node* node = new Node;
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}
/* Computes the number of nodes in a tree. */
int height(struct Node* node)
{
  if (node==NULL)
    return 0;
  else
    return 1 + max(height(node->left), height(node->right));
}
void inorder(Node *root)
{
    if (root == NULL)
       return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
/* Driver program to test size function*/
int main()
{
  int t;
  scanf("%d
", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = newNode(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = newNode(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     cout << isSumTree(root) << endl;
  }
  return 0;
}
}
/*This is a function problem.You only need to complete the function given below*/
/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

int sumTree(Node* root)
{
    if (root == nullptr)
    {
        return 0;
    }
    
    int leftSum = sumTree(root->left);
    int rightSum = sumTree(root->right);
    
    if (leftSum == -1 || rightSum == -1)
    {
        return -1;
    }
    
    if (leftSum == 0 && rightSum == 0)
    {
        return root->data;
    }
    
    if (root->data == (leftSum + rightSum))
    {
        return 2* root->data;
    }
    
    return - 1;
}

// Should return true if tree is Sum Tree, else false
bool isSumTree(Node* root)
{
    if (root == nullptr)
    {
        return true;
    }
    else
    {
        return sumTree(root) != -1;
    }
}
