//https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1/

//https://practice.geeksforgeeks.org/problems/surpasser-count0615/1

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
#include <map>
#include <sstream>
#include <limits>
#include <functional>
#include <numeric>

class Solution
{
private:
    int Solve (int pages[], int N, int M)
    {
        int begin = 0;
        int end = std::accumulate(pages, pages + N, 0);
        while (begin < end)
        {
            int mid = (begin + end) / 2;
            int n = 0;
            int m = 0;
            while (m < M)
            {
                int page = 0;
                if (n < N)
                {
                    page = pages[n++];
                    while (n < N && (page + pages[n]) <= mid)
                    {
                        page = page + pages[n++];
                    }
                }
                ++m;
            }

            //std::cout << "C0 " << m << " " << n << " " << begin << " " << mid << " " << end << std::endl;
            if (n == N)
            {
                end = mid;
            }
            else
            {
                begin = mid+1;
            }
            //std::cout << "C1 " << m << " " << n << " " << begin << " " << mid << " " << end << std::endl;

        }

        int result = begin;
        for (int n=0; n<N; ++n)
        {
            result = std::max(result, pages[n]);
        }
        return result;
    }

public:
    int findPages(int pages[], int N, int M)
    {
        return Solve(pages, N, M);
    }
};

int main()
{
    int arr[] = {250,74,159,181,23,45,129,174};
    int n = sizeof(arr) / sizeof(int);
    int m = 6;
    Solution solution{};
    int result = solution.findPages(arr, n, m);
    std::cout << "ABC " << result  << std::endl;
}
