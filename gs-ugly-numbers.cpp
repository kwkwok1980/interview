//https://practice.geeksforgeeks.org/problems/ugly-numbers/0

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <tuple>
#include <set>
#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <fstream>
#include <queue>
#include <stack>
#include <cmath>
#include <iostream>

void Solve(int N)
{
    std::unordered_set<int> values{1};
    int n = 2;

    auto task = [&](int _n, int _d)
    {
        if ((_n % _d) == 0)
        {
            if (values.find(_n / _d) != values.end())
            {
                return true;
            }
        }
        return false;
    };

    while (true)
    {
        if (task(n, 2) || task(n, 3) || task(n, 5))
        {
            values.emplace(n);
        }

        if (values.size() < N)
        {
            ++n;
        }
        else
        {
            break;
        }
    }

    std::cout << n << std::endl;
}

void Solve2(int N)
{
    std::set<int> values{1};
    while(values.size() < N)
    {
        std::unordered_set<int> currents{};
        for (int value : values)
        {
            currents.emplace(value * 2);
            currents.emplace(value * 3);
            currents.emplace(value * 5);
        }

        for (int current : currents)
        {
            if (values.find(current) == values.end())
            {
                values.emplace(current);
            }
        }
    }

    int n = 1;
    auto it = values.begin();
    while(n < N)
    {
        ++n;
        ++it;
    }
    std::cout << *it << std::endl;
}


void Solve4(int N)
{
    std::vector<int> values{1};

    int min2 = 2;
    int min3 = 3;
    int min5 = 5;
    int count2 = 0;
    int count3 = 0;
    int count5 = 0;

    while (values.size() < N)
    {
        int minN = std::min(min2, std::min(min3, min5));
        values.push_back(minN);

        if (min2 == minN)
        {
            min2 = values[++count2] * 2;
        }

        if (min3 == minN)
        {
            min3 = values[++count3] * 3;
        }

        if (min5 == minN)
        {
            min5 = values[++count5] * 5;
        }
    }
    std::cout << *values.rbegin() << std::endl;
}

void Solve5(std::int64_t N)
{
    static bool init = false;
    static std::vector<std::int64_t> values{};
    static std::queue<std::int64_t> queue2{};
    static std::queue<std::int64_t> queue3{};
    static std::queue<std::int64_t> queue5{};

    if (!init)
    {
        values.push_back(1);
        queue2.push(2);
        queue3.push(3);
        queue5.push(5);
        init = true;
    }

    while (values.size() < N)
    {
        std::int64_t min = std::min(queue2.front(), std::min(queue3.front(), queue5.front()));
        values.push_back(min);

        if (min == queue2.front())
        {
            queue2.pop();
        }

        if (min == queue3.front())
        {
            queue3.pop();
        }

        if (min == queue5.front())
        {
            queue5.pop();
        }

        queue2.emplace(2*min);
        queue3.emplace(3*min);
        queue5.emplace(5*min);
    }
    std::cout << values[N-1] << std::endl;
}


int main()
{
    int T = 0;
    int N = 0;

    std::cin >> T;
    for (int t=0; t<T; ++t)
    {
        std::cin >> N;
        Solve5(N);
    }
    return 0;
}
