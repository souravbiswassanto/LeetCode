class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        bool vis[n + 1][n+ 1]; bool dp[n + 1][n + 1];
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= n; j++)vis[i][j] = 0;
        }
        bool check = false;
        function<bool(int , int)> calc = [&] (int i, int sum){
            if (check) return true;
            if(i == n){
                if(sum == 0){check = true; return true;}
                else return false;
            }  
            if(sum < 0)return false;
            if(vis[i][sum])return dp[i][sum];
            vis[i][sum] = 1;
            dp[i][sum] = 0;
            if(s[i] == '*'){
                dp[i][sum] |= (calc(i + 1, sum + 1));
                dp[i][sum] |= calc(i + 1, sum - 1);
                dp[i][sum] |= calc(i + 1, sum);
            }
            else if(s[i] == '('){
                dp[i][sum] |= calc(i + 1, sum + 1);
            }
            else {
                dp[i][sum] |= calc(i + 1, sum - 1);
            }
            return dp[i][sum];
        };
        bool result = calc(0, 0);
        return result;
        
    }
};