//343 https://leetcode.com/problems/integer-break/

class Solution {
public:
    // **try to get more 3**
    // 2, 3 are special case, they can only be broken to 1*1 and 1*2
    // 3 is the biggest factor, 4:2*2, 5:2*3
    int integerBreak(int n) {
        if (n == 2) return 1;
        if (n == 3) return 2;
        
        if (n % 3 == 0) return pow(3, n/3);
        else if (n % 3 == 1) return pow(3, n/3-1) * 4;
        else return pow(3, n/3) * 2;
    }
};