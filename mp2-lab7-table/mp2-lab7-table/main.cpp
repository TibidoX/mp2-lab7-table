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

	cout << "Ќачальна€ таблица: \n";
	table->Print(cout);
}

void InsertIntoTable()
{
	TRecord rec;
	cout << "¬ведите ключ и запись " << endl;
	cin >> rec.key >> rec.val;


	eff = table->GetEff();
	if (table->Insert(rec)) {
		cout << "¬ставка выполнена" << endl;
	}
	else {
		cout << "¬ставка не выполнена" << endl;
	}
	cout << "Ёффективность:\n" << table->GetEff() - eff << endl;
}

void FindKey()
{
	TKey key;
	cout << "¬ведите ключ дл€ поиска " << endl;
	cin >> key;

	eff = table->GetEff();
	if (table->Find(key)) {
		cout << "Ёлемент найден" << endl;
	}
	else {
		cout << "Ёлемент не найден" << endl;
	}
	cout << "Ёффективность:\n" << table->GetEff() - eff << endl;
}

void DeleteKey()
{
	TKey key;
	cout << "¬ведите ключ дл€ удалени€ " << endl;
	cin >> key;

	eff = table->GetEff();
	if (table->Delete(key)) {
		cout << "Ёлемент удален" << endl;
	}
	else {
		cout << "Ёлемент не удален" << endl;
	}
	cout << "Ёффективность:\n" << table->GetEff() - eff << endl;

}

void main() {
	int n = 0;
	setlocale(LC_ALL, "Russian");
	int type, size;
	do {
		cout << "1. —оздать таблицу " << endl;
		cout << "2. ¬ставить в таблицу " << endl;
		cout << "3. Ќайти в таблице " << endl;
		cout << "4. ”далить из таблицы " << endl;
		cout << "5. ѕечать таблицы" << endl;
		cout << "0. ¬ыход " << endl;
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
			cout << "¬ведите тип таблицы: " << endl;
			cin >> type;
			cout << "¬ведите размер таблицы: " << endl;
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

