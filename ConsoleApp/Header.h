#include <iostream>
#include <fstream>
#include <string>
#include <windows.h> 
//#include <cstring>
#include <conio.h>

using namespace std;

struct Initial
{
	string F;
	string I;
	string O;
}; 
struct Auto 
{
	int NumberPlace;
	string KindOfAuto;
	string NumberAuto;
	bool payment; 
	bool AvailabilityAuto;
};
struct Data
{
	Initial _initial;
	Auto AutoInform;

};
//прототипы функций
void DataEntry(Data* (&d), int& n); // ввод данных вручную
void DateReading(Data* (&d), int& n, string fileName); // чтение данных из файла
void Print(Data* d, int n); //вывод данных
void SavingData(Data* d, int n, string fileName);//сохранение данных
void Copy(Data* (&d_n), Data* (&d_N), int n);//копия данных 
void AddData(Data* (&d), int& n);//добавление данных
void DeleteData(Data* (&d), int& n);//удаление данных
void DataChange(Data* (&d), int& n); //изменение данных
void PrintPayment(Data* d, int n); //вывод не оплативших за пользование автостоянкой
void PrintPlace(Data* d, int n);//вывод свободных мест