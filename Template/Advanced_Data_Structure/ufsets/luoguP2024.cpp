#include <bits/stdc++.h>
using namespace std;
typedef long long LL;typedef unsigned long long ull;
const LL MAXN = 50050;
int s[MAXN];int d[MAXN];int ans;
void init();
int find(int x);
void merge(int x,int y,int relation);
int main()
{
    int n;int k;cin>>n;cin>>k;
    init();ans=0;
    for(int i=1;i<=k;i++){
        int relation;int x;int y;cin>>relation>>x>>y;
        if(x>n||y>n||(relation==2&&x==y))  ans++;//特殊的错误情况
        else{
            merge(x,y,relation);
        }
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}
void init()
{
    for(int i=0;i<=MAXN;i++){
        s[i]=i;d[i]=0;//初始化d[i]皆为0表明自身与自身是同类
    }
}
int find(int x)
{
    if(x!=s[x]){
        int temp=s[x];
        s[x]=find(s[x]);
        d[x]=(d[x]+d[temp])%3;
    }
    return s[x];
}
void merge(int x,int y,int relation)
{
    int rootx=find(x);int rooty=find(y);
    if(rootx==rooty){
        if((relation-1)!=((d[x]-d[y]+3)%3)) ans++;
    }
    else{
        s[rootx]=rooty;
        d[rootx]=(d[y]-d[x]+relation-1)%3;
    }
}