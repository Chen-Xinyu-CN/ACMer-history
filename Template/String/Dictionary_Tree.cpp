#include <bits/stdc++.h>
using namespace std;
typedef long long LL;typedef unsigned long long ull;
const LL N = 800000;
struct node{
    bool repeat;int son[28];int num;
};
node t[N];
int cnt=1;
void Insert(char* s){
    int now=0;
    for(int i=0;s[i];i++){
        int ch=s[i]-'a';
        if(t[now].son[ch]==0){
            t[now].son[ch]=cnt++;
        }
        now=t[now].son[ch];
        t[now].num++;
    }
}
int Find(char* s){
    int now=0;
    for(int i=0;s[i];i++){
        int ch=s[i]-'a';
        if(t[now].son[ch]==0) return 3;
        now=t[now].son[ch];
    }
    if(t[now].num==0) return 3;
    if(t[now].repeat==false){
        t[now].repeat=true;
        return 1;
    }
    return 2;
}
int main()
{
    char s[51];
    int n;cin>>n;
    while(n--){
        scanf("%s",s);Insert(s);
    }
    int m;scanf("%d",&m);
    while(m--){
        scanf("%s",s);
        int r=Find(s);
        if(r==1) puts("OK");
        if(r==2) puts("REPEAT");
        if(r==3) puts("WRONG");
    }
    system("pause");
    return 0;
}