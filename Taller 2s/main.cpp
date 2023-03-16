#include <iostream>
#include "funciones.h"
#include "autores.h"
using namespace std;

int main()
{
    bool bandera = true;
    while(bandera){
    int opcion;
    set<cAutor> autores;
    cargarInformacion(autores, "example1.txt");
    cout << "Ingrese una opcion: " << endl;
    cout << "1. Listar autores alfabeticamente" << endl;
    cout << "2. Listar canciones de un autor" << endl;
    cout << "3. Listar albumes de un autor" << endl;
    cout << "4. Listar albumes en orden cronologico" << endl;
    cout << "5. Listar canciones de un album" << endl;
    cout << "6. Listar canciones y albumes" << endl;
    cout << "7. Salir" << endl;
    cin >> opcion;
    switch (opcion) {
    case 1:
        autoresAlfabeticamente(autores);
        break;
    case 2:{
        string nombre;
        cout << "Ingrese el nombre del autor: " << endl;
        cin >> nombre;
        cancionPorAutor(autores, nombre);
    }
        break;
    case 3:
        listarAlbums(autores);
        break;
    case 4:
        listarAlbumsCronologicamente(autores);
        break;
    case 5:{
        string titulo;
        cout << "Ingrese el titulo del album: " << endl;
        cin >> titulo;
        listarCancionesDadoAlbum(autores, titulo);
    }
        break;
    case 6:
        listarCancionesyAlbum(autores);
        break;
    case 7:
        bandera = false;
        cout << "Saliendo..." << endl;
        break;
    default:
        cout << "Opcion invalida" << endl;
        break;
    }
    }


    return 0;
}

