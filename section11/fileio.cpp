#include<iostream>
#include<fstream>

using namespace std;

int main()
{
    ofstream fout;
    fout.open("test.txt");
    fout<<"write to file!!!"<<endl;


    return 0;
}

