//  problem H
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;typedef unsigned long long ull;
const LL MAXN =1e6+50;
int intval[MAXN];
int main()
{
    int N;cin>>N;vector<int> v;v.push_back(-1);queue<int> one_pos;
    for(int i=1,x;i<=N;i++){
        cin>>x;v.push_back(x);
        if(x==1)    one_pos.push(i);
    }
    int left=1;int right=1;LL sum=0;
    while(left!=N+1){
        cout<<"now inteval:"<<left<<", "<<right<<endl;
        if(v[left]!=1){
            left++;right=left;memset(intval,0,sizeof(intval));
            continue;
        }
        if(v[right]==1){
            sum++;cout<<left<<", "<<right<<endl;right++;
            intval[v[right]]++;continue;
        }
        intval[v[right]]++;
        if(intval[v[right]]<=intval[v[right]-1]&&intval[v[right]]>=intval[v[right]+1]){
            sum++;cout<<left<<", "<<right<<endl;right++;
        }
        else{
            left++;right=left;memset(intval,0,sizeof(intval));
            continue;
        }
    }
    cout<<sum<<endl;
    system("pause");
    return 0;
}