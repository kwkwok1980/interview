//https://practice.geeksforgeeks.org/problems/knight-walk/0#

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

std::string Solve(const std::string& value)
{
    std::string result = "123456789";
    int index = 0;
    int size = 0;

    auto process = [&]()
    {
        for (int j=0; j<size/2; ++j)
        {
            int begin = index + j;
            int end = index + size - 1 - j;
            std::swap(result[begin], result[end]);
        }
    };

    for (int i=0; i<value.size(); ++i)
    {
        char c = value[i];
        if (c == 'I')
        {
            if (size != 0)
            {
                process();
            }

            index = 0;
            size = 0;
        }
        else
        {
            if (size != 0)
            {
                ++size;
            }
            else
            {
                index = i;
                size = 2;
            }
        }
    }

    if (size != 0)
    {
        process();
    }

    return result.substr(0, value.size() + 1);
}

int main()
{
    int T= 0;
    std::cin >> T;

    for (int t=0; t<T; ++t)
    {
        std::string value{};
        std::cin >> value;
        std::cout << Solve(value) << std::endl;
    }
}
