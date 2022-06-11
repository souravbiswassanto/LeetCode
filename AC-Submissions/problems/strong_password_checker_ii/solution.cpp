class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        bool issmall = false, isbig = false, isnum = false, issp = false;
        int n = password.size();
        string s = "!@#$%^&*()-+";
        if(password.size() < 8)return false;
        for(int i = 0; i < n; i++){
            if(password[i] >= 65 and password[i] <= 90)isbig = true;
            if(password[i] >= 97 and password[i] <= 122)issmall = true;
            if(password[i] >= 48 and password[i] <= 57)isnum = true;
            for(int j = 0; j < s.size(); j++){
                if(s[j] == password[i])issp = true;
            }
        }
        bool check = true;
        for(int i = 0; i < n - 1; i++){
            if(password[i] == password[i + 1])check = false;
        }
        if(check == false)return false;
        if(issmall and isbig and isnum and issp)return true;
        else return false;
    }
};