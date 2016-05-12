//347 https://leetcode.com/problems/top-k-frequent-elements/
//we don't need to sort whole list, we only care about k
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (int num : nums) {
            map[num]++;
        }
        vector<int> result;
        priority_queue<pair<int, int>> pq;
        for (auto iter = map.begin(); iter != map.end(); iter++) {
            pq.push(make_pair(iter->second, iter->first));
            if (pq.size() > map.size() - k) {
                result.push_back(pq.top().second);
                pq.pop();
            }
        }
        return result;
    }
};