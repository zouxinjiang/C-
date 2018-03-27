/***
 * 重载，友元
 * 
 */

/**
 * 运算符重载
 * 重载的可以是成员函数，也可以是全局函数，
 * 但是全局函数必须有一个是用户自定义类型，防止影响本身的运算符
 */
// 返回值 operator 运算符(参数列表){};
class A
{
    public:
    int a;
    A operator +(A obj);
    operator int();
};
A A::operator+(A obj){
    this->a = obj.a + this->a;
    return *this;
};
//全局
int operator-(A a,int b){
    return (a.a - b);
};
//不能重载的运算符有   sizeof  ?:  .  ::  .*
//非成员函数版本的运算符重载需要指定运算符需要的个数的参数
//成员函数版本的运算符重载默认将本类作为函数参数的第一个参数

/**
 * 转换函数。强制类型转换的时候就知道了
 * 转换函数必须是类方法，不能指定返回类型，不能有参数
 * 
 */

// operator 类型名();
A::operator int(){
    return this->a;
};



