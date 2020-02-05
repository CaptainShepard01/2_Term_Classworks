#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <direct.h>
#include <cstdlib>
using namespace std;
struct dict {
	char angl[100];
	char ukr[100];
};
void fun() {
	ifstream f("words.bin", ios::binary);
	dict d;
	_chdir("Ductionary");
	//_mkdir("words");

	while (f.read((char*)&d, sizeof(dict))) {
		ofstream f1(d.angl, ios::binary);
		f1 << d.ukr;
		f1.close(); cout << "\nCreated\n";
	}
	f.close();
}

int main()
{
	
	return 0;
}