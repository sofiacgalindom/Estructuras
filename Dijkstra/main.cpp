#include <iostream> // Biblioteca estándar para operaciones de entrada y salida.
#include <limits> // Biblioteca para manipular límites de tipos de datos.
#include <vector> // Biblioteca para usar el contenedor vector de la biblioteca estándar.
#include <queue> // Biblioteca para usar el contenedor queue de la biblioteca estándar.
using namespace std;

#define INF INT_MAX // Definición de infinito como el valor máximo que un entero puede tener.

// Función para implementar el algoritmo de Dijkstra.
vector<int> dijkstra(vector<vector<int>> graph, int source, int vertices) {
    vector<int> distance(vertices, INF); // Inicializa las distancias a infinito.
    distance[source] = 0; // La distancia al vértice origen es 0.

    // Se crea una cola de prioridad para los vértices que se van procesando.
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, source)); // Se agrega el vértice origen a la cola de prioridad.

    // Mientras la cola de prioridad no esté vacía...
    while (!pq.empty()) {
        int u = pq.top().second; // Se toma el vértice con la menor distancia.
        pq.pop(); // Se elimina este vértice de la cola.

        // Se revisan todos los vértices vecinos del vértice u.
        for (int v = 0; v < vertices; v++) {
            // Si el vértice v es un vecino de u y la distancia a v puede ser acortada...
            if (graph[u][v] && distance[u] != INF && distance[u] + graph[u][v] < distance[v]) {
                // Se acorta la distancia a v.
                distance[v] = distance[u] + graph[u][v];
                // Se agrega el vértice v a la cola de prioridad.
                pq.push(make_pair(distance[v], v));
            }
        }
    }
    // Se retorna el vector con las distancias más cortas desde el vértice origen.
    return distance;
}

// Función principal.
int main() {
    int vertices = 5; // Número de vértices en el gráfico.
    // Se define el gráfico como una matriz de adyacencia.
    vector<vector<int>> graph = {{0, 2, 0, 6, 0},
                                 {2, 0, 3, 8, 5},
                                 {0, 3, 0, 0, 7},
                                 {6, 8, 0, 0, 9},
                                 {0, 5, 7, 9, 0}};

    // Se aplica el algoritmo de Dijkstra al gráfico.
    vector<int> distance = dijkstra(graph, 0, vertices);

    // Se imprime la distancia más corta desde el vértice origen a cada uno de los otros vértices.
    for (int i = 0; i < vertices; ++i)
        cout << "Shortest distance from source to vertex " << i << " is " << distance[i] << endl;
    return 0;
}
