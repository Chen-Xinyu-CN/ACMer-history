#include <iostream>
#include <string>
using namespace std;
void test01()//string容器构造
{
    string s1;//默认构造函数
    const char* str="I give you all I had, really.";
    string s2(str);
    cout<<"s2="<<s2<<endl;
    string s3(s2);
    cout<<"s3="<<s3<<endl;
    string s4(5,'a');
    cout<<"s4="<<s4<<endl;

}
void test02()//string容器赋值
{
    string str1;
    str1="I give you all I had, really";
    cout<<"str1 = "<<str1<<endl;
    string str2;
    str2=str1;
    cout<<"str2 = "<<str2<<endl;
    string str3;str3='z';
    cout<<"str3 = "<<str3<<endl;
    string str4;str4.assign("I really miss you.");
    cout<<"str4 = "<<str4<<endl;
    string str5;str5.assign("I hate you, I love you.",6);
    cout<<"str5 = "<<str5<<endl;
    string str6;str6.assign(str5);
    cout<<"str6 = "<<str6<<endl;
    string str7;str7.assign(10,'l');
    cout<<"str7 = "<<str7<<endl;
}
void test03()//string容器拼接
{
    string str1="我";
    str1+="喜欢你!";
    cout<<"str1 = "<<str1<<endl;
    string str2="张亦菲!";
    str1+=str2;
    cout<<"str1 = "<<str1<<endl;
    //也可以使用append成员函数
}
void test04()//字符串的查找和替换(在指定的位置替换字符串)
{
    //1.查找find是从左往右查的第一个，rfind是从右往左查的第一个，但是返回的下标都是从左往右的0标准
    string str1="abcdefg";int pos=str1.find("de");//查找出来的下标是从0开始的
    cout<<"pos= "<<pos<<endl;
    //2.替换replace
    string str2="abcdefg";
    str2.replace(1,3,"zyfl");//如果将要进行替换的字符串的长度超过了在replace函数中指定的个数，则字符串还是完全替换进入，多余的字符以插入形式进入
    cout<<"now str2 = "<<str2<<endl;
}
void test05()//字符串的比较
{
    string str1="hello";string str2="xello";
    if(str1.compare(str2)==0)   cout<<"str1 等于 str2"<<endl;
    else if(str1.compare(str2)>0)   cout<<"str1 大于 str2"<<endl;
    else    cout<<"str1 小于 str2"<<endl;
}
void test06()//string字符存取,即直接访问字符串中的字符
{
    string str1="hello world";
    //1.通过[]访问单个字符
    for(int i=0;i<str1.length();i++) cout<<str1[i]<<endl;
    //2.通过at方式访问单个字符
    for(int i=0;i<str1.size();i++) cout<<str1.at(i)<<endl;
    //修改单个字符 hello->xello
    str1[0]='x';str1.at(1)='y';
    cout<<str1<<endl;
}
void test07()//STL  string容器的插入和删除,起始下标都是从0开始
{
    string str="hello";
    //插入
    str.insert(1,"lsy");//insert函数有很多重载版本
    cout<<"str = "<<str<<endl;
    //删除
    str.erase(1,3);
    cout<<"str = "<<str<<endl;
}
void test08()//string子串
{
    string str="Hello,World!";
    string subStr=str.substr(0,5);
    cout<<"subStr = "<<subStr<<endl;
}
void test09()       //邮箱例子应用
{
    string user_email="1937714332@qq.com";
    int pos=user_email.find('@');
    string user_account=user_email.substr(0,pos);
    cout<<"Based the email account: "<<user_email<<endl;
    cout<<"The user account is: "<<user_account<<endl;
}
int main()
{
    //test01();
    //test02();
    //test03();
    //test04();
    //test05();
    //test06();
    //test07();
    //test08();
    test09();
    system("pause");
    return 0;
}