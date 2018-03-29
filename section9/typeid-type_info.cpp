#include<iostream>

using namespace std;

/**
 * typeid()返回type_info对象的引用。type_info重载了==和！=，可以很方便的比较
 * 百度的type_info类结构
 * class type_info {
 *   public:
 *     virtual ~type_info();
 *     bool operator== (const type_info& rhs) const;
 *     bool operator!= (const type_info& rhs) const;
 *     bool before (const type_info& rhs) const;
 *     const char* name() const;
 *   private:
 *     type_info (const type_info& rhs);
 *     type_info& operator= (const type_info& rhs);
 *  };
 * 
 */

class A{};
class B{};

int main()
{
    A a1,a2,*a3;
    B b1,b2;
    cout<<"typeid(a1):"<<typeid(a1).name()<<endl;
    cout << "typeid(a2):" << typeid(a2).name() << endl;
    cout << "typeid(a3):" << typeid(a3).name() << endl;
    cout << "typeid(b1):" << typeid(b1).name() << endl;
    cout << "typeid(b2):" << typeid(b2).name() << endl;
}




