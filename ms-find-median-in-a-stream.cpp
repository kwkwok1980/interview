//https://practice.geeksforgeeks.org/problems/find-median-in-a-stream/0

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
#include <fstream>

void Solve(int N)
{
    int value = 0;
    std::priority_queue<int, std::vector<int>, std::less<int>> leftValues{};
    std::priority_queue<int, std::vector<int>, std::greater<int>> rightValues{};
    std::stringstream ss{};

    int median = 0;
    for (int i=0; i<N; ++i)
    {
        std::cin >> value;
        if (i == 0)
        {
            leftValues.push(value);
        }
        else
        {
            if (value < leftValues.top())
            {
                leftValues.push(value);
            }
            else
            {
                rightValues.push(value);
            }
        }

        if (std::abs(static_cast<int>(leftValues.size() - rightValues.size())) == 2)
        {
            if (leftValues.size() > rightValues.size())
            {
                rightValues.push(leftValues.top());
                leftValues.pop();
            }
            else
            {
                leftValues.push(rightValues.top());
                rightValues.pop();
            }
        }

        if (leftValues.size() == rightValues.size())
        {
            median = (leftValues.top() + rightValues.top())/2;
        }
        else if (leftValues.size() > rightValues.size())
        {
            median = leftValues.top();
        }
        else
        {
            median = rightValues.top();
        }

        std::cout << median << std::endl;
    }
}

int main()
{
    int N = 0;
    std::cin >> N;
    Solve(N);
    return 0;
}

