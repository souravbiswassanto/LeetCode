class Solution {
public:
    int removePalindromeSub(string s) {
        string s1 = s;
        reverse(s1.begin(), s1.end());
        if(s == s1)return 1;
        else return 2;
    }
};