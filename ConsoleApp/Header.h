#include <iostream>
#include <fstream>
#include <string>
#include <windows.h> 
#include <cstring>
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
void DataEntry(Data* (&d), int& n);
void DateReading(Data* (&d), int& n, string fileName);
void Print(Data* d, int n);
void SavingData(Data* d, int n, string fileName);
void Copy(Data* (&d_n), Data* (&d_N), int n);
void AddData(Data* (&d), int& n);
void DeleteData(Data* (&d), int& n);
void DataChange(Data* (&d), int& n); 
void PrintPayment(Data* d, int n); 
void PrintPlace(Data* d, int n);