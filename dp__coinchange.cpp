#include<stdio.h>
int c[1000000];
int min(int a,int b)
{
    if(a>b)return b;
    return a;
}
int dp_coin_change(int coins[],int total,int n)
{
    int t[total+1];
    t[0] = 0;
    c[0] = -1;
    for(int i=1;i<=total;i++) {
        t[i] = 100000000;
        c[i] = -1;
    }
    for(int j=0;j<n;j++) {
        for(int i=coins[j];i<=total;i++) {
            int temp = min(t[i],1+t[i-coins[j]]);
            if (temp != t[i]) {
                t[i] = temp;
                c[i] = j;
            }
        }
    }
    return t[total];
}
void traceback(int coins[],int c[],int total)
{
    while(total) {
        printf("%d ",coins[c[total]]);
        total -= coins[c[total]];
    }
}
int main()
{
    int total=12,n=4;
    int coins[]={7,2,3,6};
    int ans = dp_coin_change(coins,total,n);
    if(ans == 100000000) {
        printf("Not Possible");
        return 0;
    }
    printf("Total Coins : %d\n",ans);
    traceback(coins,c,total);
    
}