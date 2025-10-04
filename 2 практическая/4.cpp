#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int numProducts;
    double totalAmount = 0.0;
    char hasLoyaltyCard;
    double customerPayment;

    cout << "=== КАССОВАЯ ПРОГРАММА ===" << endl;

    cout << "Введите количество товаров: ";
    cin >> numProducts;

    if (numProducts <= 0) {
        cout << "Ошибка: количество товаров должно быть положительным!" << endl;
        return 1;
    }

    cout << "\n=== ВВОД ЦЕН ТОВАРОВ ===" << endl;
    for (int i = 1; i <= numProducts; i++) {
        double price;
        cout << "Введите цену товара " << i << ": ";
        cin >> price;

        if (price < 0) {
            cout << "Ошибка: цена не может быть отрицательной!" << endl;
            i--;
            continue;
        }

        totalAmount += price;
    }

    double discount1 = 0.0;
    double discount2 = 0.0;
    double finalAmount = totalAmount;

    if (totalAmount > 5000) {
        discount1 = totalAmount * 0.10;
        finalAmount = totalAmount - discount1;
    }

    cout << "\nЕсть ли у клиента карта лояльности? (y/n): ";
    cin >> hasLoyaltyCard;

    if (hasLoyaltyCard == 'y' || hasLoyaltyCard == 'Y') {
        discount2 = finalAmount * 0.05;
        finalAmount -= discount2;
    }

    double totalDiscount = discount1 + discount2;

    cout << "\nВведите сумму, которую дал клиент: ";
    cin >> customerPayment;

    if (customerPayment < finalAmount) {
        cout << "Ошибка: недостаточно средств! Не хватает: "
             << (finalAmount - customerPayment) << " руб." << endl;
        return 1;
    }

    double change = customerPayment - finalAmount;

    cout << "\n=== КАССОВЫЙ ЧЕК ===" << endl;
    cout << fixed << setprecision(2);
    cout << "Количество товаров: " << numProducts << endl;
    cout << "Общая стоимость без скидок: " << totalAmount << " руб." << endl;
    cout << "-----------------------------" << endl;

    if (discount1 > 0) {
        cout << "Скидка за сумму (>5000 руб.): -" << discount1 << " руб." << endl;
    }

    if (discount2 > 0) {
        cout << "Скидка по карте лояльности: -" << discount2 << " руб." << endl;
    }

    if (totalDiscount > 0) {
        cout << "Общая сумма скидок: -" << totalDiscount << " руб." << endl;
    }

    cout << "-----------------------------" << endl;
    cout << "ИТОГО К ОПЛАТЕ: " << finalAmount << " руб." << endl;
    cout << "ВНЕСЕНО: " << customerPayment << " руб." << endl;
    cout << "СДАЧА: " << change << " руб." << endl;
    cout << "=============================" << endl;
    cout << "СПАСИБО ЗА ПОКУПКУ!" << endl;

    return 0;
}