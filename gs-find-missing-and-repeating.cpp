//https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1/

class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        
        int value1 = 0;
        for (int i=1; i<=n; ++i)
        {
            value1 = value1 ^ i;
        }
        
        
        int value2 = 0;
        for (int i=0; i<n; ++i)
        {
            value2 = value2 ^ arr[i];
        }
        
        int value3 = value1 ^ value2;
        
        int value4 = ((value3-1) ^ value3) & value3;
        
        int value5 = 0;
        
        int value6 = 0;
        
        for (int i=1; i<=n; ++i)
        {
            if (i & value4)
            {
                value5 = value5 ^ i;
            }
            else
            {
                value6 = value6 ^ i;
            }
        }
        
        for (int i=0; i<n; ++i)
        {
            if (arr[i] & value4)
            {
                value5 = value5 ^ arr[i];
            }
            else
            {
                value6 = value6 ^ arr[i];
            }
        }
        
        int B = value5;
        int A = value6;
        
        for (int i=0; i<n; ++i)
        {
            if (A == arr[i])
            {
                B = value6;
                A = value5;
                break;
            }
        }

        return new int[2]{B,A};
    }
};
