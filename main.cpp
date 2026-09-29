#include <iostream>
#include "DynamicArray.h"

using namespace std;

int main() {
    DynamicArray arr(5);

    arr.set(0, 10);
    arr.set(1, -20);
    arr.set(2, 50);
    arr.set(3, 100);
    arr.set(4, -100);

    arr.print();

    cout << "Элемент с индексом 2: " << arr.get(2) << endl;

    arr.set(10, 50);
    arr.set(1, 150);

    DynamicArray copy(arr);

    cout << "Копия массива: ";
    copy.print();

    arr.addValue(30);

    cout << "Массив после добавления: ";
    arr.print();

    arr.addValue(150);

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

    return 0;
}