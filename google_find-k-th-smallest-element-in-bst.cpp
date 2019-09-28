//https://practice.geeksforgeeks.org/problems/find-k-th-smallest-element-in-bst/1

void KthSmallestElementInternal(Node *root, int& k, int& r)
{
    if (root == nullptr)
    {
        return;
    }
    
    KthSmallestElementInternal(root->left, k, r);
    if (k == 0)
    {
        return;
    }
    
    --k;
    if (k == 0)
    {
        r = root->data;
        return;
    }
    
    KthSmallestElementInternal(root->right, k, r);
}


int KthSmallestElement(Node *root, int k)
{
    int r;
    KthSmallestElementInternal(root, k ,r);
    return r;
}
