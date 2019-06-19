//https://practice.geeksforgeeks.org/problems/lru-cache/1
{
#include<bits/stdc++.h>
using namespace std;
class LRUCache
{
public:
    LRUCache(int );
 
    int get(int );
 
    void set(int , int );
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    int n;
    cin>>n;
    LRUCache *l  = new LRUCache(n);
    int q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        string a;
        cin>>a;
        if(a=="SET")
        {
            int aa,bb;
            cin>>aa>>bb;
            l->set(aa,bb);
        }else if(a=="GET")
        {
            int aa;
            cin>>aa;
            cout<<l->get(aa)<<" ";
        }
    }
    cout<<endl;
    }
}

}
/*This is a function problem.You only need to complete the function given below*/
/*The structure of the class is as follows 
class LRUCache
{
public:
    LRUCache(int );
    int get(int );
    void set(int , int );
};*/
/*You are required to complete below methods */
/*Inititalize an LRU cache with size N */

#include <map>
#include <unordered_map>

static std::uint64_t counter = 0;
static int size = 0;
static std::unordered_map<int, int> keyToValue{};
static std::unordered_map<int, std::uint64_t> keyToCount{};
static std::map<std::uint64_t, int> countToKey{};

void UpdateCount(int x, int count)
{
    if (count != -1)
    {
        auto itFind = keyToCount.find(x);
        if (itFind != keyToCount.end())
        {
            countToKey.erase(keyToCount[x]);
        }
        countToKey[count] = x;
        keyToCount[x] = count;
    }
    else
    {
        auto itFind = keyToCount.find(x);
        if (itFind != keyToCount.end())
        {
            countToKey.erase(keyToCount[x]);
            keyToCount.erase(x);
        }
    }
}

LRUCache::LRUCache(int N)
{
    counter = 0;
    size = N;
    keyToValue.clear();
    keyToCount.clear();
    countToKey.clear();
}

/*Sets the key x with value y in the LRU cache */
void LRUCache::set(int x, int y)
{
    auto itFind = keyToValue.find(x);
    if (itFind != keyToValue.end())
    {
        keyToValue[x] = y;
        UpdateCount(x, ++counter);
    }
    else
    {
        if (keyToValue.size() == size)
        {
            int key = countToKey.begin()->second;
            keyToValue.erase(key);
            UpdateCount(key, -1);
        }

        keyToValue[x] = y;
        UpdateCount(x, ++counter);
    }
}

/*Returns the value of the key x if
present else returns -1 */
int LRUCache::get(int x)
{
    auto itFind = keyToValue.find(x);
    if (itFind != keyToValue.end())
    {
        UpdateCount(x, ++counter);
        return itFind->second;
    }
    else
    {
        return -1;
    }
}
