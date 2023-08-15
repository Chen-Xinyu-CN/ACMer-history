//Longest palindrome string luoguP3501
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ull;
const int N = 5e5+10;
char s[N];char t[N];int n;LL ans;ull f[N];ull g[N];int PP = 131;ull P[N];
void bin_search(int pos);
int main()
{
    scanf("%d",&n);scanf("%s",s+1);
    for(int i=1;i<=n;i++)   s[i]=='1'?t[i]='0':t[i]='1';//t是s的反串
    P[0]=1;
    for(int i=1;i<=n;i++)   P[i]=P[i-1]*PP;
    for(int i=1;i<=n;i++)   f[i]=f[i-1]*PP+s[i];//预处理主串的哈希值
    for(int i=n;i>=1;i--)   g[i]=g[i+1]*PP+t[i];//预处理反串的哈希值
    for(int i=1;i<n;i++)    bin_search(i);
    printf("%lld\n",ans);
    system("pause");
    return 0;
}
void bin_search(int pos)
{
    int L=0;int R=min(pos,n-pos);
    while(L<R){
        int mid = (L+R+1)>>1;
        if((ull)(f[pos]-f[pos-mid]*P[mid])==(ull)(g[pos+1]-g[pos+1+mid]*P[mid]))    L = mid;
        else    R=mid-1;
    }
    ans +=L;
}
ull BKDRHash(char* s){
    ull P = 131,H=0;
    int n=strlen(s);
    for(int i=0;i<n;i++){
        H=H*P+s[i]-'a'+1;
    }
    return H;
}