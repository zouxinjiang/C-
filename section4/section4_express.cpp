/**
 * 关系表达式，分支，顺序，循环结构
 */

#include<iostream>

using namespace std;

int main()
{
    //程序都是自上而下运行，默认就是顺序结构

    //分支结构
    if(true){}
    if(true){}else{}
    if(true)else if(true){}else if(true){}else{}
    switch(var){
        case 'a':
        break;
        case 20:
        break;
        default:
        break;
    };

    //循环结构
    for(int i = 0;i < 10; i++){};
    do{}while(true);
    while(true){};

    //++ --
    int a = 0,b;
    b = a++;//b=0
    b = ++a;//b=1
    b = a--;//b=0
    b = --a;//b=-1
    a += b;//同a=a+b，可以认为是一种简写方式。但是两个表达式的运算符完全不同，一个为 + ，一个为+=

    //关系表达式 == > < >= <= !=
    a > b;
    //三元表达式 condition ? true : false;
    a > b ? a : b;
    //C风格的字符串不能直接使用这些符号比较，需要用到比较函数

    //逻辑表达式  || 或 && 与 !否   具有短路功能
    true || false;//true
    true && false;//false
    !true;//false
    //位运算 |按位或 & 按位与 ~按位取反 ^按位异或  >> 右移  << 左移
    0x01 | 0x03;//0x03
    0x01 & 0x03;//0x01
    ~0x01;//0xFE
    0x01 ^ 0x03;//0x02
    0x01 << 1;//0x02
    0x03 >> 1;//0x01//丢失了一位

    //break，continue
    //break 用于循环和switch中，代表退出到上一层
    //continue 用于循环，代表直接进入下一次循环



}
