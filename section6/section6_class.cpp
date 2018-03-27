/**
 * 类，类似C中的结构体，只是这种结构体中可以有函数
 * 在C++中struct关键字已经扩展为class的概念了，只是二者有些区别
 * 也就是说C++中的struct也可以含有函数成员
 * 区别在于：struct中的默认成员是public的，class默认是private的
 * 
 */

class A
{
    //个人习惯将变量生命放在开始处，所以第一个就使用的是private限定为私有变量
    private:
        int a;
    //然后是对外的接口成员函数
    public:
        int x;
        void bfun();
    //继承后可用的成员函数
    protected:
        void cfun();
    //只能归本类使用的函数
    private:
        void dfun();
};
//类的声明
A obj;
//使用
// obj.bfun();
//指针形式
A *pobj = new A();
//pobj->bfun();

/**
 * 构造函数和析构函数
 * 构造函数是在定义对象时自动调用的函数，析构函数实在对象被销毁时自动调用
 * 构造函数是没有返回值，且函数名和类名相同的函数
 * 析构函数是没有返回值，函数名在类名前加一个 ~ 符号且没有参数的函数
 * 类如果没有构造函数，编译器会自动创建一个默认构造函数，但是一旦类中有构造函数声明
 * 编译器将不再自动生成默认构造函数.
 * 一般是将构造函数声明为public的，如果声明为其他方式，那么类将不能由外部方式构造，
 * 只能在类的内部才能调用构造函数
 */
class B
{
    public:
    //构造函数
    B();//默认构造函数
    B(int,int);
    B(int,float);
    B(B &);//副本构造函数
    //析构函数
    ~B();
};
//使用构造函数
B obj;
B obj3(2,3);
B obj4(2,3.0F);
//析构函数将在对象变量失效时被调用

//指针形式
B *pobj = new B();
B *pobj = new B(2,3);
//析构函数在delete对象指针后被调用
// delete pobj;


/**
 * this指针在类的内部代表本类
 * 即可通过  this->成员名  使用成员函数或成员变量
 * 或者用 (*this).成员名
 */



/**
 * 对象数组
 */
B arr[4];//使用的默认构造函数
B arr[4] = {B(),B(2,3),B(2,3.0F),B()};//使用构造函数定义

/**
 * 如何将类的声明和成员函数的定义(分开)
 * 1：将声明放在.h文件中,定义放在.cpp中
 * 2：定义时用域限定符来限定函数是成员函数
 */

//D.h
class D
{
    public:
    void afun();
    protected:
    void bfun();
    private:
    void cfun();
};
//D.cpp
#include"D.h"
void D::afun(){};
void D::bfun(){};
void D::cfun(){};
