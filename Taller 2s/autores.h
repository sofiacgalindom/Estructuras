#ifndef AUTORES_H
#define AUTORES_H

#include <iostream>
#include <iterator>
#include <list>
#include <sstream>
#include <string>
#include <set>
#include <vector>

using namespace std;

class cCancion{
    private:
    string titulo;
    string genero;
    public:
    cCancion(string titulo, string genero);
    string getTitulo();
    string getGenero();
    void setTitulo(string titulo);
    void setGenero(string genero);
    bool operator < (const cCancion& cancion) const;
    bool operator != (const cCancion& cancion) const;
};

class cAlbum{
    private:
    string titulo;
    int anio;
    set<cCancion> canciones;
    public:
    cAlbum(string titulo, int anio);
    string getTitulo();
    int getAnio();
    set<cCancion> getCanciones();
    void setTitulo(string titulo);
    void setAnio(int anio);
    void setCanciones(set<cCancion> canciones);
    void agregarCancion(cCancion cancion);
    bool operator < (const cAlbum& album) const;
    bool operator != (const cAlbum& album) const;
};

class cAutor{
    private:
    string nombre;
    set<cAlbum> albums;
    public:
    cAutor(string nombre);
    string getNombre();
    set<cAlbum> getAlbums();
    void setNombre(string nombre);
    void setAlbums(set<cAlbum> albums);
    void agregarAlbum(cAlbum album);
    bool operator < (const cAutor& autor) const;
    bool operator != (const cAutor& autor) const;

};


#endif // AUTORES_H