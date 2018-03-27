#include<iostream>

using namespace std;

/***
 * 下面是交叉引用的示例
 * A中含有B，B中含有A  (其中一个类中含有的不是对象实例)
 * 解决方式就是采用先声明是一个类，定义在后面
 * 实验发现，如果两个类中多是对象的实例，而不是一个是指针或两个全是指针
 * 无论怎么调整，都是报错。
 * 
 */



class B;

class A
{
    public:
        B *b;
};
class B
{
    public:
        A a;
};

int main()
{
    A a;
    B b;
}

