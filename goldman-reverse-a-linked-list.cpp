//https://practice.geeksforgeeks.org/problems/reverse-a-linked-list/1

#include <stack>
#include <iostream>
#include <vector>

struct Node {
    int data;
    Node* next;
};

Node* reverse(Node* node) {
    Node* next = node->next;
    if (next != nullptr)
    {
        Node* head = reverse(next);
        next->next = node;
        node->next = nullptr;
        return head;
    }
    else
    {
        node->next = nullptr;
        return node;
    }
}

Node* reverse2(Node* node)
{
    std::stack<Node*> nodes{};
    while(node != nullptr)
    {
        nodes.push(node);
        node = node->next;
    }
    
    node = nodes.top();
    nodes.pop();
    node->next = nullptr;
    Node* head = node;    
    
    while(!nodes.empty())
    {
        Node* next = nodes.top();
        nodes.pop();
        next->next = nullptr;
        
        node->next = next;
        node = next;
    }
    return head;
}
