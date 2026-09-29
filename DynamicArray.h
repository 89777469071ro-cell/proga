#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

class DynamicArray {
private:
    int* data;
    int size;

public:
    DynamicArray(int size);
    ~DynamicArray();

    DynamicArray(const DynamicArray& other);

    void set(int index, int value);
    int get(int index);
    void print();
    void addValue(int value);

    void add(const DynamicArray& other);
    void subtract(const DynamicArray& other);
};

#endif