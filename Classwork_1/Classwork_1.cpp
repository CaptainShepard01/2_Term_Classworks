#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <io.h>
#include <fcntl.h>
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
	/*_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stderr), _O_U16TEXT);*/

	//setlocale(LC_ALL, "Russian");

	ifstream f("words.bin", ios::binary);
	dict d;
	//_mkdir("Dictionary");
	_chdir("Dictionary");
	
	
	
	

	while (f.read((char*)&d, sizeof(dict))) {
		//ofstream f1(strcat(d.angl, ".txt"));
		FILE* f1 = fopen(strcat(d.angl, ".txt"), "wb");
		cout << d.ukr;
		fwrite(d.ukr, sizeof(d.ukr), 1, f1);
		//f1 << d.ukr;
		fclose(f1);
		//f1.close(); 
		cout << "Created\n";
	}
	system("pause");
	f.close();
}

void Words_creator(int n)
{
	/*_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stderr), _O_U16TEXT);*/

	//setlocale(LC_ALL, "Russian");
	//FILE* file = fopen("words.bin", "wb");
	ofstream f2("words.bin", ios::binary);
	dict d;
	for (int i = 0; i < n; ++i) {
		cout << "Enter in English: ";
		cin.getline(d.angl, 100);
		cout << "Enter in Russian (translation or description): ";
		//setlocale(LC_ALL, "rus");
		cin.getline(d.ukr, 100);
		f2.write((char*)&d, sizeof(dict));
		//fwrite(&d, sizeof(dict), 1, file);
	}
	//fclose(file);
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
	/*_setmode(_fileno(stdout), _O_U16TEXT);
	_setmode(_fileno(stdin), _O_U16TEXT);
	_setmode(_fileno(stderr), _O_U16TEXT);*/

	int count = 0;
	//setlocale(LC_ALL, "Russian");
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

