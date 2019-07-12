//https://practice.geeksforgeeks.org/problems/counting-sort/1

{
// C Program for counting sort
#include <stdio.h>
#include <string.h>
#define RANGE 255
// The main function that sort the given string arr[] in
// alphabatical order
void countSort(char arr[]);
// Driver program to test above function
int main()
{
    long int t;
    scanf("%ld",&t);
    while(t--)
    {
        long int n;
        scanf("%ld",&n);
        char arr[n+1];
        scanf("%s",arr);
        countSort(arr);
    printf("%s
", arr);
    }return 0;
}

}
/*This is a function problem.You only need to complete the function given below*/
// The main function that sort the given string arr[] in
// alphabatical order
#include <iostream>
void countSort(char arr[])
{
    int count[26]{};
    int N = strlen(arr);
    
    for (int n=0; n<N; ++n)
    {
        ++count[arr[n]-'a'];
    }
    
    for (int i=1; i<26; ++i)
    {
        count[i] = count[i] + count[i-1];
    }
    
    char result [N+1]{};
    for (int n=0; n<N; ++n)
    {
        result[count[arr[n]-'a']-1] = arr[n];
        --count[arr[n]-'a'];
    }
    
    memcpy(arr, result, N);
}
