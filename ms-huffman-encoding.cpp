//https://practice.geeksforgeeks.org/problems/huffman-encoding/0

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <tuple>
#include <set>
#include <memory>
#include <unordered_map>
#include <sstream>
#include <fstream>
#include <queue>

struct Node
{
    char value;
    int frequency;
    std::string code;
    Node* left;
    Node* right;
};

struct NodeLess
{
    bool operator()(const Node* const pNode1, const Node* const pNode2) const
    {
        return pNode1->frequency < pNode2->frequency;
    }
};

struct NodeGreater
{
    bool operator()(const Node* const pNode1, const Node* const pNode2) const
    {
        return pNode1->frequency > pNode2->frequency;
    }
};

void PrintNode(const Node* const pNode)
{
    if (pNode == nullptr)
    {
        return;
    }

    if (pNode->right == nullptr && pNode->left == nullptr)
    {
        std::cout << pNode->code << " ";
    }
    else
    {
        PrintNode(pNode->left);
        PrintNode(pNode->right);
    }
}

void EncodeNode(Node* pNode, const std::string& code)
{
    if (pNode == nullptr)
    {
        return;
    }

    pNode->code = code;
    EncodeNode(pNode->left, code + "0");
    EncodeNode(pNode->right, code + "1");
}

void Solve(std::vector<Node*>& values)
{
    std::priority_queue<Node*, std::vector<Node*>, NodeGreater> input{};
    for (Node* pNode : values)
    {
        input.push(pNode);
    }

    while(input.size() != 1)
    {
        Node* pLeft = input.top();
        input.pop();
        //std::cout << pLeft->value << " " << pLeft->frequency << std::endl;

        Node* pRight = input.top();
        input.pop();
        //std::cout << pRight->value << " " << pRight->frequency << std::endl;

        Node* pParent = new Node();
        pParent->frequency = pLeft->frequency + pRight->frequency;
        pParent->left = pLeft;
        pParent->right = pRight;
        input.push(pParent);
    }

    //std::cout << "-----------------------" << std::endl;
    EncodeNode(input.top(), "");
    PrintNode(input.top());
    std::cout << std::endl;
}

int main()
{
    int T = 0;
    std::cin >> T;
    for (int t=0; t<T; ++t)
    {
        std::string s{};
        std::cin >> s;
        std::vector<Node*> values{};

        for (int n=0; n<s.size(); ++n)
        {
            int frequency = 0;
            std::cin >> frequency;
            Node* pNode = new Node();
            pNode->frequency = frequency;
            pNode->value = s[n];
            values.push_back(pNode);
        }

        Solve(values);
    }
    return 0;
}
