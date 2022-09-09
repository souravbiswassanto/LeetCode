class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int maxElement = 0; int n = properties.size();
        for (auto it: properties){
            maxElement = max(maxElement, it[0]);
        }
        int arr[maxElement + 2], mxarr[maxElement + 2];
        memset(arr, 0, sizeof arr);
        memset(mxarr, 0, sizeof mxarr);
        for (int i = 0; i < n; i++) {
            arr[properties[i][0]] = max(arr[properties[i][0]], properties[i][1]);
        }
        for (int i = maxElement; i >= 1; i--) {
            mxarr[i] = max(mxarr[i + 1], arr[i]);
        }
        int Counter = 0;
        for (auto it: properties) {
            if (mxarr[it[0] + 1] > it[1]) Counter++;
        }
        
        return Counter;
    }
};