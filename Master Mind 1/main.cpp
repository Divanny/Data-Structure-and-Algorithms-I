#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int randomNumber()
{
	srand(time(NULL)); // crear verdaderos numeros aleatorios 
	int random = 1 + rand() % 6;
	return random;
}

bool isNumber(const string& str)
{
	for (char const& c : str) {
		if (isdigit(c) == 0) return false;
	}
	return true;
}

int main()
{
	vector <int> keys;
	vector <int>::iterator it;

	int numbersGenerate = 3, tries = 10;
	keys.push_back(randomNumber());

	while (numbersGenerate--)
	{
		int random = randomNumber();
		it = find(keys.begin(), keys.end(), random);

		if (it == keys.end())
		{
			keys.push_back(random);
		}
		else
		{
			numbersGenerate++;
		}
	}
	
	int Plays[10][4];
	string Result[10][4];

	int k = 0;

	while (tries--)
	{
		k++;
		
		vector <int> actualPlay;
		int count = 0;
		cout << "Ingrese su intento #" << k << ":" << endl;
		
		vector <int> temporalPlay;
		bool valid = true;

		while (valid)
		{
			temporalPlay.clear();
			int numbersInput = 4;
			int check = 0;

			while (numbersInput--)
			{
				string num;
				cin >> num;

				if (isNumber(num))
				{
					int numberInt = stoi(num);

					if (numberInt < 1 || numberInt > 6)
					{
						cout << "El numero " << num << " esta fuera del rango establecido (rango de 1 a 6)." << endl << endl;
					}
					else
					{
						temporalPlay.push_back(numberInt);
						check++;
					}
				}
				else
				{
					cout << "Solo se pueden ingresar numeros." << endl << endl;
				}
			}
			if (check == 4)
			{
				valid = false;
				for (int i = 0; i < 4; i++)
				{
					actualPlay.push_back(temporalPlay[i]);
				}
			}
		}



		for (int i = 0; i < 4; i++)
		{
			it = find(keys.begin(), keys.end(), actualPlay[i]);

			if (actualPlay[i] == keys[i])
			{
				cout << "C ";
				Plays[k - 1][i] = actualPlay[i];
				Result[k - 1][i] = "C";
				count++;
			}

			else if (it != keys.end())
			{
				cout << "F ";
				Plays[k - 1][i] = actualPlay[i];
				Result[k - 1][i] = "F";
			}

			else
			{
				cout << "X ";
				Plays[k - 1][i] = actualPlay[i];
				Result[k - 1][i] = "X";
			}
		}

		cout << endl;
		
		system("cls");

		cout << "Registro de jugadas: " << endl;

		
		for (int i = 0; i < k; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				cout << Plays[i][j] << " ";
			}
			
			cout << "| ";

			for (int j = 0; j < 4; j++)
			{
				cout << Result[i][j] << " ";
			}
			
			cout << endl;
		}

		cout << endl;

		if (count == 4)
		{
			cout << endl << "Has ganado. Puntuacion: " << tries << endl;
			return 0;
		}
	}
	cout << endl << "Has perdido." << endl;
}