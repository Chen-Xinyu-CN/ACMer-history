#include <bits/stdc++.h>
using namespace std;
typedef long long LL;typedef unsigned long long ull;
const int MAXN = 1e5+5;
struct node{
    int to;
};
vector<node> Grip[MAXN];
int main()
{
    LL n;LL m;scanf("%lld",&n);scanf("%lld",&m);
    for(int i=1;i<=m;i++){
        int u;int v;scanf("%d",&u);scanf("%d",&v);
        node temp;temp.to=v;Grip[u].push_back(temp);
    }
    system("pause");
    return 0;
}