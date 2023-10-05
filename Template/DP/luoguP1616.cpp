//luoguP1616疯狂的采药 完全背包问题
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e4+3;
int cost[MAXN];int value[MAXN];
LL dp[2][10000005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;int m;
    cin>>t>>m;
    for(int i=1;i<=m;i++){  //from 1
        cin>>cost[i];cin>>value[i];
    }
    int now=0;int old=1;
    for(int i=1;i<=m;i++){
        swap(now,old);
        for(int j=0;j<=t;j++){

        }
    }
    return 0;
}