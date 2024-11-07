#ifndef MY_VECTOR_HPP
#define MY_VECTOR_HPP
class myVector
{
    public:
    myVector();
    myVector(unsigned int lenght, int init[]);
    ~myVector();
    const int at(unsigned int idx);
    void pushback(int data);
    const int size();
    unsigned int filled_spaces;
    private:
    int *data;
    int size_vec;
    int count_expansions;
    int* CreateNewArray(int *oldArray);
};
#endif