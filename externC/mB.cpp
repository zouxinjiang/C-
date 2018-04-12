#include<iostream>
extern "C"{
#include "mA.h"
}
using namespace std;

int main()
{
        cout<<add(2,3)<<endl;
}

/**
 *让头文件中的声明采用C的方式编译，调用函数的时候就能够匹配了。 
 */