#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 3e5;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);
    int n;cin>>n;
    int numarray[MAXN];
    int seqans[MAXN];
    for(int i=1;i<=n;i++){
        cin>>numarray[i];
    }
    LL ans = -1e3;
    for(int i=1;i<=n;i++){
        if(i==1){
            seqans[i] = numarray[i];
        }
        else{
            seqans[i] = max(numarray[i],numarray[i]+seqans[i-1]);
        }
        ans = max(ans,(LL)seqans[i]);
    }
    cout<<ans<<endl;
    return 0;
}