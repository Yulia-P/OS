#include "pch.h";
#include <iostream>
#include "OS10_HTAPI.h"

void printStr(char* str);
int main()
 {
	int capacity = 10;
	int capacity2 = 10;
	int snapshotIntervalSec = 2;
	int maxKeyLength = 10;
	int maxKeyLength2 = 10;
	int maxPayloadLength = 10;
	const wchar_t* fileName  = L"C:\\Users\\37529\\Documents\\GitHub\\OS\\Lab10\\OS10_02\\HT\\lab03-1.ht";
	const wchar_t* fileName2 = L"C:\\Users\\37529\\Documents\\GitHub\\OS\\Lab10\\OS10_02\\HT\\lab03-2.ht";
	try {
		HT::HTHANDLE* HT  = HT::Create(capacity, snapshotIntervalSec, maxKeyLength, maxPayloadLength, fileName);
		HT::HTHANDLE* HT2 = HT::Create(capacity2, snapshotIntervalSec, maxKeyLength2, maxPayloadLength, fileName2);

		//HT::HTHANDLE* HT = HT::Open(fileName);
		//HT::HTHANDLE* HT2 = HT::Open(fileName2);
		if (HT == NULL)
			throw "Invalid handle";
		if (HT2 == NULL)
			throw "Invalid handle";

		HT::Element* el1 = new HT::Element("str",    4, "string1",    7);
		HT::Element* el2 = new HT::Element("key123", 7, "string22",   8);
		HT::Element* el3 = new HT::Element("strqq",  4, "string333",  9);
		HT::Element* el4 = new HT::Element("keyq",   5, "string4444", 10);
		//HT1 INSERT
		if (!HT::Insert(HT, el1)) {
			printStr(HT::GetLastError(HT));
		}
		if (!HT::Insert(HT, el2)) {
			printStr(HT::GetLastError(HT));
		}
		if (!HT::Insert(HT, el3)) {
			printStr(HT::GetLastError(HT));
		}
		if (!HT::Insert(HT, el4)) {
			printStr(HT::GetLastError(HT));
		}
		//HT2 INSERT
		if (!HT::Insert(HT2, el1)) {
			printStr(HT::GetLastError(HT));
		}
		if (!HT::Insert(HT2, el2)) {
			printStr(HT::GetLastError(HT));
		}
		if (!HT::Insert(HT2, el3)) {
			printStr(HT::GetLastError(HT));
		}
		if (!HT::Insert(HT2, el4)) {
			printStr(HT::GetLastError(HT));
		}

		//GET HT1
		HT::Element* el;
		std::cout << "-----INSERT1-----" << std::endl;
		if ((el = HT::Get(HT, el1)) == NULL)
			printStr(HT::GetLastError(HT));
		else
			HT::print(el);
		if ((el = HT::Get(HT, el2)) == NULL)
			printStr(HT::GetLastError(HT));
		else
			HT::print(el);
		if ((el = HT::Get(HT, el3)) == NULL)
			printStr(HT::GetLastError(HT));
		else
			HT::print(el);
		if ((el = HT::Get(HT, el4)) == NULL)
			printStr(HT::GetLastError(HT));
		else
			HT::print(el);

		//GET HT 2
		std::cout << "-----INSERT2-----" << std::endl;
		if ((el = HT::Get(HT2, el1)) == NULL)
			printStr(HT::GetLastError(HT));
		else
			HT::print(el);
		if ((el = HT::Get(HT2, el2)) == NULL)
			printStr(HT::GetLastError(HT));
		else
			HT::print(el);
		if ((el = HT::Get(HT2, el3)) == NULL)
			printStr(HT::GetLastError(HT));
		else
			HT::print(el);
		if ((el = HT::Get(HT2, el4)) == NULL)
			printStr(HT::GetLastError(HT));
		else
			HT::print(el);

		//UPDATE HT1
		if (!HT::Update(HT, el1, el3->payload, el3->payloadlength)) {
			printStr(HT::GetLastError(HT));
		}
		if (!HT::Update(HT, el4, el3->payload, el3->payloadlength)) {
			printStr(HT::GetLastError(HT));
		}

		//UPDATE HT2
		if (!HT::Update(HT2, el1, el3->payload, el3->payloadlength)) {
			printStr(HT::GetLastError(HT));
		}
		if (!HT::Update(HT2, el4, el3->payload, el3->payloadlength)) {
			printStr(HT::GetLastError(HT));
		}

		//SNAP HT1
		if (!HT::Snap(HT))
			printStr(HT::GetLastError(HT));
		std::cout << "-----UPDATE1-----" << std::endl;

		//GET AFTER UPDATE HT1
		if ((el = HT::Get(HT, el1)) == NULL) printStr(HT::GetLastError(HT));
		else HT::print(el);

		if ((el = HT::Get(HT, el2)) == NULL) printStr(HT::GetLastError(HT));
		else HT::print(el);

		if ((el = HT::Get(HT, el3)) == NULL) printStr(HT::GetLastError(HT));
		else HT::print(el);

		//SNAP HT2
		if (!HT::Snap(HT2))
			printStr(HT::GetLastError(HT2));
		std::cout << "-----UPDATE2-----" << std::endl;		

		//GET AFTER UPDATE HT2
		if ((el = HT::Get(HT2, el1)) == NULL) printStr(HT::GetLastError(HT));
		else HT::print(el);

		if ((el = HT::Get(HT2, el2)) == NULL) printStr(HT::GetLastError(HT));
		else HT::print(el);

		if ((el = HT::Get(HT2, el3)) == NULL) printStr(HT::GetLastError(HT));
		else HT::print(el);

		//DELETE HT1
		if (!HT::Delete(HT, el2)) {
			printStr(HT::GetLastError(HT));
		}
		if (!HT::Delete(HT, el4)) {
			printStr(HT::GetLastError(HT));
		}

		//GET AFTER DELETE HT1
		std::cout << "-----DELETE1-----" << std::endl;
		if ((el = HT::Get(HT, el1)) == NULL) printStr(HT::GetLastError(HT));
		else HT::print(el);

		if ((el = HT::Get(HT, el2)) == NULL) printStr(HT::GetLastError(HT));
		else HT::print(el);

		if ((el = HT::Get(HT, el3)) == NULL) printStr(HT::GetLastError(HT));
		else HT::print(el);

		//DELETE HT2
		if (!HT::Delete(HT2, el2)) {
			printStr(HT::GetLastError(HT));
		}
		if (!HT::Delete(HT2, el4)) {
			printStr(HT::GetLastError(HT));
		}		

		//GET AFTER DELETE HT2
		std::cout << "-----DELETE2-----" << std::endl;
		if ((el = HT::Get(HT2, el1)) == NULL) printStr(HT::GetLastError(HT));
		else HT::print(el);

		if ((el = HT::Get(HT2, el2)) == NULL) printStr(HT::GetLastError(HT));
		else HT::print(el);

		if ((el = HT::Get(HT2, el3)) == NULL) printStr(HT::GetLastError(HT));
		else HT::print(el);


		HT::Close(HT);
		HT::Close(HT2);
		delete el1;
		delete el2;
		delete el3;
		delete el4;
		delete el;
	}
	catch (const char* err) {
		std::cout << err << std::endl;
	}

	system("pause");
	return 0;
}
void printStr(char* str) {
	std::cout << "ERROR:\t";
	int i = 0;
	while (str[i]) {
		std::cout << str[i];
		i++;
	}
	std::cout << std::endl;
}