 #include "Pelicula.hpp"
 #include <iostream>

 Pelicula::Pelicula(int id, const std::string& nombre, int duracion, const std::string& genero)
     : Contenido(id, nombre, duracion, genero) {}

 void Pelicula::mostrarDetalle() const {
     std::cout << "\nID: " << id << std::endl;
     std::cout << "Película: " << nombre << std::endl;
     std::cout << "Duración: " << duracion << " minutos" << std::endl;
     std::cout << "Género: " << genero << std::endl;
 }

 void Pelicula::mostrarNombre() const {
     std::cout << "Película: " << nombre << std::endl;
 }