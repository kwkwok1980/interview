//https://practice.geeksforgeeks.org/problems/number-following-a-pattern/0

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

std::string Solve1(const std::string& value)
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

std::string Solve2 (const std::string& value)
{
    std::stringstream ss{};
    int N = value.length();
    int index = 1;

    for (int i=0; i<N; ++i)
    {
        int count = 1;
        if (value[i] == 'I')
        {
            while (i < N && value[i] == 'I')
            {
                ++count;
                ++i;
            }

            for (int j=0; j<count; ++j)
            {
                ss << index + j;
            }
            index = index + count;
        }
        else
        {
            while (i < N && value[i] == 'D')
            {
                ++count;
                ++i;
            }

            for (int j=0; j<count; ++j)
            {
                ss << index + count - 1 - j;
            }
            index = index + count;
        }
    }
    std::cout << ss.str() << std::endl;
    return ss.str();
}

int main()
{
    int T= 0;
    std::cin >> T;

    for (int t=0; t<T; ++t)
    {
        std::string value{};
        std::cin >> value;
        std::cout << Solve2(value) << std::endl;
    }
}
