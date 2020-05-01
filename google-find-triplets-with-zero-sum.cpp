bool findTriplets(int arr[], int n)
{
    for (int i=0; i<n; ++i)
    {
        for (int j=i+1; j<n; ++j)
        {
            int sum1 = arr[i] + arr[j];
            for (int k=j+1; k<n; ++k)
            {
                int sum2 = sum1 + arr[k];
                if (sum2 == 0)
                {
                    return true;
                }
            }
            
        }
    }

    return false;
}
