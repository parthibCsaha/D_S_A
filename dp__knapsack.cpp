#include<stdio.h>
int max(int a,int b) 
{
    if(a>b) return a;
    return b;
}
int dp__knapsack(int S,int s[],int v[],int n)
{
    int V[n+1][S+1];
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=S;j++) {
            if(i == 0 || j == 0) {
                V[i][j] = 0;
            }
            else if(s[i-1]<=j) {
                V[i][j] = max(v[i-1]+V[i-1][j-s[i-1]],V[i-1][j]);
            }
            else {
                V[i][j] = V[i-1][j];
            }
        }
    }
    int i = n,j = S,m = V[n][S];
    printf("Used Profits : ");
    while(i>0 && j>0) {
        if(V[i][j] == V[i-1][j]) {
            i --;
        }
        else {
            i --;
            m -= v[i];
            for(int k=S;k>=0;k--) {
                if(V[i][k] == m) {
                    j = k;
                    break;
                }
            }
            printf("%d ",v[i]);
        }
    }
    printf("\n");
    return V[n][S];
}
int main()
{
    int S = 15,n = 4;
    int s[] = {6,3,5,7};
    int v[] = {9,7,9,8};
    printf("Total = %d",dp__knapsack(S,s,v,n));
}