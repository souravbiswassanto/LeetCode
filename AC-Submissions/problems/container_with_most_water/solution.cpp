class Solution {
public:
    int maxArea(vector<int>& height) {
        int sizeOfVec = height.size();
        
        int l = 0, r = sizeOfVec - 1;
        int Area = 0;
        while(l < r){
            int thisArea = min(height[l], height[r]) * (r - l);
            Area = max(Area, thisArea);
            if(height[l] > height[r]){
                r--;
            }
            else l++;
        }
        return Area;
    }
};