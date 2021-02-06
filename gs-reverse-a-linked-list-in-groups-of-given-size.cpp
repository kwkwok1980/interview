//https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <tuple>
#include <set>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <fstream>
#include <queue>
#include <stack>
#include <cmath>
#include <iostream>

using namespace std;
/* Link list node */
struct node *reverse (struct node *head, int k);
struct node
{
    int data;
    struct node* next;
}*head;
/* UTILITY FUNCTIONS */
/* Function to push a node */
void insert()
{
    int n,value;
    cin>>n;
    struct node *temp;
    for(int i=0;i<n;i++)
    {
        cin>>value;
        if(i==0)
        {
            head=(struct node *) malloc( sizeof(struct node) );
            head->data=value;
            head->next=NULL;
            temp=head;
            continue;
        }
        else
        {
            temp->next= (struct node *) malloc( sizeof(struct node) );
            temp=temp->next;
            temp->data=value;
            temp->next=NULL;
        }
    }
}
/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("");
}
/* Drier program to test above function*/
int main(void)
{
    /* Start with the empty list */
    int t,k,value,n;
    cin>>t;
    while(t--)
    {
        insert();
        cin>>k;
        head = reverse(head, k);
        printList(head);
    }
    return(0);
}
/*This is a function problem.You only need to complete the function given below*/
/*
  Reverse a linked list
  The input list will have at least one element
  Return the node which points to the head of the new LinkedList
  Node is defined as
  struct node
  {
     int data;
     struct Node *next;
  }
*/
struct node *reverse (struct node *head, int k)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    struct node * prev = nullptr;
    struct node * current = head;
    struct node * next = nullptr;
    int count = k;

    while(current != nullptr && count != 0)
    {
        //std::cout << current->data << " " << k << std::endl;
        next = current->next;
        current->next = prev;

        prev = current;
        current = next;
        --count;
    }

    head->next = reverse(current, k);
    return prev;
}

struct node *reverse2 (struct node *head, int k)
{
    if (head == nullptr)
    {
        return nullptr;
    }
    
    node* A = nullptr;
    node* B = head;
    node* C = nullptr;
    for (int i=0; i<k; ++i)
    {
        C = B->next;
        B->next = A;
        A = B;
        B = C;
    }
    head->next = reverse2(B, k);
    return A;
    
    // Complete this method
}
