/**
 * 变量的声明，定义，以及使用
 * C++区分大小写
 */
#include<iostream>

using namespace std;

int main()
{
    /**
     * 变量的声明，定义   类型 变量名;   
     * a为普通变量,b为指针变量,c为引用(引用需要在声明的时候赋值)
     * 变量名不能以数字开头,只能使用字母，数字，下划线构成变量名
     */
    int a,*b,&c=a;
    /**
     * 纯变量的声明
     * extern 表示使用外部文件定义的变量。这里仅仅只是变量的声明
     */
    extern float d;

    /**
     * 类型可以是c++的基本数据类型，也可以是构造类型，比如struct，enum等。也可以是自定义类型
     */
    //变量的使用。 直接用变量名即可
    a = 0;
    b = &a;
    /**
     * 不同类型的变量所占据的空间大小也不一样，可以通过sizeof运算符进行查看
     * 空间大小也决定了变量存储的数据的范围
     * 基本数据类型的范围在 <climits>头文件中  
     * CHAR_MAX char类型的最大值
     * CHAR_MIN char类型最小值
     * UCHAR_MAX unsigned char类型最大值
     * ……
     */

    /**
     * 还可以使用typedef关键字给类型取一个别名
     * 这样就简化类型名特别长的类型的书写
     */
    typedef unsigned float ufloat;//将unsigned float 取别名为ufloat  简化书写
    ufloat e;

    cout<<"size of int is :"<<sizeof(a)<<endl;


    /**
     * 不同进制的书写
     * 123十进制
     * 0123 八进制
     * 0x123 十六进制
     */
    a = 10;
    a = 010;
    a = 0xF1;

    //cout 按进制输出
    cout<<a<<endl;//十进制
    cout<<hex;
    cout<<a<<endl;//十六进制输出
    cout<<oct;//八进制输出
    cout<<a<<endl;
    /**
     * 当C++中出现常数时，默认存储为int类型
     * 也可以是程序员手动指定。在常数后面加上后缀
     */
    1000L;//long 类型
    1000UL;//unsigned long类型
    1000F;//float 类型

    /**
     * 常量，类似于c语言中的define定义的量，但两者有实质上的不同
     * 变量声明时使用 const关键字限定,常量要在声明的时候就初始化
     */
    const int X = 99;


    return 0;
}

