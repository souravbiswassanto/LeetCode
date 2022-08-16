class Solution {
public:
    int firstUniqChar(string s) {
        int frequency[26];
        memset(frequency, 0, sizeof frequency);
        for (int i = 0; i <s.size(); ++i) {
            frequency[s[i] - 97]++;
        }
        for (int i = 0; i < s.size(); ++i) {
            if (frequency[s[i] - 97] == 1) return i;
        }
        return -1;
    }
};