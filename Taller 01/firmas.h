#ifndef firma_h
#define firma_h
#include <iostream>


// Definimos la estructura Cliente
struct Cliente {
    std::string nombre;
    std::string direccion;
    int edad;
    std::string telefono;
};

// Función para capturar los datos del cliente
void capturarDatosCliente(Cliente *cliente) ;

// Función para imprimir la factura
void imprimirFactura(Cliente *cliente);

#endif