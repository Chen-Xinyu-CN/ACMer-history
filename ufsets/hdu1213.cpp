#include <bits/stdc++.h>
using namespace std;
typedef long long LL;typedef unsigned long long ull;
const LL MAXN = 1e3+50;
int ufsets[MAXN];int height[MAXN];//高度数组用来记录每个等价类的高度
void init();
void Merge(int x,int y);
int Find(int x);
// int find(int x){   //路径压缩的查找，在路径压缩的过程中往往附带了优化缩短了等价类的高度,因而Merge函数中可以不用判断两个等价类的高度
//     //递归实现
//     if(x!=ufsets[x]) ufsets[x]=find(ufsets[x]);
//     return ufsets[x];
// }
// int find(int x){
//     //非递归实现
//     int root=x;
//     while(root!=ufsets[root]){
//         root=ufsets[root];
//     }
//     while(x!=ufsets[x]){
//         int temp=ufsets[x];
//         ufsets[x]=root;x=temp;
//     }
//     return root;
// }
int main()
{
    LL T;scanf("%lld",&T);
    for(int z=1;z<=T;z++){
        init();     //初始化并查集为MAXN个独立的集合
        int n;int m;scanf("%d",&n);scanf("%d",&m);
        for(int i=1;i<=m;i++){
            int a;int b;scanf("%d",&a);scanf("%d",&b);
            Merge(a,b);
        }
        LL sum=0;
        for(int i=1;i<=n;i++){
            if(ufsets[i]==i)    sum++;  //搜素总共有几个并查集，即有几个等价类
        }
        printf("%lld\n",sum);
        for(int i=1;i<=n;i++)    cout<<height[i]<<" ";
        cout<<endl;
    }
    system("pause");
    return 0;
}
void init()
{
    for(int i=1;i<=MAXN;i++){
        ufsets[i]=i;height[i]=1;
    }    
}
void Merge(int x,int y)
{
    x=Find(x);y=Find(y);
    if(x==y) return;
    if(height[x]==height[y]){           //只有两个等价类高度相等时，才会发生高度增加
        ufsets[x]=ufsets[y];
        height[y]++;
    }
    else{
        if(height[x]>height[y]) ufsets[y]=ufsets[x];
        else    ufsets[x]=ufsets[y];
    }
}
int Find(int x)
{
    while(x!=ufsets[x]){
        x=ufsets[x];
    }
    return x;
}