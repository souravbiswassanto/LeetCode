class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int maxFromLeft[n + 1];
        int maxFromRight[n + 1];
        int counter = 1; int reset = 1;
        maxFromLeft[0] = maxFromRight[n - 1] = 1;
        for(int i= 1; i < n; i++){
            if(ratings[i] > ratings[i - 1]){
                counter++;
                maxFromLeft[i] = counter;
            }
            else{
                counter = reset;
                maxFromLeft[i] = 1;
            }
        }
        counter = reset;
        for(int i = n - 2; i >= 0; i--){
            if(ratings[i] > ratings[i + 1]){
                maxFromRight[i] = ++counter;
            }
            else{
                counter = reset;
                maxFromRight[i] = 1;
            }
        }
        int minCandyNeeded = 0;
        for(int i = 0; i < n; i++){
            minCandyNeeded += max(maxFromLeft[i], maxFromRight[i]);
        }
        return minCandyNeeded;
    }
};