#include<iostream>
using namespace std;

/**
 * auto_ptr类（模板类）
 * 通过这个类，可以实现自动释放内存，避免忘记释放内存
 * auto_ptr定义了类似指针的对象，可以将new的地址赋值给这种对象
 * 当auto_ptr过期时，他的析构函数将自动调用delete来释放内存
 * 注意auto_ptr析构函数调用的是delete，不是delete[]。所以只能用于new申请的地址
 * 用new[]申请的地址还是要自己手动调用释放。当然你可以将auto_ptr的代码拷贝，改成另外一个名字，然后修改析构函数调用delete[]
 * 
 */





