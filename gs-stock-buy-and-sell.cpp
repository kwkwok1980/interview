//https://practice.geeksforgeeks.org/problems/stock-buy-and-sell/0

#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <sstream>

void Solve(std::vector<int>& values)
{
    int min = 0;
    int max = 0;
    int N = values.size();
    std::stringstream ss{};

    for (int i=0; i<N; ++i)
    {
        if (i == 0)
        {
            if (values[i] > values[i+1])
            {
                max = i;
            }
            else
            {
                min = i;
            }
        }
        else if (i == N-1)
        {
            if (values[i] > values[i-1])
            {
                max = i;
                ss << "(" << min << " " << max << ") ";
            }
            else
            {
                min = i;
            }
        }
        else
        {
            if (values[i] < values[i-1] && values[i] < values[i+1])
            {
                min = i;
            }
            else if (values[i] > values[i-1] && values[i] > values[i+1])
            {
                max = i;
                ss << "(" << min << " " << max << ") ";
            }
        }
    }

    if (!ss.str().empty())
    {
        std::cout << ss.str() << std::endl;
    }
    else
    {
        std::cout << "No Profit" << std::endl;
    }
}


void Solve2(std::vector<int>& values)
{
    int min = 0;
    int max = 0;
    int N = values.size();
    std::stringstream ss{};

    for (int i=1; i<N; ++i)
    {
        if (values[i] > values[i-1])
        {
            max = i;
        }
        else
        {
            if (min != max)
            {
                ss << "(" << min << " " << max << ") ";
            }
            min = i;
            max = i;
        }
   }

    if (min != max)
    {
        ss << "(" << min << " " << max << ") ";
    }

    if (!ss.str().empty())
    {
        std::cout << ss.str() << std::endl;
    }
    else
    {
        std::cout << "No Profit" << std::endl;
    }
}

int main()
{
    int T = 0;
    int N = 0;
    std::cin >> T;
    for (int t=0; t<T; ++t)
    {
        std::cin >> N;
        std::vector<int> values{};
        for (int n=0; n<N; ++n)
        {
            int a;
            std::cin >> a;
            values.emplace_back(a);
        }
        Solve2(values);
    }

    return 0;
}
