//https://practice.geeksforgeeks.org/problems/k-anagrams-1/0

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>
#include <unordered_map>
#include <unordered_set>


struct Anagram
{
   int keys[26];
};

struct Equal
{
    bool operator()(const Anagram& a1, const Anagram& a2) const
    {
        for(int i=0; i<26; ++i)
        {
            if (a1.keys[i] != a2.keys[i])
            {
                return false;
            }
        }
        return true;
    }
};

struct Hash
{
    unsigned int operator()(const Anagram& a) const
    {
        static std::hash<int> INT_HASH{};
        unsigned int value = 31;
        for (const auto& key : a.keys)
        {
            value |= INT_HASH(key);
        }
        return value;
    }
};

std::vector<std::vector<std::string>> Anagrams(std::vector<std::string>& string_list)
{
    std::vector<std::vector<std::string>> results{};
    std::unordered_map<Anagram, int, Hash, Equal> anagramsMap{};

    for (const auto& string_value : string_list)
    {
        Anagram a{};
        for (const auto &c : string_value)
        {
            ++a.keys[c - 'a'];
        }

        auto itFind = anagramsMap.find(a);
        if (itFind != anagramsMap.end())
        {
            results[itFind->second].push_back(string_value);
        }
        else
        {
            results.emplace_back(std::vector<std::string>{string_value});
            anagramsMap.emplace(a, results.size()-1);
        }

    }
    return results;
}
