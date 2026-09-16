class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(1+n,0));
        for(int i=0;i<n;i++)
            dp[i][i] = 1;
        
        for(int l=2;l<=n;l++){
            for(int i=0;i+l-1<n;i++){
                int j = i+l-1;
                if(s[i] == s[j])
                    dp[i][j] = 2 + dp[i+1][j-1];
                else
                    dp[i][j] = max(dp[i+1][j] , dp[i][j-1]);
            }
        }

        return n-dp[0][n-1];
    }
};