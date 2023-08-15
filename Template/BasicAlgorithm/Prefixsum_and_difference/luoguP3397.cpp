#include <bits/stdc++.h>
using namespace std;
typedef long long LL;typedef unsigned long long ull;
int Map[1024][1024];int Diff[1024][1024];
int main()
{
    memset(Map,0,sizeof(Map));
    memset(Diff,0,sizeof(Diff));
    int n;int m;scanf("%d",&n);scanf("%d",&m);
    for(int z=1;z<=m;z++){
        int x1,y1;int x2,y2;
        scanf("%d",&x1);scanf("%d",&y1);
        scanf("%d",&x2);scanf("%d",&y2);
        Diff[x1][y1]+=1;Diff[x1][y2+1]-=1;
        Diff[x2+1][y1]-=1;Diff[x2+1][y2+1]+=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            Map[i][j]=Map[i][j-1]+Map[i-1][j]-Map[i-1][j-1]+Diff[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",Map[i][j]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}