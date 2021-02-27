//https://practice.geeksforgeeks.org/problems/max-absolute-difference/0

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
#include <mutex>
#include <atomic>
#include <memory>
#include <thread>
#include <condition_variable>
#include <chrono>


void Solve(std::vector<int>& values)
{
    int N = values.size();
    int result = std::numeric_limits<int>::min();
    int sums[100][100]{};

    for (int i=0; i<N; ++i)
    {
        int sum = 0;
        for (int j=i; j<N; ++j)
        {
            sum = sum + values[j];
            sums[i][j] = sum;
        }
    }

    for (int i=0; i<N; ++i)
    {
        for (int j=i; j<N; ++j)
        {
            for (int k=j; k<N; ++k)
            {
                for (int l=k; l<N; ++l)
                {
                    result = std::max(result, std::abs(sums[i][j] - sums[k][l]));
                }
            }
        }
    }

    std::cout << result << std::endl;
}

int main()
{
    int T = 0;
    std::cin >> T;
    for (int t=0; t<T; ++t)
    {
        int K = 0;
        std::cin >> K;

        std::vector<int> values{};
        for (int k=0; k<K; ++k)
        {
            int value;
            std::cin >> value;
            values.push_back(value);
        }

        Solve(values);
    }
}
