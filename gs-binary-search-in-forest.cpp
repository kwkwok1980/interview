//https://practice.geeksforgeeks.org/problems/ffd66b6a0bf7cefb9987fa455974b6ea5695709e/1/

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

int find_height(int tree[], int n, int k)
{
    int min = 0;
    int max = std::numeric_limits<int>::min();
    for (int i=0; i<n; ++i)
    {
        max = std::max(max, tree[i]);
    }

    while (min <= max)
    {
        int mid = (max + min)/2;

        int wood = 0;
        for (int i=0; i<n; ++i)
        {
            if (tree[i] > mid)
            {
                wood = wood + tree[i] - mid;
            }
        }

        std::cout << min << " " << max << " " << mid << " " << wood << std::endl;

        if (wood == k)
        {
            return mid;
        }

        if (wood > k)
        {
            min = mid + 1;
        }
        else
        {
            max = mid - 1;
        }
    }

    return -1;
    // code here
}

int main()
{
    int tree [] = {54,5,65,82,40,21,65};
    int n = sizeof(tree) / sizeof(int);
    int k = 86;
    int h = find_height(tree, n, k);
    std::cout << h << std::endl;
}
