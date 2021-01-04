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
    std::unordered_map<Anagram, int, Hash, Equal> groupMap{};

    for (const auto& string_value : string_list)
    {
        Anagram a{};
        for (const auto &c : string_value)
        {
            ++a.keys[c - 'a'];
        }

        auto itGroup = groupMap.find(a);
        if (itGroup != groupMap.end())
        {
            results[itGroup->second].push_back(string_value);
        }
        else
        {
            results.emplace_back(std::vector<std::string>{string_value});
            groupMap.emplace(a, results.size()-1);
        }

    }
    return results;
}


int main()
{
    std::vector<std::string> string_list {"act","god","cat","dog","tac"};
    auto results = Anagrams(string_list);
    for (const auto& group : results)
    {
        for (const auto& value : group)
        {
            std::cout << value <<std::endl;
        }
    }
}
