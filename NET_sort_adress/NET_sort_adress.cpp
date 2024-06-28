#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class Adress {
public:
	Adress(string city, string street, int number_house, int number_apartament)
		: city(city), street(street), number_house(number_house), number_apartament(number_apartament) {}

	string get_output() {
		return city + ", " + street + ", " + to_string(number_house) + ", " + to_string(number_apartament);
	}
	
	string get_city() const {
		return city;
	}
private:
	string city;
	string street;
	int number_house;
	int number_apartament;
};

void sort(vector<Adress>& addresses) {
	int size = addresses.size();
	for (int i = 0; i < size - 1; ++i) {
		for (int j = 0; j < size - 1 - i; ++j) {
			if (addresses[j].get_city() > addresses[j + 1].get_city()) {
				swap(addresses[j], addresses[j + 1]);
			}
		}
	}
}

int main() {
	setlocale(LC_ALL, "rus");
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	int n;
	fin >> n;

	vector<Adress> addresses;
	for (int i = 0; i < n; ++i) {
		string city, street;
		int number_house, number_apartament;

		fin >> city;
		fin >> street;
		fin >> number_house;
		fin >> number_apartament;
		addresses.emplace_back(city, street, number_house, number_apartament);
	}
	sort(addresses);
	fout << n << endl;
	for (int i = 0; i < n; i++) {
		fout << addresses[i].get_output() << endl;
	}

	fin.close();
	fout.close();
}