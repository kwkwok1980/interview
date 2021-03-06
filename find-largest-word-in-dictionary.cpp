//https://practice.geeksforgeeks.org/problems/find-largest-word-in-dictionary2430/1/

class Solution {
  public:
    string findLongestWord(string S, vector<string> d) {
        
        std::string result{};
        
        for (const std::string& value : d)
        {
            int index = 0;
            for (char c : value)
            {
                for (; index<S.size(); ++index)
                {
                    if (c == S[index])
                    {
                        break;
                    }
                }
                
                if ((index < S.size()) == false)
                {
                    break;
                }
            }

            if (index < S.size())
            {
                if (result.size() < value.size())
                {
                    result = value;    
                }
                else if (result.size() == value.size() && value < result)
                {
                    result = value;
                }
            }
        }
        return result;
        // code here
    }
};
