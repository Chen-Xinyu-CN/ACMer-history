//  树状数组求解hdu1556
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;typedef unsigned long long ull;
#define N 1000005
#define lowbit(x)   ((x)&-(x))
int tree[N]={0};    //初始化树状数组全为0
void update(int x,int d){
    while(x<=N){
        tree[x]+=d;
        x+=lowbit(x);
    }
}
int sum(int x){
    int ans=0;
    while(x>0){
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
}
int main()
{
    LL T;
    while(scanf("%lld",&T)&&T){
        memset(tree,0,sizeof(tree));
        for(LL i=1;i<=T;i++){
            LL left;LL right;scanf("%lld %lld",&left,&right);
            update(left,1);update(right+1,-1);
        }
        for(LL i=1;i<=T;i++){
            printf("%d ",sum(i));
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}