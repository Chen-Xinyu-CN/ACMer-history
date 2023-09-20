#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
map<string,int> schoolm1;
map<string,int> schoolm2;
struct node{
    int paixu;string str;
    // bool operator>(const node n){
    //     return paixu>n.paixu;
    // }
};
class MyCompare{
public:
    bool operator()(node n1,node n2) const{
        return n1.paixu>n2.paixu;
    }
};
priority_queue<node,vector<node>,MyCompare> heap1;
priority_queue<node,vector<node>,MyCompare> heap2;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    LL n;LL m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        string s;cin>>s;
        if(schoolm1[s]==0){
            schoolm1[s]=i;
        }
    }
    for(map<string,int>::iterator it=schoolm1.begin();it!=schoolm1.end();it++){
        node nd;nd.paixu=it->second;nd.str=it->first;
        heap1.push(nd);
    }
    for(int i=1;i<=m;i++){
        string t;cin>>t;
        if(schoolm2[t]==0){
            schoolm2[t]=i;
        }
    }
    for(map<string,int>::iterator it=schoolm2.begin();it!=schoolm2.end();it++){
        node nd;nd.paixu=it->second;nd.str=it->first;
        heap2.push(nd);
    }
    schoolm1.clear();schoolm2.clear();
    // cout<<"===================="<<endl;
    // while(!heap1.empty()){
    //     cout<<heap1.top().str<<" "<<heap1.top().paixu<<endl;
    //     heap1.pop();
    // }
    // cout<<"===================="<<endl;
    // while(!heap2.empty()){
    //     cout<<heap2.top().str<<" "<<heap2.top().paixu<<endl;
    //     heap2.pop();
    // }
    //cout<<"==========="<<endl;
    map<string,int> checkmap;
    //+cout<<"================"<<endl;
    int h1num=heap1.size();int h2num=heap2.size();
    for(int i=1;i<=min(h1num,h2num);i++){
        string s1=heap1.top().str;
        string t1=heap2.top().str;
        if(checkmap[s1]==0){
            cout<<s1<<endl;
            checkmap[s1]=1;
        }
        if(checkmap[t1]==0){
            cout<<t1<<endl;
            checkmap[t1]=1;
        }
        heap1.pop();heap2.pop();
    }
    
    if(!heap1.empty()){
        while(!heap1.empty()){
                string ss=heap1.top().str;
                if(checkmap[ss]==0){
                    cout<<ss<<endl;
                    checkmap[ss]=1;
                }
                heap1.pop();
        }

    }
    else{
        while(!heap2.empty()){
            string ss=heap2.top().str;
                if(checkmap[ss]==0){
                cout<<ss<<endl;
                checkmap[ss]=1;
            }
            heap2.pop();

        }
    }
    return 0;
}