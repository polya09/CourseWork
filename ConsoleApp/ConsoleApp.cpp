#include "Header.h"
void color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void gotoxy(int x, int y) {
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
int Set[] = { 7,7,7,7,7,7,7,7,7,7 };

void Menu() {
	gotoxy(15, 6);
	color(Set[0]);
	cout << "(1) Импортировать базу";

	gotoxy(15, 7);
	color(Set[1]);
	cout << "(2) Создать нову базу";

	gotoxy(15, 8);
	color(Set[2]);
	cout << "(3) Изменить данные";

	gotoxy(15, 9);
	color(Set[3]);
	cout << "(4) Добавить новую запись в базу";

	gotoxy(15, 10);
	color(Set[4]);
	cout << "(5) Удалить из базы владельца с указано фамилией";

	gotoxy(15, 11);
	color(Set[5]);
	cout << "(6) Вывод всех данных";

	gotoxy(15, 12);
	color(Set[6]);
	cout << "(7) Вывести не оплативших за пользование автостоянки";

	gotoxy(15, 13);
	color(Set[7]);
	cout << "(8) Вывести свободные места";

	gotoxy(15, 14);
	color(Set[8]);
	cout << "(9) Сохранение";

	gotoxy(15, 15);
	color(Set[9]);
	cout << "(10) Выход";

	gotoxy(12, 21);
	HANDLE hOUTPUT = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hOUTPUT, FOREGROUND_GREEN | FOREGROUND_BLUE);
	cout << "Выберите пункт меню стрелками Вверх, Вниз и нажмите Enter" << endl;
	SetConsoleTextAttribute(hOUTPUT, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
}
int main() {
	SetConsoleCP(1251); //установка кодовой страницы win-cp 1251 в поток ввода
	SetConsoleOutputCP(1251); //установка кодовой страницы win-cp 1251 в поток вывода
	Menu();

	int amoundOfData = 0;
	string fileName;
	Data* d = new Data[amoundOfData];
	int counter = 1;
	char key;
	while (counter <= 10)
	{
		Menu();
		key = _getch();

		if (key == 72 && (counter >= 2 && counter <= 10)) {
			counter--;
		}
		if (key == 80 && (counter >= 1 && counter <= 9)) {
			counter++;
		}
		switch (counter)
		{
		case 1:
			if (key == '\r') {
				system("cls");
				cout << "Введите название файла (Например: Input.txt): " << endl;
				cin >> fileName;
				DateReading(d, amoundOfData, fileName);
				system("pause");
				system("cls");
				Menu();
			}
			break;
		case 2:
			if (key == '\r') {
				system("cls");
				DataEntry(d, amoundOfData);
				system("pause");
				system("cls");
				Menu();
			}
			break;
		case 3:
			if (key == '\r') {
				system("cls");
				if (amoundOfData != 0) {
					DataChange(d, amoundOfData);
				}
				system("pause");
				system("cls");
				Menu();
			}
			break;
		case 4:
			if (key == '\r') {
				system("cls");
				if (amoundOfData != 0) {
					AddData(d, amoundOfData);
					amoundOfData++;
				}
				else {
					cout << "Данные пусты!" << endl;
				}
				system("pause");
				system("cls");
				Menu();
			}
			break;
		case 5:
			if (key == '\r') {
				system("cls");
				if (amoundOfData != 0) {
					DeleteData(d, amoundOfData);
				}
				else
					cout << "Данные пусты!" << endl;
				system("pause");
				system("cls");
				Menu();
			}
			break;
		case 6:
			if (key == '\r') {
				system("cls");
				if (amoundOfData != 0) {
					Print(d, amoundOfData);
				}
				else {
					cout << "Данные пусты!" << endl;
				}
				system("pause");
				system("cls");
				Menu();
			}
			break;
		case 7:
			if (key == '\r') {
				system("cls");
				if (amoundOfData != 0) {
					PrintPayment(d, amoundOfData);
				}
				else {
					cout << "Данные пусты!" << endl;
				}
				system("pause");
				system("cls");
				Menu();
			}
			break;
		case 8:
			if (key == '\r') {
				system("cls");
				if (amoundOfData != 0) {
					PrintPlace(d, amoundOfData);
				}
				system("pause");
				system("cls");
				Menu();
			}
			break;
		case 9:
			if (key == '\r') {
				system("cls");
				cout << "Введите название файла (Например: Input.txt):	";
				cin >> fileName;
				if (amoundOfData != 0) {
					SavingData(d, amoundOfData, fileName);
				}
				else {
					cout << "Данные пусты! " << endl;
				}
				system("pause");
				system("cls");
				Menu();
			}
			break;
		case 10:
			if (key == '\r') {
				system("cls");
				exit(0);
			}
			break;
		default:
			cout << " " << endl;
			system("pause");
			system("cls");
			Menu();
			break;
		}
		for (int i = 0; i < 10; i++) 
		{
		Set[i] = 7;
	    }

	    for (int i = 0; i < 10; i++) 
	    {
			if (counter == i + 1) {
			Set[i] = 3;
		    }
	    }
	}
	return 0;
}