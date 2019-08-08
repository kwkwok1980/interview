//https://practice.geeksforgeeks.org/problems/fibonacci-sum/0

#include <iostream>
#include <array>

const int MOD = 1000000007;

void Solve(int N)
{
    static std::array<int, 1000000> values{};
    static std::array<int, 1000000> sums{};
    static int last = 0;
    static bool init = false;
    
    if (!init)
    {
        init = true;
        values[0] = 0;
        values[1] = 1;
        sums[0] = 0;
        sums[1] = 1;
        last = 1;
    }
    
    while (last < N)
    {
        ++last;
        values[last] = (values[last-1] + values[last-2]) % MOD;
        sums[last] = (sums[last-1] + values[last]) % MOD;
    }
    
    std::cout << sums[N] << std::endl;
}

int main() {
	int T = 0;
	int N = 0;
	std::cin >> T;
	for (int t=0; t<T; ++t)
	{
	    std::cin >> N;
	    Solve(N);
	}
	//code
	return 0;
}
