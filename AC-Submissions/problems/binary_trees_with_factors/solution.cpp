class Solution {
public:
    const int mod = 1e9 + 7;
    int numFactoredBinaryTrees(vector<int>& arr) {
        unordered_map<int, int> hashMap;
        for (int i = 0; i < arr.size(); ++i) {
            hashMap[arr[i]] = 1;
        }
        int sum = arr.size(); sum  = 0;
        sort(arr.begin(), arr.end());
        for(int i = 0; i < arr.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                int a = arr[i] / arr[j];
                if (a * arr[j] != arr[i]) continue;
                if (a <= 1) continue;
                if (hashMap.find(a) == hashMap.end())continue;
                hashMap[arr[i]] = (hashMap[arr[i]] + (hashMap[arr[j]] * 1LL * hashMap[a]) % mod) % mod;
                //cout << hashMap[arr[i]] << endl;
            }
        }
        for (auto a: hashMap) {
            //cout << a.first <<" " << a.second << endl;
            sum = (sum + a.second) % mod;
        }
        return sum;
    }
};