 #include "Serie.hpp"
 #include <iostream>
 using namespace std;

 Serie::Serie(int id, const string& nombre, int duracion, const string& genero)
     : Contenido(id, nombre, duracion, genero) {}

 void Serie::mostrarDetalle() const {
     cout << "\nID: " << id << endl;
     cout << "Serie: " << nombre << endl;
     cout << "Duración: " << (duracion * episodios.size()) << " minutos" << endl;
     cout << "Género: " << genero << endl;
 }

 void Serie::mostrarEpisodios() const {
     cout << "Episodios de la serie " << nombre << ":" << endl;
     for (const auto& ep : episodios) {
         ep.imprimir();
     }
 }

 void Serie::mostrarNombre() const {
     cout << "Serie: " << nombre << endl;
 }

 void Serie::agregarEpisodio(const string& titulo) {
     if (episodios.size() < 12) {
         int temporada = static_cast<int>(episodios.size()) / 4 + 1;
         episodios.emplace_back(titulo, temporada);
     } else {
         cout << "No se pueden agregar más episodios." << endl;
     }
 }