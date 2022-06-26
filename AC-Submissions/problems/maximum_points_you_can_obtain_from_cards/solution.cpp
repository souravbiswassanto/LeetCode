class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        int mx = 0;
        for(int i = 0; i < k; i++)sum += cardPoints[i];
        mx = sum;
        int left = k - 1;
        if(cardPoints.size() == k)return sum;
        for(int i = cardPoints.size() - 1, j = 0; j < k; i--, j++){
            sum += cardPoints[i];
            sum -= cardPoints[left];
            left--;
            mx = max(mx, sum);
        }
        return mx;
    }
};