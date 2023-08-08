//  problem M
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;typedef unsigned long long ull;
#define MAX_N 600000+5
int n, a[MAX_N  +5], temp[MAX_N + 5];
LL num;
LL qpow(LL a,LL n);
void merge(int begin, int mid, int end)
{
    int i = begin;
    int j = mid + 1;
    int k = begin;
 
    while (i <= mid && j <= end)
    {
        if (a[i] > a[j]) {
            temp[k] = a[j];
            k++;
            j++;
            num += mid - i + 1; //对交换的次数进行统计
        } else {
            temp[k] = a[i];
            k++;
            i++;
        }
    }
    while (i <= mid) {
        temp[k] = a[i];
        k++;
        i++;
    }
    while (j <= end) {
        temp[k] = a[j];
        k++;
        j++;
    }
    for (int p = begin; p <= end; p++)
        a[p] = temp[p];
}
 
void mergesort(int begin, int end) { //归并排序
    if (begin >= end)
        return;
 
    int mid = (begin + end) / 2;
    mergesort(begin, mid);
    mergesort(mid + 1, end);
    merge(begin, mid, end);
}
int main()
{
    LL t;scanf("%lld",&t);
    for(int z=1;z<=t;z++){
        memset(a,0,sizeof(a));
        LL n;scanf("%lld",&n);
        for(LL i=0,x;i<=n-1;i++){
            scanf("%lld",&x);a[i]=x;
        }
        num = 0;
        mergesort(0, n-1);
        //cout<<num<<endl;
        //caluate min
        if(num%2==0){
            printf("%lld ",0);
        }
        else{
            printf("%lld ",2);
        }
        LL temp=n;LL cnt=0;
        while(temp){
            cnt++;
            temp>>=1;
        }
        n=qpow(2,cnt)-1;
        if(num%2==0){
            printf("%lld\n",n^2);
        }
        else{
            printf("%lld\n",n);
        }
    }
    system("pause");
    return 0;
}
LL qpow(LL a,LL n)
{
    LL ans =1;
    while(n){
        if(n&1){
            ans = ans*a;
        }
        a=a*a;
        n>>=1;
    }
    return ans;
}

/*
something new
*/