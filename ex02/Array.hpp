#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>

class Array
{
    private:
        T *arry;
        unsigned int i;

    public:
        Array();
        Array(unsigned int n);
        Array(const Array &obj);
        Array &operator=(const Array &obj);
        ~Array();

        T &operator[](unsigned int index);
        unsigned int size() const;
        class FIALDINDEX : public std::exception
        {
            public:
                const char * what() const throw();
        };
};  

template <typename T>

Array<T>::Array() : arry(NULL), i(0)
{}

template <typename T>
Array<T>::Array(unsigned int n) : arry(new T[n]) , i(n)
{}
template <typename T>
Array<T>::Array(const Array &obj)
{
    arry = new T[obj.i];
    i = obj.i;
    for (unsigned int idx = 0; idx < i; idx++)
    {
        arry[idx] = obj.arry[idx];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &obj)
{
    delete[] arry;
    this->arry = new T[obj.i];
    this->i = obj.i;
    for (unsigned int idx = 0; idx < this->i ; idx++)
    {
        this->arry[idx] = obj.arry[idx];
    }
    return *this;
}

template <typename T>
Array<T>::~Array()
{
    delete[] arry;
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= i)
        throw (Array<T>::FIALDINDEX());
    else
        return (arry[index]);

}


template <typename T>
const char * Array<T>::FIALDINDEX::what() const throw()
{
    return("index is out of bounds");
}

template <typename T>

unsigned int Array<T>::size() const 
{
    return i;
}
#endif