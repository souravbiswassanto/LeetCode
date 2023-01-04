class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> hashMap;
        for (int i = 0; i < tasks.size(); i++) {
            hashMap[tasks[i]]++;
        }
        long long res = 0;
        for (auto it1: hashMap) {
            int it = it1.second;
            if(it % 3) res += (it / 3 + 1);
            else res += it / 3;
            if (it == 1) return -1;
        }
        return res;
    }
};