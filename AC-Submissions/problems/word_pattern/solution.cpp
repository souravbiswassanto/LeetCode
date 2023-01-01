class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> M;
        unordered_set<string> S;
        stringstream str(s);
        int cntr = 0;
        string word;
        
        while(str >> word) {
            if (M.count(pattern[cntr]) == 0) {
                M[pattern[cntr]] = word;
                if(S.find(word) != S.end()) return false;
                S.insert(word);
            }
            else if(M[pattern[cntr]] != word) return false;
            cntr++;
        }
        if (cntr != pattern.size()) return false;
        return true;
    }
};