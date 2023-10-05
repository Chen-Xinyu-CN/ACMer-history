//hud2602自顶向下记忆化搜索代码
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=1002;
LL dpbag[MAXN][MAXN];
LL w[MAXN];LL vol[MAXN];
LL solve(int n,int C);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);
    int t;cin>>t;
    for(int z=1;z<=t;z++){
        int N;int C;
        cin>>N>>C;
        memset(w,0,sizeof(w));
        memset(vol,0,sizeof(vol));
        memset(dpbag,0,sizeof(dpbag));
        for(int i=1;i<=N;i++){
            cin>>w[i];
        }
        for(int i=1;i<=N;i++){
            cin>>vol[i];
        }
        cout<<solve(N,C)<<endl;
    }
    return 0;
}
LL solve(int i,int j){
    if(dpbag[i][j]!=0){
        return dpbag[i][j];
    }
    else{
        if(i==0){
            return 0;
        }
        LL res;
        if(vol[i]>j){
            res=solve(i-1,j);
        }
        else{
            res = max(solve(i-1,j),solve(i-1,j-vol[i]) + w[i]);
        }
        dpbag[i][j]=res;
        return dpbag[i][j];
    }
}