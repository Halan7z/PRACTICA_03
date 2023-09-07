// Materia: Programación I, Paralelo 1

// Autor: Alan Franz Flores Campos

// Fecha creación: 07/09/2023

// Fecha modificación: 07/09/2023

// Número de ejericio: 12

/* Problema planteado: Ingresa una matriz de NxN y a continuación:
a. Elimine una fila ingresada por el usuario.
b. Elimine una columna ingresada por el usuario.
c. Inserte una fila por un valor determinado por el usuario.
d. Inserte una columna por un valor determinado por el usuario. */
#include <iostream>
#include <vector>

using namespace std;

// Función para imprimir la matriz
void imprimirMatriz(const vector<vector<int>>& matriz) {
    for (const vector<int>& fila : matriz) {
        for (int valor : fila) {
            cout << valor << " ";
        }
        cout << endl;
    }
}

// Función para eliminar una fila
vector<vector<int>> eliminarFila(vector<vector<int>>& matriz, int fila) {
    if (fila < 0 || fila >= matriz.size()) {
        cout << "Fila fuera de rango." << endl;
        return matriz;
    }
    matriz.erase(matriz.begin() + fila);
    return matriz;
}

// Función para eliminar una columna
vector<vector<int>> eliminarColumna(vector<vector<int>>& matriz, int columna) {
    if (matriz.empty() || columna < 0 || columna >= matriz[0].size()) {
        cout << "Columna fuera de rango." << endl;
        return matriz;
    }
    for (vector<int>& fila : matriz) {
        fila.erase(fila.begin() + columna);
    }
    return matriz;
}

// Función para insertar una fila con un valor determinado
vector<vector<int>> insertarFila(vector<vector<int>>& matriz, int fila, int valor) {
    if (fila < 0 || fila > matriz.size()) {
        cout << "Fila fuera de rango." << endl;
        return matriz;
    }
    vector<int> nuevaFila(matriz[0].size(), valor);
    matriz.insert(matriz.begin() + fila, nuevaFila);
    return matriz;
}

// Función para insertar una columna con un valor determinado
vector<vector<int>> insertarColumna(vector<vector<int>>& matriz, int columna, int valor) {
    if (matriz.empty() || columna < 0 || columna > matriz[0].size()) {
        cout << "Columna fuera de rango." << endl;
        return matriz;
    }
    for (vector<int>& fila : matriz) {
        fila.insert(fila.begin() + columna, valor);
    }
    return matriz;
}

int main() {
    int N;
    cout << "Ingrese el tamaño de la matriz NxN: ";
    cin >> N;

    // Crear matriz NxN con valores iniciales
    vector<vector<int>> matriz(N, vector<int>(N, 0));

    // Llenar matriz con valores (esto es opcional, puedes omitirlo si deseas)
    cout << "Ingrese los valores de la matriz:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> matriz[i][j];
        }
    }

    cout << "Matriz original:" << endl;
    imprimirMatriz(matriz);

    // Realizar operaciones solicitadas
    int opcion;
    do {
        cout << "Seleccione una operación:" << endl;
        cout << "1. Eliminar una fila" << endl;
        cout << "2. Eliminar una columna" << endl;
        cout << "3. Insertar una fila" << endl;
        cout << "4. Insertar una columna" << endl;
        cout << "0. Salir" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                int filaEliminar;
                cout << "Ingrese el número de fila a eliminar: ";
                cin >> filaEliminar;
                matriz = eliminarFila(matriz, filaEliminar);
                break;
            case 2:
                int columnaEliminar;
                cout << "Ingrese el número de columna a eliminar: ";
                cin >> columnaEliminar;
                matriz = eliminarColumna(matriz, columnaEliminar);
                break;
            case 3:
                int filaInsertar, valorFila;
                cout << "Ingrese el número de fila donde insertar: ";
                cin >> filaInsertar;
                cout << "Ingrese el valor para la fila: ";
                cin >> valorFila;
                matriz = insertarFila(matriz, filaInsertar, valorFila);
                break;
            case 4:
                int columnaInsertar, valorColumna;
                cout << "Ingrese el número de columna donde insertar: ";
                cin >> columnaInsertar;
                cout << "Ingrese el valor para la columna: ";
                cin >> valorColumna;
                matriz = insertarColumna(matriz, columnaInsertar, valorColumna);
                break;
            case 0:
                break;
            default:
                cout << "Opción no válida." << endl;
        }

        cout << "Matriz actual:" << endl;
        imprimirMatriz(matriz);

    } while (opcion != 0);

    return 0;
}


