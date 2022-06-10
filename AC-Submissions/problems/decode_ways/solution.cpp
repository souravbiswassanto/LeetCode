class Solution {
public:
    int numDecodings(string s) {
        unordered_map<string, bool> M;
        if(s[0] == '0')return 0;
        M["00"] = 1;
        M["30"] = 1;
        M["40"] = 1;
        M["50"] = 1;
        M["60"] = 1;
        M["70"] = 1;
        M["80"] = 1;
        M["90"] = 1;
        for(int i = 0; i < s.size() - 1; i++){
            string s1 = s.substr(i, 2);
            if(M[s1])return 0;
        }
        int dp[s.size() + 4];
        memset(dp, 0, sizeof dp);
        
        dp[0] = 1; dp[1] = 1;
        for(int i = 2; i <= s.size(); i++){
            int num = s[i - 2] - 48; num *= 10;
            num += (s[i - 1] - 48);
            if(s[i - 1] == '0')dp[i] = dp[i - 2];
            else if(num < 10)dp[i] = dp[i - 1];
            else if(num > 26)dp[i] = dp[i - 1];
            else dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        return dp[s.size()];
    }
};