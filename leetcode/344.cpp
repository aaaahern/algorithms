class Solution {
public:
    string reverseString(string s) {
        if (s.size() == 0) return s;
        int j = s.size() - 1;
        int i = 0;
        while (i < j) {
            swap(s[i], s[j]);
            i++;
            j--;
        }
        return s;
    }
};