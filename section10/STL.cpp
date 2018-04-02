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
    // Sort(start,end,,排序方法)
    sort(arr1.begin(),arr1.end());
    // 排序后
    cout<<"\nafter sort:\n";
    for_each(arr1.begin(), arr1.end(), print);
    // 对自定义对象进行排序时，需要重载<运算符
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

int main()
{
 useVerctor();

 cout<<"STLfunc"<<endl;
 useSTLfunc();
cout<<"\nfor_each:"<<endl;
 for_eachFunc();
}


