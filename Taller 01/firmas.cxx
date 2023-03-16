#include "firmas.h"
#include <iostream>
#include <fstream>
using namespace std;

// Función para capturar los datos del cliente
void capturarDatosCliente(Cliente *cliente) {
    fflush(stdin);
    cout << "Introduzca el nombre del cliente: ";
    getline(cin, cliente->nombre);

    cout << "Introduzca la dirección del cliente: ";
    getline(cin, cliente->direccion);

    cout << "Introduzca la edad del cliente: ";
    cin >> cliente->edad;

    cout << "Introduzca el teléfono del cliente: ";
    cin >> cliente->telefono;
}

// Función para imprimir la factura
void imprimirFactura(Cliente *cliente) {
    ofstream factura;
    factura.open("factura.txt");

    factura << "Nombre: " << cliente->nombre << endl;
    factura << "Dirección: " << cliente->direccion << endl;
    factura << "Edad: " << cliente->edad << endl;
    factura << "Teléfono: " << cliente->telefono << endl;

    factura.close();

    cout << "La factura ha sido guardada en el archivo factura.txt" << endl;
}