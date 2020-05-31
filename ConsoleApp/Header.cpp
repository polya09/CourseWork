#include "Header.h"

void DataEntry(Data* (&d), int& n){
	cout << "������� ��������� ������:	";
	cin >> n;

	d = new Data[n];
	for (int i = 0; i < n; i++) 
	{
		cout << "������� ���:	";
		cin >> d[i]._initial.F;
		cin >> d[i]._initial.I;
		cin >> d[i]._initial.O;
		cout << "������� ����� ������������ �����:	";
		cin >> d[i].AutoInform.NumberPlace;
		cout << "����� �������:	";
		cin >> d[i].AutoInform.KindOfAuto;
		cout << "����� ������:	";
		cin >> d[i].AutoInform.NumberAuto;
		cout << "������� �� ������:	";
		cin >> d[i].AutoInform.payment;
		cout << "������� � ��������� ������ �� �����������:	";
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
		cout << "������ �������! " << endl;
	}
	else
		cout << "������ �������� �����!" << endl;
	reading.close();
}
void Print(Data* d, int n) 
{
	for (int i = 0; i < n; i++) {

		cout << "����� �������� � ����: " << i + 1 << endl;
		cout << "��� :	" << d[i]._initial.F << "	" << d[i]._initial.I << "	" << d[i]._initial.O << endl;
		cout << "����� ������������ �����: " << d[i].AutoInform.NumberPlace << endl;
		cout << "����� ������: " << d[i].AutoInform.KindOfAuto << endl;
		cout << "����� ������: " << d[i].AutoInform.NumberAuto << endl;
		cout << "������� �� ������: " << d[i].AutoInform.payment << endl;
		cout << "������� � ��������� ������ �� �����������: " << d[i].AutoInform.AvailabilityAuto << endl;
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
		cout << "������ ���������! " << endl;
	}
	else
		cout << "������ �������� �����! " << endl;
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
	cout << endl << "������� ���:	";
	cin >> d[n]._initial.F;
	cin >> d[n]._initial.I;
	cin >> d[n]._initial.O;

	cout << "����� ������������ �����:";
	cin >> d[n].AutoInform.NumberPlace;
	cout << "����� �������: " ;
	cin >> d[n].AutoInform.KindOfAuto; 
	cout << "����� ������: " ;
	cin >> d[n].AutoInform.NumberAuto;
	cout << "������� � ������: " ;
	cin >> d[n].AutoInform.payment;
	cout << "������� � ��������� ������ �� �����������: " ;
	cin >> d[n].AutoInform.AvailabilityAuto;
	system("cls");
	cout << "������ ���������!" << endl;
	delete[]buf;
}
void DeleteData(Data* (&d), int& n) {
	int _n;
	string f;
	cout << "������� ������� ��� �������� ������: ";
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
		cout << "������ �������!" << endl;
	}
	else {
		cout << "����� ������ �� �����!" << endl;
	}
}
void DataChange(Data* (&d), int& n)
{
	int _n, number;
	cout << "������� ����� �������� � ����(�� 1 �� " << n << "): ";
	cin >> _n;
	_n--;
	system("cls");
	if (_n >= 0 && _n < n) {
		cout << "��������: " << endl;
		cout << "(1) ���" << endl;
		cout << "(2) ����� ������������ �����" << endl;
		cout << "(3) ����� ������" << endl;
		cout << "(4) ����� ������" << endl;
		cout << "(5) ������� � ������" << endl;
		cout << "(6) ������� � ������� ������ �� �����������" << endl;
		cout << ">>>	";
		cin >> number;
			switch (number)
			{
			case 1:

				system("cls");
				cout << "������� ���:	";
				cin >> d[_n]._initial.F;
				cin >> d[_n]._initial.I;
				cin >> d[_n]._initial.O;
				cout << "������ ��������! " << endl;
				break;
			case 2:
				system("cls");
				cout << "������� ����� ������������ �����:	";
				cin >> d[_n].AutoInform.NumberPlace;
				cout << "������ ��������! " << endl;
				break;
			case 3:
				system("cls");
				cout << "������� ����� ������:	";
				cin >> d[_n].AutoInform.KindOfAuto;
				cout << "������ ��������! " << endl;
				break;
			case 4:
				system("cls");
				cout << "������� ����� ������:	";
				cin >> d[_n].AutoInform.NumberAuto;
				cout << "������ ��������! " << endl;
				break;
			case 5:
				system("cls");
				cout << "������� ������� � ������:	";
				cin >> d[_n].AutoInform.payment;
				cout << "������ ��������! " << endl;
				break;
			case 6:
				system("cls");
				cout << "������� ������� � ������� ������ �� �����������:	";
				cin >> d[_n].AutoInform.AvailabilityAuto;
				cout << "������ ��������! " << endl;
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
			cout << "����� �������� � ����: " << i + 1 << endl;
			cout << "��� :	" << d[i]._initial.F << "	" << d[i]._initial.I << "	" << d[i]._initial.O << endl;
			cout << "����� ������������ �����: " << d[i].AutoInform.NumberPlace << endl;
			cout << "����� ������: " << d[i].AutoInform.KindOfAuto << endl;
			cout << "����� ������: " << d[i].AutoInform.NumberAuto << endl;
			cout << "������� �� ������: " << d[i].AutoInform.payment << endl;
			cout << "������� � ��������� ������ �� �����������: " << d[i].AutoInform.AvailabilityAuto << endl;
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
