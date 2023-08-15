//hdu1556 使用差分数组求解
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;typedef unsigned long long ull;
const LL N =100010;
int a[N];int D[N];  //数组D是数组a的差分数组
int main()
{
    LL n;
    while(scanf("%lld",&n)&&n){
        memset(a,0,sizeof(a));memset(D,0,sizeof(D));
        for(int z=1;z<=n;z++){
            int left;int right;scanf("%d",&left);scanf("%d",&right);
            D[left]+=1;D[right+1]-=1;
        }
        for(int i=1;i<=n;i++){
            a[i]=a[i-1]+D[i];
            printf("%d ",a[i]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}