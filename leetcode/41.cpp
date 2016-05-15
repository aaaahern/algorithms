//41 https://leetcode.com/problems/first-missing-positive/
class Solution {
public:
    //we are looking for first missing num from [1, nums.size()]
    //so we can try to put all possitive num on corresponding position
    //then the first position index unmatching the value is the result
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] != i+1) {
                if (nums[i] >= 1 && nums[i] <= nums.size() && nums[i] != nums[nums[i]-1]) {
                    swap(nums[i], nums[nums[i]-1]);
                    continue;
                }
            }
            i++;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (i+1 != nums[i]) {
                return i+1;
            }
        }
        return nums.size()+1;
    }
};
