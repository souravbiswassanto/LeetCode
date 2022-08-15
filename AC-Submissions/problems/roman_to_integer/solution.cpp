class Solution {
public:
    int romanToInt(string s) {
        map<char, int> M;
        M['M'] = 1000;
        M['D'] = 500;
        M['C'] = 100;
        M['L'] = 50;
        M['X'] = 10;
        M['V'] = 5;
        M['I'] = 1;
        int sum = 0;
        for(int i = s.size() - 1; i >= 0; i--) {
            if(i > 0 and M[s[i]] > M[s[i - 1]]) {
                sum += M[s[i]] - M[s[i - 1]]; i--;
            }
            else sum += M[s[i]];
        }
        return sum;
    }
};