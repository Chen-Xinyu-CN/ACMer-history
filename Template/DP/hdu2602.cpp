//hud2602递推代码
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=1002;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);
    int t;cin>>t;
    for(int z=1;z<=t;z++){
        int N;int C;
        cin>>N>>C;
        LL w[MAXN];LL vol[MAXN];
        memset(w,0,sizeof(w));
        memset(vol,0,sizeof(vol));
        LL dpbag[MAXN][MAXN];
        memset(dpbag,0,sizeof(dpbag));
        for(int i=1;i<=N;i++){
            cin>>w[i];
        }
        for(int i=1;i<=N;i++){
            cin>>vol[i];
        }
        for(int i=1;i<=N;i++){
            for(int j=0;j<=C;j++){
                if(vol[i]>j){
                    dpbag[i][j]=dpbag[i-1][j];
                }
                else{
                    dpbag[i][j] = max(dpbag[i-1][j], dpbag[i-1][j-vol[i]]+w[i]);
                }
            }
        }
        cout<<dpbag[N][C]<<endl;
    }
    return 0;
}