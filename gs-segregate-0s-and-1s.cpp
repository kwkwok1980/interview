//https://practice.geeksforgeeks.org/problems/segregate-0s-and-1s/0
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

void Solve(int N, std::vector<int>& values)
{
    int i = 0;
    int j = N-1;
    while (j>i)
    {
        while (values[i] == 0) ++i;
        while (values[j] == 1) --j;
        if (j>i)
        {
            std::swap(values[i], values[j]);
            ++i;
            --j;
        }
    }

    for (int value : values)
    {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}

int main() {
    int T = 0;
    int N = 0;
    std::cin >> T;
    for (int t=0; t<T; ++t)
    {
        std::cin >> N;
        std::vector<int> values(N);
        for (int n=0; n<N; ++n)
        {
            std::cin >> values[n];
        }
        Solve(N, values);
    }
    return 0;
}
