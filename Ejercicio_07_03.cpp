// Materia: Programación I, Paralelo 1

// Autor: Alan Franz Flores Campos

// Fecha creación: 07/09/2023

// Fecha modificación: 07/09/2023

// Número de ejericio: 7

// Problema planteado: Efectuar la suma de una matriz tridimensional de orden n x n x n
#include<iostream>
using namespace std;
int main()
{
    int n, suma=0;
    cout<<"Ingrese el valor de (n) para una matriz tridimensional (n x n x n):";cin>>n;
    int matriz[n][n][n];
    cout<<"Ingrese los elementos de la matriz: ";
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            for (int k=0; k<n; k++)
            {
                cin>>matriz[i][j][k];
                suma+=matriz[i][j][k];
            }
        }
    }
    cout<<"La matriz tridimensional es: "<<endl;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
        {
            for (int k=0; k<n; k++)
            {
                cout<<matriz[i][j][k]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    cout<<"Suma total de los elementos de la matriz: "<<suma<<endl;
    return 0;
}
