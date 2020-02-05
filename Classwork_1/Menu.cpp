#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <direct.h>
#include <cstdlib>
#include <stdio.h>
#include <conio.h>
#include "Header.h"
using namespace std;

int menu()
{
	int key = 0;
	int code;
	do {
		system("cls");
		key = (key + 3) % 3;
		if (key == 0) cout << "-> Write words in binary file." << endl;
		else  cout << "   Write words in binary file." << endl;
		if (key == 1) cout << "-> Insert dictionary files." << endl;
		else  cout << "   Insert dictionary files." << endl;
		if (key == 2) cout << "-> Exit." << endl;
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