class Solution {
public:
    long long totalMoney(int n) {
        long long cntr = 0, sum = 0;
        for(int i = 0;i < n; i++){
            if(i % 7 == 0)cntr++;
            sum += ( i % 7 + cntr);
        }
        return sum;
    }
};