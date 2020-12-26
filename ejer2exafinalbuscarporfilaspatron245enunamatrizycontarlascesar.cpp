#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;
using namespace System;


int ingresetamañomatriz()
{
	int n;
	do {
		cout << "ingrese tamaño de la matriz"; cin >> n;
	} while (n > 30);
	return n;
}

void generardatosmatriz(int n, int **matriz)
{
	Random r;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matriz[i][j] = r.Next(0, 10);
	//imprime matriz
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << matriz[i][j] << "\t";
		cout << endl;
	}

}
int ingresopatronnumerico()
{
	int n;
	do {
		cout << "ingreso patron numerico: "; cin >> n;
	} while (n < 99 || n>1000);
	return n;

}

void busca_patron_numerico(int n, int **matriz, int m)
{
	int contador = 0;
	for (int i = 0; i < n; i++)
		for (int j = 1; j < n-1; j++)
			if (matriz[i][j-1]*100+matriz[i][j]*10+ matriz[i][j+1] * 1 == m)
				contador++;
	cout << "numero de coincidencias con el patron: " << contador << endl;


}


int main()
{
	int n = ingresetamañomatriz();
	int m = ingresopatronnumerico();

	int**matriz;
	matriz = new int*[n];
	for (int i = 0; i < n; i++)
		matriz[i] = new int[n];
	generardatosmatriz(n, matriz);
	busca_patron_numerico(n, matriz, m);
	for (int i = 0; i < n; i++)
		delete[]matriz[i];
	delete[] matriz;


	system("pause");


}

