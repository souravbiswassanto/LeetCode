class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.size(); int cntr = 0, cnt = 0;
        for (int i = 0; i < n / 2; i++) {
            int a;
            if (s[i] < 90) s[i] = char(s[i] + 32);
            if (s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u') {
                cntr++;
            }
        }
        for (int i = n / 2; i < n; i++) {
            int a;
            if (s[i] < 90) s[i] = char(s[i] + 32);
            if (s[i] == 'a' or s[i] == 'e' or s[i] == 'i' or s[i] == 'o' or s[i] == 'u') {
                cnt++;
            }
        }
        return cntr == cnt;
    }
};