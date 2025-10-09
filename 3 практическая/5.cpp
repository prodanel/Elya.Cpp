#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> sales(22), lastYear(22);
    int total = 0, totalLast = 0;

    cout << "Текущий месяц:\n";
    for (int i = 0; i < 22; i++) {
        cout << "День " << i+1 << ": ";
        cin >> sales[i];
        total += sales[i];
    }

    cout << "Прошлый год:\n";
    for (int i = 0; i < 22; i++) {
        cout << "День " << i+1 << ": ";
        cin >> lastYear[i];
        totalLast += lastYear[i];
    }

    double avg = total / 22.0;
    int maxCount = 0, minCount = 0, declinePeriods = 0, currentDecline = 1;

    cout << "\n--- Анализ текущего месяца ---\n";
    cout << "Средняя сумма: " << avg << endl;

    cout << "Дни с продажами >100000: ";
    for (int i = 0; i < 22; i++)
        if (sales[i] > 100000) { cout << i+1 << " "; maxCount++; }
    cout << "(" << maxCount << " дней)" << endl;

    cout << "Дни с продажами <10000: ";
    for (int i = 0; i < 22; i++)
        if (sales[i] < 10000) { cout << i+1 << " "; minCount++; }
    cout << "(" << minCount << " дней)" << endl;

    vector<int> declineLengths;
    for (int i = 1; i < 22; i++) {
        if (sales[i] < sales[i-1]) {
            currentDecline++;
        } else {
            if (currentDecline > 3) {
                declinePeriods++;
                declineLengths.push_back(currentDecline);
            }
            currentDecline = 1;
        }
    }
    if (currentDecline > 3) {
        declinePeriods++;
        declineLengths.push_back(currentDecline);
    }

    cout << "Периоды уменьшения >3 дней: " << declinePeriods;
    if (!declineLengths.empty()) {
        cout << " (длины: ";
        for (int len : declineLengths) cout << len << " ";
        cout << ")";
    }
    cout << endl;

    int nextMonthPlan;
    if (total >= totalLast) {
        nextMonthPlan = total * 1.1;
    } else {
        nextMonthPlan = (total + totalLast) / 2;
    }

    cout << "\n--- План на следующий месяц ---\n";
    cout << "Текущий месяц: " << total << endl;
    cout << "Прошлый год: " << totalLast << endl;
    cout << "План: " << nextMonthPlan << endl;

    return 0;
}