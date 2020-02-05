#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <direct.h>
#include <cstdlib>
#include "Header.h"
using namespace std;
struct dict {
	char angl[100];
	char ukr[100];
};

void Dictionary_creator() {
	//system("chcp utf-8");
	//system("cls");
	//std::wcout.imbue(std::locale("rus_rus.866"));
	setlocale(LC_ALL, "rus");

	ifstream f("words.bin", ios::binary);
	dict d;
	//_mkdir("Dictionary");
	_chdir("Dictionary");
	

	while (f.read((char*)&d, sizeof(dict))) {
		ofstream f1(strcat(d.angl, ".txt"));
		f1 << d.ukr;
		f1.close(); cout << "\nCreated\n";
	}
	f.close();
	_chdir("Classwork_1");
	main();
}

void Words_creator()
{
	//system("chcp utf-8");
	//system("cls");
	//std::wcout.imbue(std::locale("rus_rus.866"));
	setlocale(LC_ALL, "rus");
	FILE* file = fopen("words.bin", "wb");
	//ofstream wrd("words.bin", ios::binary);
	dict d;
	cout << "Enter in English: ";
	cin.getline(d.angl, 100);
	cout << "Enter in Ukrainian (translation or description): ";
	cin.getline(d.ukr, 100);
	fwrite(&d, sizeof(dict), 1, file);
	fclose(file);
	//wrd.write((char*)&d, sizeof(dict));
	//wrd.close();
	main();
}

int main()
{
	//system("chcp utf-8");
	setlocale(LC_ALL, "rus");
	system("cls");
	//std::wcout.imbue(std::locale("rus_rus.866"));
	bool isRunning = true;
	while (isRunning)
	{
		int answer = 0;
		setlocale(LC_ALL, "Russian");
		answer = menu();
		switch (answer)
		{
		case 0:Words_creator(); isRunning = 0; break;
		case 1:Dictionary_creator(); isRunning = 0; break;
		case 2: system("cls"); cout << "Goodbye!\n__________________"; isRunning = false;
		}

	}

	return 0;
}

