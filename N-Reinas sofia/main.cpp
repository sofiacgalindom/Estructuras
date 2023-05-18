#include <iostream>
#include <vector>

using namespace std;

bool es_seguro(vector<vector<int>>& tablero, int fila, int columna, int N) {
    
    for (int i = 0; i < columna; i++) {
        if (tablero[fila][i] == 1) {
            return false;
        }
    }
    
    // Comprueba la diagonal superior izquierda
    int i = fila, j = columna;
    while (i >= 0 && j >= 0) {
        if (tablero[i][j] == 1) {
            return false;
        }
        i--;
        j--;
    }
    
    // Comprueba la diagonal inferior izquierda
    i = fila, j = columna;
    while (i < N && j >= 0) {
        if (tablero[i][j] == 1) {
            return false;
        }
        i++;
        j--;
    }
    
    return true;
}

bool resolver_n_reinas_util(vector<vector<int>>& tablero, int columna, int N) {
    // Función auxiliar para resolver el problema de las N reinas
    
    // Caso base: si todas las reinas están colocadas, se ha encontrado una solución
    if (columna >= N) {
        return true;
    }
    
    // Intenta colocar una reina en cada fila de la columna actual
    for (int i = 0; i < N; i++) {
        if (es_seguro(tablero, i, columna, N)) {
            tablero[i][columna] = 1;
            
            // Llamada recursiva para colocar las reinas en las columnas restantes
            if (resolver_n_reinas_util(tablero, columna + 1, N)) {
                return true;
            }
            
            // Si no se puede colocar una reina en la posición actual, retrocede y prueba la siguiente fila
            tablero[i][columna] = 0;
        }
    }
    
    // Si no se puede colocar una reina en ninguna fila de la columna actual, devuelve false
    return false;
}

void resolver_n_reinas(int N) {
    // Resuelve el problema de las N reinas
    
    // Crea un tablero de tamaño NxN inicializado con ceros
    vector<vector<int>> tablero(N, vector<int>(N, 0));
    
    // Llama a la función auxiliar para resolver el problema
    if (resolver_n_reinas_util(tablero, 0, N)) {
        // Imprime la solución encontrada
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << tablero[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "No se encontró solución para N = " << N << endl;
    }
}

int main() {
    // Ejemplo de uso:
    resolver_n_reinas(8);
    
    return 0;
}