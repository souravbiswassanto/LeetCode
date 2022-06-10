class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> Map;
        int Max = 0;
        int last = -1;
        
        for(int i = 0; i < s.size(); i++){
            if(Map.find(s[i]) == Map.end()){
                Max = max(Max, i - last);
            }
            else{
                last = max(last, Map[s[i]]);
                Max = max(Max, i - last);
            }
            Map[s[i]] = i;
        }
        return Max;
    }
};