//  problem E
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;typedef unsigned long long ull;
void row_dividefunc(int x1,int x2,int y1,int y2);
void col_dividefunc(int x1,int x2,int y1,int y2);
struct node
{
    int x;int y;int l;
};
vector<node> ans;
int main()
{
    int T;scanf("%d",&T);
    for(int z=1;z<=T;z++){
        ans.empty();
        int n;int m;scanf("%d",&n);scanf("%d",&m);
        if(n<m){
            int x1=1;int x2=n;int y1=1;int y2=m;int type=1;
            LL sum=0;
            while(true){
                if(type==1){
                    row_dividefunc(x1,x2,y1,y2);
                    int num=(y2-y1+1)/(x2-x1+1);
                    y1+=(num*(x2-x1+1));
                    type=-type;
                    sum+=(num)*(x2-x1+1)*(x2-x1+1);
                }
                else{
                    col_dividefunc(x1,x2,y1,y2);
                    int num=(x2-x1+1)/(y2-y1+1);
                    x1+=(num*(y2-y1+1));
                    type=-type;
                    sum+=(num)*(y2-y1+1)*(y2-y1+1);
                }
                if(sum==n*m){
                    break;
                }
            }
        }
        else if(n==m){
            printf("%d\n",1);
        }
        printf("%d\n",ans.size());
        // for(int i=0;i<ans.size();i++){
        //     printf("%d ",ans[i].x);printf("%d ",ans[i].y);printf("%d\n",ans[i].l);
        // }
    }
    system("pause");
    return 0;
}
void row_dividefunc(int x1,int x2,int y1,int y2)
{
    int squaresize=x2-x1+1;
    for(int i=y1;i<=y2-squaresize+1;i+=squaresize){
        //cout<<i<<endl;
        node temp;temp.x=x1-1;temp.y=i-1;temp.l=squaresize;
        ans.push_back(temp);
    }
}
void col_dividefunc(int x1,int x2,int y1,int y2)
{
    int squaresize=y2-y1+1;
    for(int i=x1;i<=x2-squaresize+1;i+=squaresize){
        node temp;temp.x=i-1;temp.y=y1-1;temp.l=squaresize;
        ans.push_back(temp);
    }
}