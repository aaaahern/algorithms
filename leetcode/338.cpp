//338 https://leetcode.com/problems/counting-bits/ 

class Solution {
public:
    //if the ith number is even, the bit count is the same as i/2th; 
    //otherwise the bit count is one more than bit count of ith.
    vector<int> countBits(int num) {
        vector<int> result(num + 1);
        result[0] = 0;
        for (int i = 0; i < num + 1; i++) {
            if (i % 2 == 0) 
                result[i] = result[i/2];
            else
                result[i] = result[i-1] + 1;
        }
        return result;
    }
};