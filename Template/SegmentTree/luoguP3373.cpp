//此线段树的结点上表示结点代表的线段的区间和
//luogu P3373线段树模板2
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;typedef unsigned long long ull;
const LL N = 1e5+5;
LL tree[N<<2];LL a[N];
LL tag[N<<2];LL mtag[N<<2];
LL ls(LL p);
LL rs(LL p);
void push_up(int p);
void build(int p,int pl,int pr);
LL query(LL L,LL R,LL p,LL pl,LL pr);
void addtag(LL p,LL pl,LL pr,LL d);
void push_down(LL p,LL pl,LL pr);
void update(LL left,LL right,LL p,LL pl,LL pr,LL d);
void multitag(LL p,LL pl,LL pr,LL f);
void multiupdate(LL left,LL right,LL p,LL pl,LL pr,LL f);
LL mod;
int main()
{
    std::ios::sync_with_stdio(false);
    cin.tie(0); 
    cout.tie(0);
    int n;cin>>n;int q;cin>>q;cin>>mod;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=(N<<2-1);i++){
        mtag[i]=1;
    }
    memset(tag,0,sizeof(tag));
    build(1,1,n);                           //建树
    for(int i=1;i<=q;i++){
        int type;int x;int y;
        cin>>type>>x>>y;
        if(type==1){
            LL k;cin>>k;
            multiupdate(x,y,1,1,n,k);
        }
        else if(type==2){
            LL k;cin>>k;
            update(x,y,1,1,n,k);
        }
        else{
            cout<<query(x,y,1,1,n)<<endl;
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
        tree[p]=a[pl];return;       //线段树的叶子结点
    }
    LL mid=(pl+pr)>>1;
    build(ls(p),pl,mid);
    build(rs(p),mid+1,pr);
    push_up(p);                     //从下至上传递区间值
}
//区间查询代码
LL query(LL L,LL R,LL p,LL pl,LL pr){  //L与R是此时要查询的左右区间
    if(L<=pl&&pr<=R){                   //代表此时递归到的结点被要查询的区间[L,R]所包住了,该节点是要查询的结点的子区间
        return tree[p];
    }
    push_down(p,pl,pr);     //不能覆盖，需要下放lazy tag
    LL mid=(pl+pr)>>1;
    LL res=0;
    if(L<=mid){
        res=((res%mod)+(query(L,R,ls(p),pl,mid)%mod))%mod;
    }
    if(R>mid){
        res=((res%mod)+(query(L,R,rs(p),mid+1,pr)%mod))%mod;
    }
    return res;
}
//Lazy tag
void addtag(LL p,LL pl,LL pr,LL d){
    tag[p]=(tag[p]%mod+d%mod)%mod;
    tree[p]=(tree[p]%mod+((d%mod)*((pr-pl+1)%mod))%mod)%mod;
    //cout<<"add "<<d<<" in ["<<pl<<", "<<pr<<" ], and the sum now is "<<tree[p]<<" tag is "<<tag[p]<<" mtag is "<<mtag[p]<<endl;
}
void multitag(LL p,LL pl,LL pr,LL f){
    mtag[p]=((mtag[p]%mod)*(f%mod))%mod;                     //mtag更新
    tag[p]=((tag[p]%mod)*(f%mod))%mod;                        //tag更新
    tree[p]=((tree[p]%mod)*(f%mod))%mod;
    //cout<<"multi "<<f<<" in ["<<pl<<", "<<pr<<" ], and the sum now is "<<tree[p]<<" tag is "<<tag[p]<<" mtag is "<<mtag[p]<<endl;
}
void push_down(LL p,LL pl,LL pr){
    if(tag[p]!=0&&mtag[p]!=1){                      //tag 与 mtag 都存在
        LL mid=(pl+pr)>>1;
        //先乘后加
        multitag(ls(p),pl,mid,mtag[p]);
        addtag(ls(p),pl,mid,tag[p]);
        multitag(rs(p),mid+1,pr,mtag[p]);
        addtag(rs(p),mid+1,pr,tag[p]);
        //两个tag重置
        tag[p]=0;mtag[p]=1;
    }
    else if(tag[p]!=0&&mtag[p]==1){
        LL mid=(pl+pr)>>1;
        addtag(ls(p),pl,mid,tag[p]);
        addtag(rs(p),mid+1,pr,tag[p]);
        tag[p]=0;
    }
    else if(tag[p]==0&&mtag[p]!=1){
        LL mid=(pl+pr)>>1;
        multitag(ls(p),pl,mid,mtag[p]);
        multitag(rs(p),mid+1,pr,mtag[p]);
        mtag[p]=1;
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
void multiupdate(LL left,LL right,LL p,LL pl,LL pr,LL f){
    if(left<=pl&&right>=pr){
        multitag(p,pl,pr,f);
        return;
    }
    push_down(p,pl,pr);
    LL mid = (pl+pr)>>1;
    if(left<=mid){
        multiupdate(left,right,ls(p),pl,mid,f);
    }
    if(right>mid){
        multiupdate(left,right,rs(p),mid+1,pr,f);
    }
    push_up(p);
}