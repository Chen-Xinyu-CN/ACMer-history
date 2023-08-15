#include <iostream>
#include <stack>
using namespace std;
void test01()
{
    stack<int> s;s.push(10);s.push(20);s.push(30);s.push(40);
    s.push(50);
    //只要栈不为空就查看栈顶并执行出栈操作
    cout<<"栈中元素个数为:"<<s.size()<<endl;
    while(!s.empty()){
        cout<<"栈顶元素为:"<<s.top()<<endl;
        //出栈
        s.pop();
    }
}
int main()
{
    //栈不允许有遍历行为；栈可以判断容器是否为空；栈可以返回元素个数
    //栈的特点是符合先进后出
    test01();
    system("pause");
    return 0;
}