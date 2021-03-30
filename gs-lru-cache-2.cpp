//https://practice.geeksforgeeks.org/problems/surpasser-count0615/1

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <queue>
#include <list>
#include <mutex>
#include <atomic>
#include <memory>
#include <thread>
#include <condition_variable>
#include <chrono>
#include <map>
#include <sstream>
#include <limits>
#include <functional>
#include <numeric>
#include <execution>

struct Node
{
    std::string url;
    std::string content;
    Node* prevNode = nullptr;
    Node* nextNode = nullptr;
};

struct LRUCache2
{
    std::unordered_map<std::string, Node*> cache{};
    Node* headNode = nullptr;
    Node* tailNode = nullptr;
    int K = 20;

    std::string GetPage(const std::string& url)
    {
        auto it = cache.find(url);
        if (it != cache.end())
        {
            Node* currentNode = it->second;
            Remove(currentNode);
            PushBack(currentNode);
            return currentNode->content;
        }
        else
        {
            Node* newNode = new Node();
            newNode->url = url;
            newNode->content = GetPage(url);

            if (cache.size() == K)
            {
                Node* removeNode = PopFront();
                cache.erase(removeNode->url);
                delete removeNode;
            }

            cache[newNode->url] = newNode;
            PushBack(newNode);
        }
    }

    Node* PopFront()
    {
        if (headNode == nullptr)
        {
            return nullptr;
        }
        else if (headNode == tailNode)
        {
            Node* currentNode = headNode;
            currentNode->prevNode = nullptr;
            currentNode->nextNode = nullptr;

            headNode = nullptr;
            tailNode = nullptr;
            return currentNode;
        }
        else
        {
            Node* currentNode = headNode;
            Node* nextNode = currentNode->nextNode;

            currentNode->prevNode = nullptr;
            currentNode->nextNode = nullptr;
            nextNode->prevNode = nullptr;

            headNode = nextNode;
            return currentNode;
        }
    }

    Node* PushBack(Node* currentNode)
    {
        if (headNode == nullptr)
        {
            currentNode->prevNode = nullptr;
            currentNode->nextNode = nullptr;

            headNode = currentNode;
            tailNode = currentNode;
        }
        else
        {
            Node* prevNode = tailNode;
            prevNode->nextNode = currentNode;

            currentNode->prevNode = prevNode;
            currentNode->nextNode = nullptr;

            tailNode = currentNode;
        }
        return currentNode;
    }

    Node* Remove(Node* currentNode)
    {
        Node* prevNode = currentNode->prevNode;
        Node* nextNode = currentNode->nextNode;

        currentNode->prevNode = nullptr;
        currentNode->nextNode = nullptr;

        if (headNode == nullptr)
        {
            return currentNode;
        }
        else if (headNode == currentNode && tailNode == currentNode)
        {
            headNode = nullptr;
            tailNode = nullptr;
            return currentNode;
        }
        else if (headNode == currentNode)
        {
            nextNode->prevNode = nullptr;
            headNode = nextNode;
            return currentNode;
        }
        else if (tailNode == currentNode)
        {
            prevNode->nextNode = nullptr;
            tailNode = prevNode;
            return currentNode;
        }
        else
        {
            prevNode->nextNode = nextNode;
            nextNode->prevNode = prevNode;
            return currentNode;
        }
    }
};

struct LRUCache1
{
    Node* head = new Node{};
    int N = 0;
    int K = 10;

    std::unordered_map<std::string, std::string> cache1{};
    std::list<std::string> cache2{};

    std::string GetPage(const std::string& url)
    {
        auto it1 = cache1.find(url);
        if (it1 != cache1.end())
        {
            cache2.remove(url);
            cache2.push_back(url);
            return it1->second;
        }
        else
        {
            if (cache1.size() == K)
            {
                std::string front = cache2.front();
                cache1.erase(front);
                cache2.pop_front();
            }
            cache1[url] = DownloadPage(url);
            cache2.push_back(url);
        }
    }

    std::string DownloadPage(const std::string& url)
    {
        return "";
    }
};
