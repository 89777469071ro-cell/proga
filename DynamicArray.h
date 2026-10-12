#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>
#include <stdexcept>
#include <type_traits>
#include <cmath>
#include <typeinfo>

template <typename T>
class DynamicArray {
private:
    T* data;
    int size;

    void checkValue(T value) {
        if constexpr (std::is_integral_v<T>) {
            if (value > 100 || value < -100) {
                throw std::invalid_argument("Значение должно быть от -100 до 100");
            }
        }
    }

public:
    DynamicArray(int size) {
        if (size < 0) {
            throw std::invalid_argument("Размер массива не может быть отрицательным");
        }

        this->size = size;
        data = new T[size];

        for (int i = 0; i < size; i++) {
            data[i] = T{};
        }
    }

    ~DynamicArray() {
        delete[] data;
    }

    DynamicArray(const DynamicArray& other) {
        size = other.size;
        data = new T[size];

        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    void set(int index, T value) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Индекс вне границ массива");
        }

        checkValue(value);
        data[index] = value;
    }

    T get(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Индекс вне границ массива");
        }

        return data[index];
    }

    void print() {
        for (int i = 0; i < size; i++) {
            std::cout << data[i] << " ";
        }

        std::cout << std::endl;
    }

    void addValue(T value) {
        checkValue(value);

        T* newData = new T[size + 1];

        for (int i = 0; i < size; i++) {
            newData[i] = data[i];
        }

        newData[size] = value;

        delete[] data;
        data = newData;
        size++;
    }

    void add(const DynamicArray& other) {
        for (int i = 0; i < size && i < other.size; i++) {
            data[i] += other.data[i];
        }
    }

    void subtract(const DynamicArray& other) {
        for (int i = 0; i < size && i < other.size; i++) {
            data[i] -= other.data[i];
        }
    }

    double distance(const DynamicArray& other) {
        if constexpr (!std::is_arithmetic_v<T>) {
            throw std::bad_typeid();
        }
        else {
            if (size != other.size) {
                throw std::invalid_argument("Размеры массивов должны совпадать");
            }

            double sum = 0;

            for (int i = 0; i < size; i++) {
                double diff = static_cast<double>(data[i]) -
                              static_cast<double>(other.data[i]);
                sum += diff * diff;
            }

            return std::sqrt(sum);
        }
    }

    friend std::ostream& operator<<(std::ostream& out, const DynamicArray& arr) {
        for (int i = 0; i < arr.size; i++) {
            out << arr.data[i] << " ";
        }

        return out;
    }
};

#endif
