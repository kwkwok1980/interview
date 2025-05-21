// https://www.geeksforgeeks.org/problems/queue-using-two-stacks--115418/1?page=4&company=Goldman%20Sachs&sortBy=submissions

// User function Template for C++
//Back-end complete function Template for C++
class StackQueue {
  private:
    stack<int> s1;
    stack<int> s2;

  public:
    void push(int B) {
        s1.push(B);
    }

    int pop() {
        if (s1.empty()) {
            return -1;
        }
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        int result = s2.top();
        s2.pop();
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        return result;
    }
};
