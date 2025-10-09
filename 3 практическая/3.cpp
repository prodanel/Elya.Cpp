#include <iostream>
#include <string>
using namespace std;

int main() {
    string text;
    int shift;

    cout << "Введите текст: ";
    getline(cin, text);
    cout << "Введите сдвиг: ";
    cin >> shift;

    for (char &c : text) {
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            c = base + (c - base + shift) % 26;
        }
    }

    cout << "Результат: " << text << endl;
    return 0;
}