// 9. Пользователь вводит число – определите, является ли оно четным с помощью побитовых операций.

#include <iostream>
using namespace std;

int main() {
    int number;
    cout << "Введите число: ";
    cin >> number;

    if ((number & 1) == 0) {
        cout << number << " - четное" << endl;
    } else {
        cout << number << " - нечетное" << endl;
    }
    return 0;
}
