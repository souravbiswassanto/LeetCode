class Solution {
public:
    
    string convert(string s){
        string nwS = "@";
        for (int i = 0; i < (int)s.size(); i++) {
            nwS += "#" + s.substr(i, 1);
        }
        nwS += "#$";
        return nwS;
    }
    string longestPalindrome(string s) {
        string res = s;
        s = convert(s);
        int n = s.size();
        int P[s.size() * 2];
        int l = 0, r = -1;
        for(int i = 1; i < (int)s.size() - 1; i++){
            int k;
            if(i > r){
                k = 0;
            }
            else {
                int j = r - i + l;
                k = min (P[j], r - i);
            }
            while(i + k < n and i - k >= 0 and s[i+k] == s[i-k])k++;
            if(s[i-k] != s[i+k])k--;
            P[i] = k;
            if(i + k > r){
                r = i + k;
                l = i - k;
            }
        }
        int maxpal = 0;
        int idx = 0;
        for(int i = 1; i < s.size() - 1; i++){
            if(P[i] > maxpal){
                maxpal = P[i];
                idx = i - P[i] ;
                idx /= 2;
            }
        }
	return res.substr(idx,maxpal);
    }
};