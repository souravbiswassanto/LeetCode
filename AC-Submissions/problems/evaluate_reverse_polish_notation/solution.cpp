class Solution {
public:
    bool compare(string s) {
        if (s.size() >= 2) return false;
        return !(s[0] >= 48 and s[0] <= 57);
    }
    
    long long solve (long long var1, string operand, long long var2) {
        if (operand == "*") return var1 * 1LL * var2;
        if (operand == "+") return var1 + var2;
        if (operand == "-") return var1 - var2;
        return var1 / var2;
    }
    int evalRPN(vector<string>& tokens) {
        stack<long long> s;
        for (int i = 0 ; i < tokens.size(); i++) {
            string token = tokens[i];
            bool isOperand = compare(token);
            if(isOperand) {
                long long num1, num2;
                num1 = s.top(); s.pop();
                num2 = s.top(); s.pop();
                long long result = solve(num2, token, num1);
                s.push(result);
            }
            else s.push(stoi(token));
        }
        return s.top();
    }
};