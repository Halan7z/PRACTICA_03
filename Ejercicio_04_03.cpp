// Materia: Programación I, Paralelo 1

// Autor: Alan Franz Flores Campos

// Fecha creación: 06/09/2023

// Fecha modificación: 06/09/2023

// Número de ejercicio: 4

/* Problema planteado: En la segunda temporada de The Walking Dead......*/
#include<iostream>
#include<vector>
using namespace std;
const int filas = 3, columnas = 4;

void mostrarMatriz(char matriz[filas][columnas])
{
    for(int i=0; i<filas; i++)
    {
        for(int j=0; j<columnas; j++)
            cout << matriz[i][j] << " ";
        cout << endl;
    }
}

void contarFilasColumnasSeguras(char matriz[filas][columnas])
{
    int filasSeguras = 0, columnasSeguras = 0;

    for(int i=0; i<filas; i++)
    {
        bool hayMuertoViviente = false;
        for(int j=0; j<columnas; j++)
        {
            if(matriz[i][j] == 'x')
            {
                hayMuertoViviente = true;
                break;
            }
        }
        if(!hayMuertoViviente)
            filasSeguras++;
    }

    for(int j=0; j<columnas; j++)
    {
        bool hayMuertoViviente = false;
        for(int i=0; i<filas; i++)
        {
            if(matriz[i][j] == 'x')
            {
                hayMuertoViviente = true;
                break;
            }
        }
        if(!hayMuertoViviente)
            columnasSeguras++;
    }
    cout << "Numero de filas seguras:" << filasSeguras << endl;
    cout << "Numero de columnas seguras:" << columnasSeguras << endl;
}

void coordenadasMuertosVivientes(char matriz[filas][columnas], vector<int>& filasMuertos, vector<int>& columnasMuertos)
{
    for(int i=0; i<filas; i++)
    {
        for(int j=0; j<columnas; j++)
        {
            if(matriz[i][j] == 'x')
            {
                filasMuertos.push_back(i);
                columnasMuertos.push_back(j);
            }
        }
    }
}

int contarMuertosVivientes(char matriz[filas][columnas])
{
    int cantidadMuertosVivientes = 0;

    for(int i=0; i<filas; i++)
        {
        for(int j=0; j<columnas; j++)
        {
            if(matriz[i][j] == 'x')
                cantidadMuertosVivientes++;
        }
    }
    return cantidadMuertosVivientes;
}

int main()
{
    char matriz[filas][columnas] =
    {
        {'x', 'o', 'x', 'o'},
        {'o', 'o', 'o', 'o'},
        {'o', 'o', 'x', 'o'}
    };

    cout << "a)";cout<<endl;

    mostrarMatriz(matriz);
    cout << "b)";
    contarFilasColumnasSeguras(matriz);

    cout << "c) Coordenadas de los muertos vivientes:" << endl;
    vector<int> filasMuertos;
    vector<int> columnasMuertos;
    coordenadasMuertosVivientes(matriz, filasMuertos, columnasMuertos);
    for(size_t i=0; i<filasMuertos.size(); i++)
        cout << "(" << filasMuertos[i] << ", " << columnasMuertos[i] << ")" << endl;
    cout << "d) Cantidad de muertos vivientes:" << contarMuertosVivientes(matriz) << endl;

    cout << "e)";
    bool esPosibleEntrar = true;
    for(int i=0; i<filas; i++)
    {
        if(matriz[i][0] == 'x')
        {
            esPosibleEntrar = false;
            break;
        }
    }
    if(esPosibleEntrar)
        cout << "Es posible entrar al complejo" << endl;
    else
        cout << "No es posible entrar al complejo" << endl;
    return 0;
}

