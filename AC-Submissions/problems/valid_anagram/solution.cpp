class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<char> vs, vt;
        for(auto c: s)vs.push_back(c);
        for(auto c: t)vt.push_back(c);
        sort(vs.begin(),vs.end());
        sort(vt.begin(),vt.end());
        if(vs == vt) return true;
        return false;
    }
};