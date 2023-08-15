#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> v;
    v.push_back(1);v.push_back(2);v.push_back(4);v.push_back(4);v.push_back(5);v.push_back(6);
    cout<<lower_bound(v.begin(),v.end(),4)-v.begin()<<endl;
    for(vector<int>::iterator it=v.begin();it!=v.end();it++){
        cout<<(*it)<<endl;
    }
    system("pause");
    return 0;
}