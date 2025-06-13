 #include "Filmoteca.hpp"
 #include <iostream>
 using namespace std;

 void Filmoteca::agregarPelicula(Pelicula* pelicula) {
     if (peliculas.size() < MAX_PELICULAS) {
         peliculas.push_back(pelicula);
     } else {
         cout << "No se pueden agregar más películas." << endl;
     }
 }

 void Filmoteca::agregarSerie(Serie* serie) {
     if (series.size() < MAX_SERIES) {
         series.push_back(serie);
     } else {
         cout << "No se pueden agregar más series." << endl;
     }
 }

 void Filmoteca::mostrarPeliculas() const {
     cout << "\nPelículas:" << endl;
     for (const auto* pelicula : peliculas) {
         pelicula->mostrarNombre();
     }
 }

 void Filmoteca::mostrarSeries() const {
     cout << "\nSeries:" << endl;
     for (const auto* serie : series) {
         serie->mostrarNombre();
     }
 }

 void Filmoteca::mostrarContenido() const {
     mostrarPeliculas();
     mostrarSeries();
 }

 Pelicula* Filmoteca::buscarPeli(int id) const {
     for (auto* pelicula : peliculas) {
         if (pelicula->getId() == id) {
             return pelicula;
         }
     }
     return nullptr;
 }

 Serie* Filmoteca::buscarSerie(int id) const {
     for (auto* serie : series) {
         if (serie->getId() == id) {
             return serie;
         }
     }
     return nullptr;
 }