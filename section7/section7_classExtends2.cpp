/**
 * C++类
 * 
 * 
 */

//小插曲  valarray模板类提供了变长数组
//头文件
#include<valarray>
//声明定义变量
valarray<int> arr;
valarray<double> darr;
//使用构造函数声明
valarray<int> v2(8);//初始8个长度的数组
valarray<int> v3(8,10);//初始8个长度的数组并用10将每个元素初始化
//可以用下标形式访问  v2[0];
//size   元素个数、
//sum   所有元素总和
//max   所有元素中最大值
//min   所有元素中最小值


/***
 * C++的限制
 * 可以使用 explicit 关键字防止单参数构造函数隐式转换
 * 使用const限制方法修改数据 
 */
class A{
private:
    int a;
    int b;
    string str;
    A(int a,int b,string c):a(a),b(b),str(c){ }
    A(int a,string c,int b){
        this->a = a;//为了让编译器区分是成员a还是参数a，需要用this指针说明是成员变量a
        this->b = b;
        this->str = c;//或者str=c //这里能够区分是成员变量str还是参数c，所以可以不用this指针
    }
};

/**
 * 构造函数
 * 初始化列表的形式
 * A(……):x(x),y(y),z(z)……{}  【类的常数据成员只能通过初始化列表初始化，类的静态常数据成员可以通过在类外进行初始化】
 * 普通函数形式就和函数一样，只是要注意让编译器能够区分是成员变量还是函数参数
 * 多个项目时初始化顺序跟变量的声明顺序一致。如果一个成员的初始化依赖另一个成员，那么这个声明顺序就特别重要了
 */


/**
 * 三种继承方式 :  public  protected private
 * 继承方式将影响从父类继承过来的成员的访问方式
 * public继承方式不改变基类成员的访问方式
 * protected继承方式将基类public成员继承为protected。也就是到了本类就成了本类的protected成员
 * private继承方式将基类的public和protected成员变成本类的private成员
 * 遵循尽可能保持最大访问权限原则
 */

/**
 * 继承就相当于将基类的成员拷贝到本类
 * 使用就当成自己的成员函数即可
 * 友元函数不是类的成员函数，所以继承并不能将友元函数继承，要想使用父类的友元函数，就要将本类强制转换为基类然后就能匹配到基类的友元函数了 
 * 原因：1，私有继承的类的引用或指针在不显示强制转换的情况下是不会装换为基类指针或引用的(私有继承改变了从基类继承过来的成员访问权限)
 *      2，类有可能继承多个基类，那么基类中可能都有相似的友元函数，如果不转换就不知道该使用哪个友元函数了。
 */

/***
 * C++提供多继承，一个类可以继承自多个基类。
 * 由于这种特性，导致了一些问题。
 * 首先就是由于多继承可能导致类的原始基类是同一个，导致子类中有多个原始基类的成员拷贝
 * 解决方法就是将原始基类的方法声明为虚函数，这样就只会让子类只有一份原始基类的成员拷贝。
 * 
 * 
 */





