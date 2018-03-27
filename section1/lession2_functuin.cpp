#include <iostream>
#include<cmath>   //数学函数库头文件

using namespace std;

/**
 * 自定义函数
 * 此处为声明和定义一起
 * 函数的结构为：
 * 返回值类型  函数名 (参数类型 形参名, ……){ 函数体;  return 返回值;}
 */
int fun1(int a){
    //code
    return 0;
};
/**
 * 此处为声明和定义分开，但是处于同一文件
 */
int fun2();


int main()
{

    fun1(222);//调用函数

    int a = sqrt(33);//调用cmath数学库里面的函数    
    return 0;
};
int fun2(){
    //code
    return 1;
};
/**
 * 自定义函数的调用和函数库中的函数调用方式一样
 * 函数名(参数……)
 */

//g++ lession2_function.cpp -o function.exe
