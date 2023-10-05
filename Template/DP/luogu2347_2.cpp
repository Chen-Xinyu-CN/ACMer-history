//有点假的多重背包，想用二进制拆分,拆分成功
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int a[7];int w[7]={-100,1,2,3,5,10,20};
LL dp[1024];
struct node{
    int w;int m;
};
int main()
{
    for(int i=1;i<=6;i++){
        cin>>a[i];
    }
    dp[0]=1;
    vector<node> binground;
    for(int i=1;i<=6;i++){
        for(int j=1;j<=a[i];j=j<<1){
            node niude;
            niude.w=w[i]*j;niude.m=j;
            a[i]-=j;
            binground.push_back(niude);
        }
        if(a[i]){
            node niude;
            niude.w=w[i]*a[i];niude.m=a[i];
            binground.push_back(niude);
        }
    }
    for(int i=0;i<binground.size();i++){
        for(int j=1000;j>=binground[i].w;j--){
            dp[j]+=dp[j-binground[i].w];
        }
    }
    LL ans=0;
    for(int i=1;i<=1000;i++){
        if(dp[i]){
            ans++;
        }
    }
    cout<<"Total="<<ans<<endl;
    return 0;
}