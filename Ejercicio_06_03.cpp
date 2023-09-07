// Materia: Programación I, Paralelo 1

// Autor: Alan Franz Flores Campos

// Fecha creación: 07/09/2023

// Fecha modificación: 07/09/2023

// Número de ejericio: 6

// Problema planteado: Generar una matriz NxN, que se llene con la serie de Fibonacci.
#include <iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Ingrese el valor de (n) para la matriz (n x n): ";cin>>n;
    int matriz[n][n];
    int a = 0, b = 1, anterior;

    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            matriz[i][j]=a;
            anterior=a;
            a=b;
            b=anterior+b;
        }
    }
    cout<<"Matriz (n x n) con la serie de Fibonacci: "<<endl;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            cout << matriz[i][j] << " ";
        cout << endl;
    }
    return 0;
}
