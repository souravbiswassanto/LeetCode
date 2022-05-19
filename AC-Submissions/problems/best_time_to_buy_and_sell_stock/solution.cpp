class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int Max = 0, Max1 = 0;
        for(int i = prices.size() - 1; i >= 0; i--){
            Max1 = max(Max1, Max - prices[i]);
            Max = max(Max, prices[i]);
        }
    
        return Max1;
    }
};