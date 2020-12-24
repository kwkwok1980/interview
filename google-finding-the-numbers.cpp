#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<int> singleNumber(std::vector<int>& nums)
    {
        int x = 0;
        for (int num : nums)
        {
            x = x ^ num;
        }

        int right_most_bit = x & ~(x - 1);

        int a = 0;
        int b = 0;

        for (int num : nums)
        {
            if (num & right_most_bit)
            {
                a = a ^ num;
            }
            else
            {
                b = b ^ num;
            }
        }
        std::vector<int> results = {a, b};
        std::sort(results.begin(), results.end());
        return results;
    }
};

int main()
{
    Solution solution{};

    std::vector<int> values1 {1,2,3,2,1,4};
    std::vector<int> results1 =  solution.singleNumber(values1);
    std::cout << results1[0] << "," << results1[1] << std::endl;

    std::vector<int> values2 {2,1,3,2};
    std::vector<int> results2 =  solution.singleNumber(values2);
    std::cout << results2[0] << "," << results2[1] << std::endl;


}
