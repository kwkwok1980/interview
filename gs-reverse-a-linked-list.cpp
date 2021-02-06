//https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1

#include <stack>
#include <iostream>
#include <vector>

struct Node {
    int data;
    Node* next;
};

struct Node* reverseList1(struct Node *head)
{
    Node* A = nullptr;
    Node* B = head;
    Node* C = nullptr;
    
    while (B != nullptr)
    {
        C = B->next;
        B->next = A;
        A = B;
        B = C;
    }
    return A;
}

struct Node* reverseList2(struct Node *head)
{
    if (head->next == nullptr)
    {
        return head;
    }
    
    Node* A = head;
    Node* B = head->next;
    
    head = reverseList2(B);
    B->next = A;
    A->next = nullptr;
    return head;
}

Node* reverse2(Node* node)
{
    std::stack<Node*> nodes{};
    while(node != nullptr)
    {
        nodes.push(node);
        node = node->next;
    }

    Node* head = nullptr;
    while(!nodes.empty())
    {
        Node* next = nodes.top();
        nodes.pop();
        next->next = nullptr;

        if (head == nullptr)
        {
            node = next;
            head = next;
        }
        else
        {
            node->next = next;
            node = next;
       }
    }

    return head;
}

