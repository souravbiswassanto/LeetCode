class NumArray {
public:
    int n; vector<int> BIT, Nums;
    NumArray(vector<int>& nums) {
        int idx = -1; Nums.resize(nums.size(), 0);
        n = nums.size();
        BIT.resize(n + 2, 0);
        for(auto numberinNums: nums){
            update(++idx, numberinNums);
        }
    }
    
    void update(int index, int val) {
        int temp = val;
        val = val - Nums[index];
        Nums[index] = temp; index++;
        for(int x = index; x <= n; x += x & -x){
            //cout << x <<" " << n << endl;
            BIT[x] += val;
            //cout << x <<" " << n << endl;
        }
        //cout << "h " << endl;
    }
    
    int sumRange(int left, int right) {
        int sumLeft = 0;
        int sumRight = 0;
        for (int x = left; x; x -= x & -x) {
            sumLeft += BIT[x];
        }
        for (int x = right + 1; x; x -= x & -x) {
            sumRight += BIT[x];
        }
        return sumRight - sumLeft;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */