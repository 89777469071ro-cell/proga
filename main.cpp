#include <iostream>
#include <string>
#include "DynamicArray.h"

using namespace std;

int main() {
    try {
        DynamicArray<int> arr(3);
        arr.set(0, 10);
        arr.set(1, 20);
        arr.set(2, 30);

        DynamicArray<int> arr2(3);
        arr2.set(0, 10);
        arr2.set(1, 25);
        arr2.set(2, 35);

        cout << "Целочисленный массив: " << arr << endl;
        cout << "Второй массив: " << arr2 << endl;
        cout << "Расстояние между массивами: " << arr.distance(arr2) << endl;

        DynamicArray<string> words(2);
        words.set(0, "Привет");
        words.set(1, "мир");

        cout << "Строковый массив: " << words << endl;

        cout << "\nПроверка исключений:" << endl;

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

        cout << "\nПроверка operator[]:" << endl;

        arr[0] = 50;
        cout << "Элемент с индексом 0: " << arr[0] << endl;

        arr[1] = arr[2];
        cout << "После копирования элемента: " << arr << endl;

        try {
            arr[0] = 150;
        }
        catch (const invalid_argument& e) {
            cout << "invalid_argument: " << e.what() << endl;
        }

        try {
            arr[10] = 5;
        }
        catch (const out_of_range& e) {
            cout << "out_of_range: " << e.what() << endl;
        }

        cout << "\nПроверка операторов сравнения:" << endl;

        if (arr == arr2) {
            cout << "Массивы равны" << endl;
        }
        else {
            cout << "Массивы не равны" << endl;
        }

        if (arr != arr2) {
            cout << "Массивы различаются" << endl;
        }
        else {
            cout << "Массивы одинаковые" << endl;
        }

        cout << "\nПроверка арифметических операторов:" << endl;

        DynamicArray<int> numbers1(3);
        numbers1.set(0, 10);
        numbers1.set(1, 20);
        numbers1.set(2, 30);

        DynamicArray<int> numbers2(3);
        numbers2.set(0, 5);
        numbers2.set(1, 10);
        numbers2.set(2, 0);

        numbers1 += numbers2;
        cout << "После сложения массивов: " << numbers1 << endl;

        numbers1 -= numbers2;
        cout << "После вычитания массивов: " << numbers1 << endl;

        numbers1 += 5;
        cout << "После прибавления числа: " << numbers1 << endl;

        numbers1 -= 5;
        cout << "После вычитания числа: " << numbers1 << endl;

        cout << "\nПроверка итераторов:" << endl;

        cout << "Перебор массива: ";
        for (int value : numbers1) {
            cout << value << " ";
        }
        cout << endl;

        for (int& value : numbers1) {
            value += 1;
        }

        cout << "После изменения элементов: " << numbers1 << endl;

        const DynamicArray<int>& constNumbers = numbers1;

        cout << "Перебор константного массива: ";
        for (int value : constNumbers) {
            cout << value << " ";
        }
        cout << endl;
    }
    catch (const exception& e) {
        cout << "Ошибка: " << e.what() << endl;
    }

    return 0;
}
