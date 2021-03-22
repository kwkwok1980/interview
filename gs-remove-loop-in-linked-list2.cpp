//https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1#

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void removeLoop(Node* head)
{
    Node* first = head;
    Node* second = head->next;
    bool hasLoop = false;
    while (first != nullptr && second != nullptr)
    {
        if (first == second)
        {
            hasLoop = true;
            break;
        }
        else
        {
            first = first->next;
            if (second->next != nullptr)
            {
                second = second->next->next;
            }
            else
            {
                break;
            }
        }
    }
    
    if (!hasLoop)
    {
        return;
    }
    
    
    int count = 0;
    do
    {
        ++count;
        first = first->next;
    }
    while (first != second);
    
    first = head;
    second = head;
    for (int i=0; i<count-1; ++i)
    {
        second = second->next;
    }
    
    while (first != second->next)
    {
        first = first->next;
        second = second->next;
    }
    
    second->next = nullptr;

 }
