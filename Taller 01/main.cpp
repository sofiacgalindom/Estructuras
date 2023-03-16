#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include "firmas.h"

using namespace std;



// Función principal
int main() {
    int opcion;

    do {
        cout << "MENU" << endl;
        cout << "1. Generar array aleatorio" << endl;
        cout << "2. Capturar datos del cliente y generar factura" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int tam = 10;
                int array[tam];
                srand(time(NULL));
                for (int i = 0; i < tam; i++) {
                    array[i] = rand() % 26;
                }
                cout << "Contenido del array:" << endl;
                for (int i = 0; i < tam; i++) {
                    cout << "array[" << i << "] = " << array[i] << endl;
                }
                cout << "Direcciones del contenido del array:" << endl;
                for (int i = 0; i < tam; i++) {
                    cout << "Dirección de array[" << i << "] = " << &array[i] << endl;
                }
                break;
            }
            case 2: {
                Cliente cliente;
                capturarDatosCliente(&cliente);
                imprimirFactura(&cliente);
                break;
            }
            case 3: {
                cout << "Saliendo del programa..." << endl;
                break;
            }
            default: {
                cout << "Opción inválida. Inténtelo de nuevo." << endl;
                break;
            }
        }

    } while (opcion != 3);

    return 0;
}
