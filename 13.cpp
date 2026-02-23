// COMSC-210 | Lab 13 | Seoyeon An

#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

const int DAYS = 30;

bool loadData(const string& filename, vector<int>& visits);
void printData(const vector<int>& visits, const string& title);

int main() {
    vector<int> visits;

    cout << "empty()? "
         << (visits.empty() ? "True" : "False") << endl;

    if (!loadData("visit.txt", visits)) {
        cout << "File error visit.txt not found";
        return 0;
    }

    cout << "size(): " << visits.size() << "\n";
    cout << "front(): " << visits.front() << "\n";
    cout << "back(): " << visits.back() << "\n";
    cout << "at(2): " << visits.at(2) << "\n";



    int sum = accumulate(visits.begin(), visits.end(), 0);
    cout << "\nSum: " << sum << endl;



    vector<int> sorted = visits;


    sort(sorted.begin(), sorted.end());
    printData(sorted, "\nSorted data:");

    // member functions: fill(), swap()
    vector<int> baseline(visits.size());
    baseline.assign(visits.size(), 0);
    printData(baseline, "\nBaseline (fill(0)):");

    baseline.swap(sorted);
    printData(baseline, "\n After swap:");
    printData(sorted, "\n After swap:");

    return 0;
}


bool loadData(const string& filename,vector<int>& visits) {
    ifstream fin;


    if (!fin.good())
        return false;

    for (int i = 0; i < DAYS; i++){
        fin >> visits[i];
        if (fin.fail()) {
            fin.close();
            return false;
        }
    }

    fin.close();
    return true;
}
void printData(const array<int, DAYS>& visits, const string& title) {
    cout << title << "\n";
    for (int i = 0; i < DAYS; i++) {
        cout << "Day " << i + 1 << ": " << visits[i] << "\n";
    }
}