class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;
        vector<int> rightPart[n + 1];
        sort(nums.begin(), nums.end());
        int sum = 0, mindiff = INT_MAX, requiredSum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        requiredSum = sum / 2;
        for(int i = 0; i < (1 << n); i++){
            int Bit = 0;
            int totalSum = 0;
            for(int j = 0; j < n; j++){
                if((i & (1 << j)) == 0)continue;
                Bit++;
                totalSum += (nums[n + j]);
            }
            rightPart[Bit].push_back(totalSum);
        }
        for(int i = 0 ;i <= n; i++){
            rightPart[i].push_back(-400000000);
            rightPart[i].push_back(400000000);
            sort(rightPart[i].begin(), rightPart[i].end());
        }
        
        for(int i = 0; i < (1 << n); i++){
            int Bit = 0;
            int totalSum = 0;
            for(int j = 0; j < n; j++){
                if((i & (1 << j)) == 0)continue;
                Bit++;
                totalSum += (nums[j]);
            }
            auto it = upper_bound(rightPart[n - Bit].begin(), rightPart[n - Bit].end(), requiredSum - totalSum);
            //cout << totalSum <<" " << *it <<" " << *(it - 1) << endl;
            int curSum1 = sum - (totalSum + *it);
            int curSum2 = sum - (totalSum + *(--it));
            //cout << curSum1 <<" " << curSum2 << endl;
            int curMinDiff = min(abs(curSum1 * 2 - sum), abs(curSum2 * 2 - sum));
            mindiff = min(mindiff, curMinDiff);
            if(mindiff == 0)break;
        }
        return mindiff;
    }
};