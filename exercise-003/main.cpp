#include "MyVector.hpp"
#include <fmt/format.h>
#include<iostream>    

MyVector::MyVector()
{
    data =nullptr;
    size_vec = 0;
    fmt::println("Vektor wurde erstellt mit Null Elementen");
}

/*MyVector::MyVector(unsigned int size)
{
    size_vec = size;
    for(int i= 0; i<size; i++)
    {
        data= new int;
        data++
    }
    for(int i = 0; i<size; i++)
    {
        data--;
    }
    fmt::println("Vektor wurde erstellt mit {} Elementen", size);
}*/

MyVector::~MyVector()
{
    for(int i = 0; i< size_vec; i++)
    {
        delete data;
        data++;
        
    }
    fmt::println("Der allokierte Speicher wurde freigegeben");
}

const int MyVector::size()
{
    fmt::println("Der Vektor hat die Größe {}", size_vec);
    return size_vec;
}

const int MyVector::at(int index)
{
    for(int i = 0; i<index; i++)
    {
        data++;
    }
    int data_idx = *data;
    
    for(int i = 0; i<index; i++)
    {
        data--;
    }
    fmt::print("An der Stelle {} ist der Wert {} gespeichert",index, data_idx);
    return data_idx;
}

void MyVector::pushback(unsigned int number)
{
    if(size_vec == 0)
    {
        data = new int;
        *data = number;
       //size_vec = size_vec+1;

    }
    if(size_vec != 0){
    for(int i = 0; i<size_vec+1; i++)
    {
        data++;
    }
    data = new int;
    *data = number;
    for(int i = 0; i<size_vec+1;i++)
    {
        data--;
    }
    }
    size_vec= size_vec+1;
}




auto main() ->int
{
    MyVector Vector1;
    Vector1.pushback(1);
    Vector1.size();
    Vector1.pushback(2);
    Vector1.pushback(3);
    Vector1.at(2);
    return 0;
}

