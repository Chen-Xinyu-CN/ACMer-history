#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);
    int N,M;
    cin>>N>>M;
    int value[101];
    for(int i=1;i<=N;i++){
        cin>>value[i];
    }
    int dp[101][10001];
    int ways[101][10001];
    for(int i=0;i<=N;i++){
        ways[0][i]=1;ways[i][0]=1;
    }
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=N;i++){
        for(int j=0;j<=M;j++){
            if(value[i]>j){
                dp[i][j] = dp[i-1][j];
                ways[i][j] = ways[i-1][j];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i-1][j-value[i]]+value[i]);
                if(dp[i-1][j]==dp[i-1][j-value[i]]+value[i]){
                    ways[i][j]=ways[i-1][j]+ways[i-1][j-value[i]];
                }
                else if(dp[i-1][j] > dp[i-1][j-value[i]]+value[i]){
                    ways[i][j]=ways[i-1][j];
                }
                else{
                    ways[i][j]=ways[i-1][j-value[i]];
                }
            }
        }
    }
    // for(int i=1;i<=N;i++){
    //     for(int j=0;j<=M;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // for(int i=1;i<=N;i++){
    //     for(int j=0;j<=M;j++){
    //         cout<<ways[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    cout<<ways[N][M]<<endl;
    // int sum=0;
    // for(int i=1;i<=N;i++){
    //     for(int j=0;j<=M;j++){
    //         if(dp[i][j]==M){
    //             sum+=ways[i][j];
    //         }
    //     }
    // }
    // cout<<sum<<endl;
    return 0;
}