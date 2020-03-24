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

using namespace std;

int menu();

struct dict {
	char angl[100] = {};
	char rus[100] = {};
};

void Dictionary_creator() {
	ifstream f("words.bin", ios::binary);
	dict d;
	//_mkdir("Dictionary");
	_chdir("Dictionary");


	while (f.read((char*)& d, sizeof(dict))) {
		FILE* f1 = fopen(strcat(d.angl, ".txt"), "a");
		cout << d.rus << endl;
		setlocale(LC_ALL, "rus");
		fwrite(d.rus, strlen(d.rus), 1, f1);
		fclose(f1);
		cout << "Created\n";
	}
	system("pause");
	f.close();
}

void Words_add()
{
	dict d, d1;
	int choice = 0;
	bool iWant = 1;
	ifstream file("words.bin");
	if (!file.is_open()) {
		ofstream file1("words.bin", ios::binary);
		file1.close();
	}
	else file.close();

	while (iWant) {
		ofstream f("words.bin", ios::binary | ios::app);
		bool moreTranslations = 1;
		cout << "Enter in English: ";
		cin.getline(d.angl, 100);
		while (moreTranslations) {
			cout << "Enter in Russian (translation or description): ";
			cin.getline(d.rus, 100);
			f.write((char*)& d, sizeof(dict));
			system("cls");
			cin.clear();
			cout << "Are there any more translations for word (" << d.angl << ") ?\n1 --> Yes\n2 --> No\n";
			while (cin.get() != '\n');
			cin >> choice;
			switch (choice) {
			case 1: {
				moreTranslations = 1;
				system("cls");
				cout << "In English: " << d.angl << endl;
				break;
			}
			case 2:moreTranslations = 0; break;
			}
		}
		f.close();
		system("cls");
		cout << "Would you like to insert more words?\n1 --> Yes\n2 --> No\n\n";
		cin.clear();
		cin >> choice;
		switch (choice) {
		case 1:iWant = 1; break;
		case 2:iWant = 0; break;
		}

	}
	return;
}

dict* Words_read(const char* filename)
{
	int cnt = 0;
	dict d;
	ifstream f("words.bin", ios::binary);
	while (f.read((char*)& d, sizeof(dict))) {
		cnt++;
	}
	f.close();
	ifstream f1("words.bin", ios::binary);
	if (cnt != 0) {
		cout << "There are " << cnt << " words\n";
		system("pause");
		system("cls");

		dict* mas = new dict[cnt];

		for (int i = 0; i < cnt; ++i) {
			f1.read((char*)& mas[i], sizeof(dict));
		}

		f1.close();
		for (int i = 0; i < cnt; ++i) {
			cout << "English word: " << mas[i].angl << " ---> " << "Translation: " << mas[i].rus << endl;
		}

		return mas;
	}
	else {
		cout << "There are no words!\nLet's add some!\n";
		system("pause");
		system("cls");
		return NULL;
	}
}

void Words_upd(const char* filename)
{

}

void Words_delete(const char* filename)
{

}

void Words_find(const char* filename)
{

}


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
			Words_read("words.bin");
			system("pause");
			break;
		}
		case 1: {
			if (Words_read("words.bin") != NULL);
			else {
				Words_add();
				Words_read("words.bin");
				system("pause");
			}
			system("pause");
			break;
		}
		case 2: {

			break;
		}
		case 3: {

			break;
		}
		case 4: {

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
		if (key == 3) cout << "-> Update words' translations." << endl;
		else  cout << "   Update words' translations." << endl;
		if (key == 4) cout << "-> Delete words." << endl;
		else  cout << "   Delete words." << endl;
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

/*#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <experimental/filesystem>
#include "Word.h"
#include "List.h"
#include "functions.h"

void setWords()
{
	Word word;

	bool isDone = false;

	while (!isDone)
	{
		system("cls");
		std::cout << "Enter the word : \n";
		word.setEng();
		word.setUkr();
		word.saveWord();
		std::cout << "One more? (press Enter)\n";
		switch (_getch())
		{
		case 13:
			break;
		default:
			isDone = true;
			break;
		}
	}
	updWords();
}

void updWords()
{
	std::experimental::filesystem::remove_all(FOLDER);
	_mkdir(FOLDER);
	Word word;

	int i = 1;
	while (word.readWord(i))
	{
		word.writeToFile();
		i++;
	}
}

int showWords()
{
	Word word;

	int i = 1, read = 0;
	while (word.readWord(i))
	{
		std::cout << i << ". ";
		word.show();
		i++;
		read++;
	}
	return read;
}

void presentWords()
{
	if (showWords() == 0)
	{
		std::cout << "There`s nothing to show!\n";
		return;
	}
}

void changeWord()
{
	system("cls");
	std::cout << "CHANGE WORD\n\n";
	if (showWords() == 0)
	{
		std::cout << "There`s nothing to change!\n";
		system("pause");
		return;
	}

	std::cout << "\nWhich one do you want to change?\n";
	int choice = 0;

	Word word;

	try
	{
		std::cin >> choice;
		if (!word.readWord(choice))
		{
			throw 20;
		}
	}
	catch (int error)
	{
		std::cout << "Error!\n";

		FILE* file = fopen(LOGFILE, "a+");
		char log[100] = {};

		char* er = new char[2];
		_itoa(error, er, 10);

		strcat(log, "Error ");
		strcat(log, er);

		if (error == 20)
			strcat(log, " there`s not such word in dictionary.");

		fputs(log, file);
		fputc('\n', file);
		system("pause");
		return;
	}

	word.setWord();
	word.writeWord(choice);
	updWords();
	std::cout << "\nDone!\n";
	system("pause");
}

void deleteWord()
{
	system("cls");
	std::cout << "DELETE WORD\n\n";
	if (showWords() == 0)
	{
		std::cout << "There`s nothing to delete!\n";
		system("pause");
		return;
	}

	std::cout << "\nWhich one do you want to delete?\n";
	int choice = 0;

	Word word;

	try
	{
		std::cin >> choice;
		if (!word.readWord(choice))
		{
			throw 20;
		}
	}
	catch (int error)
	{
		std::cout << "Error!\n";

		FILE* file = fopen(LOGFILE, "a+");
		char log[100] = {};

		char* er = new char[2];
		_itoa(error, er, 10);

		//time
		struct tm* u;
		char logTime[40] = {};
		const time_t timer = time(NULL);
		u = localtime(&timer);
		strftime(logTime, 40, "%d.%m.%Y %H:%M:%S ", u);

		strcat(log, logTime);
		strcat(log, " error ");
		strcat(log, er);

		if (error == 20)
			strcat(log, " there`s not such word in dictionary.");

		fputs(log, file);
		fputc('\n', file);
		return;
	}

	word.deleteWord(choice);
	updWords();
	std::cout << "\nDone!\n";
	system("pause");
}

void showWordsByList()
{
	List list;
	Word word;
	int i = 1;
	while (word.readWord(i))
	{
		list.push_back(word);
		i++;
	}
	list.show();
}

std::cout << "Error!\n";

FILE* file = fopen(LOGFILE, "a+");
char log[100] = {};

char* er = new char[2];
_itoa(error, er, 10);

//time
struct tm* u;
char logTime[40] = {};
const time_t timer = time(NULL);
u = localtime(&timer);
strftime(logTime, 40, "%d.%m.%Y %H:%M:%S ", u);

strcat(log, logTime);
strcat(log, " error ");
strcat(log, er);

if (error == 20)
strcat(log, " there`s not such word in dictionary.");

fputs(log, file);
fputc('\n', file);
return;*/
