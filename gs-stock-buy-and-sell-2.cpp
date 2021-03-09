//https://practice.geeksforgeeks.org/problems/stock-buy-and-sell-1587115621/1

class Solution{
public:
    //Function to find the days of buying and selling stock for max profit.
    vector<vector<int> > stockBuySell(vector<int> A, int n)
    {
        
        std::vector<std::vector<int>> results{};
        int begin = 0;
        int end = 0;
        while (begin < n)
        {
            end = begin + 1;    
            while (end < n)
            {
                if (A[begin] == A[end])
                {
                    ++begin;
                    ++end;
                }
                else
                {
                    break;
                }
            }
            
            while (end < n)
            {
                if (A[end-1] <= A[end])
                {
                    ++end;
                }
                else
                {
                    break;
                }
            }
            
            if (end - begin >= 2)
            {
                std::vector<int> pair{};
                pair.push_back(begin);
                pair.push_back(end-1);
                results.emplace_back(pair);
            }
            
            begin = end;
        }
        return results;
        // code here
    }
};
