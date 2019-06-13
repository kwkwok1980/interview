//https://practice.geeksforgeeks.org/problems/non-repeating-character/0

#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

void Solve(const std::string& value)
{
    int counts[26]{0};
    int positions[26]{0};
    int P = 0;

    for (char c : value)
    {
        int index = c - 'a';
        if (counts[index] == 0)
        {
            counts[index] = 1;
            positions[P++] = index;
        }
        else if (counts[index] == 1)
        {
            counts[index] = 2;
        }
    }

    for (int i=0; i<P; ++i)
    {
        if (counts[positions[i]] == 1)
        {
            std::cout << static_cast<char>('a'+positions[i]) << std::endl;
            return;
        }
    }

    std::cout << -1 << std::endl;
}

int main()
{
    int T = 0;
    int N = 0;
    std::string value{};
    std::cin >> T;
    for (int t=0; t<T; ++t)
    {
        std::cin >> N;
        std::cin >> value;
        Solve(value);
    }
}
