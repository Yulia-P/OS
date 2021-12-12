#include <iostream>
#include <Windows.h>

using namespace std;
#define PG (4096)
int pg = 512;

int main()
{
	setlocale(LC_ALL, "rus");

	int* m1 = (int*)VirtualAlloc(NULL, pg * PG, MEM_COMMIT, PAGE_READWRITE);
	for (int i = 0; i < pg * PG / 4; i++)
	{
		m1[i] = i;
	}

	
	int* m2 = m1 + 4* 207 * 1024 + 3823;
	cout << m2 << hex << endl;
	system("pause");
}
