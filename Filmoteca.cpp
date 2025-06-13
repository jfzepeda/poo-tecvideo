#include "Filmoteca.hpp"
#include <iostream>
#include <algorithm>
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

std::vector<Pelicula*> Filmoteca::filtrarPeliculasPorGenero(const std::string& genero) const {
    std::vector<Pelicula*> resultado;
    for (auto* pelicula : peliculas) {
        if (pelicula->getGenero() == genero) {
            resultado.push_back(pelicula);
        }
    }
    return resultado;
}

std::vector<Pelicula*> Filmoteca::ordenarPeliculasPorCalificacion() const {
    std::vector<Pelicula*> resultado = peliculas;
    std::sort(resultado.begin(), resultado.end(), [](Pelicula* a, Pelicula* b) {
        return a->getCalificacion() > b->getCalificacion();
    });
    return resultado;
}

std::vector<Serie*> Filmoteca::filtrarSeriesPorGenero(const std::string& genero) const {
    std::vector<Serie*> resultado;
    for (auto* serie : series) {
        if (serie->getGenero() == genero) {
            resultado.push_back(serie);
        }
    }
    return resultado;
}

std::vector<Serie*> Filmoteca::ordenarSeriesPorCalificacion() const {
    std::vector<Serie*> resultado = series;
    std::sort(resultado.begin(), resultado.end(), [](Serie* a, Serie* b) {
        return a->getCalificacion() > b->getCalificacion();
    });
    return resultado;
}