#include <iostream>
#include <cmath> //数学函数库头文件

using namespace std;

/**
 * 自定义函数
 * 此处为声明和定义一起
 * 函数的结构为：
 * 返回值类型  函数名 (参数类型 形参名, ……){ 函数体;  return 返回值;}
 */
int fun1(int a)
{
    //code
    return 0;
};
/**
 * 此处为声明和定义分开，但是处于同一文件
 */
int fun2();

int main()
{

    fun1(222); //调用函数

    int a = sqrt(33); //调用cmath数学库里面的函数
    return 0;
};
int fun2()
{
    //code
    return 1;
};
/**
 * 自定义函数的调用和函数库中的函数调用方式一样
 * 函数名(参数……)
 */


/**
 * 函数参数
 * 参数可以是基本数据类型，也可以是复合数据类型，也可以是自定义类型
 */
//数组为参数
int sum_arr(int arr[],int len);
int sum_arr1(int *arr,int len);
//两种方式是等价的。但是数组方式更加明了，直接让用户知道传入数组。
//只有在函数的参数中 int arr[]和int* arr是等价的，其他情况不一样

//在函数内不能修改数组，就要用const限制
int sum_arr2(const int arr[],int len);
int sum_arr3(const int *arr,int len);

//const定义不能修改的值
const int a;
int const b;
//以上二者等价
const int *a;//*a不能变
int const *a;//*a不能变
int * const a;//a的内容不能变，所以这是一个常指针
/**
 * 如果数据类型本身并不是指针，则可以将const数据或非const数据的地址赋值给指向const的指针，但是只能将非const数据的地址赋值给非const的指针
 */
const int arr[4] = {1,2,3,4};//不能传递给下面这个函数
int sum_arr4(int arr[],int len);
/**
 * 传递二维数组
 * 必须确定其中一个维数
 */
int sum_arr5(int arr[][4],int len);
/**
 * 传递自定义结构的时候，方式就是将自定义类型当成基本类型即可
 */
struct Node{
    char a;
    int b;
};

struct Node myfun(struct Node node);
//可以使用之前说过的typedef关键字简化自定义类型的书写,那么函数就可以这样写
typedef struct Node mytype;
mytype myfun(mytype node);


/**
 * 函数指针
 * 返回类型 (*函数指针名)(形参列表)
 * 函数名其实就可以看成是函数指针，所以使用函数指针调用函数时  函数指针名(实参列表) 进行函数的调用. 也可以用 (*函数指针名)(实参列表) 调用函数
 */
//声明一个指向myfun的函数指针
mytype (*pfun)(mytype node);
//其实这个指针能指向所有返回值是mytype类型，参数为一个mytype类型的所有函数。

/**
 * 将引用作为参数.(引用就是别名)
 */
int sum(int &a,int &b);
//函数内部对a，b进行改变，那么外部的a,b也跟着改变。这有点像传地址，但是内部可以免去地址的解引用。
//按照严格意义来说，C中只有按值传递，指针也遵循按值传递。实参传递之后，都会在函数内部进行一次拷贝
//在后面学了对象后，传引用不会调用对象的副本构造函数。所以引用传递应该就不会发生拷贝生成副本



//返回函数指针的函数声明
pf()    //代表函数
* pf()  //代表返回指针的函数
(* pf()) () //代表返回 xx (*)()函数指针类型的函数指针
* (* pf()) () //代表返回 xx* (*)()函数指针类型的函数指针
//现在声明一个返回值为 int * (*p)(int,int)类型的函数指针，该如何声明
int *( *pf()) (int,int)
//拆解
typedef int *(*pfun)(int,int)
//变成
pfun pf();

//对经典的信号量函数进行拆解
void (*signal(int,void(*)(int)))(int)
typedef void(*callback)(int)
//变成
void (*signal(int ,callback))(int)
typedef void (*pfun)(int)
//变成
pfun signal(int ,callback)



