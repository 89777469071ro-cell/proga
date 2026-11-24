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
    class Proxy {
    private:
        DynamicArray& arr;
        int index;

    public:
        Proxy(DynamicArray& arr, int index) : arr(arr), index(index) {}

        Proxy& operator=(T value) {
            arr.set(index, value);
            return *this;
        }

        Proxy& operator=(const Proxy& other) {
            return *this = static_cast<T>(other);
        }

        operator T() const {
            return arr.get(index);
        }
    };

    Proxy operator[](int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Индекс вне границ массива");
        }

        return Proxy(*this, index);
    }

    T operator[](int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Индекс вне границ массива");
        }

        return data[index];
    }

    T* begin() {
        return data;
    }

    T* end() {
        return size == 0 ? data : data + size;
    }

    const T* begin() const {
        return data;
    }

    const T* end() const {
        return size == 0 ? data : data + size;
    }

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

    // Конструктор копирования
    DynamicArray(const DynamicArray& other) {
        size = other.size;
        data = new T[size];

        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    // Оператор копирующего присваивания
    DynamicArray& operator=(const DynamicArray& other) {
        if (this == &other) {
            return *this;
        }

        T* newData = new T[other.size];

        for (int i = 0; i < other.size; i++) {
            newData[i] = other.data[i];
        }

        delete[] data;

        data = newData;
        size = other.size;

        return *this;
    }

    // Конструктор перемещения
    DynamicArray(DynamicArray&& other) noexcept {
        data = other.data;
        size = other.size;

        other.data = nullptr;
        other.size = 0;
    }

    // Оператор перемещающего присваивания
    DynamicArray& operator=(DynamicArray&& other) noexcept {
        if (this != &other) {
            delete[] data;

            data = other.data;
            size = other.size;

            other.data = nullptr;
            other.size = 0;
        }

        return *this;
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

    bool operator==(const DynamicArray& other) const {
        if (size != other.size) {
            return false;
        }

        for (int i = 0; i < size; i++) {
            if (data[i] != other.data[i]) {
                return false;
            }
        }

        return true;
    }

    bool operator!=(const DynamicArray& other) const {
        return !(*this == other);
    }

    DynamicArray& operator+=(const DynamicArray& other) {
        for (int i = 0; i < size; i++) {
            T value = data[i];

            if (i < other.size) {
                value += other.data[i];
            }

            checkValue(value);
            data[i] = value;
        }

        return *this;
    }

    DynamicArray& operator-=(const DynamicArray& other) {
        for (int i = 0; i < size; i++) {
            T value = data[i];

            if (i < other.size) {
                value -= other.data[i];
            }

            checkValue(value);
            data[i] = value;
        }

        return *this;
    }

    DynamicArray& operator+=(T value) {
        for (int i = 0; i < size; i++) {
            T newValue = data[i] + value;

            checkValue(newValue);
            data[i] = newValue;
        }

        return *this;
    }

    DynamicArray& operator-=(T value) {
        for (int i = 0; i < size; i++) {
            T newValue = data[i] - value;

            checkValue(newValue);
            data[i] = newValue;
        }

        return *this;
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
