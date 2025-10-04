#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    int drinkChoice, addonChoice;
    char sizeChoice;

    cout << "=== ДОБРО ПОЖАЛОВАТЬ В КОФЕЙНЮ ===" << endl;

    do {
        // Вывод меню напитков
        cout << "\n=== МЕНЮ НАПИТКОВ ===" << endl;
        cout << "1 - Эспрессо (120 руб.)" << endl;
        cout << "2 - Капучино (150 руб.)" << endl;
        cout << "3 - Латте (160 руб.)" << endl;
        cout << "4 - Чай (100 руб.)" << endl;
        cout << "5 - Горячий шоколад (180 руб.)" << endl;
        cout << "0 - Выход" << endl;
        cout << "Выберите напиток (0-5): ";
        cin >> drinkChoice;

        if (drinkChoice == 0) {
            break;
        }

        if (drinkChoice < 1 || drinkChoice > 5) {
            cout << "Ошибка: неверный выбор напитка!" << endl;
            continue;
        }

        cout << "\n=== ВЫБОР РАЗМЕРА ===" << endl;
        cout << "S - маленький (базовая цена)" << endl;
        cout << "M - средний (+30%)" << endl;
        cout << "L - большой (+50%)" << endl;
        cout << "Выберите размер (S/M/L): ";
        cin >> sizeChoice;

        if (sizeChoice != 'S' && sizeChoice != 's' &&
            sizeChoice != 'M' && sizeChoice != 'm' &&
            sizeChoice != 'L' && sizeChoice != 'l') {
            cout << "Ошибка: неверный выбор размера!" << endl;
            continue;
        }

        cout << "\n=== ВЫБОР ДОБАВКИ ===" << endl;
        cout << "1 - без добавок" << endl;
        cout << "2 - молоко (+10 руб.)" << endl;
        cout << "3 - сироп (+15 руб.)" << endl;
        cout << "4 - сливки (+20 руб.)" << endl;
        cout << "Выберите добавку (1-4): ";
        cin >> addonChoice;

        if (addonChoice < 1 || addonChoice > 4) {
            cout << "Ошибка: неверный выбор добавки!" << endl;
            continue;
        }

        int basePrice = 0;
        string drinkName;

        switch(drinkChoice) {
            case 1:
                basePrice = 120;
                drinkName = "Эспрессо";
                break;
            case 2:
                basePrice = 150;
                drinkName = "Капучино";
                break;
            case 3:
                basePrice = 160;
                drinkName = "Латте";
                break;
            case 4:
                basePrice = 100;
                drinkName = "Чай";
                break;
            case 5:
                basePrice = 180;
                drinkName = "Горячий шоколад";
                break;
        }

        double sizeMultiplier = 1.0;
        string sizeName;

        if (sizeChoice == 'S' || sizeChoice == 's') {
            sizeMultiplier = 1.0;
            sizeName = "Маленький";
        } else if (sizeChoice == 'M' || sizeChoice == 'm') {
            sizeMultiplier = 1.3;
            sizeName = "Средний";
        } else if (sizeChoice == 'L' || sizeChoice == 'l') {
            sizeMultiplier = 1.5;
            sizeName = "Большой";
        }

        double priceWithSize = basePrice * sizeMultiplier;

        int addonPrice = 0;
        string addonName;

        switch(addonChoice) {
            case 1:
                addonPrice = 0;
                addonName = "Без добавок";
                break;
            case 2:
                addonPrice = 10;
                addonName = "Молоко";
                break;
            case 3:
                addonPrice = 15;
                addonName = "Сироп";
                break;
            case 4:
                addonPrice = 20;
                addonName = "Сливки";
                break;
        }

        double totalPrice = priceWithSize + addonPrice;

        cout << "\n=== ВАШ ЧЕК ===" << endl;
        cout << "Напиток: " << drinkName << endl;
        cout << "Размер: " << sizeName << endl;
        cout << "Добавка: " << addonName << endl;
        cout << "-------------------" << endl;
        cout << fixed << setprecision(2);
        cout << "Базовая цена: " << basePrice << " руб." << endl;
        cout << "Цена с размером: " << priceWithSize << " руб." << endl;
        if (addonPrice > 0) {
            cout << "Добавка: +" << addonPrice << " руб." << endl;
        }
        cout << "ИТОГО: " << totalPrice << " руб." << endl;
        cout << "===================" << endl;

        cout << "\nНажмите Enter для нового заказа..." << endl;
        cin.ignore();
        cin.get();

    } while (true);

    cout << "\nСпасибо за посещение! Ждем вас снова!" << endl;

    return 0;
}