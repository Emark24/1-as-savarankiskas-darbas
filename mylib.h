//mylib.h
#ifndef MYLIB_H
#define MYLIB_H

#include <string>
#include <vector>
#include <fstream> 
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <random>


class Studentas {
public:
    Studentas();
    Studentas(const std::string& vardas, const std::string& pavarde, const std::vector<int>& namuDarbai, int egzaminas, bool naudotiVidurki);
    Studentas(const Studentas& other);
    Studentas& operator=(const Studentas& other);
    ~Studentas();

    void OutputData() const;

    Studentas(bool generateRandom);
    void GenerateRandomGrades();
    void WriteToFile(const std::string& filename) const;
    void SetStudentNumber(int number) {
        studentNumber_ = number;
    }

    void WriteToFile(std::ostream& file) const;



    const std::string& GetVardas() const { return Vardas; }
    const std::string& GetPavarde() const { return Pavarde; }
    const std::vector<int>& GetNamuDarbai() const { return ND; }
    double GetGalutinis() const { return Galutinis; }

private:
    std::string Vardas;
    std::string Pavarde;
    std::vector<int> ND;
    int Egzaminas;
    double Galutinis;
    bool Vidurkis;
    int studentNumber_;
    void SkaiciuotiGalutiniPazymi();
};

#endif
