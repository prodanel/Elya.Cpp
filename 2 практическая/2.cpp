#include <iostream>
using namespace std;

int main() {
    int mainScore, extraTasks;
    char hasBonus, choice;

    do {
        cout << " СИСТЕМА УЧЕТА РЕЗУЛЬТАТОВ ТЕСТИРОВАНИЯ " << endl;

        cout << "Введите балл за основной тест (0-100): ";
        cin >> mainScore;

        if (mainScore < 0 || mainScore > 100) {
            cout << "Ошибка: балл должен быть от 0 до 100!" << endl;
            continue;
        }

        cout << "Введите количество выполненных дополнительных заданий: ";
        cin >> extraTasks;

        if (extraTasks < 0) {
            cout << "Ошибка: количество заданий не может быть отрицательным!" << endl;
            continue;
        }

        cout << "Есть ли бонусный балл? (y/n): ";
        cin >> hasBonus;

        int finalScore = mainScore;

        finalScore += extraTasks * 3;

        if (hasBonus == 'y' || hasBonus == 'Y') {
            finalScore += 15;
        }

        if (finalScore > 100) {
            finalScore = 100;
        }

        cout << "\n--- РЕЗУЛЬТАТЫ ---" << endl;
        cout << "Основной балл: " << mainScore << endl;
        cout << "Бонус за дополнительные задания: +" << extraTasks * 3 << endl;
        if (hasBonus == 'y' || hasBonus == 'Y') {
            cout << "Бонусный балл: +15" << endl;
        }
        cout << "Итоговый балл: " << finalScore << endl;

        string grade;

        if (finalScore >= 90 && finalScore <= 100) {
            grade = "Отлично";
        } else if (finalScore >= 75 && finalScore <= 89) {
            grade = "Хорошо";
        } else if (finalScore >= 60 && finalScore <= 74) {
            grade = "Удовлетворительно";
        } else {
            grade = "Неудовлетворительно";
        }

        cout << "Итоговая оценка: " << grade << endl;

        cout << "\nХотите ввести результаты еще одного студента? (y/n): ";
        cin >> choice;
        cout << endl;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}