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
	dict d1;
	int cnt1 = 0, cnt2 = 0;
	int choice = 0;
	bool iWant = 1;
	ifstream file("words.bin");
	if (!file.is_open()) {
		ofstream file1("words.bin", ios::binary);
		file1.close();
	}
	else file.close();

	while (iWant) {
		dict d;
		cnt2 = 0;
		ofstream f("words.bin", ios::binary | ios::app);
		bool moreTranslations = 1;
		cout << "Enter in English: ";
		if (cnt1 != 0) {
			while (cin.get() != '\n');
		}
		cin.getline(d.angl, 100);
		while (moreTranslations) {
			cout << "Enter in Russian (translation or description): ";
			if (cnt2 != 0) {
				while (cin.get() != '\n');
			}
			cin.getline(d.rus, 100);
			f.write((char*)& d, sizeof(dict));
			system("cls");
			cin.clear();
			cout << "Are there any more translations for word (" << d.angl << ") ?\n1 --> Yes\n2 --> No\n";
			do {
				cin >> choice;
			} while (choice != 1 && choice != 2);
			switch (choice) {
			case 1: {
				cnt2++;
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
		do {
			cin >> choice;
		} while (choice != 1 && choice != 2); choice;
		switch (choice) {
		case 1: {
			cnt1++; cnt2++;
			iWant = 1;
			//delete d;
			system("cls");
			break;
		}
		case 2:iWant = 0; break;
		}

	}

	return;
}

dict* Words_read(int& count)
{
	int cnt = 0;
	dict d;
	ifstream f("words.bin", ios::binary);
	while (f.read((char*)& d, sizeof(dict))) {
		cnt++;
	}
	count = cnt;
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

void Words_delete()
{
	int count = 0;
	if (Words_read(count) == NULL) {
		cout << "File is empty!\n";
		system("pause");
		return;
	}
	else {
		NodeList* great = new NodeList;
		system("pause");
		char key[100];
		ifstream f("words.bin", ios::binary);
		dict* mas = new dict[count];

		for (int i = 0; i < count; ++i) {
			f.read((char*)& mas[i], sizeof(dict));
		}
		f.close();
		for (int i = 0; i < count; ++i) {
			great->addLast(mas[i]);
		}
		cout << "\nWhich word would you like to delete?\n";
		cin.getline(key, 100);
		int cnt = 0;
		bool isFound = 0;
		Node* cur = great->head;
		for (int i = 0; i < count; ++i) {
			if (!strcmp(key, cur->info.angl)) {
				isFound = 1;
				cnt++;
			}
			cur = cur->next;
		}
		if (isFound == 1) {
			if (cnt == count) {
				ofstream f1("words.bin", ios::binary);
				f1.close();
				system("cls");
				cout << "Remove completed!\n";
				system("pause");
			}
			else {
				for (int i = 0; i < cnt; ++i) {
					great->remove_complete(key);
				}
				ofstream f1("words.bin", ios::binary);
				if (great->head != NULL) {
					cur = great->head;
					while (cur) {
						f1.write((char*)& cur->info, sizeof(dict));
						cur = cur->next;
					}
					system("cls");
					cout << "Remove completed!\n";
					system("pause");
					f1.close();
				}
				else {
					system("cls");
					cout << "Now there are no words in file!\n";
					system("pause");
					f1.close();
				}
			}
		}
		else {
			system("cls");
			cout << "No such word!\n";
			system("pause");
		}
		delete great, cur;
	}
}

void Words_upd()
{
	int count = 0;
	system("cls");
	if (Words_read(count) == NULL) {
		cout << "File is empty!\n";
		system("pause");
		return;
	}
	else {
		NodeList* list = new NodeList;
		dict d;
		system("pause");
		char key[100];
		cout << "\nWhich word and all its translations would you like to find?\nWord-target: ";
		cin.getline(key, 100);
		ifstream f("words.bin", ios::binary);
		dict* mas = new dict[count];

		for (int i = 0; i < count; ++i) {
			f.read((char*)& mas[i], sizeof(dict));
		}
		f.close();
		bool isFound = 0;
		int number = 0;
		for (int i = 0; i < count; ++i) {
			if (!strcmp(key, mas[i].angl)) {
				number = i;
				isFound = 1;
				strcpy(d.angl, key);
				for (int j = 0; j < i; ++j) {
					list->addLast(mas[j]);
				}
				break;
			}
		}
		if (isFound) {
			system("cls");
			int tmp = 0;
			cout << "In English: " << d.angl << endl;
			bool moreTranslations = 1;
			while (moreTranslations) {
				cout << "Enter translation: ";
				if (tmp != 0) {
					while (cin.get() != '\n');
				}
				cin.getline(d.rus, 100);
				list->addLast(d);
				int choice = 0;
				system("cls");
				cin.clear();
				cout << "Are there any more translations for word (" << d.angl << ") ?\n1 --> Yes\n2 --> No\n";
				do {
					cin >> choice;
				} while (choice != 1 && choice != 2);
				switch (choice) {
				case 1: {
					system("cls");
					tmp = 1;
					cout << "In English: " << d.angl << endl;
					break;
				}
				case 2:moreTranslations = 0; break;
				}
			}
			for (int i = number + 1; i < count; ++i) {
				if (strcmp(key, mas[i].angl) != 0) {
					int j = i;
					while (i != count) {
						list->addLast(mas[j]);
						j++;
					}
					break;
				}
			}
			ofstream f1("words.bin", ios::binary);
			Node* cur = list->head;
			while (cur) {
				f1.write((char*)& cur->info, sizeof(dict));
				cur = cur->next;
			}
			cout << "Update completed!\n";
			system("pause");
			f1.close();
			delete cur, list;
			return;
		}
		else {
			system("cls");
			cout << "No such word!\n";
			system("pause");
			delete list;
			return;
		}

	}
}

void Words_find()
{
	int count = 0;
	system("cls");
	if (Words_read(count) == NULL) {
		cout << "File is empty!\n";
		system("pause");
		return;
	}
	else {
		NodeList* list = new NodeList;
		system("pause");
		char key[100];
		cout << "\nWhich word and all its translations would you like to find?\nWord-target: ";
		cin.getline(key, 100);
		ifstream f("words.bin", ios::binary);
		dict* mas = new dict[count];

		for (int i = 0; i < count; ++i) {
			f.read((char*)& mas[i], sizeof(dict));
		}
		f.close();
		for (int i = 0; i < count; ++i) {
			if (!strcmp(key, mas[i].angl)) {
				list->addLast(mas[i]);
			}
		}

		system("cls");
		if (list->head != NULL) {
			cout << "Here are all translations to the word " << list->head->info.angl << ":\n";
			list->Print();
			cout << endl;
			cout << "First translation: " << list->head->info.rus << endl;
			cout << "Last translation: " << list->tail->info.rus << endl;
			system("pause");
		}
		else {
			cout << "There is no such word in file!\n";
			system("pause");
		}
		delete mas, list;
		return;
	}
}
