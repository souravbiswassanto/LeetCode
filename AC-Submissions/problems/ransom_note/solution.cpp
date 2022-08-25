class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int cnt[26];
        memset(cnt, 0, sizeof cnt);
        for (int i = 0; i < magazine.size(); ++i) {
            cnt[magazine[i] - 97]++;
        }
        for (int i = 0; i < ransomNote.size(); ++i) {
            cnt[ransomNote[i] - 97]--;
            if (cnt[ransomNote[i] - 97] < 0) return false;
        }
        return true;
    }
};