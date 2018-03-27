/**
 * c风格的字符串
 */

#include<iostream>
#include<cstring>

using namespace std;

int main()
{
    const int SIZE = 15;
    char name1[SIZE] = {'a','b','c','\0'};//列表法赋值
    char name2[SIZE] = "xyzmnq";//字符串常量赋值
    strlen(name2);//计算字符串长度

    /**
     * C风格的字符串以\0为结束符
     */

    //字符串输入
    cin>>name2;
    cin.getline(name2,15);
    cin.get(name2,15);//不会丢弃换行符，下一次再用get的时候就会有问题。
    cin.clear();//清除缓冲区

    return 0;
}


