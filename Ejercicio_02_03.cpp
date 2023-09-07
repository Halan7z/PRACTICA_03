// Materia: Programación I, Paralelo 1

// Autor: Alan Franz Flores Campos

// Fecha creación: 06/09/2023

// Fecha modificación: 06/09/2023

// Número de ejercicio: 2

/* Problema planteado: Generar la matriz espiral para un orden n :
Sea n=3:
1 2 3
8 9 4
7 6 5 */
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Ingrese el orden de la matriz espiral: ";cin >> n;
    int matriz[n][n];
    int valor = 1, inicioFila = 0, finFila = n - 1, inicioColumna = 0, finColumna = n - 1;
    while (valor <= n * n)
    {
        // Llena la fila superior
        for (int i = inicioColumna; i <= finColumna; i++)
            matriz[inicioFila][i] = valor++;
        inicioFila++;
        // Llena la columna derecha
        for (int i = inicioFila; i <= finFila; i++)
            matriz[i][finColumna] = valor++;
        finColumna--;
        // Llena la fila inferior
        for (int i = finColumna; i >= inicioColumna; i--)
            matriz[finFila][i] = valor++;
        finFila--;

        // Llena la columna izquierda
        for (int i = finFila; i >= inicioFila; i--)
            matriz[i][inicioColumna] = valor++;
        inicioColumna++;
    }
    // Imprime la matriz espiral
    cout << "Matriz espiral de orden " << n << ":" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << matriz[i][j] << " ";
        cout << endl;
    }
    return 0;
}

