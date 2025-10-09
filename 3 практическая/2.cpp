#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int days;
    cout << "Количество дней: ";
    cin >> days;

    vector<int> visits(days);
    int total = 0;

    for (int i = 0; i < days; i++) {
        cout << "Посещений за день " << i + 1 << ": ";
        cin >> visits[i];
        total += visits[i];
    }

    double average = (double)total / days;
    auto max_it = max_element(visits.begin(), visits.end());
    auto min_it = min_element(visits.begin(), visits.end());
    int low_days = count_if(visits.begin(), visits.end(), [average](int x) { return x < average; });

    cout << "\nОбщее количество: " << total << endl;
    cout << "Среднее в день: " << average << endl;
    cout << "Максимум: " << *max_it << " (день " << (max_it - visits.begin() + 1) << ")" << endl;
    cout << "Минимум: " << *min_it << " (день " << (min_it - visits.begin() + 1) << ")" << endl;
    cout << "Низкая посещаемость: " << (low_days * 100.0 / days) << "%" << endl;

    return 0;
}