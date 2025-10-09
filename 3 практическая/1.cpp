#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> tasks;
    int choice, id;

    while (true) {
        cout << "\n1. Добавить задачу\n2. Удалить задачу\n3. Показать задачи\n4. Выход\nВыберите: ";
        cin >> choice;

        if (choice == 1) {
            tasks.push_back(tasks.empty() ? 1 : tasks.back() + 1);
            cout << "Добавлена задача ID: " << tasks.back() << endl;
        }
        else if (choice == 2) {
            cout << "ID для удаления: ";
            cin >> id;
            auto it = find(tasks.begin(), tasks.end(), id);
            if (it != tasks.end()) {
                tasks.erase(it);
                cout << "Задача " << id << " удалена\n";
            } else cout << "Задача не найдена\n";
        }
        else if (choice == 3) {
            cout << "Задачи: ";
            for (int task : tasks) cout << task << " ";
            cout << endl;
        }
        else if (choice == 4) break;
        else cout << "Неверный выбор\n";
    }
    return 0;
}