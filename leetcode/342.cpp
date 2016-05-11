//342 https://leetcode.com/problems/power-of-four/

class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num == pow(2, 0) || num == pow(2, 2) || num == pow(2, 4) || num == pow(2, 6) || num == pow(2, 8) || 
            num == pow(2, 10) || num == pow(2, 12) || num == pow(2, 14) || num == pow(2, 16) || num == pow(2, 18) || 
            num == pow(2, 20) || num == pow(2, 22) || num == pow(2, 24) || num == pow(2, 26) || num == pow(2, 28) || 
            num == pow(2, 30))
            return true;
        else return false;
    }
};