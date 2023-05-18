#include<stdio.h>
#include <string.h>
int max(int a,int b) 
{
    if(a>b) return a;
    return b;
}
int longestCommonSubsequence(char text1[],char text2[]) {
        int n = strlen(text1),m = strlen(text2);
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=m;j++) {
                if(i==0 or j==0) {
                    dp[i][j] = 0;
                }
                else if(text1[i-1] == text2[j-1]) {
                    dp[i][j] = 1+dp[i-1][j-1];
                }
                else {
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int i = n,j = m,k = dp[n][m]-1;
        char ch[dp[n][m]+1];
        ch[k+1]='\0';
        while(i>0 && j>0) 
        {
            if(text1[i-1] == text2[j-1]) 
            {
                ch[k] = text2[j-1];
                i --;
                j --;
                k --;
            }
            else if(dp[i-1][j] > dp[i][j-1]) i--;
            else j--;
        }
        printf("LCS : %s",ch);
        printf("\n");
        return dp[n][m];
    }
int main()
{
    char a[20]="hello",b[20]="helloworld";
    printf("LCS len : %d",longestCommonSubsequence(a,b));
}
