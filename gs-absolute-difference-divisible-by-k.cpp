// https://www.geeksforgeeks.org/problems/absolute-difference-divisible-by-k/1?page=4&company=Goldman%20Sachs&sortBy=submissions

long long countPairs(int n, int arr[], int k) {
    std::unordered_map<int, int> results{};
    for (int i=0; i<n; ++i) {
        int mod = arr[i] % k;
        ++results[mod];
    }
    long long result = 0;
    for (int i=0; i<k; ++i) {
        long long count = results[i];
        if (count > 1) {
            result = result + (count * (count-1)) / 2;
        }
    }
    return result;
}
