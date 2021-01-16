//https://practice.geeksforgeeks.org/problems/rectangles-in-nn-board/0
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
    std::int64_t sum = 1;
    std::int64_t count = 0;
    for (int i=2; i<=N; ++i)
    {
        count = count + i * sum;
        sum = sum + i;
    }
    std::cout << count * 2 << std::endl;
}

long long rectanglesInChessBoard(long long N) {
    long long rectangleCount = 0;
    long long squareCount = 0;
    for (long long i=1; i<=N; ++i)
    {
        rectangleCount = rectangleCount + (N-i+1);
        squareCount = squareCount + (N-i+1) * (N-i+1);
    }
    rectangleCount = rectangleCount * rectangleCount;
    return rectangleCount - squareCount;
}

int main() {
    int T = 0;
    int N = 0;
    std::cin >> T;
    for (int t=0; t<T; ++t)
    {
        std::cin >> N;
        Solve(N);
    }
    return 0;
}
