#include <iostream>
#include <vector>
#include <algorithm>

#include <iostream>
#include <vector>
#include <algorithm>

#include <iostream>
#include <vector>


std::vector<int> SolveInternal(int n, int s, const std::vector<int>& values)
{
    int sum = 0;
    int a = 0;
    int b = 0;
    for (int i=0; i<n; ++i)
    {
        sum = sum + values[i];
        b = b + 1;
        if (sum == s)
        {
            return std::vector<int>{a+1, b};
        }
        else if (sum > s)
        {
            while(a < b)
            {
                sum = sum - values[a];
                ++a;
                if (sum == s)
                {
                    return std::vector<int>{a+1, b};
                }
                else if (sum < s)
                {
                    break;
                }
            }
        }
    }
    return std::vector<int>{};
}

void Solve(int N, int S, const std::vector<int>& values)
{
    std::vector<int> results = SolveInternal(N, S, values);
    if (!results.empty())
    {
        std::cout << results[0] << " " << results[1] << std::endl;
    }
    else
    {
        std::cout << -1 << std::endl;
    }
}

int main()
{
    int T = 0;
    std::cin >> T;
    for (int t = 0; t < T; ++t)
    {
        int N =0;
        int S = 0;
        std::cin >> N;
        std::cin >> S;
        std::vector<int> values{};
        for (int n=0; n<N; ++n)
        {
            int value = 0;
            std::cin >> value;
            values.emplace_back(value);
        }
        Solve(N, S, values);
    }

}

