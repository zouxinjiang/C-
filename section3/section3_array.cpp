#include<iostream>
using namespace std;
/**
 * 数组声明，数组的使用
 * 类型 数组名[数字];声明一个“数字”大小的数组
 * 使用方法1： 数组名[下标值]
 * 方法2：数组名+下标值
 * C/C++默认是以0为开始下标
 */
int main()
{

    int arr[10];

    arr[0] = 1;

    arr+1 = 2;
    //遍历
    for(int i = 0;i < 10;i++){
        arr[i] = i;
    }

    //列表赋值法
    int b[3] = {1,2,3};
    char c[3] = {'a','b','\0'};


    return 0;
}