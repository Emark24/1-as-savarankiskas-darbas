#include "mylib.h"
#include <fstream>
#include <cstdlib>
#include <ctime>

char skaiciavimo_Strategija = 'v';

int main() {
    srand(time(0)); 

    const int fileCounts[] = { 1000, 10000, 100000, 1000000, 10000000 };
    for (int i = 0; i < 5; ++i) {
        string filename = "studentai_" + to_string(fileCounts[i]) + ".txt";
        ofstream output(filename);

        if (!output.is_open()) {
            cout << "Klaida atidarant failą " << filename << endl;
            continue;
        }

        int n = fileCounts[i];

        output << left << setw(15) << "Pavarde" << setw(15) << "Vardas" << setw(5) << "ND1" << setw(5) << "ND2" << setw(5) << "ND3" << setw(5) << "ND4" << setw(5) << "ND5" << setw(10) << "Egzaminas" << setw(10) << "Vidurkis" << endl;
        output << "----------------------------------------------------------" << endl;

        for (int j = 1; j <= n; ++j) {
            string vardas = "Vardas" + to_string(j);
            string pavarde = "Pavarde" + to_string(j);
            vector<int> pazymiai;

            for (int k = 0; k < 5; ++k) {
                int pazymys = rand() % 10 + 1; 
                pazymiai.push_back(pazymys);
            }

            int egzaminas = rand() % 10 + 1; 

            output << left << setw(15) << pavarde << setw(15) << vardas;
            for (int k = 0; k < 5; ++k) {
                output << setw(5) << pazymiai[k];
            }
            output << setw(10) << egzaminas;

            float vidurkis = accumulate(pazymiai.begin(), pazymiai.end(), 0.0) / pazymiai.size();
            float galutinis = vidurkis * 0.4 + egzaminas * 0.6;

            output << setw(10) << fixed << setprecision(2) << galutinis << endl;
        }

        output.close();
        cout << "Sukurtas failas: " << filename << endl;
    }

    return 0;
}
