#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;
class Player
{
public:
    string name;double grades;
public:
    Player();
    Player(string nam,double gra);
    ~Player();
};
Player::Player(){
    //空实现
}
Player::Player(string nam,double gra){
    this->name=nam;this->grades=gra;
}
Player::~Player(){
    //空实现
}
void CreatePlayers(vector<Player>&v1)
{
    string nameseed="ABCDEFGHIJKL";
    for(int i=0;i<5;i++){
        string name="选手";
        name=name+nameseed[i];
        Player player(name,0);
        v1.push_back(player);
    }
}
void PrintPlayers(const vector<Player>& v1)
{
    for(vector<Player>::const_iterator it=v1.begin();it!=v1.end();it++){
        cout<<"姓名:"<<(*it).name<<" 分数:"<<(*it).grades<<endl;
    }
}
void Setgrades(vector<Player>& v1)
{
    for(vector<Player>::iterator itb=v1.begin();itb!=v1.end();itb++){
        deque<double> d1;
        for(int i=0;i<10;i++){
        double score=rand()%41+60; //60-100
        d1.push_back(score);
        }
    //排序
        sort(d1.begin(),d1.end());
        d1.pop_back();d1.pop_front();
        double sum=0;
        for(deque<double>::iterator it=d1.begin();it!=d1.end();it++){
            sum=sum+(*it);
        }
        double avg=sum/d1.size();
        itb->grades=avg;
    }
    
}
int main()
{
    vector<Player> v1;
    CreatePlayers(v1);
    PrintPlayers(v1);
    Setgrades(v1);
    PrintPlayers(v1);
    system("pause");
    return 0;
}