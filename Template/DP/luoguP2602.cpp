#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=18;
LL ten[MAXN];LL dp[MAXN];
LL cntfir[MAXN];LL cntsec[MAXN];
int num[MAXN];
void init();
void solve(LL x,LL* cnt);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    init();
    LL left;LL right;
    cin>>left;cin>>right;
    LL sum1=0;LL sum2=0;
    // for(int i=0;i<MAXN;i++){
    //     cout<<dp[i]<<endl;
    // }
    solve(left-1,cntfir);
    solve(right,cntsec);

    // for(int i=0;i<=9;i++){
    //     cout<<cntfir[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=0;i<=9;i++){
    //     cout<<cntsec[i]<<" ";
    // }
    // cout<<endl;
    for(int i=0;i<=9;i++){
        cntsec[i]-=cntfir[i];
    }
    for(int i=0;i<=9;i++){
        cout<<cntsec[i]<<" ";
    }
    cout<<endl;
    return 0;
}
void init(){
    ten[0]=1;dp[0]=0;
    for(int i=1;i<MAXN;i++){
        dp[i]=i*ten[i-1];
        ten[i]=ten[i-1]*10;
    }
    memset(cntfir,0,sizeof(cntfir));
    memset(cntsec,0,sizeof(cntsec));
}
void solve(LL x,LL* cnt){
    int length=0;
    while(x){
        length++;
        num[length]=x%10;
        x=x/10;
    }
    for(int i=length;i>=1;i--){
        //计算0xx,1xx,2xx中的xx
        for(int j=0;j<=9;j++){
            cnt[j]+=dp[i-1]*num[i];
        }
        //计算0xx,1xx,2xx中的0,1,2
        for(int j=0;j<num[i];j++){
            cnt[j]+=ten[i-1];
        }
        //计算3xx中的3
        LL post=0;
        for(int j=i-1;j>=1;j--){
            post=10*post+num[j];
        }
        cnt[num[i]]+=post+1;
        cnt[0]-=ten[i-1];
    }
}
