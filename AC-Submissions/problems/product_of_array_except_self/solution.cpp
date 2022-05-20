class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        stack<int> front, back;
        front.push(1);
        back.push(1);
        for(int i = 0; i < nums.size(); i++){
            front.push(front.top() * nums[i]);
        }
        vector<int> sol(nums.size(), 0);
        for(int i = nums.size() -1; i >= 0; i--){
            front.pop();
            sol[i] = front.top() * back.top();
            back.push(back.top() * nums[i]);
        }
        return sol;
    }
};