#include <iostream>
#include <new>
#include <stdexcept>
#include "DynamicArray.h"

using namespace std;

int main() {
    DynamicArray arr(5);

    arr.set(0, 10);
    arr.set(1, -20);
    arr.set(2, 50);
    arr.set(3, 100);
    arr.set(4, -100);

    cout << "Массив: ";
    arr.print();

    cout << "Элемент с индексом 2: " << arr.get(2) << endl;

    DynamicArray copy(arr);

    cout << "Копия массива: ";
    copy.print();

    arr.addValue(30);

    cout << "Массив после добавления: ";
    arr.print();

    DynamicArray arrA(4);
    DynamicArray arrB(3);

    arrA.set(0, 10);
    arrA.set(1, 20);
    arrA.set(2, 30);
    arrA.set(3, 40);

    arrB.set(0, 1);
    arrB.set(1, 2);
    arrB.set(2, 3);

    cout << "Массив A: ";
    arrA.print();

    cout << "Массив B: ";
    arrB.print();

    arrA.add(arrB);

    cout << "A после сложения: ";
    arrA.print();

    arrA.subtract(arrB);

    cout << "A после вычитания: ";
    arrA.print();

    cout << endl << "Проверка исключений:" << endl;

    try {
        arr.get(10);
    }
    catch (const out_of_range& e) {
        cout << "out_of_range: " << e.what() << endl;
    }

    try {
        arr.set(0, 150);
    }
    catch (const invalid_argument& e) {
        cout << "invalid_argument: " << e.what() << endl;
    }

    try {
        // Демонстрация перехвата bad_alloc
        throw bad_alloc();
    }
    catch (const bad_alloc& e) {
        cout << "bad_alloc: не удалось выделить память" << endl;
    }

    return 0;
}
