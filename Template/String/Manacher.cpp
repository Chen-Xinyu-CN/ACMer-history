#include <bits/stdc++.h>
using namespace std;
const int N = 11000002;
int n;int P[N<<1];char a[N];char S[N<<1];
void change(){
    n=strlen(a);
    int k=0;S[k++]='$';S[k++]='#';
    for(int i=0;i<n;i++){
        S[k++]=a[i];S[k++]='#';
    }
    S[k++]='&';n=k;
}
void manacher(){
    int R=0;int C;
    for(int i=1;i<n;i++){   //此时的n已经是经过处理后的长度了
        if(i<R) P[i] = min(P[(C<<1)-i],P[C]+C-i);
        else P[i] = 1;
        while(S[i+P[i]]==S[i-P[i]]) P[i]++;//此时是暴力扩展法
        if(P[i]+i>R){
            R = P[i]+i;C=i;//更新最大半径+原点和其原点下标
        }
    }
}
int main()
{
    scanf("%s",a);change();
    manacher();
    int ans=1;
    int pos=max_element(P,P+n)-P;ans = P[pos];
    printf("%d\n",ans-1);
    //每个回文串在原字符串的开头位置是(i-p[i])/2;
    // for(int i=0;i<n;i++){
    //     cout<<S[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=(pos-P[pos])/2;i<(pos-P[pos])/2+ans-1;i++){
    //     cout<<a[i]<<" ";
    // }
    // cout<<endl;
    system("pause");
    return 0;
}