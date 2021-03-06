/***
 * 继承，抽象类，虚函数
 * 
 */

class Base
{
    private:
        int b_v1;
        float b_v2;
    public:
        int b_gv1;
        int b_fun1();
    protected:
        int b_pv1;
        int b_fun2();
    private:
        int b_fun3();
};
//继承的类中可以访问基类中的非private成员
class A : public Base
{
    private:
        int a_v1;
    public:
        int a_fun();
};
//A是public继承方式继承的Base，那么没有缩小访问权限，所以B类的子类中可以访问所有非private成员
class B:private A
{

};
/**
 * public 继承方式不修改继承后基类成员的权限直接放入类中
 * protected继承方式将基类的public成员缩小为protected后放入类中
 * private方式将基类所有的成员都缩小为private后放入类中
 */


/**
 * 创建派生类对象时，先调用基类的构造函数，再调用派生类的构造对象
 * 派生类被释放时，先调用派生类的析构函数，再调用基类的析构函数
 * 
 */


/**
 * 虚析构函数
 * 使用虚析构函数的原因就是，当指针指向派生类对象时，delete掉的时候就只会调用派生类的析构函数
 * 如果将基类的析构函数写成虚函数，那么在delete派生类对象的时候就会自动调用基类的析构函数
 * 所以如果派生类中有析构函数，那么基类就需要虚析构函数，即使基类虚析构函数不做任何事情
 */ 

/**
 * 需要动态联编的函数都需要声明为virtual 虚函数
 * 在派生类需要重写的方法需要声明为虚函数
 * 动态联编需要牺牲性能，所以要避免将不必要的函数声明为虚函数
 *
 * 构造函数【不能】是虚函数
 * 析构函数【应该】是虚函数
 * 友元函数【不能】是虚函数
 * 不会被重写的基类函数【不应该】是虚函数
 * 
 */

/**
 * 抽象类
 * 含有纯虚函数的类
 * 内部含有 virtual  类型名 函数名(参数列表) = 0;  这样的函数
 * 这样的函数在派生类中要实现（复写一次），所以是虚函数
 * 抽象类是不能定义对象的，所以在实际中为了强调类是抽象类，
 * 将类的构造函数声明为protected权限
 * 
 * 
 * 抽象类只能用作其他类的基类，不能建立抽象类对象。
 * 抽象类不能用作参数类型、函数返回类型或显式转换的类型。（作为参数时会用到副本构造函数，所以不能作为参数）
 * 可以定义指向抽象类的指针和引用，此指针可以指向它的派生类，进而实现多态性
 * 
 */
