class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int sz = *max_element(arr.begin(), arr.end());
        int frequency[sz];
        memset(frequency, 0, sizeof frequency);
        for (int i = 0; i < arr.size(); ++i) {
            --arr[i];
            frequency[arr[i]] ++;
        }
        vector<int> vec;
        for (int i = 0; i < sz; ++i) {
            vec.push_back(frequency[i]);
        }
        sort(vec.begin(), vec.end());
        int target = arr.size() / 2 + (arr.size() % 2);
        int sum = 0; int ans = vec.size();
        for (int i = vec.size() - 1; i  >= 0; i--) {
            sum += vec[i];
            if (sum >= target) {
                ans = vec.size() - i;
                break;
            }
        }
        return ans;
    }
};