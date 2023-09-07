// Materia: Programación I, Paralelo 1

// Autor: Alan Franz Flores Campos

// Fecha creación: 06/09/2023

// Fecha modificación: 06/09/2023

// Número de ejercicio: 3

/* Problema planteado: Generar una matriz de N x N con números al azar entre A y B, y determinar:
• La suma de la última columna
• El producto total de la última fila
• Obtener el mayor valor y su posición
• Obtener la desviación estándar de todos los elementos de la matriz */
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cmath>
using namespace std;

int main()
{
    int tamano, minimo, maximo;

    cout<<"Ingrese el tamano de la matriz (tamano x tamano):";cin>>tamano;
    cout<<"Ingrese el valor minimo:";cin>>minimo;
    cout<<"Ingrese el valor maximo:";cin>>maximo;
    // numeros aleatorios
    srand(time(0));
    int matriz[tamano][tamano];
    // llenado de matriz con números aleatorios
    for(int i=0;i<tamano;i++)
    {
        for(int j=0;j<tamano;j++)
            matriz[i][j] = rand()%(maximo-minimo+1)+minimo;
    }
    // imprimir la matriz
    cout<<"Matriz generada:"<<endl;
    for(int i=0;i<tamano;i++)
    {
        for(int j=0;j<tamano;j++)
            cout<<matriz[i][j]<<" ";
        cout<<endl;
    }
    // suma de la última columna
    int sumaUltimaColumna = 0;
    for(int i=0;i<tamano;i++)
        sumaUltimaColumna += matriz[i][tamano-1];
    // producto de la última fila
    int productoUltimaFila = 1;
    for(int j=0;j<tamano;j++)
        productoUltimaFila *= matriz[tamano-1][j];
    // valor maximo y su posicion
    int mayorValor = matriz[0][0], filaMayor, columnaMayor;
    for(int i=0;i<tamano;i++)
    {
        for(int j=0;j<tamano;j++)
        {
            if(matriz[i][j] > mayorValor)
            {
                mayorValor = matriz[i][j];
                filaMayor = i+1;
                columnaMayor = j+1;
            }
        }
    }
    // desviacion estandar
    double media = 0.0, sumaCuadrados = 0.0;

    for(int i=0;i<tamano;i++)
    {
        for(int j=0;j<tamano;j++)
            media += matriz[i][j];
    }
    media /= (tamano*tamano);
    for(int i=0;i<tamano;i++)
    {
        for(int j=0;j<tamano;j++)
            sumaCuadrados += pow(matriz[i][j] - media, 2);
    }
    double desviacionEstandar = sqrt(sumaCuadrados / (tamano*tamano));
    cout<<"Suma de la ultima columna:"<<sumaUltimaColumna<<endl;
    cout<<"Producto total de la ultima fila:"<<productoUltimaFila<<endl;
    cout<<"Mayor valor:"<<mayorValor<<" (Fila:"<<filaMayor<<", Columna:"<<columnaMayor<<")"<<endl;
    cout<<"Desviacion estandar de los elementos de la matriz:"<<desviacionEstandar<<endl;

    return 0;
}
