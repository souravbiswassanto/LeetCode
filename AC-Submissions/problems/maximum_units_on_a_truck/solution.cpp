class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<pair<int, int>> V;
        for(int i = 0; i < boxTypes.size(); i++){
            int numberOfBoxes = boxTypes[i][0];
            int unitPerBoxes = boxTypes[i][1];
            V.push_back({unitPerBoxes, numberOfBoxes});
        }
        sort(V.begin(), V.end());
        int totalTaken = 0, sum = 0;
        for(int i = boxTypes.size() - 1; i >= 0; i--){
            int taken = max(0, min(V[i].second, truckSize - totalTaken));
            totalTaken += taken;
            sum += (taken * V[i].first);
        }
        return sum;
    }
};