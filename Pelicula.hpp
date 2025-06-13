 #pragma once

 #include "Contenido.hpp"

 class Pelicula : public Contenido {
 public:
     Pelicula(int id, const std::string& nombre, int duracion, const std::string& genero);
     void mostrarDetalle() const override;
     void mostrarNombre() const override;
 };