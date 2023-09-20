#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    LL T;LL mintime;
    cin>>T>>mintime;
    LL ct=0;
    LL maxnum=-1e3;
    for(int i=0;i<T;i++){
        LL checktime;cin>>checktime;
        if(checktime>=maxnum){
            maxnum=checktime;
        }
    }
    double beishu=(double)maxnum/(double)mintime;
    int x=beishu;
    if(x<beishu){
        cout<<max(2,x+1)<<endl;
    }
    else{
        cout<<max(2,x)<<endl;
    }
    return 0;
}