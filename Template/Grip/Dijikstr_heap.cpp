#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=2e5+5;
const LL infinity=4e9+7;
struct enode{
    int to;LL w;
};
bool operator<(const enode&e1,const enode&e2){
    return e1.w>e2.w;
}
vector<enode> grip[MAXN];
priority_queue<enode,vector<enode>> heap;
int hasvis[MAXN];LL dist[MAXN];int path[MAXN];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;int m;
    cin>>n>>m;
    int s;cin>>s;
    for(int i=1;i<=m;i++){
        int u;int v;int w;
        cin>>u>>v>>w;
        enode en;en.to=v;en.w=w;
        grip[u].push_back(en);
    }
    memset(hasvis,0,sizeof(hasvis));
    for(int i=1;i<=n;i++){
        dist[i]=infinity;
        path[i]=-1;
    }
    for(int i=0;i<grip[s].size();i++){
        enode en;
        en.to=grip[s][i].to;en.w=grip[s][i].w;
        heap.push(en);
        dist[en.to]=en.w;
        path[en.to]=s;
    }
    hasvis[s]=1;dist[s]=0;
    for(int i=1;i<=n-1;i++){
        int minpos;LL minnum;
        minpos=heap.top().to;minnum=heap.top().w;
        if(hasvis[minpos]==1||(hasvis[minpos]==0&&minnum==infinity)){
            break;
        }
        heap.pop();
        hasvis[minpos]=1;//加入s集合
        for(int i=0;i<grip[minpos].size();i++){
            int nextto=grip[minpos][i].to;
            LL appenddist=grip[minpos][i].w;
            if(hasvis[nextto]==0&&dist[nextto]>minnum+appenddist){
                dist[nextto]=minnum+appenddist;
                path[nextto]=minpos;
                enode en;en.to=nextto;en.w=dist[nextto];
                heap.push(en);
            }
            
        }
    }
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;


    system("pause");
    return 0;
}