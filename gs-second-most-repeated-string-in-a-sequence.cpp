//https://practice.geeksforgeeks.org/problems/second-most-repeated-string-in-a-sequence/0
#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>

void Solve(const std::vector<std::string>& values, int N)
{
    std::unordered_map<std::string, int> counts{};
    for (const auto& value : values)
    {
        ++counts[value];
    }
    
    int firstCount = 0;
    int secondCount = 0;
    std::string firstString{};
    std::string secondString{};
    
    for (auto& count : counts)
    {
        if (count.second > firstCount)
        {
            secondCount = firstCount;
            secondString = firstString;
            firstCount = count.second;
            firstString = count.first;
        }
        else if(count.second > secondCount)
        {
            secondCount = count.second;
            secondString = count.first;
        }
    }
    std::cout << secondString << std::endl;    
}


int main() 
{
	int T=0;
	int N=0;
	
	std::cin >> T;
	for (int t=0; t<T; ++t)
	{
	    std::cin >> N;
	    std::vector<std::string> values(N);
	    for (int n=0; n<N; ++n)
	    {
	        std::cin >> values[n];
	    }
	    Solve(values, N);
	}
	
	
	//code
	return 0;
}
