#ifndef MY_VECTOR_HPP
#define MY_VECTOR_HPP
class MyVector
{
    public:
    MyVector();
    //MyVector(unsigned int size);
    ~MyVector();
    
    const int size();
    const int at(int index);
    void pushback(unsigned int number);
    
    unsigned int size_vec;
    private:
    int* data;

};

#endif