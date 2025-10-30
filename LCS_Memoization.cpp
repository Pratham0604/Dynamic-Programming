class Solution {
public:

      int lcsRec(string x,string y,int n,int m,vector<vector<int>> &dp){
          
        if(n==0 || m==0) return 0;

        if(dp[n][m] != -1) return dp[n][m];

        else{

        if(x[n-1] == y[m-1]){
            return dp[n][m] = 1+lcsRec(x,y,n-1,m-1,dp);
        }
        else{
            return dp[n][m] = max(lcsRec(x,y,n-1,m,dp),lcsRec(x,y,n,m-1,dp));
        }
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        
        int n=text1.size();
        int m=text2.size();
       // int static dp[n+1][m+1];
        //memset(dp,-1,sizeof(dp));

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        int ans = lcsRec(text1,text2,n,m,dp);
        return ans;
    }
};