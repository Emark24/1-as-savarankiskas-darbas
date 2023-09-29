using namespace std;

#include <array>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::array;
using std::vector;
using std::setw;
using std::left;
using std::right;
using std::fixed;
using std::setprecision;

class studentas {
	string vard, pav;
	//array<int, 10>paz;
	vector<int> paz;
	int egz;
	float rez;
public:
	studentas();
	studentas(string v, string p, vector<int>pp, int e);
	studentas(const studentas& temp);
	studentas& operator = (const studentas& temp);
	~studentas();
	//Getter
	inline string getVardas() { return vard; }
	inline int getPazNr() { return paz.size(); }
	//Setter
	inline void setVardas(string t) { vard = t; }
	void printas();
	void printasRez();
	void rezVid();




};