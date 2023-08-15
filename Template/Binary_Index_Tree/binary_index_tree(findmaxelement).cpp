//树状数组板子，查询区间内的最大值
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;typedef unsigned long long ull;
#define N 50005
#define lowbit(x)   ((x)&-(x))
int tree[N]={0};    //初始化树状数组全为0
void update(int x,int d){//更新区间内的最大值
    while(x<=N){
        tree[x]=max(tree[x],d);
        x+=lowbit(x);
    }
}
int queryMAX(int x){//查询区间[1->x]之间的最大值
    int ans=-1e9;
    while(x>0){
        ans=max(tree[x],ans);
        x-=lowbit(x);
    }
    return ans;
}
int main()
{
    int n;cin>>n;vector<int> v;v.push_back(0);
    for(int i=1,x;i<=n;i++){
        cin>>x;v.push_back(x);update(i,x);
    }
    for(int i=1;i<=n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    cout<<"querytimes: "<<endl;int query;cin>>query;
    for(int i=1;i<=query;i++){
        int x;cin>>x;cout<<queryMAX(x)<<endl;
    }
    system("pause");
    return 0;
}