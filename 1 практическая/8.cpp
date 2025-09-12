// 8.Пользователь вводит число – определите, является ли оно степенью двойки
//с помощью побитовых операций.

#include <iostream>
using namespace std;

int main() {
    int number;
    cout << "Введите число: ";
    cin >> number;

    if (number > 0 && (number & (number - 1)) == 0) {
        cout << number << " является степенью двойки" << endl;
    } else {
        cout << number << " не является степенью двойки" << endl;
    }
    return 0;
}
