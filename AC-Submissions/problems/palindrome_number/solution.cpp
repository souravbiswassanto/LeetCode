class Solution {
public:
    bool isPalindrome(int x) {
        int n = abs(x);
        long long ans = 1, rev = 0; 
        while (n){
            int rem = n % 10;
            n /=  10;
            rev = rev * 10LL + rem;
        }
        if(rev == x){
            return true;
        }
        else return false;
    }
};