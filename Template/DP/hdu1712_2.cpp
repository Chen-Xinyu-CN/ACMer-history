//采用了一维滚动数组来实现
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int group[128][128];
int dp[128];
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
            for(int j=M;j>=0;j--){
                for(int k=1;k<=M;k++){
                    if(k<=j){
                        dp[j] = max(dp[j], dp[j-k] + group[i][k]);
                    }
                }
            }
        }
        cout<<dp[M]<<"\n";
    }
    return 0;
}