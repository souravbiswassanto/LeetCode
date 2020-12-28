class Solution {
public:
    int reverse(int y) {
        long long x = y;
        bool check = false;
        if(x < 0) {
            check = true;
            x *= -1;
        }
        string s = "";
        while(x){
            int rem = x % 10; x /= 10;
            s += rem + 48;
        }
        x = 0;
        long long ans = 1;
        long long range1 = (1LL<<31) * - 1, range2 = (1LL<<31) - 1;
        for(int i = s.size()-1; i >= 0; i--){
            x += (s[i] - 48) * ans ;
            ans *=  10;
        }
        if(x < range1 or x > range2)return 0;
        if(check){
            return -1*x;
        }
        else return x;
        
    }
};