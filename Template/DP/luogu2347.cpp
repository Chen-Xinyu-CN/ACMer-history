//0-1背包思路
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[7];int w[7]={-100,1,2,3,5,10,20};
LL dp[1024][1024];
int main()
{
    LL sum=0;
    //init
    memset(dp,0,sizeof(dp));
    for(int i=0;i<1000;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<=6;i++){
        cin>>a[i];
        sum+=a[i]*w[i];
    }
    vector<int> WeiSeq;
    for(int i=1;i<=6;i++){
        for(int j=1;j<=a[i];j++){
            WeiSeq.push_back(w[i]);
        }
    }

    // for(int i=0;i<WeiSeq.size();i++){
    //     cout<<WeiSeq[i]<<" ";
    // }
    // cout<<endl;

    for(int i=1;i<=WeiSeq.size();i++){
        for(int j=1;j<=1000;j++){
            if(j<WeiSeq[i-1]){
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=(dp[i-1][j]||dp[i-1][j-WeiSeq[i-1]]);
            }
            //cout<<i<<", "<<j<<" "<<dp[i][j]<<endl;
        }
    }

    for(int i=0;i<=10;i++){
        for(int j=0;j<=10;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    LL ans=0;
    for(int i=1;i<=1000;i++){
        if(dp[WeiSeq.size()][i]){
            ans++;
        }
    }
    cout<<"Total="<<ans<<endl;
    return 0;
}