//luoguP1833樱花
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=1e5+5;
int hhs,mms;int hhe,mme;int n;
string s,temp;
void init(){
    cin>>s;
    int z;
    for(z=0;z<s.size()&&s[z]!=':';z++){
        temp+=s[z];
    }
    istringstream in1(temp);
    in1>>hhs;
    temp.clear();
    z++;
    for(;z<s.size();z++){
        temp+=s[z];
    }
    istringstream in2(temp);
    in2>>mms;
    temp.clear();
    s.clear();
    cin>>s;
    z=0;
    for(z=0;z<s.size()&&s[z]!=':';z++){
        temp+=s[z];
    }
    istringstream in3(temp);
    in3>>hhe;
    temp.clear();
    z++;
    for(;z<s.size();z++){
        temp+=s[z];
    }
    istringstream in4(temp);
    in4>>mme;
    temp.clear();
}
struct node{
    int type;   //0完全背包 1有数量限制
    LL w;LL c;
};
vector<node> bag;
LL dp[2][MAXN];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //我初始化写的太抽象了
    init();
    memset(dp,0,sizeof(dp));
    LL T=(hhe-hhs)*60+(mme-mms);
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        LL c;LL w;LL num;
        cin>>c>>w>>num;
        if(num==0){
            num=1e6;
        }
        for(int i=1;i<=num;i=i<<1){
                node nd2;
                nd2.type=1;nd2.c=i*c;nd2.w=i*w;
                bag.push_back(nd2);
                num-=i;
        }
            if(num){
                node nd3;
                nd3.type=1;nd3.c=num*c;nd3.w=num*w;
                bag.push_back(nd3);
            }
    }

    // for(int i=0;i<bag.size();i++){
    //     cout<<bag[i].type<<bag[i].c<<bag[i].w<<endl;
    // }
    
    int old=0;int now=1;
    for(int i=1;i<=bag.size();i++){
        for(int j=1;j<=T;j++){
            if(bag[i-1].type==0){//是完全背包
                if(j<bag[i-1].c){
                    dp[now][j]=dp[old][j];
                }
                dp[now][j]=max(dp[old][j],dp[now][j-bag[i-1].c]+bag[i-1].w);
            }
            else{//不是完全背包
                if(j<bag[i-1].c){
                    dp[now][j]=dp[old][j];
                }
                else{
                    dp[now][j]=max(dp[old][j],dp[old][j-bag[i-1].c]+bag[i-1].w);
                }
            }
        }
        swap(old,now);
    }
    cout<<dp[old][T]<<endl;
    

    

    return 0;
}