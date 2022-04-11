class Solution {
public:
    bool isValid(string s) {
        stack<char> S;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == ')'){
                if(!S.empty() and S.top() == '('){
                    S.pop();
                }
                else return false;
            }
            
             if(s[i] == '}'){
                if(!S.empty() and S.top() == '{'){
                    S.pop();
                }
                else return false;
            }
           
            
             if(s[i] == ']'){
                if(!S.empty() and S.top() == '['){
                    S.pop();
                }
                else return false;
            }
            if(s[i] == '(' or s[i] == '{' or s[i] == '[') {
                S.push(s[i]);
            }
        }
        if(S.empty())return true;
        else return false;
    }
};