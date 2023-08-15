//  problem luogu P3386 Hungary algorithm求无权二部图的最大匹配
#include <bits/stdc++.h>
using namespace std;
int G[510][510];
int match[510],reserve_boy[510];
int n;int m;
bool dfs(int x);
int main()
{
    int e;scanf("%d",&n);scanf("%d",&m);scanf("%d",&e);
    for(int z=1;z<=e;z++){
        int a;int b;scanf("%d",&a);scanf("%d",&b);G[a][b]=1;//矩阵存初始图
    }
    int sum=0;
    for(int i=1;i<=n;i++){  //为第一类中的每个点寻找配对
        memset(reserve_boy,0,sizeof(reserve_boy));
        if(dfs(i))  sum++;
    }
    printf("%d\n",sum);
    system("pause");
    return 0;
}
bool dfs(int x)
{
    for(int i=1;i<=m;i++){
        if(!reserve_boy[i]&&G[x][i]){ //若二部图第二类中的第i个点未被预约过且x可以与该点匹配
            reserve_boy[i]=1;
            if(!match[i]||dfs(match[i])){
                match[i]=x;
                return true;
            }
        }
    }
    return false;
}