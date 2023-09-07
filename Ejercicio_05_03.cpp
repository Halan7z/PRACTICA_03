// Materia: Programación I, Paralelo 1

// Autor: Alan Franz Flores Campos

// Fecha creación: 06/09/2023

// Fecha modificación: 06/09/2023

// Número de ejercicio: 4

/* Problema planteado: Generar la matriz para un orden NxN
Sea n=5
1 2 3 4 5
3 4 5 6 7
5 6 7 8 9
7 8 9 10 11
9 10 11 12 13 */
#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Ingrese el valor de N: ";cin >> n;
    int matriz[n][n];
    // llenado de la matriz
    int valor=1;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            matriz[i][j] = valor+j;
        valor +=2;
    }

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            cout << matriz[i][j] << " ";
        cout << endl;
    }

    return 0;
}
