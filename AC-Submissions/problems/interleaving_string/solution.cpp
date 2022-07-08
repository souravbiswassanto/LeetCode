class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int k = s3.size();
        int dp[n + 2][m + 2];
        memset(dp, -1, sizeof dp);
        
        function<int(int, int, int)> calc =[&](int N, int M, int K){
            if(K == k){
                if(n == N and m == M)return 1;
                return 0;
            }
            int &ret = dp[N][M];
            if(ret != -1)return ret;
            ret = 0;
            if(N < n and s1[N] == s3[K])ret |= calc(N + 1, M, K + 1);
            if(M < m and s2[M] == s3[K])ret |= calc(N, M + 1, K + 1);
            return ret;
        };
        int ans = calc(0, 0, 0);
        if(ans)return true;
        return false;
    }
};