#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace System;
using namespace std;
// EF_2012_2_Pregunta2.cpp : main project file.

using namespace System;
using namespace std;
void Genera(int **Mat, int N)
{
	Random f;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			Mat[i][j] = f.Next(0, 10);
}
void Imprime(int **Mat, int N)
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << Mat[i][j] << "\t";
		cout << endl;
	}
}

void Cuenta_Patron(int **Mat, int N, int patron)
{
	int c, d, u, cont = 0;
	c = patron / 100;
	d = (patron % 100) / 10;
	u = (patron % 10)%10;
	for (int i = 0; i < N - 2; i++)
		for (int j = 0; j < N; j++)
			if (c == Mat[i][j] &&
				d == Mat[i + 1][j] &&
				u == Mat[i + 2][j])
				cont++;
	cout << "veces : " << cont << endl;
}
int main()
{
	int N, patron;
	do {
		cout << "Ingrese N: ";
		cin >> N;
	} while (N <= 0 || N > 30);
	int ** Matriz;
	Matriz = new int *[N];
	for (int i = 0; i < N; i++)
		Matriz[i] = new int[N];
	Genera(Matriz, N);
	Imprime(Matriz, N);
	do {
		cout << "Ingrese patron: ";
		cin >> patron;
	} while (patron <= 99 || patron >= 1000);
	Cuenta_Patron(Matriz, N, patron);
	system("pause");
	return 0;
}
