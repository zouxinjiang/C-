#include<stdio.h>

int main()
{
#if defined(__WIN32__) || defined(WIN32)
    printf("windows\n");
#endif

#if __cplusplus
    printf("c++\n");
#endif

// 下面代码采用C编译器编译
#if __cplusplus
extern "C" {
#endif

// 结束掉C编译的代码
#if __cplusplus
}
#endif

return 0;
}



