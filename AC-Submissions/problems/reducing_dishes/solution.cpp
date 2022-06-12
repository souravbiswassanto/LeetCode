class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size(); int Max = 0;
        sort(satisfaction.begin(), satisfaction.end());
        for(int i = n ; i >= 1; i--){
            int cntr = n - 1;
            int sum = 0;
            for(int j = i; j  >= 1; j--){
                sum += (satisfaction[cntr--] * j);
            }
            Max = max(Max, sum);
        }
        return Max;
    }
};