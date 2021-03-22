//https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum/0

#include <iostream>
#include <vector>

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) 
    {
        std::unordered_map<int, int> results{};
        for (int i=0; i<n; ++i)
        {
            ++results[arr[i]];
        }
        
        int count = 0;
        for (auto pair : results)
        {
            if (pair.first * 2 == k)
            {
                count = count + (pair.second * (pair.second-1) / 2);
            }
            else
            {
                auto find = results.find(k - pair.first);
                if (find != results.end())
                {
                    if (pair.first < find->first)
                    {
                        count = count + (pair.second * find->second);    
                    }
                }    
            }
        }
        return count;
    }
};

int main() 
{
	int T=0;
	int N=0;
	int K=0;
	
	std::cin >> T;
	for (int t=0; t<T; ++t)
	{
	    std::cin >> N;
	    std::cin >> K;
	    std::vector<int> values(N);
	    for (int n=0; n<N; ++n)
	    {
	        std::cin >> values[n];
	    }
	    Solution solution{};
	    std::cout << solution.getPairsCount(values.data(), N, K) << std::endl;
	}
	return 0;
}
