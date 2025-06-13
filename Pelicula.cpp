 #include "Pelicula.hpp"
 #include <iostream>
 using namespace std;

 Pelicula::Pelicula(int id, const string& nombre, int duracion, const string& genero)
     : Contenido(id, nombre, duracion, genero) {}

 void Pelicula::mostrarDetalle() const {
     cout << "\nID: " << id << endl;
     cout << "Película: " << nombre << endl;
     cout << "Duración: " << duracion << " minutos" << endl;
     cout << "Género: " << genero << endl;
 }

 void Pelicula::mostrarNombre() const {
     cout << "Película: " << nombre << endl;
 }