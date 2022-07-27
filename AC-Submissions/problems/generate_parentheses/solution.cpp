class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> answer; n *= 2;
        string globalString = ""; for(int i = 0; i < n; i++)globalString += 'a';
        function<void(int, int)> backtrack = [&](int idx, int sum){
            
            if(idx == n){
                bool isvalid = true;
                int cntr = 0;
                for(int i = 0; i < n; i++){
                    if(globalString[i] == '(')cntr++;
                    else cntr--;
                    if(cntr < 0)isvalid = false;
                }
                if(cntr != 0 or isvalid == false)return;
                answer.push_back(globalString);
                return;
            }
            if(sum < 0)return;
            if(sum > (n - idx))return;
            globalString[idx] = '(';
            backtrack(idx + 1, sum + 1);
            globalString[idx] = ')';
            backtrack(idx + 1, sum - 1);
            return;
        };
        backtrack(0, 0);
        return answer;
    }
};