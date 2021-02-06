//https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string5459/1

#include <algorithm>
string reverseWords(string S) 
{ 
    std::reverse(S.begin(), S.end());
    auto it1 = S.begin();
    auto it2 = S.begin();
    while (true)
    {
        while (*it2 != '.' && it2 != S.end())
        {
            ++it2;
        }
        std::reverse(it1, it2);
        
        if (it2 == S.end())
        {
            break;
        }
        it1 = it2 + 1;
        it2 = it2 + 1;
    }
    return S;
} 
