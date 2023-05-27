#include <iostream>
#include <vector>
using namespace std;

// Definimos la estructura Point que representa un punto en 2D.
struct Point {
    int x;
    int y;
};

// Definimos la estructura Node que representa un nodo en el Quadtree.
struct Node {
    Point pos; // posición del punto en el espacio 2D.
    int data; // datos del nodo.

    Node(Point _pos, int _data) : pos(_pos), data(_data) {}
};

// Definimos la estructura Quad que representa el Quadtree.
struct Quad {
    Point topLeft; // punto superior izquierdo del quad.
    Point botRight; // punto inferior derecho del quad.
    Node* node; // nodo que reside en el Quad.

    Quad* topLeftTree; // subárbol superior izquierdo.
    Quad* topRightTree; // subárbol superior derecho.
    Quad* botLeftTree; // subárbol inferior izquierdo.
    Quad* botRightTree; // subárbol inferior derecho.

    // Constructor
    Quad(Point topL, Point botR) {
        topLeft = topL;
        botRight = botR;
        node = NULL;
        topLeftTree = topRightTree = botLeftTree = botRightTree = NULL;
    }

    // Función para verificar si este Quad contiene un punto.
    bool inBoundary(Point p) {
        return (p.x >= topLeft.x && p.x <= botRight.x && p.y >= topLeft.y && p.y <= botRight.y);
    }

    // Función para insertar un nodo en el Quadtree.
    void insert(Node* n) {
        if (n == NULL) // Si el nodo es NULL, no hacemos nada.
            return;

        // Si el punto no está en el límite de este Quad, no hacemos nada.
        if (!inBoundary(n->pos))
            return;

        // Si estamos en un Quad de una unidad de área, es un nodo hoja, por lo que almacenamos el punto aquí.
        if (abs(topLeft.x - botRight.x) <= 1 && abs(topLeft.y - botRight.y) <= 1) {
            if (node == NULL)
                node = n;
            return;
        }

        // Calculamos el punto medio.
        int xMid = (topLeft.x + botRight.x) / 2;
        int yMid = (topLeft.y + botRight.y) / 2;

        // Verificamos en qué cuadrante del Quad debe residir el punto.
        // Creamos un nuevo Quadtree si el cuadrante no tiene un Quadtree.
        if ((n->pos.x <= xMid) && (n->pos.y <= yMid)) {
            if (topLeftTree == NULL)
                topLeftTree = new Quad({topLeft.x, topLeft.y}, {xMid, yMid});
            topLeftTree->insert(n);
        }
        else if ((n->pos.x <= xMid) && (n->pos.y > yMid)) {
            if (botLeftTree == NULL)
                botLeftTree = new Quad({topLeft.x, yMid}, {xMid, botRight.y});
            botLeftTree->insert(n);
        }
        else if ((n->pos.x > xMid) && (n->pos.y <= yMid)) {
            if (topRightTree == NULL)
                topRightTree = new Quad({xMid, topLeft.y}, {botRight.x, yMid});
            topRightTree->insert(n);
        }
        else {
            if (botRightTree == NULL)
                botRightTree = new Quad({xMid, yMid}, {botRight.x, botRight.y});
            botRightTree->insert(n);
        }
    }
};

int main() {
    Quad center({0, 0}, {8, 8});
    Node n1({2, 3}, 1);
    center.insert(&n1);
    // Continuar con más inserciones.

    return 0;
}
