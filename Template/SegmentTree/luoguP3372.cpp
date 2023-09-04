#include <bits/stdc++.h>
using namespace std;
typedef long long LL;typedef unsigned long long ull;
#define N 100010
#define lowbit(x)   ((x)&-(x))
LL treediff[N]={0};LL tree2[N]={0};    //初始化树状数组全为0
void updatediff(LL x,LL d){
    while(x<=N){
        treediff[x]+=d;
        x+=lowbit(x);
    }
}
LL sumdiff(LL x){
    LL ans=0;
    while(x>0){
        ans+=treediff[x];
        x-=lowbit(x);
    }
    return ans;
}
void update2(LL x,LL d){
    while(x<=N){
        tree2[x]+=d;
        x+=lowbit(x);
    }
}
LL sum2(LL x){
    LL sum=0;
    while(x>0){
        sum+=tree2[x];
        x-=lowbit(x);
    }
    return sum;
}
int main()
{
    int n;int m;scanf("%d",&n);scanf("%d",&m);
    LL array[N];memset(array,0,sizeof(array));
    for(int i=1;i<=n;i++){  //初始化树状数组
        scanf("%lld",&array[i]);
        updatediff(i,array[i]-array[i-1]);
        update2(i,(i-1)*(array[i]-array[i-1]));
    }
    for(int i=1;i<=m;i++){
        int type;int x;int y;scanf("%d",&type);scanf("%d",&x);scanf("%d",&y);
        if(type==1){
            LL k;scanf("%lld",&k);
            updatediff(x,k);
            updatediff(y+1,-k);
            update2(x,(x-1)*k);
            update2(y+1,(y)*(-k));
        }
        else{
            cout<<(y*sumdiff(y)-sum2(y))-((x-1)*sumdiff(x-1)-sum2(x-1))<<endl;
        }
    }
    system("pause");
    return 0;
}