class Solution {
public:
    int minDeletions(string s) {
        int cnt[26];
        memset(cnt, 0, sizeof cnt);
        for(int i = 0; i < s.size(); i++){
            cnt[s[i] - 97]++;
        }
        vector<int> v;
        for(int  i = 0; i < 26; i++){
            if(cnt[i])v.push_back(cnt[i]);
        }
        sort(v.begin(), v.end());
        int ptr = v[v.size() - 1]; int sum = 0;
        for(int i = v.size() - 2; i >= 0; i--){
            if(ptr == 1){
                sum += v[i]; continue;
            }
            int a = v[i] - (ptr - 1);
            if(a > 0){
                sum += a;
                ptr--;
            }
            else ptr = v[i];
        }
        return sum;
    }
};