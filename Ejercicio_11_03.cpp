// Materia: Programación I, Paralelo 1

// Autor: Alan Franz Flores Campos

// Fecha creación: 07/09/2023

// Fecha modificación: 07/09/2023

// Número de ejericio: 11

// Problema planteado: Realizar el típico juego del 3 en raya.....
#include <iostream>
using namespace std;

const int FILAS = 3;
const int COLUMNAS = 3;

// TABLERO
void imprimirTablero(char tablero[FILAS][COLUMNAS])
{
    for (int i=0; i<FILAS; i++)
    {
        for (int j=0; j<COLUMNAS; j++)
            cout<<tablero[i][j]<<" ";
        cout<<endl;
    }
}

// Función para verificar si alguien ganó
char verificarGanador(char tablero[FILAS][COLUMNAS])
{
    // Verificar filas y columnas
    for (int i = 0; i < FILAS; i++)
    {
        if (tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2] && tablero[i][0] != '-')
            return tablero[i][0];

        if (tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i] && tablero[0][i] != '-')
            return tablero[0][i];
    }
    // Verificar diagonales
    if (tablero[0][0] == tablero[1][1] && tablero[1][1] == tablero[2][2] && tablero[0][0] != '-')
        return tablero[0][0];

    if (tablero[0][2] == tablero[1][1] && tablero[1][1] == tablero[2][0] && tablero[0][2] != '-')
        return tablero[0][2];

    return ' '; // No hay ganador todavía
}

int main()
{
    char tablero[FILAS][COLUMNAS];
    int fila, columna;
    char jugadorActual = 'X';
    bool juegoTerminado = false;

    // Inicializar el tablero
    for (int i=0; i<FILAS; i++)
    {
        for (int j=0; j<COLUMNAS; j++)
            tablero[i][j] = '-';
    }
    // Loop principal del juego
    while (!juegoTerminado)
    {
        // Imprimir el tablero
        cout<<"Tablero actual:"<<endl;
        imprimirTablero(tablero);
        // Pedir al jugador actual su movimiento
        cout<<"Turno del jugador "<<jugadorActual<<". Ingrese la fila (0-2) y columna (0-2) separadas por espacio: ";
        cin>>fila>>columna;
        // Verificar si la posición es válida
        if (fila<0 || fila>=FILAS || columna<0 || columna>=COLUMNAS || tablero[fila][columna]!='-')
        {
            cout << "Movimiento no válido. Intente nuevamente." << endl;
            continue;
        }
        // Realizar el movimiento
        tablero[fila][columna] = jugadorActual;

        // Verificar si alguien ganó
        char ganador = verificarGanador(tablero);
        if (ganador=='X' || ganador=='O')
            {
            cout<<"¡El jugador "<<ganador<<" ha ganado!"<< endl;
            juegoTerminado=true;
        } else {
            // Verificar empate
            bool empate = true;
            for (int i = 0; i < FILAS; i++) {
                for (int j = 0; j < COLUMNAS; j++) {
                    if (tablero[i][j] == '-') {
                        empate = false;
                        break;
                    }
                }
                if (!empate) break;
            }

            if (empate)
            {
                cout << "¡El juego ha terminado en empate!" << endl;
                juegoTerminado = true;
            }
        }

        // Cambiar al siguiente jugador
        jugadorActual = (jugadorActual == 'X') ? 'O' : 'X';
    }

    // Imprimir el tablero final
    cout << "Tablero final:" << endl;
    imprimirTablero(tablero);

    return 0;
}
