/**
 * c++风格的字符串
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str = "abcd";
    string str1;
    cin>>str1;

    str1 = str1 + str2;//字符串拼接
    str1.empty();//判空
    str1.size();//获取字符串长度
    str1.length();//同size()
    str1[2];//获取第三个字符
    str1.assign(str2);//赋值
    str1.at(2);//同str1[2]
    str1.begin();//同str1[0]
    str1.end();//最后一个字符
    char * s = str1.c_str();//转换为C风格的字符串
    str1.ompare(str2);//比较字符串
    str1.erase(……);//删除
    str1.find(……);//查找
    str1.rfind(……);  //逆向查找
    str1.insert(……);//插入
    str1.replace(……); //替换
    str1.substr(……);//子串
    str1.swap(……);//交换字符串
    


    return 0;
}
