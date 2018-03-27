#include<iostream>

using namespace std;

class A
{
    public:
    A(){
        bootstrap();
    }
    void bootstrap(){
        cout<<"调用bootstrap"<<endl;
    }

};

A a;
int main()
{
    cout<<"调用main"<<endl;

}