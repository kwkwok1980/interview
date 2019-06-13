//https://practice.geeksforgeeks.org/problems/anagram/0

#include <iostream>
#include <algorithm>

int main() {
	int T = 0;
	std::cin >> T;
	for (int t=0; t<T; ++t)
	{
	    int count1[26]{};
	    std::string s1{};
	    std::cin >> s1;
	    for (char c : s1)
	    {
	        ++count1[c-'a'];
	    }
	    
	    int count2[26]{};
	    std::string s2{};
	    std::cin >> s2;
	    for (char c : s2)
	    {
	        ++count2[c-'a'];
	    }
	    
	    bool diff = false;
	    for (int i = 0; i<26; ++i)
	    {
	        if (count1[i] != count2[i])
	        {
	            diff = true;
	            break;
	        }
	    }
	    
	    std::cout << (diff ? "NO" : "YES") << std::endl;
	}
	return 0;
}
