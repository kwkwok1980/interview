//https://practice.geeksforgeeks.org/problems/squares-in-nn-chessboard/0
#include <iostream>

void Solve(int N)
{
    std::int64_t count=0;
    
    if (N==1)
    {
        std::cout << 1 << std::endl;
        return;
    }
    
    count = 1;
    for (int n=2; n<=N; ++n)
    {
        for (int m=1; m<=n; ++m)
        {
            count += 2*m;
        }
        count -= n;
    }
    
    std::cout << count << std::endl;
}

int main() {
	int T=0;
	int N=0;
	std::cin >> T;
	for (int t=0; t<T; ++t)
	{
	    std::cin >> N;
	    Solve(N);
	}
	return 0;
}
