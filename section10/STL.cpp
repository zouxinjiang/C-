#include<iostream>
#include<vector>
#include<algorithm>   //包含一系列算法等操作
#include<cstdlib>
#include<ctime>

using namespace std;

/***
 * STL提供了许多容器，迭代器，函数对象和算法模板
 * 
 * 
 */

/**
 * vector 模板类
 * 存储方式为数组类型线性表，所以适合随机数据存取，
 * 不适合需要大量中间或头部数据删除的需求。
 * 
 */
void useVerctor()
{
    vector <int> arr(5);
    for(int i = 0;i < arr.size();i++){
        arr[i] = i;
    }
    arr.push_back(100);

    arr.insert(arr.begin()+2,200);
    // insert(start,pi,pj)   将其他数组类型线性表的[pi,pj]之间的元素插入到start之后

    arr.erase(arr.begin()+5);

    // erase(i,j)删除[i,j]区间的元素

    for(int i = 0;i<arr.size();i++){
        cout<<" "<<arr[i];
    }
    // 使用迭代器遍历。迭代器使用了智能指针auto_ptr
    vector<int>::iterator it;
    cout<<"\nuse iterator:"<<endl;
    for(it = arr.begin();it != arr.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;

    arr.clear();
    // for循环遍历
    cout<<"after clear "<<arr.size()<<" : "<<endl;
    for(int i = 0;i<arr.size();i++){
        cout<<" "<<arr[i];
    }
    
}
void print(int a)
{

    cout<<a<<"  ";
}
void assign(int &a)
{
    static int i = 0;
    a = i;
    i++;
}
struct MyObj
{
    string str;
    MyObj(){}
    bool operator<(const MyObj &obj2){
        return this->str < obj2.str;
    }
};

void useSTLfunc()
{
    vector<int> arr(10);
    
    for_each(arr.begin(),arr.end(),assign);

    for_each(arr.begin(),arr.end(),print);

    int a[] = {2,5,4,6,8,0,5,7,9,10};
    vector<int> arr1(a,a+sizeof(a)/sizeof(a[0]));
    // Sort(start,end,排序方法)
    // 如果是标准类型 int float string等，可以直接传入内置的仿函数 less<T>()  equal_to<T>()  not_equal_to<T>()  greater<T>() less_equal<T>() greater_equal<T>()
    // 默认传入的是less函数
    sort(arr1.begin(),arr1.end());

    // 排序后
    cout<<"\nafter sort:\n";
    for_each(arr1.begin(), arr1.end(), print);
    // 对自定义对象进行排序时，需要重载<运算符。如果没有重载需要将比较函数传入sort函数的第三个参数
    vector<MyObj> obj(10);
    vector<MyObj>::iterator it;
    srand((unsigned)time(NULL));

    cout<<"MyObj Sort:"<<endl;
    for(it = obj.begin();it < obj.end();it++){
        char tmp[20];
        itoa(rand()%100,tmp,10);
        it->str = string("str") + tmp;
    }
    cout<<endl<<"before sort:"<<endl;
    for (it = obj.begin(); it < obj.end(); it++)
    {
        cout << it->str<<" ";
    }
    cout<<endl;
    sort(obj.begin(),obj.end());
    cout << endl<< "after sort:" << endl;
    for (it = obj.begin(); it < obj.end(); it++)
    {
        cout << it->str << " ";
    }
    cout << endl;
    // find 函数
    // find(first, end, value); 返回值是迭代器(找到的第一个元素指针,如果没有找到，就返回的是容器end()的地址)。
    vector<int>::iterator  pos = find(arr1.begin(),arr1.end(),100);
    if(pos == arr1.end()){
        cout<<"not find 100"<<endl;
    }else{
        cout<<"find 100 :"<<*pos<<endl;
    }
    // find_if函数
    // find_if(first, end, bool pred); 第三个参数是返回bool类型的接收一个参数的函数或像sort函数重载了()运算符的对象

    // count函数  同上find，find_if
    // count（l.begin（），l.end（），value）
    // count_if（l.begin（），l.end()，pred）

    // search()函数
    // search算法函数在一个序列中搜索与另一序列匹配的子序列。参数分别为一个序列的开始位置，结束位置和另一个序列的开始，结束位置。
    // search(v1.begin(), v1.end(), v2.begin(), v2.end());

    // copy()函数
    // copy(v.begin(),v.end(),l.begin());将v中的元素复制到l中。
    // transform(v.begin(),v.end(),l.begin(),复制方式);也是复制，但是要按某种方案复制。

    // replace()
    // replace(v.begin(),v.end(),25,100);将元素范围中的25替换为100
    // replace_if(v.begin(),v.end(),bool pred,100);将满足pred规则的替换

    // 用于基本类型
    // fill(v.begin(),v.end(),value)  开始到结束填充value
    // fill_n(v.begin(),5,value)    从开始往后填5个value

    // 用于自定义类型
    // 同上面fill
    // generate(v.begin(),v.end(),func) func是一个无参返回容器指定类型的函数
    // generate_n(v.begin(),5,func)

    // remove_if(v.begin(),v.end(),bool pred);

    // unique(v.begin(),v.end()); 剔除【相邻】重复元素unique


}

struct Play{
    void operator() (int i){
        cout<<i<<" ";
    }
};
struct Play2{
    string str;
    Play2(string s):str(s){}
    void operator()(int i)
    {
        cout << str<< i << " ";
    }
};
void argFunc(int item,string front)
{
    cout<<front<<item<<endl;
}

void for_eachFunc()
{
    // 对象跟for_each搭配。对象需要重载()运算符。且参数只能有一个
    // 不传参数
    int a[] = {1,2,3,4,5,6};
    vector<int> arr(a,a+sizeof(a) / sizeof(a[0]));
    cout<<endl;
    for_each(arr.begin(),arr.end(),Play());
    // 传入参数
    cout<<endl;
    for_each(arr.begin(), arr.end(), Play2("content:"));

    // 函数跟for_each搭配。
    // 1：函数只有一个参数且和迭代器中参数类型一致，如useSTLfunc中的使用方式
    // 2：函数有对个参数
    cout<<endl;
    for_each(arr.begin(), arr.end(), bind2nd(ptr_fun(argFunc), "front"));
}


void useIterator(){
/****
 * 迭代器类型：输入迭代，输出迭代，正向迭代，双向迭代和随机迭代
 * STL中的算法对迭代器有要求，比如find函数就是使用了输入迭代器
 * template<class InputIterator,class T>
 * InputIterator find(InputIterator first, InputIterator last,const T& value)
 * sort函数则是要求使用随机迭代器。
 * 
 * 输入迭代器：将容器的内容视为迭代器的输入，对输入迭代器的解引用就能使程序获取到容器中的值
 * 需要输入迭代器的算法不会修改容器中的值，比如find。基于输入迭代器的任何算法都应该是单通行的
 * 不依赖前一次遍历的迭代器的值，也不依赖本次迭代前面迭代器的值。
 * 内部通过前++和后++实现容器遍历
 * 
 * 输出迭代器：将程序的输出通过解引用将值存入容器中。但是不能读取，只能写入。
 * 适用于单通行只写算法
 * 
 * 正向迭代器：只使用++操作符来遍历容器。和输入输出迭代器不同的是正向迭代器总是按照相同的顺序遍历一系列值
 * 将迭代器的值自增后，仍然可以对前面的迭代器解除引用，并可以得到相同的值。可用于多次通行算法，
 * 
 * 双向迭代器：双向迭代器拥有正向迭代器的所有特性，同时还支持++,--操作
 * 
 * 随机访问迭代器：具有双向迭代器的所有特性,同时添加了支持随机访问的操作和用于对元素进行排序的关系操作符等
 * 
 * vector<int>::iterator是随机迭代器
 * list<int>::iterator是双向迭代器
 * 
 * 内容复杂，暂时停滞以后再看
 * 
 * 
 * 
 */



}


int main()
{
    useVerctor();

    cout<<"STLfunc"<<endl;
    useSTLfunc();
    cout<<"\nfor_each:"<<endl;
    for_eachFunc();
    

}


