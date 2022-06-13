class Solution {
public:
    int dp[1001][100 + 1], n, k;
    vector<int> Prices;
    int calc (int idx, int kth){
        if(idx >= n or kth == k)return 0;
        int &ret = dp[idx][kth];
        if(ret != -1)return ret;
        ret = 0;
        for(int i = idx + 1; i < n; i++){
            if(Prices[idx] > Prices[i])continue;
            ret = max(ret, calc(i + 1, kth + 1) + (Prices[i] - Prices[idx]));
        }
        ret = max(ret, calc(idx + 1,  kth));
        return ret;
    }
    
    int maxProfit(int K, vector<int>& prices) {
        Prices = prices;
        n = prices.size();
        k = K;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < k; j++){
                dp[i][j] = -1;
            }
        }
        int ans = calc(0, 0);
        return ans;
        
    }
};