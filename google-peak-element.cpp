#include <iostream>


int peakElementInternal(int arr[], int n, int i, int j)
{
    int d = j-i;
    if (d == 1)
    {
        return i;
    }
    else if (d==2)
    {
        if (arr[i] > arr[i+1])
        {
            return i;
        }
        else
        {
            return i+1;
        }
    }
    else
    {
        int k = d/2;
        if (arr[k-1] <= arr[k] && arr[k] >= arr[k+1])
        {
            return k;
        }
        else if (arr[k-1] <= arr[k])
        {
            return peakElementInternal(arr, n, k+1, j);
        }
        else
        {
            return peakElementInternal(arr, n, i, k);
        }
    }
}

int peakElement(int arr[], int n)
{
    return peakElementInternal(arr, n, 0, n);
}


int main()
{
    int arr[] = {6,1,15,19,9,13,12,6,7,2,10,4,1,14,11,14,14,13};
    int k = peakElement(arr, 18);
    std::cout << k << std::endl;
    std::cout << arr[k] << std::endl;
    return 0;
}
