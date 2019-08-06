//https://practice.geeksforgeeks.org/problems/nth-fibonacci-number/0

#include <iostream>
using namespace std;

static const int mod = 1000000007;

void Solve(int N)
{
    int v0 = 0;
    int v1 = 1;
    int v2 = 1;
    int n = 2;
    while (n < N)
    {
        v0 = v1;
        v1 = v2;
        v2 = (v0 + v1) % mod;
        ++n;
    }
    std::cout << v2 << std::endl;
}

int main() {
	int T = 0, N = 0;
	std::cin >> T;
	for (int t=0; t<T; ++t)
	{
	    std::cin >> N;
	    Solve(N);
	}
	return 0;
}
