//预编译指令，引入iostream头文件
#include<iostream>
//行注释
/**
 * 块级注释
 */

//使用std命名空间，为了简化后边使用该命名空间下的对象等
using namespace std;
//c++主函数 返回值标准是int类型。 这里没有参数，使用有参数的可以定义为：
/**
 *  int main(int argc,char *argv[])  或 int main(int argc,char *argv[],char *env)
 */
int main()
{
    //cout就是std命名空间下的一个对象，该对象用于输出到屏幕。如果没有前面的using namespace std，那么此处就要用std::cout
    cout<<"hello world!"<<endl;

    return 0;
};
//如何编译程序
//g++ lession1_helloworld.cpp -o helloworld.exe
