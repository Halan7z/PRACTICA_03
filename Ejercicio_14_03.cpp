// Materia: Programación I, Paralelo 1

// Autor: Alan Franz Flores Campos

// Fecha creación: 07/09/2023

// Fecha modificación: 07/09/2023

// Número de ejericio: 14

/* Problema planteado: Simule una elección de nuestro país Bolivia. En ello se mostrará las elecciones por departamento y existirá N candidatos.
El programa debe pedir la cantidad de votos por departamento y candidato y almacenarlos en una matriz. El programa debe calcular lo siguiente:
• Si un candidato gana con el 50% + 1 voto es ganador absoluto.
• Si no ningún candidato que logre el 50% + 1 voto el programa debe sacar los dos mas votados para una segunda vuelta. */
#include <iostream>

using namespace std;

int main()
 {
    int num_departamentos;
    int num_candidatos;

    // Solicitar al usuario la cantidad de departamentos y candidatos
    cout << "Ingrese la cantidad de departamentos: ";
    cin >> num_departamentos;
    cout << "Ingrese la cantidad de candidatos: ";
    cin >> num_candidatos;

    // Crear una matriz para almacenar los votos por departamento y candidato
    int votos[num_departamentos][num_candidatos];

    // Solicitar al usuario que ingrese los votos por departamento y candidato
    for (int i = 0; i < num_departamentos; ++i)
        {
        for (int j = 0; j < num_candidatos; ++j)
        {
            cout << "Ingrese los votos para el candidato " << (j + 1) << " en el departamento " << (i + 1) << ": ";
            cin >> votos[i][j];
        }
    }

    // Calcular el total de votos por candidato
    int total_votos_candidato[num_candidatos] = {0};
    for (int i = 0; i < num_departamentos; ++i)
    {
        for (int j = 0; j < num_candidatos; ++j)
        {
            total_votos_candidato[j] += votos[i][j];
        }
    }

    // Calcular el total de votos en la elección
    int total_votos_eleccion = 0;
    for (int i = 0; i < num_candidatos; ++i)
    {
        total_votos_eleccion += total_votos_candidato[i];
    }

    // Verificar si hay un ganador absoluto
    bool hay_ganador_absoluto = false;
    int candidato_ganador_absoluto = -1;
    for (int i = 0; i < num_candidatos; ++i)
    {
        if (total_votos_candidato[i] > total_votos_eleccion / 2)
        {
            hay_ganador_absoluto = true;
            candidato_ganador_absoluto = i + 1;
            break;
        }
    }

    if (hay_ganador_absoluto)
        cout << "El candidato " << candidato_ganador_absoluto << " es el ganador absoluto." << endl;
    else
    {
        // Encontrar los dos candidatos mas votados para una segunda vuelta
        int primer_mas_votado = 0;
        int segundo_mas_votado = 1;
        for (int i = 2; i < num_candidatos; ++i)
        {
            if (total_votos_candidato[i] > total_votos_candidato[primer_mas_votado])
            {
                segundo_mas_votado = primer_mas_votado;
                primer_mas_votado = i;
            }
            else if (total_votos_candidato[i] > total_votos_candidato[segundo_mas_votado])
                segundo_mas_votado = i;
        }

        cout << "Se llevara a cabo una segunda vuelta entre los candidatos " << (primer_mas_votado + 1)
             << " y " << (segundo_mas_votado + 1) << "." << endl;
    }
    return 0;
}
