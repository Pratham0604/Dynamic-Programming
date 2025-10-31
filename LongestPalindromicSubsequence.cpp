class Solution {
public:

    int LCS(string a, string b){
        int n = a.size();
        int m = b.size();

        int dp[n+1][m+1];

        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                if(i==0 || j==0) dp[i][j]=0;
            }
        }

        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                if(a[i-1] == b[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        return dp[n][m];
    }

    int longestPalindromeSubseq(string s) {

        string revstr = s;
        reverse(revstr.begin(),revstr.end());
    
        int ans = LCS(s,revstr);
        
        return ans;
    }
};
/*
The std::reverse() function modifies the sequence in place (it reverses the contents of s directly).

It has a void return type, meaning it returns nothing.
*/