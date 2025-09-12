// 1.Запросите у пользователя 3 переменные. С помощью указателя
//вычислите их среднее арифметическое значение. Выведите результат в консоль.

#include <iostream>
using namespace std;

int main() {
    double a, b, c;
    cout << "Введите три числа: ";
    cin >> a >> b >> c;

    double sum = a + b + c;
    double* ptr = &sum;
    double average = *ptr / 3;

    cout << "Среднее арифметическое: " << average << endl;
    return 0;
}
