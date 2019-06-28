//https://practice.geeksforgeeks.org/problems/count-pairs-with-given-sum/0

#include <iostream>
#include <vector>

void Solve(const std::vector<int>& values, int N, int K)
{
    int count = 0;
    for (int i=0; i<N-1; ++i)
    {
        for (int j=i+1; j<N; ++j)
        {
            if (values[i] + values[j] == K)
            {
                ++count;
            }
        }
    }
    std::cout << count << std::endl;
}

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
	    Solve(values, N, K);
	}
	return 0;
}
