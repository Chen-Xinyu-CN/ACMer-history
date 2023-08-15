//  树状数组板子
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;typedef unsigned long long ull;
#define N 1000
#define lowbit(x)   ((x)&-(x))
int tree[N]={0};    //初始化树状数组全为0
void update(int x,int d){
    while(x<=N){
        tree[x]+=d;
        x+=lowbit(x);
    }
}
int sum(int x){
    int ans=0;
    while(x>0){
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
}
vector<int> a;
int main()
{
    a.push_back(0);
    int size;scanf("%d",&size);
    for(int i=1,x;i<=size;i++){
        scanf("%d",&x);a.push_back(x);
    }
    for(int i=1;i<=size;i++){
        update(i,a[i]);
    }
    for(int i=1;i<=size;i++){
        printf("%d ",tree[i]);
    }
    printf("\n");
    printf("enter the [l,r] to query the sum of this scale...\n");
    int left;int right;scanf("%d %d",&left,&right);
    printf("%d\n",sum(right)-sum(left-1));
    system("pause");
    return 0;
}