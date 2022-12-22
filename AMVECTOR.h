#ifndef AMVECTOR_H
#define AMVECTOR_H

/*
class AMVector
{

    public:
        AMVector();
        virtual ~AMVector();

    protected:

    private:


};
*/

#include <bits/stdc++.h>

using namespace std;

class invaliditerator
{
public:
    invaliditerator() {};
    const char* what()const throw()
    {
        return "invalid iterator";
    };
};

class OutofRang : public exception
{
public:
    void msg()
    {
        cout<<"out of range";
    }
};

template <class T>
class AMVector
{
private:
    T* arr;
    T* temp;
    int sizee;
    int capacityy;
public:
    using iterator=T*;
    AMVector(int cap = 2)
    {
        capacityy = cap;
        sizee = 0;
        arr = new T[capacityy];
    }
    AMVector(T* arr1, int n);
    AMVector(const AMVector& vector);
    AMVector &operator=(const AMVector& vector);
    AMVector &operator=(const AMVector&& vector);
    bool operator==(const AMVector<T>& vector);
    bool operator<(const AMVector<T>& arr1);
    void push_back(const T& item) ;
    T pop_back();
    void resize();
    void clear();
    int size() const;
    int capacity() const;
    iterator begin();
    iterator end();
    iterator erase(iterator it);
    iterator erase( iterator it1, iterator it2);
    void insert(iterator it,T value);
    bool empty();
    //funtion without main not avaliable i not handling this problem
    T & operator[](T x);
    // friend ostream& operator << (ostream& out, AMVector<T>);
};

template <class T>
AMVector<T>::AMVector(const AMVector& vector)
{
    sizee = vector.sizee;
    capacityy = vector.capacityy;
    arr = new T[capacityy];
    for(int i = 0; i < sizee; i++)
    {
        arr[i] = vector.arr[i];
    }
}

template <class T>
T & AMVector<T>:: operator[](T x)
{
    try
    {
        if (x>sizee)
        {
            OutofRang o;
            throw o;
        }
        else
        {
            return arr[x];
        }
    }
    catch (OutofRang & o)
    {
        o.msg();
        exit(0);
    }
}


template <class T>
AMVector<T>::AMVector(T* arr1, int n)
{
    arr = new T[n];
    sizee = n;
    capacityy = n;
    for(int i = 0; i < n; i++)
    {
        arr[i] = arr1[i];
    }
}
template <class T>
bool AMVector<T>::operator==(const AMVector<T>& arr1)
{
    if(sizee != arr1.sizee)
    {
        return false;
    }
    for(int i = 0; i < sizee; i++)
    {
        if(arr[i] != arr1.arr[i])
        {
            return false;
        }
    }
    return true;
}


template <class T>
bool AMVector<T>::operator<(const AMVector<T>& arr1)
{
    if(sizee < arr1.sizee)
    {
        return true;
    }
    for(int i = 0; i < sizee; i++)
    {
        if(arr[i] < arr1.arr[i])
        {
            return true;
        }
    }
    return false;
}


template <class T>
AMVector<T>& AMVector<T>::operator=(const AMVector& vector)
{
    if(this != &vector)
    {
        sizee = vector.sizee;
        capacityy = vector.capacityy;
        arr = new T[capacityy];
        for(int i = 0; i < sizee; i++)
        {
            arr[i] = vector.arr[i];
        }
    }
    return *this;
}

template <class T>
AMVector<T>& AMVector<T>::operator=(const AMVector<T>&& vector)
{
    if(this!=vector)
    {

        delete[] arr;
        arr=nullptr;
        sizee=vector.sizee;
        capacityy=vector.capacityy;
        arr=vector.arr;
        vector.sizee=0;
        vector.capacityy=0;
        vector.arr=nullptr;
        return *this;
    }

}

template <class T>
void AMVector<T>::push_back(const T& item)
{
    if (sizee == capacityy)
    {
        resize();
    }
    arr[sizee] = item;
    sizee++;
}
template <class T>
void AMVector<T>::resize()
{
    capacityy = capacityy * 2;
    temp = new T[capacityy];
    for(int i = 0; i < sizee; i++)
    {
        temp[i] = arr[i];
    }
    delete[] arr;
    arr = temp;
}
template <class T>
void AMVector<T>::clear()
{
    sizee = 0;
    capacityy = 0;
    delete[] arr;
}
template <class T>
int AMVector<T>::size() const
{
    return sizee;
}
template <class T>
int AMVector<T>::capacity() const
{
    return capacityy;
}
template <class T>
ostream& operator << (ostream& out, AMVector<T> vector)
{
    for(int i = 0; i < vector.sizee; i++)
    {
        out << vector.arr[i] << " ";
    }
    return out;
}
template <class T>
typename AMVector<T>::iterator AMVector<T>::erase(AMVector<T>::iterator it)
{

    if(it < 0 || it > sizee)
    {
        throw "Invalid iterator";
    }
    for(int i = it; i < sizee; i++)
    {
        arr[i] = arr[i+1];
    }
    sizee--;
}
template <class T>
typename AMVector<T>:: iterator AMVector<T>::erase(AMVector<T>::iterator it1, AMVector<T>::iterator it2)
{
    try
    {
        if(*it2 < *it1)
        {
            invaliditerator e;
            throw e;
        }
        else
        {

            int count=0;
            int x1;
            int x2;
            int counter=0;
            temp=new T[sizee];
            for(int i=0; i<sizee; i++)
            {
                if(arr[i]==*it1)
                {
                    x1=i;
                    break;
                }
            }


            for(int i=0; i<sizee; i++)
            {
                if(arr[i]==*it2)
                {
                    x2=i;
                    break;

                };
            }
            x2=x2-1;
            for(int j=0; j<x1; j++)
            {
                temp[counter]=arr[j];
                ++counter;

            }
            for(int j=x2+1; j<sizee; j++)
            {
                temp[counter]=arr[j];
                ++counter;
            }
            count=(x2)-(x1);
            sizee=sizee-count-1;
            for(int i=0; i<sizee; i++)
            {
                arr[i]=temp[i];
                //cout<<arr[i];
            }
            return arr;
        }
    }
    catch( invaliditerator& e)
    {
        cout<<e.what();

    }
}

template <class T>
typename AMVector<T>::iterator AMVector<T>::begin()
{
    return arr;
}

template <class T>
typename AMVector<T>::iterator AMVector<T>::end()
{
    return arr+sizee;
}

template <class T>
bool AMVector<T>::empty()
{
    if(sizee=0)
    {
        return true;
    }
    else
    {
        return false;
    }
}


template <class T>
void AMVector<T>::insert(AMVector<T>::iterator it,T value)
{
    temp=new T[sizee+1];

    int x=0;
    for(int i=0; i<sizee; i++)
    {
        if(arr[i]==*it)
        {
            x=i;

        }
    }
    x=x-1;
    sizee=sizee+1;
    for(int i=0; i<=x; i++)
    {
        temp[i]=arr[i];


    }
    temp[x+1]=value;
    for(int i=x+1; i<sizee; i++)
    {
        temp[i+1]=arr[i];
    }
    for(int i=0; i<sizee; i++)
    {
        arr[i]=temp[i];

    }



}



template <class T>
T AMVector<T>::pop_back()
{

    temp=new T[sizee];
    for(int i=0; i<sizee; i++)
    {
        temp[i]=arr[i];
    }
    sizee--;
    arr=new T[sizee];
    for(int i=0; i<sizee; i++)
    {
        arr[i]=temp[i];

    }
    return arr[sizee-1];
}







#endif // AMVECTOR_H
