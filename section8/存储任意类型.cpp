#include<iostream>
#include"memwatch.h"

using namespace std;

#define MAX_NUM  10

union Data {
    char chr;
    unsigned char uchr;
    short sht;
    unsigned short usht;
    int itr;
    unsigned int uitr;
    long lng;
    unsigned ulng;
    long long lng2;
    unsigned long long ulng2;
    float flt;
    double dbl;
    int *any;
};
struct Node{
    unsigned int type;
    Data data;
};

class Stack
{
    public:
    int len;
    Node stack[MAX_NUM];
    Stack()
    {
        len = 0;
    }
    void push(char chr){
        stack[len].type = 1;
        stack[len].data.chr = chr;
        len++;
    }
    void push(unsigned char chr)
    {
        stack[len].type = 2;
        stack[len].data.uchr = chr;
        len++;
    }
    void push(short chr)
    {
        stack[len].type = 3;
        stack[len].data.sht = chr;
        len++;
    }
    void push(unsigned short chr)
    {
        stack[len].type = 4;
        stack[len].data.usht = chr;
        len++;
    }
    void push(int chr)
    {
        stack[len].type = 5;
        stack[len].data.itr = chr;
        len++;
    }
    void push(unsigned int chr)
    {
        stack[len].type = 6;
        stack[len].data.uitr = chr;
        len++;
    }
    void push(long chr)
    {
        stack[len].type = 7;
        stack[len].data.lng = chr;
        len++;
    }
    void push(unsigned long chr)
    {
        stack[len].type = 8;
        stack[len].data.ulng = chr;
        len++;
    }
    void push(long long chr)
    {
        stack[len].type = 9;
        stack[len].data.lng2 = chr;
        len++;
    }
    void push(unsigned long long chr)
    {
        stack[len].type = 10;
        stack[len].data.ulng2 = chr;
        len++;
    }
    void push(float chr)
    {
        stack[len].type = 11;
        stack[len].data.flt = chr;
        len++;
    }
    void push(double chr)
    {
        stack[len].type = 12;
        stack[len].data.dbl = chr;
        len++;
    }
    void push(void * chr)
    {
        stack[len].type = 13;
        stack[len].data.any = (int *)chr;
        len++;
    }

    void *pop()
    {

        Data *tmp = (Data *)malloc(sizeof(Data));
        *tmp = stack[len-1].data;
        if (stack[len-1].type < 13)
        {
            cout<<"return node"<<endl;
            len--;
            return tmp;
        }
        else
        {
            cout << "return node.any" << endl;
            len--;
            int * x = tmp->any;
            free(tmp);
            return x;
        }
    }

    void display()
    {
        cout << "len" << len << endl;
        for (int i = 0; i < len; i++)
        {
            cout << stack[i].data.lng << endl;
        }
    }

};

class A
{
    public:
        int a;
        ~A(){
            cout<<"disconstructor"<<endl;
        }
};

int main()
{
    char *str = "ccccc";
    A *a = new A();
    a->a = 100;
    printf("%ld\n",str);
    Stack q;
    q.push(1);
    
    q.push(4L);
    q.push(str);
    q.push(a);
    q.display();
    A * res = (A *)q.pop();
    char * xxx = (char *)q.pop();
    int * it = (int *)q.pop();
    
    cout<<res->a<<"     "<<xxx<<"       "<<*it<<endl;
    delete res;
    free(it);

}
