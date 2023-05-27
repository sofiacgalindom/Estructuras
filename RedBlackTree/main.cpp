#include <iostream>
using namespace std;

// se hace usso de un enum para identificar el tipo de nodo

enum NodeColor {RED, BLACK};

struct Node {
    int data;
    bool color;
    Node *left, *right, *parent;

    // Constructor
    Node(int data)
    {
       this->data = data;
       left = right = parent = nullptr;
       this->color = RED;
    }
};

class RBTree {
private:
    Node *root;

protected:
    void rotateLeft(Node *&, Node *&);
    void rotateRight(Node *&, Node *&);
    void fixViolation(Node *&, Node *&);

public:
    // Constructor
    RBTree() { root = nullptr; }
    void insert(const int &n);
    void inorder();
    void levelOrder();
};

// Rotar a la izquierda
void RBTree::rotateLeft(Node *&root, Node *&pt) {
    Node *pt_right = pt->right;

    pt->right = pt_right->left;

    if (pt->right != nullptr)
        pt->right->parent = pt;

    pt_right->parent = pt->parent;

    if (pt->parent == nullptr)
        root = pt_right;

    else if (pt == pt->parent->left)
        pt->parent->left = pt_right;

    else
        pt->parent->right = pt_right;

    pt_right->left = pt;
    pt->parent = pt_right;
}

// Aquí habría más código para completar el árbol Rojo-Negro
// incluyendo la función de rotación derecha y la inserción.
// También habría funciones para mantener el balance del árbol 
// después de cada inserción o eliminación.

int main() {
    RBTree tree;

    // Inserciones
    tree.insert(7);
    tree.insert(6);
    tree.insert(5);
    tree.insert(4);
    tree.insert(3);
    tree.insert(2);
    tree.insert(1);

    // Recorrido en orden
    tree.inorder();

    return 0;
}

