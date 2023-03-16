#include <iostream>
#include <set>
#include <string>
#include <fstream>
#include <cstring>
#include <vector>
#include <sstream>
#include <typeinfo>
#include "funciones.h"
#include "autores.h"

using namespace std;

vector<string> leerLineaArchivo(string filename){
    ifstream file;
    file.open(filename);
    vector<string> lineas;
    string linea;
    while (getline(file, linea)) {
        lineas.push_back(linea);
    }
    file.close();
    return lineas;
}

void tokenizarlinea(string linea, vector<string> &tokens){
    stringstream ss(linea);
    string token;
    while(getline(ss, token, '|')){
        tokens.push_back(token);
    }
}



cAutor encontrarAutor(set<cAutor> autores, string nombre){
    for(auto autor:autores){
        if(autor.getNombre() == nombre){
            return autor;
        }
    }
    return cAutor("No encontrado");
}

cAlbum encontrarAlbum(set<cAlbum> albums, string titulo){
    for(auto album:albums){
        if(album.getTitulo() == titulo){
            return album;
        }
    }
    return cAlbum("No encontrado", 0);
}

//cancion3_al2_au2|autor2|genero6|album2_au2|2006
void cargarInformacion(set<cAutor> &autores, string filename){
    vector<string> lineas = leerLineaArchivo(filename);
    for (int i = 0; i < lineas.size(); i++) {
        if(i==0){
            continue;
        }
        
        vector<string> tokens;
        tokenizarlinea(lineas[i], tokens);

        cAutor autor(tokens[1]);

        cAlbum album(tokens[3], stoi(tokens[4]));

        cCancion cancion(tokens[0], tokens[2]);

        cAutor autorEncontrado = encontrarAutor(autores, autor.getNombre());

        if(autorEncontrado != cAutor("No encontrado")){
            autores.erase(autorEncontrado);
            cAlbum albumEncontrado = encontrarAlbum(autorEncontrado.getAlbums(), album.getTitulo());
            if(albumEncontrado != cAlbum("No encontrado", 0)){
                albumEncontrado.agregarCancion(cancion);
            }else{
                album.agregarCancion(cancion);
                autorEncontrado.agregarAlbum(album);
            }
            autores.insert(autorEncontrado);
        }else{
            album.agregarCancion(cancion);
            autor.agregarAlbum(album);
            autores.insert(autor);
        }
    }
}

void autoresAlfabeticamente(set<cAutor> autores){
    for(auto autor:autores){
        cout << autor.getNombre() << endl;
    }
}

void cancionPorAutor(set<cAutor> autores, string nombreautor){
    for(auto autor:autores){
        if(autor.getNombre() == nombreautor){
            for(auto album:autor.getAlbums()){
                for(auto cancion:album.getCanciones()){
                    cout << cancion.getTitulo() << endl;
                }
            }
        }
    }
}

void listarAlbums(set<cAutor> autores){
    for(auto autor:autores){
        for(auto album:autor.getAlbums()){
            cout << album.getTitulo() << endl;
        }
    }
}

void listarAlbumsCronologicamente(set<cAutor> autores){
    vector <cAlbum> albums;
    for(auto autor:autores){
        for(auto album:autor.getAlbums()){
            albums.push_back(album);
        }
    }
    for(int i = 0; i < albums.size(); i++){
        for(int j = 0; j < albums.size(); j++){
            if(albums[i].getAnio() < albums[j].getAnio()){
                cAlbum aux = albums[i];
                albums[i] = albums[j];
                albums[j] = aux;
            }
        }
    }
    for(auto album:albums){
        cout << album.getTitulo() << '-' <<album.getAnio() << endl;
    }
}

void listarCancionesDadoAlbum(set<cAutor> autores, string tituloalbum){
    for(auto autor:autores){
        for(auto album:autor.getAlbums()){
            if(album.getTitulo() == tituloalbum){
                for(auto cancion:album.getCanciones()){
                    cout << cancion.getTitulo() << endl;
                }
            }
        }
    }
}

void listarCancionesyAlbum(set<cAutor>autores){
    for(auto autor:autores){
        for(auto album:autor.getAlbums()){
            for(auto cancion:album.getCanciones()){
                cout << cancion.getTitulo() << " - " << album.getTitulo() << endl;
            }
        }
    }
}
