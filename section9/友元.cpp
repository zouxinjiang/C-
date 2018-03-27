#include<iostream>

using namespace std;

/**
 * 友元分为友元函数，友元成员函数，友元类
 * 
 * 
 */

class A;
class B;

class B
{
  public:
    void changePriB(A &a, int b);
    void changeProB(A &a, int b);
};

class A
{
    private:
        int pri_a;
        int pri_b;
        //友元类
        friend class B;
    protected:
        int pro_a;
        int pro_b;
    public:
        A()
        {
            pri_a = 0;
            pri_b = 0;
            pro_a = 0;
            pro_b = 0;
        }
        void display()
        {
            cout<<"pri_a:"<<pri_a<<",pri_b:"<<pri_b<<endl<<"pro_a:"<<pro_a<<" ,pro_b:"<<pro_b<<endl;
        }
        //友元函数
        friend void changePriA(A &obj,int a);
        //友元成员函数
        friend void B::changePriB(A &a,int b); 

};

void B::changePriB(A &a, int b)
{
    a.pri_b = b;
}

void B::changeProB(A &a, int b){
    a.pro_b = b;
}

//作为了类的友元函数
void changePriA(A &obj, int a)
{
    obj.pri_a = a;
}

int main()
{
    A a;
    changePriA(a,234);
    B b;
    b.changePriB(a,555);

    b.changeProB(a,9999);
    a.display();

}


