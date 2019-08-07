//https://practice.geeksforgeeks.org/problems/check-for-bst/1

{
#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
/* Returns true if the given tree is a binary search tree
 (efficient version). */
bool isBST(struct Node* node);
int isBSTUtil(struct Node* node, int min, int max);
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d
", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d
",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
      //  cout << n1 << " " << n2 << " " << (char)lr << endl;
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     cout << isBST(root) << endl;
  }
  return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/
/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
}; */
bool isBSTInternal(Node* node, int& min, int& max)
{
    if (node == nullptr)
    {
        return true;
    }
    
    int leftMin = 0;
    int leftMax = 0;
    if (!isBSTInternal(node->left, leftMin, leftMax))
    {
        return false;
    }
    
    int rightMin = 0;
    int rightMax = 0;
    if (!isBSTInternal(node->right, rightMin, rightMax))
    {
        return false;
    }
    
    int thisMin = 0;
    int thisMax = 0;
    
    if (leftMin != 0)
    {
        thisMin = leftMin;
    }
    else
    {
        thisMin = node->data;
    }
    
    if (leftMax !=0 )
    {
        if (leftMax > node->data)
        {
            return false;
        }
    }
    
    if (rightMin != 0)
    {
        if (rightMin < node->data)
        {
            return false;
        }
    }
    
    if (rightMax != 0)
    {
        thisMax = rightMax;
    }
    else
    {
        thisMax = node->data;
    }
    
    min = thisMin;
    max = thisMax;
    return true;
}

bool isBST(Node* root) {
    int min = 0;
    int max = 0;
    return isBSTInternal(root, min, max);
}
