#include "Header.h"

void DataEntry(Data* (&d), int& n){
	cout << "Введите количесто данных:	";
	cin >> n;

	d = new Data[n];
	for (int i = 0; i < n; i++) 
	{
		cout << "Введите ФИО:	";
		cin >> d[i]._initial.F;
		cin >> d[i]._initial.I;
		cin >> d[i]._initial.O;
		cout << "Введите номер парковочного места:	";
		cin >> d[i].AutoInform.NumberPlace;
		cout << "Марка машинны:	";
		cin >> d[i].AutoInform.KindOfAuto;
		cout << "Номер машины:	";
		cin >> d[i].AutoInform.NumberAuto;
		cout << "Отметка об оплате:	";
		cin >> d[i].AutoInform.payment;
		cout << "Отметка о наявности машины на автостоянке:	";
		cin >> d[i].AutoInform.AvailabilityAuto;
		cout << "_____________________________________" << endl;
	}

}
void DateReading(Data* (&d), int& n, string fileName) {
	ifstream reading(fileName);
	if (reading) {
		reading >> n;
		d = new Data[n];
		for (int i = 0; i < n; i++) { 

			reading >> d[i]._initial.F;
			reading >> d[i]._initial.I;
			reading >> d[i]._initial.O;

			reading >> d[i].AutoInform.NumberPlace;
			reading >> d[i].AutoInform.KindOfAuto;
			reading >> d[i].AutoInform.NumberAuto;
			reading >> d[i].AutoInform.payment;
			reading >> d[i].AutoInform.AvailabilityAuto;
		}
		cout << "Данные считаны! " << endl;
	}
	else
		cout << "Ошибка открытия файла!" << endl;
	reading.close();
}
void Print(Data* d, int n) 
{
	for (int i = 0; i < n; i++) {

		cout << "Номер элемента в базе: " << i + 1 << endl;
		cout << "ФИО :	" << d[i]._initial.F << "	" << d[i]._initial.I << "	" << d[i]._initial.O << endl;
		cout << "Номер парковочного места: " << d[i].AutoInform.NumberPlace << endl;
		cout << "Марка машины: " << d[i].AutoInform.KindOfAuto << endl;
		cout << "Номер машины: " << d[i].AutoInform.NumberAuto << endl;
		cout << "Отметка об оплате: " << d[i].AutoInform.payment << endl;
		cout << "Отметка о наявности машины на автостоянке: " << d[i].AutoInform.AvailabilityAuto << endl;
		cout << "_____________________________________" << endl;
	}
}
void SavingData(Data * d, int n, string fileName) {
	ofstream record(fileName, ios::out);
	if (record) {
		record << n << endl;
		for (int i = 0; i < n; i++)
		{
			record << d[i]._initial.F << endl;
			record << d[i]._initial.I << endl;
			record << d[i]._initial.O << endl;

			record << d[i].AutoInform.NumberPlace << endl;
			record << d[i].AutoInform.KindOfAuto << endl;
			record << d[i].AutoInform.NumberAuto << endl;
			record << d[i].AutoInform.payment << endl;
			if (n - 1) {
				record << d[i].AutoInform.AvailabilityAuto << endl;
			}
			else
				record << d[i].AutoInform.AvailabilityAuto;
		}
		cout << "Данные сохранены! " << endl;
	}
	else
		cout << "Ошибка открытия файла! " << endl;
	record.close();
}
void Copy(Data* (&d_n), Data* (&d_N), int n) {
	for (int i = 0; i < n; i++) {
		d_n[i] = d_N[i];
	}
}
void AddData(Data* (&d), int& n) {
	Data* buf;
	buf = new Data[n];
	Copy(buf, d, n); 
	n++;
	d = new Data[n];

	Copy(d, buf, --n);
	cout << endl << "Введите ФИО:	";
	cin >> d[n]._initial.F;
	cin >> d[n]._initial.I;
	cin >> d[n]._initial.O;

	cout << "Номер парковочного места:";
	cin >> d[n].AutoInform.NumberPlace;
	cout << "Марка машинны: " ;
	cin >> d[n].AutoInform.KindOfAuto; 
	cout << "Номер машины: " ;
	cin >> d[n].AutoInform.NumberAuto;
	cout << "Отметка о оплате: " ;
	cin >> d[n].AutoInform.payment;
	cout << "Отметка о наявности машины на автостоянке: " ;
	cin >> d[n].AutoInform.AvailabilityAuto;
	system("cls");
	cout << "Данные добавлены!" << endl;
	delete[]buf;
}
void DeleteData(Data* (&d), int& n) {
	int _n;
	string f;
	cout << "Введите фамилию для удаления данных: ";
	cin >> f;
	for (int i = 0; i <= n; i++) {
		if (f == d[i]._initial.F) {
			_n = i;
		}
	}
	system("cls");
	if (_n >= 0 && _n < n) {
		Data* buf = new Data[n];
		Copy(buf, d, n);
		--n;
		d = new Data[n];
		int q = 0;
		for (int i = 0; i <= n; i++) {
			if (i != _n) {
				d[q] = buf[i];
				++q;
			}
		}
		system("cls");
		delete[]buf;
		cout << "Данные удалены!" << endl;
	}
	else {
		cout << "Номер введен не верно!" << endl;
	}
}
void DataChange(Data* (&d), int& n)
{
	int _n, number;
	cout << "Введите номер элемента в базе(от 1 до " << n << "): ";
	cin >> _n;
	_n--;
	system("cls");
	if (_n >= 0 && _n < n) {
		cout << "Изменить: " << endl;
		cout << "(1) ФИО" << endl;
		cout << "(2) Номер парковочного места" << endl;
		cout << "(3) Марку машины" << endl;
		cout << "(4) Номер машины" << endl;
		cout << "(5) Отметку о оплате" << endl;
		cout << "(6) Отметку о наличии машины на автостоянке" << endl;
		cout << ">>>	";
		cin >> number;
			switch (number)
			{
			case 1:

				system("cls");
				cout << "Введите ФИО:	";
				cin >> d[_n]._initial.F;
				cin >> d[_n]._initial.I;
				cin >> d[_n]._initial.O;
				cout << "Данные изменены! " << endl;
				break;
			case 2:
				system("cls");
				cout << "Введите номер парковочного места:	";
				cin >> d[_n].AutoInform.NumberPlace;
				cout << "Данные изменены! " << endl;
				break;
			case 3:
				system("cls");
				cout << "Введите марку машины:	";
				cin >> d[_n].AutoInform.KindOfAuto;
				cout << "Данные изменены! " << endl;
				break;
			case 4:
				system("cls");
				cout << "Введите номер машины:	";
				cin >> d[_n].AutoInform.NumberAuto;
				cout << "Данные изменены! " << endl;
				break;
			case 5:
				system("cls");
				cout << "Введите отметку о оплате:	";
				cin >> d[_n].AutoInform.payment;
				cout << "Данные изменены! " << endl;
				break;
			case 6:
				system("cls");
				cout << "Введите отметку о наличии машины на автостоянке:	";
				cin >> d[_n].AutoInform.AvailabilityAuto;
				cout << "Данные изменены! " << endl;
				break;
			default:
				cout << " " << endl;
				system("pause");
				system("cls");
				break;
			}
		
	}
}
void PrintPayment(Data* d, int n) {
	for (int i = 0; i < n; i++) {
		if (d[i].AutoInform.payment == 0) {
			cout << "Номер элемента в базе: " << i + 1 << endl;
			cout << "ФИО :	" << d[i]._initial.F << "	" << d[i]._initial.I << "	" << d[i]._initial.O << endl;
			cout << "Номер парковочного места: " << d[i].AutoInform.NumberPlace << endl;
			cout << "Марка машины: " << d[i].AutoInform.KindOfAuto << endl;
			cout << "Номер машины: " << d[i].AutoInform.NumberAuto << endl;
			cout << "Отметка об оплате: " << d[i].AutoInform.payment << endl;
			cout << "Отметка о наявности машины на автостоянке: " << d[i].AutoInform.AvailabilityAuto << endl;
			cout << "_____________________________________" << endl;
		}
	}
}
void PrintPlace(Data* d, int n) 
{
	int number = 30, p;
	for (int i = 1; i <= number; i++)
	{
		p = 0;
		for (int j = 0; j < n; j++)
		{
			if (i == d[j].AutoInform.NumberPlace) { p = 1; break; }
		}
		if (!p) cout << i << " ";
	}
	cout << "\n";
}
