 #pragma once

 #include "Contenido.hpp"
 using namespace std;

 class Pelicula : public Contenido {
 public:
     Pelicula(int id, const string& nombre, int duracion, const string& genero);
     void mostrarDetalle() const override;
     void mostrarNombre() const override;
 };