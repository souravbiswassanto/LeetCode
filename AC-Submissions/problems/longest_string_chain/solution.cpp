class Solution {
public:
    bool static compare(string &A, string &B){
        return A.size() < B.size();
    }
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> dp;
        sort(words.begin(), words.end(), compare);
        for(int i = 0; i < words.size(); i++){
            dp[words[i]] = -1;
        }
        for(int i = words.size() - 1; i >= 0; i--){
            if(words[i].size() == 1)break;
            if(dp[words[i]] == -1)dp[words[i]] = 1;
            for(int j = 0; j < words[i].size(); j++){
                string s = "";
                for(int k = 0; k < words[i].size(); k++){
                    if(j == k)continue;
                    s += words[i][k];
                }
                if(s.size() == 0)continue;
                if(dp.find(s) != dp.end())dp[s] = max((int)dp[s], (int)dp[words[i]] + 1);
            }
        }
        int Max = 1;
        for(int i = 0; i < words.size(); i++){
            //cout << words[i] <<" " << dp[words[i]] << endl;
            Max = max(dp[words[i]], Max);
        }
        return Max;
    }
};