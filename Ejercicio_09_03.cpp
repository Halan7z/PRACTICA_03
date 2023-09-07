// Materia: Programación I, Paralelo 1

// Autor: Alan Franz Flores Campos

// Fecha creación: 07/09/2023

// Fecha modificación: 07/09/2023

// Número de ejericio: 9

// Problema planteado: Traspones una matriz de N x M
#include<iostream>
using namespace std;
int main()
{
    int n,m;
    cout<<"Ingrese n para la matriz (n x m): ";cin>>n;
    cout<<"Ingrese m para la matriz (n x m): ";cin>>m;
    int matriz[n][m];
    cout<<"Ingrese los valores de la matriz: ";
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
            cin>>matriz[i][j];
    }
    //TRANSPUESTA
    int transpuesta[m][n];
    cout<<endl<<"La matriz transpuesta es: ";
    for (int i=0; i<m; i++)
    {
        for (int j=0; j<n; j++)
        {
            transpuesta[i][j]=matriz[j][i];
            cout<<transpuesta[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
