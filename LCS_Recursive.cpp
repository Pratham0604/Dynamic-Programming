class Solution {
public:

    int lcsRec(string x,string y,int n,int m){

        if(n==0 || m==0) return 0;

        if(x[n-1] == y[m-1]){
            return 1+lcsRec(x,y,n-1,m-1);
        }
        else{
            return max(lcsRec(x,y,n-1,m),lcsRec(x,y,n,m-1));
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        
        int n=text1.size();
        int m=text2.size();

        int ans = lcsRec(text1,text2,n,m);
        return ans;
    }
};