#include<iostream>

using namespace std;
/****
 * 类型装换
 * operator typename(){}
 * 类型可以是基本数据类型int double 指针,也可以是自定义的数据类型
 * 不得不惊叹c++强大
 * 转换函数有几点要求
 * 1：必须是类方法
 * 2：不能有返回类型
 * 3：不能有参数
 */


class B
{
public:
    float a;
    B(float b):a(b){

    }
    operator float(){
        return a;
    }
    operator int(){
        return (int)a;
    }
    operator float *(){
        return &a;
    }
};

class C
{
    public :
    int c;
    C(int c):c(c){}
    operator B(){
        return B(c);
    }

};

int main()
{
    B b(3.4);
    float x = b;
    int y = b;
    cout<<x<<","<<y<<endl;
    float * z = b;
    cout<<*z<<endl;
    C c(6);
    B b2 = c;
    cout<<b2.a<<endl;



}

