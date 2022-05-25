class Solution {
public:
    int longestValidParentheses(string s) {
        s = '*' + s; int n = s.size();
        int arr[n + 1];
        
        stack<int> S; arr[0] = 0;
        for(int i = 1; i < s.size(); i++){
            if(s[i] == '('){
                S.push(i);
                arr[i] = 0;
            }
            else{
                if(S.size() == 0){
                    arr[i] = 0;
                }
                else{
                    int a = S.top(); S.pop();
                    arr[i] = i - a + 1 + arr[a - 1];
                }
            }
        }
        int Max = 0;
        for(int i = 1; i < s.size(); i++){
            Max = max(Max, arr[i]);
        }
        return Max;
    }
};