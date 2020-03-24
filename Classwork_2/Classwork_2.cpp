#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <io.h>
#include <fcntl.h>
#include <fstream>
#include <direct.h>
#include <conio.h>
#include <Windows.h>
#include "Header.h"
#include "List.h"
using namespace std;

int menu();

int main()
{
	int count = 0;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("cls");
	int key = 0;
	bool isRunning = 1;
	while (isRunning) {
		key = menu();
		switch (key) {
		case 0: {
			Words_add();
			Words_read(count);
			system("pause");
			break;
		}
		case 1: {
			if (Words_read(count) != NULL);
			else {
				Words_add();
				Words_read(count);
				system("pause");
			}
			system("pause");
			break;
		}
		case 2: {
			Words_upd();
			break;
		}
		case 3: {
			Words_delete();
			break;
		}
		case 4: {
			Words_find();
			break;
		}
		case 5: {
			isRunning = 0; break;;
		}
		}
	}
	return 0;
}

int menu()
{
	int key = 0;
	int code;
	do {
		system("cls");
		key = (key + 6) % 6;
		if (key == 0) cout << "-> Add new words and translations." << endl;
		else  cout << "   Add new words and translations." << endl;
		if (key == 1) cout << "-> Read all words and translations." << endl;
		else  cout << "   Read all words and translations." << endl;
		if (key == 2) cout << "-> Update words' translations." << endl;
		else  cout << "   Update words' translations." << endl;
		if (key == 3) cout << "-> Delete words." << endl;
		else  cout << "   Delete words." << endl;
		if (key == 4) cout << "-> Find word and its translations, first and last." << endl;
		else  cout << "   Find word and its translations, first and last." << endl;
		if (key == 5) cout << "-> Exit." << endl;
		else  cout << "   Exit." << endl;
		code = _getch();
		if (code == 224)
		{
			code = _getch();
			if (code == 80) key++;
			if (code == 72) key--;
		}
	} while (code != 13);
	system("cls");
	return key;
}