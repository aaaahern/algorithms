class Solution {
public:
    string reverseVowels(string s) {
        if (s.size() == 0) return s;
        int i = 0;
        int j = s.size() - 1;
        while (i < j) {
            while (i < j && !isVowels(s[i]))
                i++;
            while (i < j && !isVowels(s[j]))
                j--;
            if (i < j) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }
        return s;
    }
    
    bool isVowels(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
        else
            return false;
    }
};