// https://www.geeksforgeeks.org/problems/repeating-character-first-appearance-leftmost/1?page=4&company=Goldman%20Sachs&sortBy=submissions

int repeatedCharacter(string s) {
    // Your code here
    std::unordered_map<char, int> results{};
    int N = s.size();
    for (int i=0; i<N; ++i) {
        char c = s[i];
        ++results[c];
    }
    for (int i=0; i<N; ++i) {
        char c = s[i];
        if (results[c] > 1) {
            return i;
        }
    }
    return -1;
}
