/**
 * 结构体
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
    /**
     * 结构体类型
     * struct 类型名称 {类型 名称,……};
     */
    struct Node{
        char a,
        int b,
        string c;
        struct Node * next;//含有自身类型的指针，一般用于链表等之类的链式结构
    };

    struct Node var;//定义一个结构体类型的变量
    var.a = 0;//访问成员
    //后面的使用就基本可以将这个结构体类型当成基本数据类型的使用方法使用了

    /**
     * 共用体类型
     * union 类型名称 {类型 名称,……};
     */
    union uNode{
        char a,
        int b,
        float c;
    };
    //使用方式和结构体差不多，但是里面的所有成员只占据同一个内存空间，也就是说某一时刻，只有一个成员有效
    /**
     * 枚举类型
     * enum 类型名称 {名称,名称=（int）值,……};
     */
    enum eNode{
        red,
        blue,
        black=9,
        pink
    };
    //枚举默认从0开始，也就是所red=0，blue=1，由于black赋值为9，所以pink=10
    //枚举里面的类型都只能是整形





    return 0;
}
