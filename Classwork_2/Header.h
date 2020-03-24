#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <io.h>
#include <fcntl.h>
#include <fstream>
#include <direct.h>
#include <conio.h>
#include <Windows.h>
#include "List.h"
using namespace std;

void Dictionary_creator();
void Words_add();
dict* Words_read(int& count);
void Words_delete();
void Words_upd();
void Words_find();

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

