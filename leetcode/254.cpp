//254 https://leetcode.com/problems/factor-combinations/
class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        if (n < 4) return vector<vector<int>>();
        vector<vector<int>> res;
        vector<int> cur;
        helper(res, cur, n);
        return res;
    }

    void helper(vector<vector<int>>& res, vector<int>& cur, int n) {
        int i;
        //guarantee next candidate factor is bigger than previous one to prevent duplicate
        if (cur.size() > 0) i = cur.back();
        else i = 2;

        for (; i < n; i++) {
            if (n % i == 0) {
                cur.push_back(i);
                helper(res, cur, n / i);
                cur.pop_back();
            }
        }

        if (cur.size() > 0 && n >= cur.back()) {
            cur.push_back(n);
            res.push_back(cur);
            cur.pop_back();
        }

    }
};
