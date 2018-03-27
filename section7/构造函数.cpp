#include<iostream>

using namespace std;


class A
{
    public:
        int a;

    A()//默认构造函数
    {
        cout<<"默认构造函数"<<endl;
        a = 0;
    }
    explicit A(int a)
    {
        cout<<"int 构造函数"<<endl;
        this->a = a;
    }
    A(float a)
    {
        cout<<" float 构造函数"<<endl;
        this->a = a;
    }
    A(char * p){
        cout<<"char * 构造函数"<<endl;
        a = 4;
    }
    //副本构造函数(复制构造函数)。副本构造函数形式固定，只能这样写
    A(const A &src){
        cout<<"copy 副本构造函数"<<endl;
        a = src.a;
    }

};

int main()
{
    A a1;
    cout<<a1.a<<endl;
    A a2(1);
    cout<<a2.a<<endl;
    A a3(2.0F);
    cout<<a3.a<<endl;

    A a5 = (A)9; //只有一个参数的构造函数没有指定为explicit,所以进行了隐式类型装换。通过调用int类型构造函数的装换的。这是强制转换
    cout<<a5.a<<endl;
    A a6 = 10.0F; //只有一个参数的构造函数没有指定为explicit,所以进行了隐式类型装换。通过调用float类型构造函数的装换的。
                    //如果将float的构造函数指定为explicit的，那么这个就会用int型的构造函数转换。如果将int和float都指定为explicit，
                    //只能显示转换，否则编译器报错
    cout<<a6.a<<endl;

    A a4 = a2;//采用了副本构造函数，这里还进行了类型装换。通过调用float类型构造函数的装换的。
    cout<<a4.a<<endl;


}


