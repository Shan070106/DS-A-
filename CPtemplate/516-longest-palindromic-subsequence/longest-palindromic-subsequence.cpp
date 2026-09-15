class Solution {
    int lps(string& str,int s, int e, vector<vector<int>>& dp){
        if(s == e) return 1;
        if(s > e) return 0;
        
        if(dp[s][e] != -1) return dp[s][e];

        if(str[s] == str[e]){
            return dp[s][e] = 2 + lps(str,s+1,e-1,dp);
        }

        return dp[s][e] = max(lps(str,s+1,e,dp), lps(str,s,e-1,dp));
     }
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        return lps(s,0,n-1,dp);
    }
};