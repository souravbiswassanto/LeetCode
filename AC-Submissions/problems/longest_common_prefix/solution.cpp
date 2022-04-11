class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int Min = 202;
        for(int i = 0; i < strs.size(); i++){
            Min = min(Min, (int)strs[i].size());
        }
        int flag = 0;
        for(int i = Min; i >= 1; i--){
            flag = true;
            string s = strs[0].substr(0, i);
            for(int j = 0; j < strs.size(); j++){
                string s1 = strs[j].substr(0, i);
                if(s != s1)flag = false;
            }
            if(flag){
                return s;
            }
        }
        return "";
    }
};