#include<iostream>

using namespace std;
/**
 * 使用时请修改测试等级即可达到相应的目的
 * 测试等级
 * 0        类的声明和使用 
 * 1        类作为成员变量
 * 2        类的继承
 * 3        多态
 * 4        虚继承
 */

#define TESTLEVEL   4


class Tmp{
private:
    static int clsNum;//用来记录被实例化的次数
    int tmp;
    int num;//记录当前是实例化的第几个对象
public:
    int getTmp(){
        return tmp;
    }
    void  setTmp(int x){
        tmp = x;
    }
    //传入的num没哟实际意义，目的用来测试构造函数有参数的类作为成员变量
    Tmp(int num){
        this->num = Tmp::clsNum;
        Tmp::clsNum++;
        cout << "this is [Tmp" << this->num << " constructor]" << endl;
    }
    ~Tmp(){
        cout << "this is [Tmp" << this->num << " distructor]" << endl;
    }

};
//初始化静态成员变量
int Tmp::clsNum = 0;

class Base
{
  public:
    Tmp tmp1;
    int pubvar;
private:
    Tmp *tmp2;
    int privar;
    static int clsNum; //用来记录被实例化的次数
    int num; //记录当前是实例化的第几个对象
  public:
    int getprivar(){
        return privar;
    }
    void setprivar(int var){
        privar = var;
    }
    virtual void tell(){
        cout << "this is Base" << this->num << endl;
    }
    Base():tmp1(1){
        this->num = Base::clsNum;
        Base::clsNum++;
        tmp2 = new Tmp(2);

        cout << "this is [Base" << this->num << " constructor]" << endl;
    }
    Base(int pri, int pub) : privar(pri), pubvar(pub), tmp2(new Tmp(2)),tmp1(1)
    {
        this->num = Base::clsNum;
        Base::clsNum++;
        cout << "this is [Base" << this->num << " parameter constructor]" << endl;
    }
    virtual ~Base(){
        delete tmp2;
        cout << "this is [Base" << this->num << " distructor]" << endl;
    }

};
int Base::clsNum = 0;

class Left:public Base{
public:
    void tell(){
        cout<<"this is [Left tell]"<<endl;
    }
    Left(){
        cout<<"this is [left constructor]"<<endl;
    }
    virtual ~Left(){
        cout<<"this is [Left distructor]"<<endl;
    }


};
class Right:public Base{
public:
    void tell()
    {
        cout << "this is [Right tell]" << endl;
    }
    Right()
    {
        cout << "this is [Right constructor]" << endl;
    }
    virtual ~Right(){
        cout << "this is [Right distructor]" << endl;
    }
};

class Child : virtual public Left, virtual public Right
{
  public:
    void tell()
    { //如果不重写tell，如想调用tell就需要明确指定使用哪个基类的tell。否则就会歧义
        cout << "this is [child tell]" << endl;
    }
    void childTell()
    {
        //如果本类没有重写tell，就需要明确指定调用哪个类的方法
        tell();
    }


};

int main()
{
#if TESTLEVEL == 0
//声明的三种方式
    Tmp t1(1);
    Tmp *pt2 = new Tmp(2);
//使用方式
    t1.setTmp(1);
    cout<<"t1.tmp:"<<t1.getTmp()<<endl;
    pt2->setTmp(2);
    cout<<"t2.tmp:"<<pt2->getTmp()<<endl;

//指针的变量需要释放，其他变量自动释放
delete pt2;
/**
 * 指针需要手动释放。用new声明的要用delete释放
 * 指针用->，变量用.访问成员，和结构体保持了一致
 * 
 */
#endif

#if TESTLEVEL == 1
    Base b1 = Base();
    Base b2 = Base(1,2);
    b1.tell();
    b2.tell();
/****
 * 测试小结
 * 先声明的先构造，先声明的后析构。成员变量先构造，后析构。
 * 类作为成员变量时，如果成员变量的类的构造函数要传参数，那么只能用参数列表的形式初始化
 * 该成员变量。如果成员变量是某类的指针，那么就可以采用在构造函数内赋值来初始化。
 * 不过记得析构函数要释放指针。
 * 构造函数的参数列表初始化顺序和成员变量构造顺序无关，成员变量构造顺序跟在类中的声明顺序相关
 * 
 * 
 */

#endif

#if TESTLEVEL == 2
    Left l1;
    l1.tell();
    /****
 * 测试小结
 * 构造时先调用基类的构造函数，再调用本类的构造函数，析构时顺序相反
 * Left中的tell覆盖了继承的Base中的tell。(函数复写)，可以通过Base::tell显式的调用基类的tell
 * 
 */

#endif

#if TESTLEVEL == 3
    Base *b;
    b = new Left();
    b->tell();
    delete b;
    /****
 * 测试小结
 * 多态测试失败，b->tell()调用的还是Base::tell()。delete b后没有调用Left的析构函数。
 * 修改：将Base的tell函数改为virtual的，且将Base的析构函数也改为virtual的。
 * 修改后测试成功
 * 
 */
#endif

#if TESTLEVEL == 4
    Child c;
    c.childTell();

    /****
 * 测试小结
 * 由于c++多继承，可能导致一个了继承了来自同一个基类的多个类，
 * 为了解决继承冲突，需要采用虚继承的方式继承两个基类(任意一个虚继承或全部虚继承)
 */
#endif

    return 0;
}
