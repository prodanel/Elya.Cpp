#include <iostream>
using namespace std;

int main() {
    int age, ticketType;
    char choice;

    do {
        cout << " ПРОВЕРКА БИЛЕТА " << endl;

        cout << "Введите возраст: ";
        cin >> age;

        if (age < 5) {
            cout << "Вход запрещён: слишком маленький возраст" << endl;
            continue;
        }
        cout << "Введите тип билета (1-обычный, 2-детский, 3-пенсионер, 4-VIP): ";
        cin >> ticketType;

        if (ticketType < 1 || ticketType > 4) {
            cout << "Ошибка: неверный тип билета!" << endl;
            continue;
        }

        bool accessGranted = false;
        string ticketCategory;

        switch(ticketType) {
            case 1: ticketCategory = "обычный"; break;
            case 2: ticketCategory = "детский"; break;
            case 3: ticketCategory = "пенсионер"; break;
            case 4: ticketCategory = "VIP"; break;
        }
        if (age >= 5 && age <= 12) {
            if (ticketType == 2) {
                accessGranted = true;
                cout << "Вход разрешен с детским билетом" << endl;
            } else {
                cout << "Вход запрещён: для возраста " << age << " лет требуется детский билет" << endl;
            }
        }
        else if (age >= 13 && age <= 49) {
            if (ticketType == 1 || ticketType == 4) {
                accessGranted = true;
                cout << "Вход разрешен с " << ticketCategory << " билетом" << endl;
            } else {
                cout << "Вход запрещён: для возраста " << age << " лет требуется обычный или VIP билет" << endl;
            }
        }
        else if (age >= 50 && age <= 64) {
            if (ticketType != 2) {
                accessGranted = true;
                cout << "Вход разрешен с " << ticketCategory << " билетом" << endl;
            } else {
                cout << "Вход запрещён: детский билет не подходит для возраста " << age << " лет" << endl;
            }
        }
        else if (age >= 65) {
            if (ticketType == 3 || ticketType == 4) {
                accessGranted = true;
                cout << "Вход разрешен с " << ticketCategory << " билетом" << endl;
            } else {
                cout << "Вход запрещён: для возраста " << age << " лет требуется пенсионерский или VIP билет" << endl;
            }
        }

        cout << "\nХотите проверить еще один билет? (y/n): ";
        cin >> choice;
        cout << endl;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}