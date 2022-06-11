class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int n = spells.size();
        int m = potions.size();
        vector<int> res;
        for(int i = 0; i < n; i++){
            long long a = success / spells[i];
            if(success % spells[i])a++;
            int idx = lower_bound(potions.begin(), potions.end(), a) - potions.begin();
            res.push_back(m - idx);
        }
        return res;
    }
};