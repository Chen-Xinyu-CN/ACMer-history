#include <iostream>
#include <queue>
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

void test01()
{
    queue<Player>q;Player p1("陆诗雨",19);Player p2("张亦菲",19);
    Player p3("白神",20);Player p4("崔神",19);
    q.push(p1);q.push(p2);q.push(p3);q.push(p4);
    cout<<"此队列的元素数量为:"<<q.size()<<endl;
    while(!q.empty()){
        cout<<"队头元素为:"<<"姓名:"<<q.front().name<<" 年龄:"
        <<q.front().grades<<endl;
        q.pop();
    }
    cout<<"此队列的元素数量为:"<<q.size()<<endl;
}
int main()
{
    //队列中只有队头和队尾才可以被外界使用，
    //因此队列不允许有遍历行为(元素不被改动)
    //队列符合先进先出FIFO
    test01();
    system("pause");
    return 0;
}