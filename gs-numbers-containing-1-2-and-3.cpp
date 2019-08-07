//https://practice.geeksforgeeks.org/problems/numbers-containing-1-2-and-3/0

#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <map>
#include <set>
#include <array>

static const int MAX = 1000000;

bool IsValid(int n)
{
    static std::array<int, MAX+1> results{};
    if (results[n] != 0)
    {
        return results[n] == 1;
    }
    
    int m = n % 10;
    if (m !=1 && m != 2 && m != 3)
    {
        results[n] = 2;
        return false;
    }
    
    int d = n / 10;
    if (d == 0)
    {
        results[n] = 1;
        return true;
    }
    
    if (IsValid(d))
    {
        results[n] = 1;
        return true;
    }
    else
    {
        results[n] = 2;
        return false;
    }
}

void Solve(const std::vector<int>& values)
{
    std::vector<int> results{};
    for (auto value : values)
    {
        if (IsValid(value))
        {
            results.push_back(value);
        }
    }
    
    if (!results.empty())
    {
        std::sort(results.begin(), results.end());
        for (auto result : results)
        {
            std::cout << result << " ";     
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << -1 << std::endl;
    }
}

int main() {
	int T = 0;
	int N = 0;
	std::cin >> T;
	for (int t=0; t<T; ++t)
	{
	    std::cin >> N;
	    std::vector<int> values(N);
	    for (int n=0; n<N; ++n)
	    {
	        std::cin >> values[n];
	    }
	    Solve(values);
	}
	return 0;
}
