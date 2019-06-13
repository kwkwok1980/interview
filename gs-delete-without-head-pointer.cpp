//https://practice.geeksforgeeks.org/problems/delete-without-head-pointer/1
//...
void deleteNode(Node *node)
{
    Node* next = node->next;
    node->data = next->data;
    node->next = next->next;
    delete next;
   // Your code here
}
