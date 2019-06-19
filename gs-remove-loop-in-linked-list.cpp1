//https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1

void removeTheLoop(Node *head)
{
    Node* pFirst = head;
    Node* pSecond = head;
    bool loop = false;
    
    while (pFirst != nullptr && pSecond != nullptr && pSecond->next != nullptr)
    {
        pFirst = pFirst->next;
        pSecond = pSecond->next->next;
        if (pFirst == pSecond)
        {
            loop = true;
            break;
        }
    }
    
    if (!loop)
    {
        return;
    }
    
    int count = 0;
    do
    {
        ++count;
        pFirst = pFirst->next;
    }
    while (pFirst != pSecond)
    
    pFirst = head;
    pSecond = head;
    while (count != 1)
    {
        pSecond = pSecond->next;
        --count;
    }

    bool stop = false;
    while(!stop)
    {
        if (pFirst == pSecond->next)
        {
            pSecond->next = nullptr;
            stop = true;
        }
        else
        {
            pFirst = pFirst->next;
            pSecond = pSecond->next;
        }
    }
}
