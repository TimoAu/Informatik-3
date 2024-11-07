#include "MyVector.hpp"
#include <fmt/format.h>
#include <iostream>

myVector::myVector() {
    data = new int[10];
    size_vec = 10;
    filled_spaces = 0;
    count_expansions = 0;
} 

myVector::myVector(unsigned int length, int init[]) {
    data = new int[10];
    for (unsigned int i = 0; i < length && i < 10; i++) {
    data[i] = init[i];
    }
    size_vec = 10;
    filled_spaces = length;
    count_expansions = 0;
}

myVector::~myVector() {
    delete[] data;
    fmt::println("Allocated memory has been released");
}

const int myVector::at(unsigned int idx) {
    if (idx < filled_spaces) {  // Check for bounds
        return data[idx];
    }
    fmt::println("Index out of bounds");
    return -1;  // Return an error code or throw an exception
}

void myVector::pushback(int value) {
    if (filled_spaces < size_vec) {  // Space is available
        data[filled_spaces] = value;
        filled_spaces++;
    } else {  // Need to expand array
        data = CreateNewArray(data);
        data[filled_spaces] = value;
        filled_spaces++;
        size_vec += 10;  // Increase capacity
        count_expansions++;
    }
}

int* myVector::CreateNewArray(int* oldArray) {
    int* newArray = new int[size_vec + 10];
    for (int i = 0; i < size_vec; i++) {
        newArray[i] = oldArray[i];
    }
    delete[] oldArray;
    return newArray;
}

auto main() -> int {
    myVector Vector1;
    for (int i = 0; i < 15; i++) {  // Push more than initial capacity to test expansion
        Vector1.pushback(i);
    }

    for (int i = 0; i < Vector1.filled_spaces; i++) {
        fmt::println("The vector contains element at index {}: {}", i, Vector1.at(i));
    }
}
