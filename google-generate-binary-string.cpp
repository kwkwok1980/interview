//https://practice.geeksforgeeks.org/problems/generate-binary-string3642/1/

class Solution
{
private:
    std::vector<std::string> results{};

    void solve(const std::string& s, const std::string& t, int n)
    {
        if (n == s.size())
        {
            results.emplace_back(t);
            return;
        }

        if (s[n] == '0' || s[n] == '1')
        {
            solve(s, t + s[n], n+1);
        }
        else
        {
            solve(s, t + "0", n+1);
            solve(s, t + "1", n+1);
        }
    }

public:
    std::vector<std::string> generate_binary_string(std::string s)
    {
        solve(s, "", 0);
        return results;
    }
};
