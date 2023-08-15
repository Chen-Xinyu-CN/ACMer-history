#include <iostream>
using namespace std;
typedef long long LL;typedef unsigned long long ull;
const LL MAXN = 2e6+5;
int ufsets[MAXN];int weight[MAXN];int ans=0;
void init();
int find(int x);
void Merge(int a,int b,int v);
int main()
{
    LL N;LL M;
    while(scanf("%lld %lld",&N,&M)!=EOF){
        init();ans=0;
        for(int i=1;i<=M;i++){
            int left;int right;int sum;
            scanf("%d",&left);scanf("%d",&right);scanf("%d",&sum);
            left--;
            Merge(left,right,sum);
        }
        printf("%d\n",ans);
    }
    system("pause");
    return 0;
}
void init()
{
    for(int i=0;i<MAXN;i++){
        ufsets[i]=i;weight[i]=0;
    }
}
int find(int x)
{
    if(x!=ufsets[x]){
        int temp=ufsets[x];//temp记录原父亲结点
        ufsets[x]=find(ufsets[x]);
        weight[x]+=weight[temp];
    }
    return ufsets[x];
}
void Merge(int a,int b,int v)
{
    int roota=find(a);int rootb=find(b);
    if(roota==rootb){   //结点a和结点b属于同一个等价类内
        if(weight[a]-weight[b]!=v)  ans++;
    }
    else{
        ufsets[roota]=rootb;//默认结点a所在的等价类接到结点b所在的等价类下面
        weight[roota]=-weight[a]+weight[b]+v;
    }
}