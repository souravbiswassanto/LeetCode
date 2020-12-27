class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int A[260];
        for(int i = 0; i <= 257; i++)A[i] = 0;
        int l = 0, r = 0,Max = 0;
        s +='?';
        for(int i = 0; i < s.size(); i++){
            if(i==s.size()-1){
                Max = max(r-l,Max);continue;
            }
            if(A[(int)s[i]]){
                Max = max(Max,r-l);
                for(int j = l; ;j++){
                    if(s[i]==s[j]){l = j + 1;break;}
                    A[(int)s[j]] = 0;
                }
                
            }
            A[(int)s[i]] = 1;
            r++;
        }
        return {Max};
    }
};