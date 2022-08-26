class Solution {
public:
    bool reorderedPowerOf2(int n) {
        int poftwo = 1;
        int cnt[10]; memset(cnt, 0, sizeof cnt);
        int m = n;
        while(m) {
            cnt[m % 10]++; m /= 10;
        }
        for (int i = 1; poftwo <= 1e9; ++i) {
            
            int m = poftwo;
            int cntr[10];
            memset(cntr, 0, sizeof cntr);
            while(m) {
                cntr[m % 10]++; m /= 10;
            }
            int c = 0;
            for (int j = 0; j < 10; ++j) {
                if (cnt[j] == cntr[j])c++;
            }
            if (c == 10) return true;
            poftwo *= 2;
        }
        return false;
    }
};