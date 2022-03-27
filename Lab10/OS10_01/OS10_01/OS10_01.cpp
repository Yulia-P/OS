#include <iostream>
#include "HT.h"
using namespace std;
using namespace HT;
void printStr(char* str);
int main()
{
	//2. HT-хранилище (HT): программная система, предназначенная для хранения данных в формате ключ/значение. 
	//Для хранения данных в HT используется файл на диске и образ этого файла в оперативной памяти. Операции с данными (Insert, Delete, Update, Get) выполняются с образом. 
	//Сохранность данных осуществляется с помощью snapshot- механизма (с заданным периодом асинхронное сохранение образа в файле), snapshot может выполняться  синхронно по команде пользователя.
	const wchar_t* fileName = L"C:\\Users\\37529\\Documents\\GitHub\\OS\\Lab10\\OS10_01\\lab1.ht";
	try {
		int capacity = 10;
		int snapshotIntervalSec = 3;
		int maxKeyLength = 10;
		int maxPayloadLength = 10;
		HTHANDLE* HT = Create(capacity, snapshotIntervalSec, maxKeyLength, maxPayloadLength, fileName);
		//HTHANDLE* HT = Open(fileName);
		if (HT == NULL)
			throw "Invalid handle";

		Element* el1 = new Element("key",    4, "string1",    6);
		Element* el2 = new Element("keykey", 7, "string22",   7);
		Element* el3 = new Element("string", 7, "string333",  8);
		Element* el4 = new Element("strstr", 7, "string4444", 9);
#pragma region INSERT

		if (!Insert(HT, el1)) {
			printStr(GetLastError(HT));
		}
		if (!Insert(HT, el2)) {
			printStr(GetLastError(HT));
		}
		if (!Insert(HT, el3)) {
			printStr(GetLastError(HT));
		}
		if (!Insert(HT, el4)) {
			printStr(GetLastError(HT));
		}

#pragma endregion
		Element* el;
		cout << "INSERT" << endl;
#pragma region GET AFTER INSERT
		if ((el = Get(HT, el1)) == NULL)
			printStr(GetLastError(HT));
		else
			print(el);
		if ((el = Get(HT, el2)) == NULL)
			printStr(GetLastError(HT));
		else
			print(el);
		if ((el = Get(HT, el3)) == NULL)
			printStr(GetLastError(HT));
		else
			print(el);
		if ((el = Get(HT, el4)) == NULL)
			printStr(GetLastError(HT));
		else
			print(el);

		cout << "_____________________" << endl;
#pragma endregion

#pragma region UPDATE
		if (!Update(HT, el1, el3->payload, el3->payloadlength)) {
			printStr(GetLastError(HT));
		}
		if (!Update(HT, el4, el3->payload, el3->payloadlength)) {
			printStr(GetLastError(HT));
		}
#pragma endregion
		if (!Snap(HT))
			printStr(GetLastError(HT));
		cout << "\nUPDATE" << endl;
#pragma region GET AFTER UPDATE
		if ((el = Get(HT, el1)) == NULL)
			printStr(GetLastError(HT));
		else
			print(el);
		if ((el = Get(HT, el2)) == NULL)
			printStr(GetLastError(HT));
		else
			print(el);
		if ((el = Get(HT, el3)) == NULL)
			printStr(GetLastError(HT));
		else
			print(el);
		cout << "_____________________" << endl;
#pragma endregion
		Sleep(10000);
#pragma region DELETE
		if (!Delete(HT, el1)) {
			printStr(GetLastError(HT));
		}
		if (!Delete(HT, el2)) {
			printStr(GetLastError(HT));
		}
		if (!Delete(HT, el3)) {
			printStr(GetLastError(HT));
		}
		if (!Delete(HT, el4)) {
			printStr(GetLastError(HT));
		}
#pragma endregion
		cout << "\nDELETE" << endl;
#pragma region GET3
		if ((el = Get(HT, el1)) == NULL)
			printStr(GetLastError(HT));
		else
			print(el);
		if ((el = Get(HT, el2)) == NULL)
			printStr(GetLastError(HT));
		else
			print(el);
		if ((el = Get(HT, el3)) == NULL)
			printStr(GetLastError(HT));
		else
			print(el);
		cout << "_____________________" << endl;


		if (Close(HT))
			cout << "\nClose storage\n";
		delete el1;
		delete el2;
		delete el3;
		delete el4;
		delete el;
	}
	catch (const char* mess) {
		cout << mess << endl;
	}

	system("pause");
	return 0;
}
void printStr(char* str) {
	cout << "ERROR:\t" << str << endl;
}