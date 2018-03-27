/**
 * 动态内存分配
 * 分配用malloc，new
 * 释放用free，delete
 * 但是要记得配套使用。malloc分配的就要用free释放，new分配的要用delete释放
 */
#include<iostream>

using namespace std;

int main(){
    int *a,*b,*c;
    a = (int *)malloc(sizeof(int)*10);
    b = new int[10];
    c = new int;
    free(a);
    delete [] b;//释放数组
    delete c;//释放变量

}


