//此线段树的结点上表示结点代表的线段的区间和
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;typedef unsigned long long ull;
const LL N = 1e5+5;
LL tree[N<<2];LL a[N];LL tag[N<<2];
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
    std::ios::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);
    LL n;LL m;cin>>n>>m;
    for(LL i=1;i<=n;i++)    cin>>a[i];
    build(1,1,n);   //建树
    for(LL i=1;i<=m;i++){
        LL type;cin>>type;
        if(type==1){
            LL left;LL right;LL k;
            cin>>left>>right>>k;
            update(left,right,1,1,n,k);
        }
        else{
            LL left;LL right;
            cin>>left>>right;
            cout<<query(left,right,1,1,n)<<endl;
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
    tag[p]+=d;
    tree[p]+=(d*(pr-pl+1));
}
void push_down(LL p,LL pl,LL pr){
    if(tag[p]){
        LL mid=(pl+pr)>>1;
        addtag(ls(p),pl,mid,tag[p]);
        addtag(rs(p),mid+1,pr,tag[p]);
        tag[p]=0;
    }
}
void update(LL left,LL right,LL p,LL pl,LL pr,LL d){
    if(left<=pl&&right>=pr){
        addtag(p,pl,pr,d);
        return;
    }
    push_down(p,pl,pr);
    LL mid = (pl+pr)>>1;
    if(left<=mid){
        update(left,right,ls(p),pl,mid,d);
    }
    if(right>mid){
        update(left,right,rs(p),mid+1,pr,d);
    }
    push_up(p);
}