// https://www.geeksforgeeks.org/problems/overlapping-rectangles1924/1?page=3&company=Goldman%20Sachs&sortBy=submissions
class Solution {
  public:
    int doOverlap(vector<int> L1, vector<int> R1, vector<int> L2, vector<int> R2) {
        bool b1 = (L1[0] <= L2[0]) && (L2[0] <= R1[0]);
        bool b2 = (L1[0] <= R2[0]) && (R2[0] <= R1[0]);
        bool b3 = (L2[0] <= L1[0]) && (R1[0] <= R2[0]);
        bool b4 = (R1[1] <= L2[1]) && (L2[1] <= L1[1]);
        bool b5 = (R1[1] <= R2[1]) && (R2[1] <= L1[1]);
        bool b6 = (R2[1] <= R1[1]) && (L1[1] <= L2[1]);
        
        if ((b1||b2||b3) && (b4||b5||b6)) {
            return 1;
        } else {
            return 0;
        }
    }
};
