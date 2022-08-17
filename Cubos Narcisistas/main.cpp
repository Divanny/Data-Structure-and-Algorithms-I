#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	setlocale(LC_ALL, ""); // distintos tipos de caracteres que no pertenezcan al "estandar".
	cout << "Cubos narcicistas del 100 al 999:" << endl;

	for (int i = 100; i < 1000; i++)
	{
		int digito1 = ((i / 10) / 10) % 10, digito2 = (i / 10) % 10, digito3 = i % 10, sum;
		sum = pow(digito1, 3) + pow(digito2, 3) + pow(digito3, 3);
		if (sum == i)
		{
			cout << i << " = " << digito1 << "³ + " << digito2 << "³ + " << digito3 << "³" << endl;
		}
	}
}
