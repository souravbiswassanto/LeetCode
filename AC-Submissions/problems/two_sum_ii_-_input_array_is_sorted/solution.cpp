class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int leftptr = 0, rightptr = numbers.size() - 1;
        vector<int> result;
        while(1){
            if(numbers[leftptr] + numbers[rightptr] == target){
                result.push_back(leftptr + 1);
                result.push_back(rightptr + 1);
                break;
            }
            else if(numbers[leftptr] + numbers[rightptr] < target)leftptr++;
            else rightptr--;
        }
        return result;
    }
};