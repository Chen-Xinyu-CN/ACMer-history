#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);
    int t;int m;cin>>t>>m;
    int cost[128];int value[128];
    for(int i=1;i<=m;i++){
        cin>>cost[i];
        cin>>value[i];
    }
    int dp[128][1024];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=m;i++){
        for(int j=0;j<=t;j++){
            if(cost[i]>j){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-cost[i]] + value[i]);
            }   
        }
    }
    cout<<dp[m][t]<<endl;
    return 0;
}