//https://practice.geeksforgeeks.org/problems/smallest-subarray-with-sum-greater-than-x/0
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

void Solve(int N, int X, const std::vector<int>& values)
{
    int i = 0;
    int j = 0;
    int sum = 0;
    int min = std::numeric_limits<int>::max();

    while (i<N)
    {
        while(j<N && sum<=X)
        {
            sum += values[j];
            ++j;
        }

        //std::cout << sum << " " << i << " " << j << std::endl;
        if (sum > X)
        {
            int length = j-i;
            if (length < min)
            {
                min = length;
            }
            sum -= values[i];
            ++i;
        }
        else
        {
            break;
        }
    }

    std::cout << min << std::endl;
}

int main() {
    int T = 0;
    int N = 0;
    int X = 0;
    std::cin >> T;
    for (int t=0; t<T; ++t)
    {
        std::cin >> N;
        std::cin >> X;
        std::vector<int> values(N);
        for (int n=0; n<N; ++n)
        {
            std::cin >> values[n];
        }
        Solve(N, X, values);
    }
    return 0;
}
