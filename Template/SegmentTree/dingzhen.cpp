#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct node{
    int nx;int weight;
};
const int MAXN = 1e6+5; 
vector<int> grip[MAXN];
void add(int v,int w){
    grip[v].push_back(w);
}
LL numa[MAXN];LL numb[MAXN];
bool isvis[MAXN];
LL bfs(int x);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);
    memset(isvis,false,sizeof(isvis));
    int n;int m;int k;int w;
    cin>>n>>m>>k>>w;
    for(int i=1;i<=n;i++){
        cin>>numa[i];
    }
    for(int i=1;i<=n;i++){
        cin>>numb[i];       //标记是否是丁真帝国
    }
    for(int i=1;i<=m;i++){
        int u;int v;cin>>u>>v;
        add(u,v);add(v,u);
    }

    // for(int i=1;i<=n;i++){
    //     for(int j=0;j<grip[i].size();j++){
    //         cout<<grip[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    //bfs各个连通的星系

    priority_queue<int,vector<int>,less<int>> heap;
    for(int i=1;i<=n;i++){
        if(isvis[i]==false&&numb[i]==1){
            //cout<<i<<endl;
            heap.push(bfs(i));
        }
    }
    //cout<<"====="<<endl;
    //cout<<heap.size()<<endl;
    LL ans=0;
    if(k==0){
        cout<<0<<endl;
    }
    else{
        while(!heap.empty()){
            if(k!=0){
                ans+=heap.top();
            }
            else break;
            heap.pop();
            k--;
        }
        cout<<ans<<endl;
    }
    //system("pause");
    return 0;
}
LL bfs(int x){
    isvis[x]=true;
    queue<int> q;
    q.push(x);LL sum=numa[x];
    while(!q.empty()){
        int here=q.front();q.pop();
        for(int i=0;i<grip[here].size();i++){
            int nexnode=grip[here][i];
            if(isvis[nexnode]==false && numb[nexnode]==1){
                sum+=numa[nexnode];
                q.push(nexnode);
                isvis[nexnode]=true;
            }
        }
    }
    return sum;
}