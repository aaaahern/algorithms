//334 https://leetcode.com/problems/increasing-triplet-subsequence/
class Solution {
public:
    //idea: keep lowing first and second
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;
        int first = nums[0];
        int second = INT_MAX;
        for (int num : nums) {
            if (num < first)
                first = num;
            else if (num > first && num < second) 
                second = num;
            else if (num > first && num > second)
                return true;
        }
        return false;
    }
};