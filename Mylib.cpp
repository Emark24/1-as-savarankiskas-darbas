#include "mylib.h"

studentas::studentas() {

	cout << "Iveskite sutdento varda: "; cin >> vard;
	cout << "Ivesk pavarde: "; cin >> pav;
	cout << "Kiek pazymiu buvo semestre? "; int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int k;
		cout << "Ivesk " << i + 1 << " semestro pazymi: "; cin >> k; paz.push_back(k);
	}
	cout << "Ivesk egzamino pazymi: "; cin >> egz;
	rezVid();
}
studentas::studentas(string v, string p, vector<int>pp, int e)
{
	vard = v; pav = p; paz = pp; egz = e;
	rezVid();
}
studentas::studentas(const studentas& temp) { //1. copy constructor 
	vard = temp.vard; pav = temp.pav;
	paz = temp.paz; egz = temp.egz;
	rezVid();
}
studentas& studentas::operator=(const studentas & temp) //2. copy assignment
{
	if (this == &temp) return *this;
	vard = temp.vard; pav = temp.pav;
	paz = temp.paz; egz = temp.egz;
	rezVid();
	return *this;
}
studentas::~studentas() {							//3. destructor
	vard.clear(); pav.clear(); paz.clear(); 
	egz = 0; rez = 0;
} 
void studentas::printas() {
	printf("|%-10s|%20s|", vard.c_str(), pav.c_str());
	for (auto& a : paz) printf("%3d|", a);
	printf("%10d|\n", egz);
}
void studentas::printasRez() {
	printf("|%-10s|%20s|", vard.c_str(), pav.c_str());
	printf("%10f|\n", rez);
}
void studentas::rezVid() {
	//rez = vid * 04 + egz * 0.6;
	float sum = std::accumulate(paz.begin(), paz.end(), 0.0);
	rez = sum / paz.size() * 0.4 + egz * 0.6;
}