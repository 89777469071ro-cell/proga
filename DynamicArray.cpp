#include <iostream>
#include <stdexcept>
#include "DynamicArray.h"

using namespace std;

DynamicArray::DynamicArray(int size) {
    if (size < 0) {
        throw invalid_argument("Размер массива не может быть отрицательным");
    }

    this->size = size;
    data = new int[size];

    for (int i = 0; i < size; i++) {
        data[i] = 0;
    }
}

DynamicArray::~DynamicArray() {
    delete[] data;
}

void DynamicArray::set(int index, int value) {
    if (index < 0 || index >= size) {
        throw out_of_range("Индекс вне границ массива");
    }

    if (value < -100 || value > 100) {
        throw invalid_argument("Значение должно быть от -100 до 100");
    }

    data[index] = value;
}

int DynamicArray::get(int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Индекс вне границ массива");
    }

    return data[index];
}

void DynamicArray::print() {
    for (int i = 0; i < size; i++) {
        cout << data[i] << " ";
    }

    cout << endl;
}

DynamicArray::DynamicArray(const DynamicArray& other) {
    size = other.size;
    data = new int[size];

    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

void DynamicArray::addValue(int value) {
    if (value < -100 || value > 100) {
        throw invalid_argument("Значение должно быть от -100 до 100");
    }

    int* newData = new int[size + 1];

    for (int i = 0; i < size; i++) {
        newData[i] = data[i];
    }

    newData[size] = value;

    delete[] data;

    data = newData;
    size++;
}

void DynamicArray::add(const DynamicArray& other) {
    for (int i = 0; i < size; i++) {
        if (i < other.size) {
            data[i] += other.data[i];
        }
    }
}

void DynamicArray::subtract(const DynamicArray& other) {
    for (int i = 0; i < size; i++) {
        if (i < other.size) {
            data[i] -= other.data[i];
        }
    }
}
