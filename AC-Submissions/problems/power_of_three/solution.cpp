class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        if (n == 1) return true;
        for (int i = 1; i < 21; i++) {
            long long a = 1;
            for (int j = 1; j <= i; ++j) a *= 3LL;
            if (a == n) return true;
        }
        return false;
    }
};