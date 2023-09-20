// D problem
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=1e6+5;
LL n;LL m;
vector<LL> grip[MAXN];
void dfs(int startpos);
bool hasvis[MAXN];
LL edgenum=0;LL vexnum=0;
struct node{
    LL vexnum;LL edgenum;
};
class MyCompare{
public:
    bool operator()(node n1,node n2) const{
        return n1.vexnum>n2.vexnum;
    }
};
priority_queue<node,vector<node>,MyCompare> heap;
void liantongvec();
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u;int v;
        cin>>u>>v;
        grip[u].push_back(v);
        grip[v].push_back(u);
    }
    liantongvec();
    // while(!heap.empty()){
    //     cout<<heap.top().edgenum<<", "<<heap.top().vexnum<<endl;
    //     heap.pop();
    // }

    priority_queue<node,vector<node>,MyCompare> temp=heap;
    //bool flag=false;
    vector<node> clash;
    while(!temp.empty()){
        LL vnum=temp.top().vexnum;
        LL eenum=temp.top().edgenum;
        if(vnum*(vnum-1)!=eenum){   //记录非完全图
            clash.push_back(temp.top());
        }
        temp.pop();
    }
    LL modnum=0;
    if(!clash.empty()){
        for(int i=0;i<clash.size();i++){
            LL vnum=clash[i].vexnum;
            LL eenum=clash[i].edgenum;
            modnum+=vnum*(vnum-1)-eenum;
        }
        cout<<modnum/2<<endl;
    }
    else{
        LL vnum1=heap.top().vexnum;LL eenum1=heap.top().edgenum;
        heap.pop();
        LL vnum2=heap.top().vexnum;LL eenum2=heap.top().edgenum;
        LL sumvnum=vnum1+vnum2;
        cout<<(sumvnum*(sumvnum-1)-eenum1-eenum2)/2<<endl;
    }
    return 0;
}
void dfs(int startpos){
    hasvis[startpos]=true;
    vexnum++;
    edgenum+=grip[startpos].size();
    int v;
    for(int i=0;i<grip[startpos].size();i++){
        v=grip[startpos][i];
        if(hasvis[v]==false){
            dfs(v);
        }
    }
}
void liantongvec(){
    memset(hasvis,false,sizeof(hasvis));
    for(int u=1;u<=n;u++){
        edgenum=0;vexnum=0;
        if(hasvis[u]==false){
            dfs(u);
            LL hereen=edgenum;LL herevn=vexnum;
            node nn;nn.edgenum=hereen;nn.vexnum=herevn;
            heap.push(nn);
        }
    }
}