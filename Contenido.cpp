 #include "Contenido.hpp"
 #include <iostream>
 #include "GestorJson.hpp"

 Contenido::Contenido(int id, const std::string& nombre, int duracion, const std::string& genero)
     : id(id), nombre(nombre), duracion(duracion), genero(genero) {
     calificacion = GestorJson::leer(id, true);
 }

 void Contenido::mostrarCalificacion(bool actualizado) const {
     if (actualizado) {
         std::cout << "Calificación media: " << calificacion << std::endl;
     }
 }

 void Contenido::calificar(float nuevaCalificacion) {
     if (nuevaCalificacion >= 0 && nuevaCalificacion <= 10) {
         GestorJson::escribir(id, nuevaCalificacion);
         calificacion = GestorJson::leer(id);
         mostrarCalificacion(true);
     } else {
         std::cout << "Calificación inválida. Debe estar entre 0 y 10." << std::endl;
     }
 }

 int Contenido::getId() const noexcept {
     return id;
 }