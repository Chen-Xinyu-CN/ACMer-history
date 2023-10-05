#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int group[128][128];
int dp[128][128];
int main()
{
    int N;int M;
    while(true){
        cin>>N>>M;
        if(N==0&&M==0){
            break;
        }
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=N;i++){
            for(int j=1;j<=M;j++){
                cin>>group[i][j];
            }
        }
        for(int i=1;i<=N;i++){
            for(int j=0;j<=M;j++){
                for(int k=1;k<=M;k++){      //组中选哪个物品
                    if(k>j){
                        dp[i][j] = max(dp[i][j], dp[i-1][j]);
                    }
                    else{
                        dp[i][j] = max(dp[i][j], max(dp[i-1][j],dp[i-1][j-k] + group[i][k]));
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
        cout<<dp[N][M]<<"\n";

    }
    return 0;
}