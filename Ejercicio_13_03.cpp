// Materia: Programación I, Paralelo 1

// Autor: Alan Franz Flores Campos

// Fecha creación: 07/09/2023

// Fecha modificación: 07/09/2023

// Número de ejericio: 13

/* Problema planteado: La farmacia FARMACARP tiene N sucursales, leer sus ventas por mes de un año entero de cada sucursal y calcule:
a. Total, de ventas
b. Total, de ventas por sucursal.
c. Sucursal que más ha vendido.
d. Sucursal que menos ha vendido */
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int num_sucursales;
    cout << "Ingrese el número de sucursales: ";cin >> num_sucursales;
    const int num_meses = 12;
    int ventas_por_sucursal[num_sucursales][num_meses];

    // Ingreso de datos por sucursal
    for (int i = 0; i < num_sucursales; ++i)
    {
        cout << "Ingrese las ventas mensuales para la Sucursal " << (i + 1) << ":" << endl;
        for (int j = 0; j < num_meses; ++j)
        {
            cout << "Mes " << (j + 1) << ": ";
            cin >> ventas_por_sucursal[i][j];
        }
    }

    // a. Total de ventas
    int total_ventas = 0;
    for (int i = 0; i < num_sucursales; ++i)
    {
        for (int j = 0; j < num_meses; ++j)
        {
            total_ventas += ventas_por_sucursal[i][j];
        }
    }
    cout << "Total de ventas: $" << total_ventas << endl;

    // b. Total de ventas por sucursal
    int ventas_por_sucursal_total[num_sucursales] = {0};
    for (int i = 0; i < num_sucursales; ++i)
        {
        for (int j = 0; j < num_meses; ++j)
        {
            ventas_por_sucursal_total[i] += ventas_por_sucursal[i][j];
        }
        cout << "Sucursal " << (i + 1) << ": $" << ventas_por_sucursal_total[i] << endl;
    }

    // c. Sucursal que más ha vendido
    int max_ventas = ventas_por_sucursal_total[0];
    int sucursal_mas_vendida = 1;
    for (int i = 1; i < num_sucursales; ++i)
    {
        if (ventas_por_sucursal_total[i] > max_ventas)
        {
            max_ventas = ventas_por_sucursal_total[i];
            sucursal_mas_vendida = i + 1;
        }
    }
    cout << "Sucursal que más ha vendido: Sucursal " << sucursal_mas_vendida << endl;

    // d. Sucursal que menos ha vendido
    int min_ventas = ventas_por_sucursal_total[0];
    int sucursal_menos_vendida = 1;
    for (int i = 1; i < num_sucursales; ++i)
    {
        if (ventas_por_sucursal_total[i] < min_ventas)
        {
            min_ventas = ventas_por_sucursal_total[i];
            sucursal_menos_vendida = i + 1;
        }
    }
    cout << "Sucursal que menos ha vendido: Sucursal " << sucursal_menos_vendida << endl;

    return 0;
}

