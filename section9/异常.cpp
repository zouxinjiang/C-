#include<iostream>
#include<exception>

using namespace std;
/***
 * c++的异常是要程序员自己抛出的，这并不像java会自动抛出像除以0这样的异常
 * 感觉这是C++比较麻烦的地方。但是因为语言没有处理底层的错误，提升了语言性能
 * 所以以后在写程序的过程中可以自己完成程序的异常捕获系统。
 * 
 */


int main()
{
    int a = 2,b = 0;
    try{
        
        if(a < 2){
            //这个是为了测试int类型异常
            throw 333;
        }
        if (b == 0)
        {
            throw "sssswwww";
        }
        a = a/b;
    }
    catch(const char *s){//捕获char *类型的异常
        cout<<s<<endl;
    }
    catch(const int a){
        cout<<a<<endl;
    }
    catch(...)//捕获任意异常
    {
        cout<<"sss"<<endl;
    }
}
//也可以自定义异常类，throw的时候抛出异常类即可。




