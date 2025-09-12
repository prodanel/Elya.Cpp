// 5.Вычислите результат деления числа на 2^n с помощью побитовых операций.
//Пользователь вводит число и n. Выведите результат.

#include <iostream>
using namespace std;

int main() {
    int number, n;
    cout << "Введите число и степень n: ";
    cin >> number >> n;

    int result = number >> n;
    cout << number << " / 2^" << n << " = " << result << endl;
    return 0;
}
