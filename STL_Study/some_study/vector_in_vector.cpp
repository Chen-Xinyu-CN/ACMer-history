#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    //定义二维容器
    vector<vector <int>> doudemi_v;
    //定义多个小容器以及为向小容器中添加数据
    vector<int> v1;vector<int> v2;vector<int> v3;vector<int> v4;
    for(int i=0;i<4;i++) 
    {
        v1.push_back(i); v2.push_back(i+1); v3.push_back(i+2); v4.push_back(i+3);
    }
    //将小容器插入到大容器中
    doudemi_v.push_back(v1);doudemi_v.push_back(v2);doudemi_v.push_back(v3);doudemi_v.push_back(v4);
    //通过大容器，把所有的数据遍历一遍
    for(vector<vector <int>>::iterator it=doudemi_v.begin();it!=doudemi_v.end();it++)
    {
        for(vector<int>::iterator itson=(*it).begin();itson!=(*it).end();itson++)
        {
            cout<<(*itson)<<" ";
        }
        cout<<endl;
    }
    system("pause");
    return 0;
}