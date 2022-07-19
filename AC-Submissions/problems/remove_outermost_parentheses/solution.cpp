class Solution {
public:
    string removeOuterParentheses(string s) {
        string answer = "";
        int cntr = 0;
        int ptr[s.size()];
        memset(ptr, 0, sizeof ptr);
        for(int i = 0; i < s.size(); i++){
            if(cntr == 0)ptr[i] = 1;
            if(s[i] == '(')cntr++;
            else cntr--;
            if(cntr == 0)ptr[i] = 1;
        }
        for(int i = 0; i < s.size(); i++){
            if(!ptr[i])answer += s[i];
        }
        return answer;
    }
};