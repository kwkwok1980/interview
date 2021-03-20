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

class Solution2
{
private:
    int Solve (int pages[], int N, int M)
    {
        int min = 0;
        int max = std::accumulate(pages, pages + N, 0) ;
        int pageMin = std::numeric_limits<int>::max();

        while (min < max)
        {
            int mid = min + (max - min)/2;
            //std::cout << "CA " << min << " " << mid << " " << max << " " << std::endl;

            int pageMax = std::numeric_limits<int>::min();
            int m = 0;
            int n = 0;

            while (m < M && n < N)
            {
                int page = pages[n];
                ++n;
                ++m;

                while (n < N)
                {
                    if (page + pages[n] <= mid)
                    {
                        page = page + pages[n];
                        ++n;
                    }
                    else
                    {
                        break;
                    }
                }

                std::cout << m << " " << n << " " << page << std::endl;
                pageMax = std::max(pageMax, page);
            }

            std::cout << "C0 " << m << " " << n << " " << min << " " << mid << " " << max << " " << pageMax << " " << pageMin << std::endl;
            if (n == N && m == M)
            {
                pageMin = std::min(pageMin, pageMax);
                std::cout << "C1 " << m << " " << n << " " << min << " " << mid << " " << max << " " << pageMax << " " << pageMin << std::endl;
                max = mid;
            }
            else if (n == N)
            {
                std::cout << "C2 " << m << " " << n << " " << min << " " << mid << " " << max << " " << pageMax << " " << pageMin << std::endl;
                max = mid;
            }
            else
            {
                std::cout << "C3 " << m << " " << n << " " << min << " " << mid << " " << max << " " << pageMax << " " << pageMin << std::endl;
                min = mid;
            }
        }

        //std::cout << "result " << pageMin << std::endl;
        return pageMin;
    }

public:
    int findPages(int arr[], int n, int m)
    {
        return Solve(arr, n, m);
    }
};


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
