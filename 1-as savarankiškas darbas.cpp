#include "mylib.h"

int main() {
    cout << "Studentai" << endl;
    vector<studentas> grupe;

    for (int i = 0; i < 3; i++) {
        studentas K;
        grupe.push_back(K);
    }

    cout << endl;

    printf("|%-10s|%-20s|", "Vardas", "Pavarde");
    for (int i = 0; i < grupe[0].getPazNr(); i++) {
        printf("ND%-2d|", i + 1);
    }
    printf("%-10s|\n", "Egzaminas");

    for (auto& a : grupe) {
        a.printas();
    }

    cout << endl;

    for (auto& a : grupe) {
        a.printasRez();
    }

    system("pause");
}
