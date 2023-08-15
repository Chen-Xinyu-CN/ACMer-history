//使用倍增ST算法，动态规划的思想实现高效地查询区间[left,right]之间的最大值和最小值 
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;typedef unsigned long long ull;
const LL MAXN = 5e3+50;//栈空间开大
int main()
{
    LL n;LL q;scanf("%lld",&n);scanf("%lld",&q);vector<LL> cowheights;
    for(LL i=1,h;i<=n;i++){
        scanf("%lld",&h);cowheights.push_back(h);
    }
    int groupsize=log2(n);LL dpmin[MAXN][20];LL dpmax[MAXN][20];
    //处理预设区间内的最小值
    for(int i=0;i<n;i++){
        dpmin[i][0]=cowheights[i];
        dpmax[i][0]=cowheights[i];
    }
    for(int i=1;i<=groupsize;i++){
        for(int j=0;j<=n-(1<<i);j++){
            dpmin[j][i]=min(dpmin[j][i-1],dpmin[j+(1<<(i-1))][i-1]);
        }
    }
    for(int i=1;i<=groupsize;i++){
        for(int j=0;j<=n-(1<<i);j++){
            dpmax[j][i]=max(dpmax[j][i-1],dpmax[j+(1<<(i-1))][i-1]);
        }
    }
    for(int z=1;z<=q;z++){
        int left;int right;scanf("%d",&left);scanf("%d",&right);
        int len=right-left+1;int k=log2(len);LL maxdata;LL mindata;
        left--;right--;
        maxdata=max(dpmax[left][k],dpmax[right+1-(1<<k)][k]);
        mindata=min(dpmin[left][k],dpmin[right+1-(1<<k)][k]);
        cout<<maxdata-mindata<<endl;
    }
    system("pause");
    return 0;
}