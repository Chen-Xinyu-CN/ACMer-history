#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define SKIP 8010
struct node{    //此链式前向星不需要定义权值
    int to;int next;
};
node edges[20000];int head[4200];int cnt=0;
void add(int u,int v);
int match[20000];int hasreserved[20000];
bool dfs(int x);
LL N;
int main()
{
    scanf("%lld",&N);
    for(int i=1;i<=2*N;i++){
        int seat1;int seat2;scanf("%d",&seat1);scanf("%d",&seat2);
        add(i,seat1);add(i,seat1+SKIP);add(i,seat2);add(i,seat2+SKIP);
    }
    LL ans=0;
    for(int i=1;i<=2*N;i++){
        memset(hasreserved,0,sizeof(hasreserved));
        if(dfs(i))  ans++;
    }
    printf("%lld\n",ans);
    system("pause");
    return 0;
}
void add(int u,int v)
{
    cnt++;
    edges[cnt].to=v;edges[cnt].next=head[u];head[u]=cnt;
}
// Hungary
bool dfs(int x)
{
    for(int i=head[x];i!=0;i=edges[i].next){
        int v=edges[i].to;
        if(!hasreserved[v]){
            hasreserved[v]=1;//表明已预约
            if(!match[v]||dfs(match[v])){
                match[v]=x;return true;
            }
        }
    }
    return false;
}