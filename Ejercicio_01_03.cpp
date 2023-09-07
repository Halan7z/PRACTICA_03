// Materia: Programación I, Paralelo 1

// Autor: Alan Franz Flores Campos

// Fecha creación: 14/08/2023

// Fecha modificación: 15/08/2023

// Número de ejericio: 1

// Problema planteado: Elabore un programa que lea una matriz de orden n x n y la cambie la fila 1 por la fina n.
#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Ingrese el tamaño de la matriz (n x n): ";cin >> n;
    int matriz[n][n];
    cout << "Ingrese los elementos de la matriz:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> matriz[i][j];
    }
    // intercambia la primera fila con la última fila
    for (int j = 0; j < n; j++)
    {
        int temp = matriz[0][j];
        matriz[0][j] = matriz[n - 1][j];
        matriz[n - 1][j] = temp; //mantenemos el valor original
    }
    cout << "La matriz modificada es:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << matriz[i][j] << " ";
        cout << endl;
    }
    return 0;
}
