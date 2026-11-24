
#include <iostream>
#include <string>
#include <utility>
#include "DynamicArray.h"

using namespace std;

int main() {
    cout << "Проверка конструктора копирования:" << endl;

    DynamicArray<int> arr1(3);
    arr1.set(0, 10);
    arr1.set(1, 20);
    arr1.set(2, 30);

    DynamicArray<int> arr2(arr1);

    cout << "Исходный массив: " << arr1 << endl;
    cout << "Скопированный массив: " << arr2 << endl;

    arr2[0] = 50;

    cout << "После изменения копии: " << endl;
    cout << "Исходный массив: " << arr1 << endl;
    cout << "Скопированный массив: " << arr2 << endl;


    cout << "\nПроверка копирующего присваивания:" << endl;

    DynamicArray<int> arr3(2);
    arr3.set(0, 5);
    arr3.set(1, 15);

    arr3 = arr1;

    cout << "После присваивания: " << arr3 << endl;

    arr3[0] = 99;

    cout << "После изменения копии: " << arr3 << endl;
    cout << "Исходный массив: " << arr1 << endl;


    cout << "\nПроверка присваивания самому себе:" << endl;

    arr1 = arr1;

    cout << "Массив после присваивания самому себе: " << arr1 << endl;


    cout << "\nПроверка конструктора перемещения:" << endl;

    DynamicArray<int> arr4(3);
    arr4.set(0, 1);
    arr4.set(1, 2);
    arr4.set(2, 3);

    cout << "Исходный массив: " << arr4 << endl;

    DynamicArray<int> arr5(std::move(arr4));

    cout << "Новый массив: " << arr5 << endl;
    cout << "Исходный массив после перемещения: " << arr4 << endl;


    cout << "\nПроверка перемещающего присваивания:" << endl;

    DynamicArray<int> arr6(2);
    arr6.set(0, 7);
    arr6.set(1, 8);

    DynamicArray<int> arr7(3);
    arr7.set(0, 100);
    arr7.set(1, 90);
    arr7.set(2, 80);

    arr6 = std::move(arr7);

    cout << "Массив после перемещения: " << arr6 << endl;
    cout << "Исходный массив после перемещения: " << arr7 << endl;


    cout << "\nПроверка перемещения самого себя:" << endl;

    arr6 = std::move(arr6);

    cout << "Массив после перемещения самому себе: " << arr6 << endl;


    cout << "\nПроверка работы после перемещения:" << endl;

    arr7.addValue(25);

    cout << "Массив после добавления элемента: " << arr7 << endl;

    return 0;
}
