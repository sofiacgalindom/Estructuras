#include "autores.h"

using namespace std;

cCancion:: cCancion(string titulo, string genero){
    this->titulo = titulo;
    this->genero = genero;
}

string cCancion:: getTitulo(){
    return this->titulo;
}

string cCancion:: getGenero(){
    return this->genero;
}

void cCancion:: setTitulo(string titulo){
    this->titulo = titulo;
}

void cCancion:: setGenero(string genero){
    this->genero = genero;
}

bool cCancion:: operator < (const cCancion& cancion) const{
    return this->titulo < cancion.titulo;
}



cAlbum:: cAlbum(string titulo, int anio){
    this->titulo = titulo;
    this->anio = anio;
}

string cAlbum:: getTitulo(){
    return this->titulo;
}

int cAlbum:: getAnio(){
    return this->anio;
}

set<cCancion> cAlbum:: getCanciones(){
    return this->canciones;
}

void cAlbum:: setTitulo(string titulo){
    this->titulo = titulo;
}

void cAlbum:: setAnio(int anio){
    this->anio = anio;
}

void cAlbum:: setCanciones(set<cCancion> canciones){
    this->canciones = canciones;
}

void cAlbum:: agregarCancion(cCancion cancion){
    this->canciones.insert(cancion);
}

bool cAlbum:: operator < (const cAlbum& album) const{
    return this->titulo < album.titulo;
}

bool cAlbum:: operator!=(const cAlbum& album) const{
    return this->titulo != album.titulo;
}

cAutor:: cAutor(string nombre){
    this->nombre = nombre;
}

string cAutor:: getNombre(){
    return this->nombre;
}

set<cAlbum> cAutor:: getAlbums(){
    return this->albums;
}

void cAutor:: setNombre(string nombre){
    this->nombre = nombre;
}

void cAutor:: setAlbums(set<cAlbum> albums){
    this->albums = albums;
}

void cAutor:: agregarAlbum(cAlbum album){
    this->albums.insert(album);
}

bool cAutor:: operator<(const cAutor& autor) const{
    return this->nombre < autor.nombre;
}

bool cAutor:: operator!=(const cAutor& autor) const{
    return this->nombre != autor.nombre;
}

