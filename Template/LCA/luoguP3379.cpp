//使用链式前向星存储树
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int vexMAXN=5e5+5;
const int edgeMAXN=2e6+5;
struct edgenode{
    int from;int to;int w;
    int next;//next指向了下一个邻接点
};
int head[vexMAXN];
edgenode edge[edgeMAXN];
int cnt=0;
void init();
void addedge(int u,int v,int w){    //u->v
    edge[cnt].from=u;
    edge[cnt].to=v;
    edge[cnt].w=w;
    edge[cnt].next=head[u];
    head[u]=cnt;
    cnt++;
}
//倍增法LCA核心，构建fa表
int fa[vexMAXN][31];int deep[vexMAXN];
void dfs(int pos,int father){
    deep[pos]=deep[father]+1;
    fa[pos][0]=father;
    for(int i=1;(1<<i)<=deep[pos];i++){
        fa[pos][i]=fa[fa[pos][i-1]][i-1];
    }
    for(int i=head[pos];i!=-1;i=edge[i].next){
        if(edge[i].to!=father){
            dfs(edge[i].to,edge[i].from);
        }
    }
}
int LCA(int x,int y){
    //step1 把x和y提到相同的深度
    if(deep[x]<deep[y]){//默认x比较深
        swap(x,y);
    }
    for(int i=30;i>=0;i--){
        if(deep[x]-(1<<i)>=deep[y]){//之后要继续跳
            x=fa[x][i];
        }
    }
    if(x==y){
        return y;
    }
    //step2 x和y同步往上跳，找到LCA
    for(int i=30;i>=0;i--){
        if(fa[x][i]!=fa[y][i]){
            x=fa[x][i];
            y=fa[y][i];
        }
    }
    return fa[x][0];//返回LCA
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    init();
    int N,M,S;
    cin>>N>>M>>S;
    for(int i=1;i<=N-1;i++){
        int u;int v;
        cin>>u>>v;
        addedge(u,v,-1);
        addedge(v,u,-1);
    }
    // for(int i=1;i<=N;i++){
    //     cout<<i<<": ";
    //     for(int v=head[i];v!=-1;v=edge[v].next){
    //         cout<<edge[v].to<<" ";
    //     }
    //     cout<<endl;
    // }
    dfs(S,0);
    // for(int i=1;i<=N;i++){
    //     cout<<i<<": "<<deep[i]<<endl;
    // }
    // for(int i=1;i<=N;i++){
    //     for(int j=0;j<=10;j++){
    //         cout<<fa[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    for(int i=1;i<=M;i++){
        int qu;int qv;
        cin>>qu>>qv;
        cout<<LCA(qu,qv)<<endl;
    }
    system("pause");
    return 0;
}
void init(){
    for(int i=0;i<vexMAXN;i++){
        head[i]=-1;//-1表示此点没有邻接点
    }
    for(int i=0;i<edgeMAXN;i++){
        edge[i].next=-1;
    }
    memset(fa,0,sizeof(fa));
    memset(deep,0,sizeof(deep));
    cnt=0;
}