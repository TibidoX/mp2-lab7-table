#include "TTable.h"
#include "TScanTable.h"
#include "TSortTable.h"
#include "TArrayTable.h"
#include "TArrayHash.h"
#include "TTreeTable.h"
#include "TBalTree.h"
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <locale>
using namespace std;

TTable* table;
bool result = true;
int eff = 0;

void CreateTable(int _type ,int _size)
{
	switch (_type)
	{
	case 1: {
		table = new TScanTable(_size);
		break;
	}

	case 2: {
		table = new TSortTable(_size);
		break;
	}

	case 3: {
		table = new TArrayHash(_size);
		break;
	}

	case 4: {
		table = new TTreeTable();
		break;
	}
	case 5: {
		table = new TBalTree();
		break;
	}
	default:
		break;
	}

	srand(time(NULL));

	TRecord insertRec;

	

	for (int i = 0; i < _size; i++) {
		/*insertRec.key = rand() % 100;
		string str = "record#" + to_string(i);
		insertRec.val = str;
		table->Insert(insertRec);*/

		bool is_inserted = false;
		while (is_inserted != true)
		{
			insertRec.key = rand() % 100;
			insertRec.val = std::string("record#") + std::to_string(i);
			is_inserted = table->Insert(insertRec);
		}
	}

	cout << "��������� �������: \n";
	table->Print(cout);
}

void InsertIntoTable()
{
	TRecord rec;
	cout << "������� ���� � ������ " << endl;
	cin >> rec.key >> rec.val;


	eff = table->GetEff();
	if (table->Insert(rec)) {
		cout << "������� ���������" << endl;
	}
	else {
		cout << "������� �� ���������" << endl;
	}
	cout << "�������������:\n" << table->GetEff() - eff << endl;
}

void FindKey()
{
	TKey key;
	cout << "������� ���� ��� ������ " << endl;
	cin >> key;

	eff = table->GetEff();
	if (table->Find(key)) {
		cout << "������� ������" << endl;
	}
	else {
		cout << "������� �� ������" << endl;
	}
	cout << "�������������:\n" << table->GetEff() - eff << endl;
}

void DeleteKey()
{
	TKey key;
	cout << "������� ���� ��� �������� " << endl;
	cin >> key;

	eff = table->GetEff();
	if (table->Delete(key)) {
		cout << "������� ������" << endl;
	}
	else {
		cout << "������� �� ������" << endl;
	}
	cout << "�������������:\n" << table->GetEff() - eff << endl;

}

void main() {
	int n = 0;
	setlocale(LC_ALL, "Russian");
	int type, size;
	do {
		cout << "1. ������� ������� " << endl;
		cout << "2. �������� � ������� " << endl;
		cout << "3. ����� � ������� " << endl;
		cout << "4. ������� �� ������� " << endl;
		cout << "5. ������ �������" << endl;
		cout << "0. ����� " << endl;
		cin >> n;

		switch (n)
		{
		case 1:
		{
			cout << "1. TScanTable " << endl;
			cout << "2. TSortTable " << endl;
			cout << "3. THashTable " << endl;
			cout << "4. TTreeTable " << endl;
			cout << "5. TBalTree " << endl;
			cout << "������� ��� �������: " << endl;
			cin >> type;
			cout << "������� ������ �������: " << endl;
			cin >> size;
			CreateTable(type, size);
			break;
		}
		case 2:
		{
			InsertIntoTable();
			break;
		}
		case 3:
		{
			FindKey();
			break;
		}
		case 4:
		{
			DeleteKey();
			break;
		}
		case 5:
		{
			table->Print(cout);
			break;
		}
		default:
			break;
		}
	} while (n != 0);


}

