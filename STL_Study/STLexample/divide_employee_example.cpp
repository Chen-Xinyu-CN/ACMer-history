#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <ctime>
using namespace std;
class Employee
{
public:
    string m_Name;int m_Salary;
public:
    Employee();
    Employee(string name,int salary);
};
Employee::Employee(string name,int salary)
{
    this->m_Name=name;this->m_Salary=salary;
}
Employee::Employee()
{
    //空实现
}
void CreateEmployee(vector<Employee>& v)
{
    string nameseed="ABCDEFGHIJ";
    for(int i=0;i<10;i++){
        Employee employee;
        string name="员工";name=name+nameseed[i];
        employee.m_Name=name;
        employee.m_Salary=rand()%10000+10000;
        v.push_back(employee);
    }
}
void Print_Vector_Employee(const vector<Employee>& v)
{
    for(vector<Employee>::const_iterator it=v.begin();it!=v.end();it++){
        cout<<"员工姓名："<<it->m_Name<<" 员工薪水："<<it->m_Salary<<endl;
    }
    cout<<endl;
}
void SetGroup(vector<Employee>&v,multimap<int,Employee>&m)
{
    for(vector<Employee>::iterator it=v.begin();it!=v.end();it++)
    {
        int deptId=rand()%3;
        m.insert(pair<int,Employee>(deptId,(*it)));
    }
}
void Print_Maps_Employee(const multimap<int,Employee>& m)
{
    int n1=m.count(0);int n2=m.count(1);int n3=m.count(2);
    int ct1=1;int ct2=1;int ct3=1;
    cout<<"策划部门："<<endl;
    for(multimap<int,Employee>::const_iterator it=m.find(0);it!=m.end()&&ct1<=n1;it++,ct1++)
    {
        cout<<"员工姓名："<<(*it).second.m_Name<<" 员工薪水："<<(*it).second.m_Salary<<endl;
    }
    cout<<"美术部门："<<endl;
    for(multimap<int,Employee>::const_iterator it=m.find(1);it!=m.end()&&ct2<=n2;it++,ct2++)
    {
        cout<<"员工姓名："<<(*it).second.m_Name<<" 员工薪水："<<(*it).second.m_Salary<<endl;
    }
    cout<<"研发部门："<<endl;
    for(multimap<int,Employee>::const_iterator it=m.find(2);it!=m.end()&&ct3<=n3;it++,ct3++)
    {
        cout<<"员工姓名："<<(*it).second.m_Name<<" 员工薪水："<<(*it).second.m_Salary<<endl;
    }
}
int main()
{
    srand((unsigned int)time(NULL));
    vector<Employee> vEmployee;
    CreateEmployee(vEmployee);
    Print_Vector_Employee(vEmployee);
    multimap<int,Employee> mEmployee;
    SetGroup(vEmployee,mEmployee);
    Print_Maps_Employee(mEmployee);
    system("pause");
    return 0;
}