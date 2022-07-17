class Solution {
public:
    int mod=1e9+7;
    int kInversePairs(int n, int K) {
        //dp[i][j] denote till i numbers how many jth inversion pair wala permutations are there
        vector<vector<int>> dp(n+1,vector<int>(K+1,0));
        dp[0][0]=0;
        for(int i=1;i<=K;i++){
            dp[1][i]=0;
        }
        for(int i=1;i<=n;i++){
            dp[i][0]=1;
        }
        //now lets say we have N-1 numbers and K inversions and we are adding N to these N-1 numbers
        //if we add N to the end of the array,no increase in inversions will occur eg ****5
        //if we add N to the last second postiion of the array 1 inversion will increase so we will tell the remaining N-1 integers to rearrange them 
		//in such a way that they produce K-1 inversions among themselves because I am contributing 1 inversion by being at the second last postiion
		//eg:***5*(1 inversion increased)
        //similarly ,if we put N to the last third position we will get our answer in dp[N-1][K-2] eg:**5**(2 inversions increased)
        //so basically dp[N][K]=dp[N-1][K]+dp[N-1][K-1]+dp[N-1][k-2]+dp[N-1][k-3]+.......dp[N-1][K-(N-1)];
        //also provided K-(N-1)>=0 at the end in the last term in the formula
        
        //but this will give tle
        //the code will be like
        /*
        for(int i=2;i<=n;i++){
            for(int j=1;j<=k;j++){
                for(int k=0;k<=i-1;k++){
                 if(j-k>=0){
                    dp[i][j]+=d[i][j-k];
                    dp[i][j]%=mod;
                  }
                }
            }
        }
        return dp[N][K];
        */
        //now see the **optimization**
        /*
		Lets say we consider dp[4][6] and dp[4][7],just randomly
		Aplly the formula above,and we will get
        dp[4][6]=dp[3][6]+dp[3][5]+dp[3][4]+dp[3][3]--------------------->(1)
        
        dp[4][7]=dp[3][7]+dp[3][6]+dp[3][5]+dp[3][4]---------------------->(2)
        
        //suntract 1 from 2
        dp[4][7]-dp[4][6]=dp[3][7]-dp[3][3]
        dp[4][7]=dp[4][6]+dp[3][7]-dp[3][3]
         //so dp[N][K]=dp[N-1][K]+dp[N][K-1]-dp[N-1][K-1]
        */
        for(int i=2;i<=n;i++){
            for(int j=1;j<=K;j++){
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
                if(j-i>=0){
                    dp[i][j]=(dp[i][j]-dp[i-1][j-i]+mod)%mod;
                }
            }         
        }
        return dp[n][K];
    }
};