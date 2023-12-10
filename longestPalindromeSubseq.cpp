    int longestPalindromeSubseq(string s) {
        int dp[s.size()][s.size()];
        for(int i=0;i<s.size();i++) {
            dp[i][i] = 1;
        }
        for(int i=2;i<=s.size();i++) {
            for(int j=0;j<s.size()-i+1;j++) {
                int k = i+j-1;
                if(i==2 && s[j]==s[k]) {
                   dp[j][k] = 2;
                }
                else if(s[j] == s[k]){
                   dp[j][k] = dp[j+1][k-1]+2;
                }
                else {
                   dp[j][k] = max(dp[j+1][k],dp[j][k-1]);
                }
            }
        }
        return dp[0][s.size()-1];
    }