#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

    srand(time(0));

    int secretNumber = rand() % 20 + 1;
    int userGuess;
    int attempts = 0;

    cout << "=== ИГРА 'УГАДАЙ ЧИСЛО' ===" << endl;
    cout << "Я загадал число от 1 до 20." << endl;
    cout << "Попробуйте угадать его!" << endl << endl;

    while (true) {
        cout << "Введите вашу догадку (1-20): ";
        cin >> userGuess;

        if (userGuess < 1 || userGuess > 20) {
            cout << "Ошибка! Введите число от 1 до 20." << endl;
            continue;
        }

        attempts++;

        if (userGuess > secretNumber) {
            cout << "Слишком много! Попробуйте ещё." << endl;
        } else if (userGuess < secretNumber) {
            cout << "Слишком мало! Попробуйте ещё." << endl;
        } else {

            cout << endl << "Поздравляем, вы угадали!" << endl;
            break;
        }

        cout << endl;
    }

    cout << "Загаданное число: " << secretNumber << endl;
    cout << "Количество попыток: " << attempts << endl;
    cout << "Спасибо за игру!" << endl;

    return 0;
}