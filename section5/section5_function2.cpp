/**
 * 函数续
 * 默认参数，重载
 */

//含有默认参数时，在函数的声明和定义的时候，两者中只有将其中一个带有默认参数
//默认参数只能在参数列表中非默认参数的后面
int sum(int a,int b = 3);
//错误
int sum(int a, int b = 3)
{
    return a+b;
}
//正确
int sum(int a, int b)
{
    return a + b;
}
/*********************************************************************/
//或者
int sum1(int a, int b);

int sum1(int a, int b = 3)
{
    return a + b;
}
int main()
{
    //调用时可以传递两个参数，也可以传递一个参数
    sum1(1);//4
    sum1(1,2);//3
    return 0;
}
/**
 * 函数重载
 * 区分不同函数的是函数的参数列表，也叫做函数特征标或函数签名。
 * 参数列表的参数个数，参数类型，参数顺序都决定函数签名。函数返回值和函数形参名不参与函数签名。
 * 引用不会影响函数签名
 * 函数的默认参数，可能会影响函数的调用
 * const会影响函数签名
 */
//下面的就三个就具有相同的函数签名   fun(int,int)
// int fun(int a,int b);
// int fun(int b,int a);
// float fun(int a,int b);


//函数重载
int afun(int,int);
int afun(int);
int afun(int,float);
int afun(float,int);
int afun(float,float);
//带有默认参数
int bfun(int a,int b=3);
int bfun(int a);

// bfun(4);//当这样调用时,就不知道该使用上面哪个函数了。所以要避免这样的重载

/**
 * 函数模版
 * template<class/typename 名称,……> 
 * template<class/typename 名称=类型,……>  给模版传入默认类型
 * 
 * 
 * ？？？函数template定义后是否后面只能跟函数的定义声明
 */
template<class A=int,class B>
A tfun(A a,B b);

/**
 * 模版函数也可以重载，重载条件也是要拥有不同的函数签名
 * 函数模版并不是函数，只是一种生成函数的方案，当发现有函数调用不存在函数原型时
 * 编译器就调用函数模版，生成相应的函数实例。 由编译器生成实例的称为隐式实例化
 * 也可以显式实例化模版函数
 * template <>  返回值类型 模版名称<具体类型名称> (形参列表)
 * 
 * 编译器在调用函数时优先级：
 * 非模版函数 > 模版函数
 * 
 */




