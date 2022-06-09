class Solution {
public:
    vector<int> gpiles,cgpiles;
    int n;
    int dp[203][203];
    int calc(int cur, int m){
        if(cur >= n)return 0;
        int &ret = dp[cur][m];
        if(ret != -1)return ret;
        ret = 0; 
        for(int i = 1; i <= 2 * m; i++){
            if(cur + i > n)break;
            ret = max(ret, cgpiles[cur] - calc(cur + i, max(m, i)));
        }
        return ret;
        
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        gpiles = piles;
        cgpiles.resize(n, 0);
        for(int i = 0; i <= n + 3; i++){
            for(int j = 0; j <= n + 3; j++)dp[i][j] = -1;
        }
        cgpiles[n - 1] = piles[n - 1];
        for(int i = n - 2; i >= 0; i--){
            cgpiles[i] = cgpiles[i + 1] + piles[i];
        }
        int ans = calc(0, 1);
        return ans;
    }
};