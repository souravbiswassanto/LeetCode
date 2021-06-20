class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> A(n) ; A =  nums;
        int mindiff = INT_MAX;
        int result;
        for(int i = 0; i < n - 2; i++){
            int l = i + 1, r = n - 1;
            
            while(l < r){
                int val = (A[l] + A[i] + A[r]);
                int diff = abs(target - val);
                if(diff < mindiff){
                    result = val;
                    mindiff = diff;
                    //cout << A[i] <<" " << A[l] <<" "<< A[r]<< endl;
                }
                if(val > target){
                    r--;
                }
                else if(val < target){
                    l++;
                }
                else {
                    
                    return target;
                }
            }
        }
        return result;
    }
};