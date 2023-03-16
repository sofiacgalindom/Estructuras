#ifndef FUNCIONES_H
#define FUNCIONES_H


#include <iostream>
#include <iterator>
#include <list>
#include <sstream>
#include <string>
#include <set>
#include <vector>
#include "autores.h"
using namespace std;

vector<string> leerLineaArchivo(string filename);
void tokenizarlinea(string linea, vector<string> &tokens);
void cargarInformacion(set<cAutor> &autores, string filename);
cAutor encontrarAutor(set<cAutor> autores, string nombre);
cAlbum encontrarAlbum(set<cAlbum> albums, string titulo);
void autoresAlfabeticamente(set<cAutor> autores);
void cancionPorAutor(set<cAutor> autores, string nombre);
void listarAlbums(set<cAutor> autores);
void listarAlbumsCronologicamente(set<cAutor> autores);
void listarCancionesDadoAlbum(set<cAutor> autores, string titulo);
void listarCancionesyAlbum(set<cAutor>autores);




#endif /* FUNCIONES_H */