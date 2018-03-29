#include<iostream>
#include<string>

using namespace std;

/***
 * string类
 * c++中用string.h和cstring头文件对原C风格字符串操作的函数的支持
 * 头文件string提供C++中的string类
 * 
 */

int main()
{
    string s1("123ert");
    cout<<s1<<endl;
    string s2(20,'$');
    cout<<s2<<endl;
    string s3(s1);
    cout<<s3<<endl;
    s1 += "QQQQQQQ";
    cout<<s1<<endl;
    s2 = "s2s2s22s22s";
    cout<<s2<<endl;
    s3[0] = 'L';
    cout<<s3<<endl;
    string s4;
    s4 = s1 + s2;
    cout<<s4<<endl;
    char all[] = "this is a c string!!!";
    string s5(all,13);
    cout<<s5<<endl;
    // string s6(all,50);//超出了总长度。依然将'\0'后面的值复制。此处其实发生了内存溢出。因为字符串常量长度没有50那么长。
    // cout<<"s6 "<<s6<<endl;
    string s7(all+4,10);
    cout<<"s7 "<<s7<<endl;
    string s8(&s5[6],&s5[10]);//左闭右开。指定两个指针，初始化了为这两个指针之间的值
    cout<<"s8 "<<s8<<endl;
    cout<<"     end     "<<endl;

/**
 * 传统C风格字符串输入
 * char info[100];
 * cin>>info;
 * cin.getline(info,100);
 * cin.get(info,100);
 * 
 * string对象
 * string str;
 * cin>>str;
 * getline(cin,str);
 */

/**
 * str.length()和str.size()都返回字符串的长度
 * find的4个重载
 * size_type find(const string & findstr,size_type pos = 0)const  从pos开始在字符串中找findstr。返回子串的位置，没找到返回string::npos   (string::npos表示的是字符串的最大长度)
 * …… find(const char *findstr,size_type pos = 0) const  结果同上
 * …… find(const char *findstr,size_type pos = 0,size_type n)  //从pos开始查找s的前n个字符组成的子串
 * …… find(char ch,size_type pos = 0)   //查找字符
 */

/**
 * string类重载了关系运算符。所以可以直接比较大小 < > ……
 * str.capacity()函数返回当前字符串获取的内存块大小
 * str.reserve(int num) 保留的内存块大小，如果num比字符串的实际长度小，那么内存块缩小为刚好容纳所有字符。如果num大于字符串实际长度，那么就将字符串容量设置为num大小
 * str.c_str()方法返回C风格的字符串指针
 */


    return 0;
}


