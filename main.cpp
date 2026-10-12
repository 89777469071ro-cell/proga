#include <iostream>
#include <string>
#include <stdexcept>
#include <typeinfo>
#include "DynamicArray.h"

using namespace std;

int main() {
    DynamicArray<int> arr(3);

    arr.set(0, 10);
    arr.set(1, 20);
    arr.set(2, 30);

    cout << "Целочисленный массив: " << arr << endl;

    DynamicArray<int> arr2(3);

    arr2.set(0, 10);
    arr2.set(1, 25);
    arr2.set(2, 35);

    cout << "Второй массив: " << arr2 << endl;
    cout << "Расстояние между массивами: " << arr.distance(arr2) << endl;

    DynamicArray<string> words(2);

    words.set(0, "Привет");
    words.set(1, "мир");

    cout << "Строковый массив: " << words << endl;

    cout << endl << "Проверка исключений:" << endl;

    try {
        words.distance(words);
    }
    catch (const bad_typeid& e) {
        cout << "bad_typeid: расстояние доступно только для числовых типов" << endl;
    }

    try {
        arr.set(0, 150);
    }
    catch (const invalid_argument& e) {
        cout << "invalid_argument: " << e.what() << endl;
    }

    try {
        arr.get(10);
    }
    catch (const out_of_range& e) {
        cout << "out_of_range: " << e.what() << endl;
    }

    try {
        DynamicArray<int> arr3(2);
        arr.distance(arr3);
    }
    catch (const invalid_argument& e) {
        cout << "invalid_argument: " << e.what() << endl;
    }

    return 0;
}