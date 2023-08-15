#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL qpow(LL a,LL n);
LL qpow_MOD(LL a,LL n);
LL MOD = 998244353;
int main()
{
    LL a;scanf("%lld",&a);
    LL n;scanf("%lld",&n);
    cout<<qpow(a,n)<<endl;
    system("pause");
    return 0;
}
LL qpow(LL a,LL n)
{
    LL ans =1;
    while(n){
        if(n&1){
            ans = ans*a;
        }
        a=a*a;
        n>>=1;
    }
    return ans;
}
//幂运算往往是大数，此是取模后的快速幂代码模板
LL qpow_MOD(LL a,LL n)
{
    LL ans =1;
    a=a%MOD;
    while(n){
        if(n&1){
            ans = (ans*a)%MOD;
        }
        a=(a*a)%MOD;
        n>>=1;
    }
    return ans;
}