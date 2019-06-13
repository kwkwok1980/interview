//https://practice.geeksforgeeks.org/problems/reverse-words-in-a-given-string/0

#include <iostream>
#include <array>
#include <vector>
#include <algorithm>

void Solve(std::string& value)
{
    std::reverse(value.begin(), value.end());

    auto it1 = value.begin();
    auto it2 = value.begin();
    while(it1 != value.end() && it2 != value.end())
    {
        while(*it2 != '.' && it2 != value.end())
        {
            ++it2;
        }
        std::reverse(it1, it2);

        if (it2 != value.end())
        {
            it1 = it2 + 1;
            it2 = it1;
        }
    }
    std::cout << value << std::endl;
}


int main()
{
    int T =0;
    std::cin >> T;
    for (int t=0; t<T; ++t)
    {
        std::string sLine{};
        std::cin >>  sLine;
        Solve(sLine);
    }

    return 0;
}
