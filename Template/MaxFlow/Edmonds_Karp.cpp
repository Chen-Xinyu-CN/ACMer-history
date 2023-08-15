#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF =1e9;const int N = 250;
int n,m;LL graph[N][N];LL pre[N];LL flow[N];
LL bfs(int s,int t);    //bfs的作用就是在此时的残留网络上搜索出一条s->t的最短简单路径,各边的权值此时视为1
LL maxflow(int s,int t);
int main()
{
    int s;int t;scanf("%d %d %d %d",&n,&m,&s,&t);
    memset(graph,0,sizeof(graph));
    for(int i=1;i<=m;i++){
        int u;int v;int w;scanf("%d",&u);scanf("%d",&v);scanf("%d",&w);
        graph[u][v]+=w;//考虑重边的情况
    }
    printf("%lld\n",maxflow(s,t));
    system("pause");
    return 0;
}
LL bfs(int s,int t)
{
    memset(pre,-1,sizeof(pre));
    memset(flow,0,sizeof(flow));
    flow[s]=INF;pre[s]=0;
    queue<int> Q;Q.push(s);
    while(!Q.empty()){
        int u=Q.front();Q.pop();
        if(u==t)    break;  //此时已经搜素到了一条路径
        for(int i=1;i<=n;i++){  //bfs搜素下一层
            if(i!=s&&graph[u][i]>0&&pre[i]==-1){
                pre[i]=u;Q.push(i);
                flow[i]=min(graph[u][i],flow[u]);//更新一条路径上的瓶颈值
            }
        }
    }
    if(pre[t]==-1)  return -1;//表明在此时的残留网络中，没有任何s->t的路径了
    else    return flow[t]; //返回一条路径的flow值
}
LL maxflow(int s,int t)
{
    LL Maxflow = 0;
    while(true){
        LL flow =bfs(s,t);
        if(flow==-1)    break;  //找不到此时s->t的最短路径了
        int cur=t;  //开倒车顺着pre数组更新残留网络
        while(cur!=s){
            int father=pre[cur];
            graph[father][cur]-=flow;
            graph[cur][father]+=flow;   //添加反向边
            cur=father;
        }
        Maxflow+=flow;
    }
    return Maxflow; //返回计算得到的最大流
}