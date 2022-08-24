#include <iostream>
#include <algorithm>
#include <stdlib.h>

using namespace std;

struct Nodo {
	int dato;
	Nodo* siguiente;
};

void agregarPila(Nodo*&, int);
void sacarPila(Nodo*&, int&);

int main()
{
	Nodo* pila = NULL;
	bool check = true;
	while (check)
	{
		cout << endl << endl << "¿Que operacion desea realizar?" << endl;
		cout << "Operacion Push: Digite el numero 1" << endl;
		cout << "Operacion Pop: Digite el numero 2" << endl;
		cout << "Operacion Desplegar: Digite el numero 3" << endl;
		cout << "Operacion Finalizar: Digite el numero 4" << endl;
		cout << "Ingrese la operacion: ";

		int operacion, dato;
		cin >> operacion;

		system("cls");

		if (operacion == 4)
		{
			check = false;
		}
		else if (operacion == 3)
		{
			cout << "Despligue de valores del Stack: " << endl;

			if (pila != NULL)
			{
				while (pila != NULL)
				{
					sacarPila(pila, dato);
					if (pila != NULL)
					{
						cout << dato << " , ";
					}
					else
					{
						cout << dato << ".";
					}
				}
			}
			else
			{
				cout << "\nEmpty Stack" << endl << endl;
			}
		}
		else if (operacion == 2)
		{
			cout << "Eliminando..." << endl;
			if (pila != NULL)
			{
				sacarPila(pila, dato);
				cout << "\nElemento eliminado" << endl << endl;
			}
			else
			{
				cout << "\nEmpty Stack" << endl << endl;
			}
		}
		else if (operacion == 1)
		{
			cout << "Digite el numero que quiere agregar: ";
			cin >> dato;
			agregarPila(pila, dato);
		}
	}
	return 0;
}

void agregarPila(Nodo*& pila, int n) {

	Nodo* nuevo_nodo = new Nodo(); // reservar memoria para el nodo
	nuevo_nodo->dato = n; // igualar el dato quie el usuario introduce
	nuevo_nodo->siguiente = pila; // poner el puntero igualado a pila
	pila = nuevo_nodo; // igualar pila a nuevo nodo

	cout << "\nElemento " << n << " agregado a la PILA correctamente" << endl;

}

void sacarPila(Nodo*& pila, int& n) {

	Nodo* aux = pila;
	n = aux->dato;
	pila = aux->siguiente;
	delete aux;
}