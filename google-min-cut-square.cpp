//https://practice.geeksforgeeks.org/problems/min-cut-square3303/1

class Solution{

private:
    int results[101][101]{};

public:
    int minCut(int M, int N)
    {
        if (results[M][N] !=0)
        {
            return results[M][N];
        }

        int result = std::numeric_limits<int>::max();
        int K = std::min(M, N);
        for (int i=1; i<=K; ++i)
        {
            if (i<M && i<N)
            {
                //int result1 = 1 + minCut(M-i, i) + minCut(M-i, N-i) + minCut(i, N-i);
                //result = std::min(result, result1);

                int result2 = 1 + minCut(M-i, N) + minCut(i, N-i);
                result = std::min(result, result2);

                int result3 = 1 + minCut(M-i, i) + minCut(M, N-i);
                result = std::min(result, result3);
            }
            else if (i<M)
            {
                result = std::min(result, 1 + minCut(M-i, i));
            }
            else if (i<N)
            {
                result = std::min(result, 1 + minCut(i, N-i));
            }
            else
            {
                result = 1;
            }
        }
        results[M][N] = result;
        return result;
    }
};
