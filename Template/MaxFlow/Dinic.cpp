//  Dinic 算法
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;typedef unsigned long long ull;
const LL INF = 1e9;int n,m,s,t;
const int N =250,M=11000;int cnt=1,head[N];
struct node{
    int to;int nex;int w;
};
node e[M];  //构造链式前向星的边数组
int now[N];int dep[N];
void add(int u,int v,int w);
int bfs();
int dfs(int u,LL sum);
int main()
{
    scanf("%d",&n);scanf("%d",&m);scanf("%d",&s);scanf("%d",&t);
    for(int i=1;i<=m;i++){
        int u;int v;int w;scanf("%d",&u);scanf("%d",&v);scanf("%d",&w);
        add(u,v,w);add(v,u,0);
    }
    LL ans=0;
    while(bfs()) ans+=dfs(s,INF);
    printf("%lld\n",ans);
    system("pause");
    return 0;
}
void add(int u,int v,int w)
{
    cnt++;
    e[cnt].to=v;e[cnt].w=w;e[cnt].nex=head[u];
    head[u]=cnt;
}
int bfs()
{
    for(int i=1;i<=n;i++)   dep[i]=INF;
    dep[s]=0;now[s]=head[s];
    queue<int> Q;Q.push(s);
    while(!Q.empty()){
        int u=Q.front();Q.pop();
        for(int i=head[u];i>0;i=e[i].nex){
            int v=e[i].to;
            if(e[i].w>0&&dep[v]==INF){  //此时表明该邻接点是下一层，因为e[i].w还有容量
                Q.push(v);
                now[v]=head[v];
                dep[v]=dep[u]+1;
                if(v==t)    return 1;
            }
        }
    }
    return 0;
}
int dfs(int u,LL sum)
{
    if(u==t) return sum;
    LL k;LL flow=0;
    for(int i=now[u];i>0&&sum>0;i=e[i].nex){    //sum==0代表着分配给u点的总流量sum已经用完，可以结束了
        now[u]=i;int v=e[i].to;
        if(e[i].w>0&&(dep[v]==dep[u]+1)){
            k=dfs(v,min(sum,(LL)e[i].w));
            if(k==0) dep[v]=INF;    //此时代表这条dfs路径是不可行的，修改dep深度
            e[i].w-=k;e[i^1].w+=k;//更新残留网络
            flow+=k;sum-=k;
        }
    }
    return flow;
}