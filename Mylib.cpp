//mylib.cpp
#include "mylib.h"

Studentas::Studentas() : Vardas(""), Pavarde(""), Egzaminas(0), Galutinis(0.0), Vidurkis(true) {
}

Studentas::Studentas(const Studentas& other)
    : Vardas(other.Vardas), Pavarde(other.Pavarde),
    ND(other.ND), Egzaminas(other.Egzaminas),
    Galutinis(other.Galutinis), Vidurkis(other.Vidurkis) {}

Studentas::Studentas(const std::string& vardas, const std::string& pavarde, const std::vector<int>& namuDarbai, int egzaminas, bool naudotiVidurki)
    : Vardas(vardas), Pavarde(pavarde), ND(namuDarbai), Egzaminas(egzaminas), Vidurkis(naudotiVidurki) {
    SkaiciuotiGalutiniPazymi();
}

Studentas& Studentas::operator=(const Studentas& other) {
    if (this == &other) {
        return *this;
    }
    Vardas = other.Vardas;
    Pavarde = other.Pavarde;
    ND = other.ND;
    Egzaminas = other.Egzaminas;
    Galutinis = other.Galutinis;
    Vidurkis = other.Vidurkis;
    return *this;
}

Studentas::~Studentas() {
}

void Studentas::OutputData() const {
    std::cout << std::left << std::setw(12) << Pavarde
        << std::left << std::setw(12) << Vardas;

    if (Vidurkis) {
        std::cout << std::fixed << std::setprecision(2) << "Galutinis (Vid.)" << std::setw(10);
    }
    else {
        std::cout << std::fixed << std::setprecision(2) << "Galutinis (Med.)" << std::setw(10);
    }

    std::cout << Galutinis << std::endl;
}

void Studentas::SkaiciuotiGalutiniPazymi() {
    if (Vidurkis && !ND.empty()) {
        double vidurkis = 0.0;
        for (int nd : ND) {
            vidurkis += nd;
        }
        vidurkis /= ND.size();
        Galutinis = 0.4 * vidurkis + 0.6 * Egzaminas;
    }
    else if (!ND.empty()) {
        std::vector<int> sortedNamuDarbai = ND;
        std::sort(sortedNamuDarbai.begin(), sortedNamuDarbai.end());
        if (sortedNamuDarbai.size() % 2 == 0) {
            int n1 = sortedNamuDarbai[sortedNamuDarbai.size() / 2 - 1];
            int n2 = sortedNamuDarbai[sortedNamuDarbai.size() / 2];
            Galutinis = (n1 + n2) / 2.0;
        }
        else {
            Galutinis = sortedNamuDarbai[sortedNamuDarbai.size() / 2];
        }
        Galutinis = 0.4 * Galutinis + 0.6 * Egzaminas;
    }
    else {
        std::cerr << "nera namu darbu" << std::endl;
    }
}

void Studentas::WriteToFile(std::ostream& file) const {
    file << std::left << std::setw(15) << Pavarde << "\t" << std::setw(15) << Vardas << "\t";
    for (int nd : ND) {
        file << nd << "\t";
    }
    file << Egzaminas << "\t";
    if (Vidurkis) {
        file << "" << "\t" << Galutinis;
    }
    else {
        file << "" << "\t" << Galutinis;
    }
    file << "\n";
}



void Studentas::GenerateRandomGrades() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distribution(1, 10);

    for (int i = 0; i < 5; ++i) {
        int random_nd = distribution(gen);
        ND.push_back(random_nd);
    }

    Egzaminas = distribution(gen);
    SkaiciuotiGalutiniPazymi();
}

Studentas::Studentas(bool generateRandom) : Egzaminas(0), Galutinis(0.0), Vidurkis(true) {
    if (generateRandom) {
        static int studentoNumeris = 1;
        Vardas = "Vardas" + std::to_string(studentoNumeris);
        Pavarde = "Pavarde" + std::to_string(studentoNumeris);
        studentoNumeris++;

        GenerateRandomGrades();
    }
}

void Studentas::WriteToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << Pavarde << "\t" << Vardas << "\t";
        for (int nd : ND) {
            file << nd << "\t";
        }
        file << Egzaminas << "\n";
        file.close();
    }
    else {
        std::cerr << "nepavyko atidaryti failo " << filename << std::endl;
    }
}


