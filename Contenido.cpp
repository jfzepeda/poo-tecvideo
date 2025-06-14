 #include "Contenido.hpp"
 #include <iostream>
 #include "GestorJson.hpp"
 using namespace std;

 Contenido::Contenido(int id, const string& nombre, int duracion, const string& genero)
     : id(id), nombre(nombre), duracion(duracion), genero(genero) {
     calificacion = GestorJson::leer(id, true);
 }

 void Contenido::mostrarCalificacion(bool actualizado) const {
     if (actualizado) {
         cout << "Calificación media: " << calificacion << endl;
     }
 }

 void Contenido::calificar(float nuevaCalificacion) {
     if (nuevaCalificacion >= 0 && nuevaCalificacion <= 10) {
         GestorJson::escribir(id, nuevaCalificacion);
         calificacion = GestorJson::leer(id);
         mostrarCalificacion(true);
     } else {
         cout << "Calificación inválida. Debe estar entre 0 y 10." << endl;
     }
 }

 int Contenido::getId() const noexcept {
     return id;
 }

const string& Contenido::getGenero() const noexcept {
    return genero;
}

float Contenido::getCalificacion() const noexcept {
    return calificacion;
}

bool operator>(const Contenido& a, const Contenido& b) {
    return a.getCalificacion() > b.getCalificacion();
}

const string& Contenido::getNombre() const {
    return nombre;
}
