{
#include<bits/stdc++.h>
using namespace std;
/*You are required to complete this function */
int remove_duplicate(int [],int );
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int a[N];
        for(int i=0;i<N;i++)
        {
            cin>>a[i];
        }
    int n = remove_duplicate(a,sizeof(a)/sizeof(a[0]));
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    }
}

}

/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*You are required to complete this function */

#include <iostream>
#include <iterator>

int remove_duplicate(int A[],int N)
{
    int p = 1;
    for (int n=1; n<N; ++n)
    {
        if (A[p-1] < A[n])
        {
            A[p++] = A[n];
        }
    }
    return p;
}
