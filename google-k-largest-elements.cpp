#include <iostream>
#include <vector>
#include <algorithm>

#include <iostream>
#include <vector>
#include <algorithm>

#include <iostream>
#include <vector>
#include <set>
#include <iterator>

struct MyGreater
{
    bool operator()(int x, int y)
    {
        return x > y;
    }
};

using CompType = std::greater_equal<int>;

class Solution
{
public:
    std::vector<int> kLargest(int arr[], int n, int k)
    {
        std::vector<int> results{};
        for (int i=0; i<k; ++i)
        {
            results.emplace_back(arr[i]);
        }
        std::sort(results.begin(), results.end(), CompType{});
        std::copy(results.begin(), results.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;

        for (int i=k; i<n; ++i)
        {
            if (arr[i] > *results.rbegin())
            {
                results.erase(results.end()-1);
                results.insert(std::upper_bound(results.begin(), results.end(), arr[i], CompType{}), arr[i]);
                std::copy(results.begin(), results.end(), std::ostream_iterator<int>(std::cout, " "));
                std::cout << std::endl;
            }
        }
        return results;
    }
};

int main()
{
    {
        int arr []= {1, 23, 12, 9, 30, 2, 50};
        int n = 7;
        int k = 3;
        Solution solution{};
        std::vector<int> results = solution.kLargest(arr, n, k);
        std::copy(results.begin(), results.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
    }
}

