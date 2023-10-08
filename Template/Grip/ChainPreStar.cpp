//图的存储，链式前向星模板
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int vexMAXN=1e6+5;
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
int main()
{
    init();
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
    cnt=0;
}