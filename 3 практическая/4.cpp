#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> speed(24);
    int limit;

    cout << "Порог скорости: ";
    cin >> limit;

    for (int i = 0; i < 24; i++) {
        cout << "Скорость в " << i << " час: ";
        cin >> speed[i];
    }

    int total = 0, maxGood = 0, maxBad = 0, currentGood = 0, currentBad = 0, hours = 0;

    for (int s : speed) {
        total += s;
        if (s > 0) hours++;

        if (s <= limit && s > 0) {
            currentGood++;
            currentBad = 0;
        } else if (s > limit) {
            currentBad++;
            currentGood = 0;
        } else {
            currentGood = currentBad = 0;
        }

        maxGood = max(maxGood, currentGood);
        maxBad = max(maxBad, currentBad);
    }

    cout << "\nСредняя скорость: " << total / 24.0 << endl;
    cout << "Макс. интервал без превышения: " << maxGood << " ч" << endl;
    cout << "Макс. интервал превышения: " << maxBad << " ч" << endl;
    cout << "Часов движения: " << hours << endl;

    return 0;
}