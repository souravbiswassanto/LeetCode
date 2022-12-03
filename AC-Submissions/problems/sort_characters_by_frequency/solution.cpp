#define pb push_back
class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int, int>> vec;
        int frequency[123] ={0};
        for (int i = 0; i < s.size(); i++) {
            frequency[s[i]]++;
        }
        for (int i = 0; i < 123; i++) {
            vec.pb({frequency[i], i});
        }
        sort(vec.rbegin(), vec.rend());
        string newString = "";
        for (int i = 0; i < vec.size(); i++) {
            for (int j = 0; j < vec[i].first; j++) {
                newString += char(vec[i].second);
            }
        }
        return newString;
    }
};