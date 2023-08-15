//  luogu Problem8218   使用树状数组求解
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;typedef unsigned long long ull;
#define N 100000+50
int tree[N];
void update(int x,int data);
int sum(int pos);
int lowbit(int x);
int n;
int main()
{
    vector<int> a;a.push_back(0);
    scanf("%d",&n);
    for(int i=1,x;i<=n;i++){
        scanf("%d",&x);a.push_back(x);
        update(i,x);
    }
    // for(int i=1;i<=n;i++){
    //     cout<<tree[i]<<endl;
    // }
    int m;
    scanf("%d",&m);
    for(int i=1;i<=m;i++){
        int left;int right;scanf("%d",&left);scanf("%d",&right);
        printf("%d\n",sum(right)-sum(left-1));
    }
    system("pause");
    return 0;
}
void update(int x,int data)
{
    while(x<=n){
        tree[x]+=data;
        x+=lowbit(x);
    }
}
int sum(int pos)
{
    int sum=0;
    while(pos>0){
        sum+=tree[pos];
        pos-=lowbit(pos);
    }
    return sum;
}
int lowbit(int x)
{
    return (x&(-x));
}