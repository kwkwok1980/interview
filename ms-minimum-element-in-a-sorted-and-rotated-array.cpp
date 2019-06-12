//https://practice.geeksforgeeks.org/problems/minimum-element-in-a-sorted-and-rotated-array/0

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
#include <queue>


void Solve(int N, int values[])
{
    int left = 0;
    int right = N-1;
    while(left != right)
    {
        int mid = (right + left)/2;
        //std::cout << left << " " << mid << " "<< right << std::endl;

        if (mid == left)
        {
            if (values[left] < values[right])
            {
                right = left;
            }
            else
            {
                left = right;
            }
        }
        else
        {
            if (values[mid] > values[left] && values[mid] > values[right])
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }
    }
    std::cout << values[left] << std::endl;
}

int main()
{
    int T = 0;
    int N = 0;
    std::cin >> T;
    for (int t=0; t<T; ++t)
    {
        std::cin >> N;
        int values[N];
        for (int n=0; n<N; ++n)
        {
            std::cin >> values[n];
        }
        Solve(N, values);
    }
    return 0;
}
