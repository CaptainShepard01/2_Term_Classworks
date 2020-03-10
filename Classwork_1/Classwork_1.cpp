#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <fstream>
#include <direct.h>
#include <cstdlib>
#include <Windows.h>
#include "Header.h"
using namespace std;

struct dict {
	char angl[100];
	char ukr[100];
};

void Dictionary_creator() {
	ifstream f("words.bin", ios::binary);
	dict d;
	//_mkdir("Dictionary");
	_chdir("Dictionary");
	
	
	while (f.read((char*)&d, sizeof(dict))) {
		FILE* f1 = fopen(strcat(d.angl, ".txt"), "w");
		cout << d.ukr << endl;
		setlocale(LC_ALL, "rus");
		fwrite(d.ukr, strlen(d.ukr), 1, f1);
		fclose(f1);
		cout << "Created\n";
	}
	system("pause");
	f.close();
}

void Words_creator(int n)
{
	ofstream f2("words.bin", ios::binary);
	dict d;
	for (int i = 0; i < n; ++i) {
		cout << "Enter in English: ";
		cin.getline(d.angl, 100);
		cout << "Enter in Russian (translation or description): ";
		cin.getline(d.ukr, 100);
		//cout << strlen(d.ukr);

		/*_chdir("Dictionary");
		FILE* f1 = fopen(strcat(d.angl, ".txt"), "w");
		fwrite(d.ukr, strlen(d.ukr), 1, f1);
		fclose(f1);
		_chdir("D:\Visual studio\2_Term_Classworks\Classwork_1");*/

		f2.write((char*)&d, sizeof(dict));
	}
	f2.close();
	ifstream f1("words.bin", ios::binary);
	while (f1.read((char*)&d, sizeof(dict))) {
		cout << d.ukr << endl;
		system("pause");
	}
	f1.close();
}

int main()
{
	int count = 0;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("cls");
	bool isRunning = true;
	while (isRunning)
	{
		int answer = 0;
		answer = menu();
		switch (answer)
		{
		case 0: {
			cout << "How many words?\n";
			cin >> count;
			cin.clear();
			while (cin.get() != '\n')continue;
			Words_creator(count);
			break;
		}
		case 1:Dictionary_creator(); break;
		case 2: system("cls"); cout << "Goodbye!\n__________________"; isRunning = false;
		}

	}

	return 0;
}

