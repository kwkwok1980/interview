//https://practice.geeksforgeeks.org/problems/squares-in-nn-chessboard/0
#include <iostream>

class Solution {
  public:
    long long squaresInChessBoard(long long N) {
        long long count = 0;
        for (int i=1; i<=N; ++i)
        {
            count = count + (N-i+1) * (N-i+1);
        }
        return count;
    }
};

int main() {
	int T=0;
	int N=0;
	std::cin >> T;
	for (int t=0; t<T; ++t)
	{
	    std::cin >> N;
	    Solution solution{};
	    std::cout << solution.squaresInChessBoard(N) << std::endl;
	}
	return 0;
}
