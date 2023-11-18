#include <bits/stdc++.h>
using namespace std;
typedef long long LL;typedef unsigned long long ull;
const int N =1e3;
struct matrix{
    ull m[N][N];
};
matrix operator *(const matrix& a,const matrix& b){
    matrix c;
    memset(c.m,0,sizeof(c.m));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                c.m[i][j]=(c.m[i][j])+(a.m[i][k]*b.m[k][j]);
            }
        }
    }
    return c;
}
matrix pow_matrix(matrix a,int n){
    matrix ans;
    memset(ans.m,0,sizeof(ans.m));
    for(int i=0;i<N;i++){
        ans.m[i][i]=1;
    }
    while(n){
        if(n&1){
            ans=ans*a;
        }
        a=a*a;
    }
    return ans;
}
