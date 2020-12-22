#include <iostream>
#include <vector>


std::vector<int> subarraySum(int arr[], int n, int s)
{
    int sum = 0;
    int a = 0;
    int b = 0;
    for (int i=0; i<n; ++i)
    {
        sum = sum + arr[i];
        b = b + 1;
        if (sum == s)
        {
            return std::vector<int>{a+1, b};
        }
        else if (sum > s)
        {
            while(a < b)
            {
                sum = sum - arr[a];
                ++a;
                if (sum == s)
                {
                    return std::vector<int>{a+1, b};
                }
                else if (sum < s)
                {
                    break;
                }
            }
        }
    }
    return std::vector<int>{-1};
}

int main()
{

    int arr1[] = {1,2,3,7,5};
    std::vector<int> result1 = subarraySum(arr1, 5, 12);
    std::cout << result1[0] << "," << result1[1] << std::endl;

    int arr2[] = {1,2,3,4,5,6,7,8,9,10};
    std::vector<int> result2 = subarraySum(arr2, 10, 15);
    std::cout << result2[0] << "," << result2[1] << std::endl;

}
