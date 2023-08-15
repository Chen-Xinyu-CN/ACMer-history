#include <bits/stdc++.h>
using namespace std;
typedef long long LL;typedef unsigned long long ull;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;cin>>t;
    for(int z=1;z<=t;z++){
        string str;
        while(true){
            char ch;ch=getchar();
            str+=ch;
            if(ch=='\n') break;
        }
        cout<<str<<endl;
    }
    return 0;
}