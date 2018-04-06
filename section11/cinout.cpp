#include<iostream>
#include<iomanip>
#include<exception>


using namespace std;

int main()
{
/**
 * cout格式化
 * hex  16进制
 * dec  10进制
 * oct  8进制
 */

    cout<<hex<<10<<endl<<dec<<10<<endl<<oct<<10<<endl;
    // 设置显示的宽度  width(int)成员函数
    cout.width(12);//只生效一次
    cout<<12<<13<<14<<15<<endl;

    cout.fill('*');//设置填充字符，一直有效
    cout.width(5);
    cout<<12<<endl;

    cout.precision(2);//设置精度，一直有效。（此版本的g++解释为总位数，而不是小数点后多少位）
    cout<<1.23<<endl;

    cout.setf(ios_base::showpoint);//将末尾的0也显示出来
    // setf参数可以位与。参数有boolalpha(将bool型输出为字符串true，false)
    // showbase (显示基数)
    // uppercase(16进制大写字母表示)
    // showpos  在正数前显示+
    // 

    cout.precision(10);
    cout << 1.23 << endl;
    // 以上都是要通过cout对象设置格式。
    // 为了简化操作，在ipmanip头文件中将这些成员函数变成了控制符（我觉得应该是写成了友元函数）
    // setprecision(),setfill(),setw()

    cout<<setfill('|')<<setw(20)<<10.2<<setprecision(10)<<endl;

    
    int a;
    cin>>a;
    // a是int型的。如果输入的是12abc,那么12将被赋予变量a。后面的abc将依然在输入缓冲区内
    cout<<dec<<a;
    // 输入流的一些状态：
    // eofbit   到达文件尾被置位   badbit   流被破坏被置位  
    // failbit     输入操作未能读取预期字符或输出操作未能写入预期字符时置位     goodbit     
    //  上面这些成员变量通常使用相应的成员函数来获取。
    // good()   eof()   bad()   fail()  rdstate()返回流的状态

    cout << "==================================" << endl;

    cin.exceptions(ios_base::failbit);
    int sum = 0;
    int input;
    try{
        while(cin>>input){ //死循环
            sum += input;
            cin.exceptions(ios_base::failbit);
            cout<<"wwww"<<endl;
        }
    }catch(...){
        cout<< "O the error!" <<endl;
    }
    cout<<"the sum is :"<<sum<<endl;

    return 0;
}






