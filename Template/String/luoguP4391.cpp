#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ull;
const LL N = 1e6+50;
LL PP=131;
char s[N];LL P[N];LL H[N];
LL gethash(LL left,LL right);
int main()
{
    LL L;scanf("%lld",&L);scanf("%s",s+1);
    P[0]=1;
    for(int i=1;i<=N-1;i++) P[i]=P[i-1]*PP;
    //预处理字符串s所有前缀的哈希值
    for(int i=1;i<=L;i++){
        H[i]=H[i-1]*PP+s[i];
    }
    for(int i=1;i<=L;i++){  //遍历所有可能前缀
        LL circlehash=gethash(1,i);
        bool flag=true;
        for(int j=1;(j+1)*i<=L;j++){
            if(gethash(j*i+1,(j+1)*i)!=circlehash){
                flag=false;break;
            }
        }
        if(flag==true){
            if(L%i!=0){
                LL len=L%i;
                if(gethash(1,len)!=gethash(L-len+1,L)){
                    flag=false;
                }
            }
        }
        if(flag==true){
            printf("%d\n",i);
            // for(int k=1;k<=i;k++){
            //     printf("%c",s[k]);
            // }
            // printf("\n");
            break;
        }

    }
    system("pause");
    return 0;
}
LL gethash(LL left,LL right)
{
    return (H[right]-H[left-1]*P[right-left+1]);
}