#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
struct node{
    int lose;int win;int cost;
};
int main()
{
    int n;int x;
    cin>>n>>x;
    vector<node> friends;
    for(int i=0;i<n;i++){
        node person;
        cin>>person.lose>>person.win>>person.cost;
        friends.push_back(person);
    }
    LL sum=0;
    // for(int i=0;i<n;i++){
    //     sum+=friends[i].lose;
    // }
    LL dp[1003][1003];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int j=0;j<=x;j++){
            if(friends[i-1].cost>j){
                dp[i][j] = dp[i-1][j] + friends[i-1].lose;
            }
            else{
                dp[i][j] = max(dp[i-1][j] + friends[i-1].lose,dp[i-1][j-friends[i-1].cost] + friends[i-1].win);
            }
        }
    }
    //cout<<"dp: "<<dp[n][x]<<endl;
    //回头看装了哪些物品
    cout<<dp[n][x]*5<<endl;
    return 0;
}