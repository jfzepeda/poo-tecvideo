 #include "Filmoteca.hpp"
 #include <iostream>

 void Filmoteca::agregarPelicula(Pelicula* pelicula) {
     if (peliculas.size() < MAX_PELICULAS) {
         peliculas.push_back(pelicula);
     } else {
         std::cout << "No se pueden agregar más películas." << std::endl;
     }
 }

 void Filmoteca::agregarSerie(Serie* serie) {
     if (series.size() < MAX_SERIES) {
         series.push_back(serie);
     } else {
         std::cout << "No se pueden agregar más series." << std::endl;
     }
 }

 void Filmoteca::mostrarPeliculas() const {
     std::cout << "\nPelículas:" << std::endl;
     for (const auto* pelicula : peliculas) {
         pelicula->mostrarNombre();
     }
 }

 void Filmoteca::mostrarSeries() const {
     std::cout << "\nSeries:" << std::endl;
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