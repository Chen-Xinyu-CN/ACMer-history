//此线段树每个结点代表着结点表示的区间的区间和
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;typedef unsigned long long ull;
const LL N = 1e5+5;const LL INF = 1e8;
LL tree[N<<2];LL a[N];LL tag[N<<2]; //tree数组代表着线段树的结点,a数组代表了初始元素的值
LL ls(LL p);
LL rs(LL p);
void push_up(int p);
void build(int p,int pl,int pr);
LL query(LL L,LL R,LL p,LL pl,LL pr);
void addtag(LL p,LL pl,LL pr,LL d);
void push_down(LL p,LL pl,LL pr);
void update(LL left,LL right,LL p,LL pl,LL pr,LL d);
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);
    int t;cin>>t;
    for(int z=1;z<=t;z++){
        int N;cin>>N;
        for(LL i=1;i<=N;i++){   //从1开始存
            cin>>a[i];
        }
        build(1,1,N);
        int M;cin>>M;
        for(int i=1;i<=M;i++){
            int T;int X;int Y;
            cin>>T>>X>>Y;
            if(T==0){
                cout<<"change "<<"[ "<<X<<", "<<Y<<" ]"<<endl;
                update(X,Y,1,1,N,1);    //update once
            }
            else{
                cout<<"query "<<"[ "<<X<<", "<<Y<<" ]"<<endl;
                cout<<query(X,Y,1,1,N)<<endl;
            }
        }
    }
    system("pause");
    return 0;
}
LL ls(LL p){
    return p<<1;
}
LL rs(LL p){
    return (p<<1)|1;
}
//构造线段树的代码
void push_up(int p){
    tree[p]=tree[ls(p)]+tree[rs(p)];
}
void build(int p,int pl,int pr){    //递归建立线段树
    if(pl==pr){
        tree[p]=a[pl];return;   //线段树的叶子结点
    }
    LL mid=(pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    push_up(p);     //从下至上传递区间值
}
//区间查询代码
LL query(LL L,LL R,LL p,LL pl,LL pr){  //L与R是此时要查询的左右区间
    if(L<=pl&&pr<=R){       //代表此时递归到的结点被要查询的区间[L,R]所包住了,该节点是要查询的结点的子区间
        return tree[p];
    }
    push_down(p,pl,pr);     //不能覆盖，需要下放lazy tag
    LL mid=(pl+pr)>>1;
    LL res=0;
    if(L<=mid){
        res+=query(L,R,ls(p),pl,mid);
    }
    if(R>mid){
        res+=query(L,R,rs(p),mid+1,pr);
    }
    return res;
}
//Lazy tag
void addtag(LL p,LL pl,LL pr,LL d){
    cout<<"after update "<<"[ "<<pl<<", "<<pr<<" ] "<<d<<"times"<<endl;
    tag[p]+=d;
    while(d--){
        LL newdata=0;
        for(int i=pl;i<=pr;i++){
            a[i]=sqrt(a[i]);
            newdata+=a[i];
        }
        tree[p]=newdata;
    }
    cout<<tag[p]<<" | ";cout<<tree[p]<<endl;
}
void push_down(LL p,LL pl,LL pr){
    LL mid=(pl+pr)>>1;
    if(tag[p]>0){
        addtag(ls(p),pl,mid,tag[p]);
        addtag(rs(p),mid+1,pr,tag[p]);
        tag[p]=0;
    }
}
void update(LL left,LL right,LL p,LL pl,LL pr,LL d){
    cout<<"Node index path: "<<p<<" "<<pl<<", "<<pr<<" "<<tag[p]<<endl;
    if(left<=pl&&right>=pr){
        addtag(p,pl,pr,d);
        return;
    }
    push_down(p,pl,pr);     //如果不能覆盖，将tag传给子树
    LL mid = (pl+pr)>>1;
    if(left<=mid){
        update(left,right,ls(p),pl,mid,d);
    }
    if(right>mid){
        update(left,right,rs(p),mid+1,pr,d);
    }
    push_up(p); //递归返回时更新结点
}