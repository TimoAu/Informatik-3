#include "MyVector.hpp"
#include <fmt/format.h>
#include<iostream>    

myVector::myVector()
{
    data = nullptr;
    size_vec = 0;
}

myVector::myVector(unsigned int lenght, int init[])
{
    data = new int[lenght];
    for(int i = 0; i<lenght; i++)
    {
        data[i] =init[i];
    }
    size_vec = lenght;
}
myVector::~myVector()
{
    delete[] data;
    fmt::println("allokierter Speicher wurde freigegeben");
}

const int myVector::at(unsigned int idx)
{
    return data[idx-1];
}

void myVector::pushback(int data)
{
    if(size_vec == 0)
    {
        this->data = new int[1];
        this->data[0] = data;
        size_vec = 1;
    }else
    {
        this->data = CreateNewArray(this->data);
        this->data[(size_vec)]= data;
        size_vec++;
    }
}
int *myVector::CreateNewArray(int *oldArray)
{
    int* newArray = new int[size_vec +1];
    for(int i = 0; i<size_vec; i++)
    {
        int buffer;
        buffer= oldArray[i];
        newArray[i]= buffer;
    }
    delete[] oldArray;
    return newArray;
}

auto main() ->int
{
    myVector Vector1;
    Vector1.pushback(10);
    Vector1.pushback(20);
    Vector1.pushback(30);
    fmt::println("Wert an Stelle 2 ist{}", Vector1.at(1));
    int testArray[3]= {1,2,3};
    myVector Vector2(3,testArray);
    Vector2.pushback(4);
    Vector2.pushback(5);
    for(int i = 1; i<6;i++){
    fmt::println("Wert an Stelle {} ist{}",i, Vector2.at(i));
    }
}
