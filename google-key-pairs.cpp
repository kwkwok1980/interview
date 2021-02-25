//https://practice.geeksforgeeks.org/problems/key-pair5616/1

#include <unordered_map>

class Solution{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    std::unordered_map<int,int> values{};
	    for (int i=0; i<n; ++i)
	    {
	        values[arr[i]] = values[arr[i]] + 1;
	    }
	    
	    for (int i=0; i<n; ++i)
	    {
	        int k = x - arr[i];
	        if (k != arr[i])
	        {
	            auto it = values.find(k);
    	        if (it != values.end())
    	        {
    	            return true;
    	        }
    	    }
	        else
	        {
	            if (values[k] > 1)
	            {
	                return true;
	            }
	        }
	    }
	    
	    return false;
	}
};
