class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int mxArea = 0;
        int maxGapHorizontal = 0;
        int maxGapVertical = 0;
        for(int i = 0; i < horizontalCuts.size() - 1; i ++){
            maxGapHorizontal = max(maxGapHorizontal, horizontalCuts[i + 1] - horizontalCuts[i]);
        }
        for(int i = 0; i < verticalCuts.size() - 1; ++i) {
            maxGapVertical = max(maxGapVertical, verticalCuts[i + 1] - verticalCuts[i]);
        }
        mxArea = (maxGapHorizontal * 1LL * maxGapVertical) % 1000000007;
        return mxArea;
    }
};