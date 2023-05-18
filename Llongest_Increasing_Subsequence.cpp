#include <bits/stdc++.h>
using namespace std;
int longestincreasingsubsequence(int a[],int n)
{
    int dp[n];
    for(int i=0;i<n;i++) dp[i] = 1;
    int ans = 0;
    for(int i=0;i<n;i++) 
    {
        for(int j=0;j<i;j++)
        {
            if(a[j]<a[i])
            {
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        ans = max(ans,dp[i]);
    }
    int k = ans,arr[k],mc = INT_MAX;
    for(int i=n;i>=0&&k;i--)
    {
        if(dp[i] == k && a[i]<mc) 
        {
            arr[k-1] = a[i];
            mc = a[i];
            k--;
        }
    }
    cout << "LIS : ";
    for(auto i:arr)cout << i << ' ';
    return ans; 
}
int main()
{
    int a[]={1,7,8,2,3,9,4};
    cout << "\nLIS len : " <<longestincreasingsubsequence(a,7)<< endl;
}
