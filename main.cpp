#include <iostream>
#include"AMVECTOR.h"
using namespace std;

int main()
{
    AMVector<int>arr1(5);
    arr1.push_back(1);
    arr1.push_back(2);
    arr1.push_back(3);
    arr1.push_back(4);
    arr1.push_back(5);
    cout<<arr1[0]<<endl;
    cout<<arr1.size()<<endl;
    cout<<arr1.capacity()<<endl;
    for (int i = 0; i <5 ; ++i)
    {
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    arr1.resize();
    cout<<arr1[0]<<endl;
    cout<<arr1.size()<<endl;
    cout<<arr1.capacity()<<endl;
    for (int i = 0; i <5 ; ++i)
    {
        cout<<arr1[i]<<" ";
    }
    cout<<endl;
    int* a=arr1.begin()+1;
    //int* x=arr1.begin()+2;
    /*int* y=arr1.erase(a,x);
    for (int i = 0; i <arr1.size() ; ++i) {
        cout<<*(y++);
    }*/
    int* x=arr1.begin()+2;
    arr1.insert(x,5);
    cout<<arr1[15];

}
