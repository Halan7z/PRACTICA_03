// Materia: Programación I, Paralelo 1

// Autor: Alan Franz Flores Campos

// Fecha creación: 07/09/2023

// Fecha modificación: 07/09/2023

// Número de ejericio: 8

// Problema planteado: Multiplique dos matrices una de N x M y la otra de M x N
#include<iostream>
using namespace std;
int main()
{
    int n, m;
    cout<<"Ingrese el valor de (n): ";cin>>n;
    cout<<"Ingrese el valor de m (m): ";cin>>m;
    int matriz1[n][m], matriz2[m][n];
    // MATRIZ 1
    cout<<endl<<"Ingrese los valores de la matriz 1 (n x m): ";
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            cin>>matriz1[i][j];
    }
    cout<<endl<<"La matriz 1 es: "<<endl;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            cout<<matriz1[i][j]<<" ";
        cout<<endl;
    }
    // MATRIZ 2
    cout<<endl<<"Ingrese los valores de la matriz 2 (m x n): ";
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
            cin>>matriz2[i][j];
    }
    cout<<endl<<"La matriz 2 es: "<<endl;
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
            cout<<matriz2[i][j]<<" ";
        cout<<endl;
    }
    // Multiplicacion de matrices
    int matriz3[n][n], suma;
    for (int i=0; i<n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matriz3[i][j] = 0;
            for (int k = 0; k < m; k++)
            {
                matriz3[i][j] += matriz1[i][k] * matriz2[k][j];
            }
        }
    }
    cout<<endl<<"La multiplicación de las matrices es: "<<endl;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<n; j++)
            cout<<matriz3[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
