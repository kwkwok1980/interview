//https://practice.geeksforgeeks.org/problems/count-the-numbers/0

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
#include <tuple>
#include <set>
#include <memory>
#include <unordered_map>
#include <sstream>

int maxLen(int arr[], int N)
{
    int max = 0;
    int results[N];

    for (int i=0; i<N; ++i)
    {
        results[i] = (arr[i] == 0 ? -1 : 1);
        for (int j=i+1; j<N; ++j)
        {
            results[j] = results[j-1] + (arr[j] == 0 ? -1 : 1);
            if (results[j] == 0)
            {
                max = std::max(max, j-i+1);
            }
        }
    }
    return max;
}

int main()
{
    int T = 0;
    int N = 0;
    std::cin >> T;
    for (int t=0; t<T; ++t)
    {
        std::cin >> N;
        std::unique_ptr<int[]> values{new int[N]};
        for (int n=0; n<N; ++n)
        {
            std::cin >> values[n];
        }
        std::cout << maxLen(values.get(), N) << std::endl;
    }
    return 0;
}
