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
     for (const Pelicula* pelicula : peliculas) {
         pelicula->mostrarNombre();
     }
 }

 void Filmoteca::mostrarSeries() const {
     cout << "\nSeries:" << endl;
     for (const Serie* serie : series) {
         serie->mostrarNombre();
     }
 }

 void Filmoteca::mostrarContenido() const {
     mostrarPeliculas();
     mostrarSeries();
 }

 Pelicula* Filmoteca::buscarPeli(int id) const {
     for (Pelicula* pelicula : peliculas) {
         if (pelicula->getId() == id) {
             return pelicula;
         }
     }
     return nullptr;
 }

 Serie* Filmoteca::buscarSerie(int id) const {
     for (Serie* serie : series) {
         if (serie->getId() == id) {
             return serie;
         }
     }
     return nullptr;
 }

vector<Pelicula*> Filmoteca::filtrarPeliculasPorGenero(const string& genero) const {
    vector<Pelicula*> resultado;
    for (Pelicula* pelicula : peliculas) {
        if (pelicula->getGenero() == genero) {
            resultado.push_back(pelicula);
        }
    }
    return resultado;
}

vector<Pelicula*> Filmoteca::ordenarPeliculasPorCalificacion() const {
    vector<Pelicula*> resultado = peliculas;
    sort(resultado.begin(), resultado.end(), [](Pelicula* a, Pelicula* b) {
        return a->getCalificacion() > b->getCalificacion();
    });
    return resultado;
}

vector<Serie*> Filmoteca::filtrarSeriesPorGenero(const string& genero) const {
    vector<Serie*> resultado;
    for (Serie* serie : series) {
        if (serie->getGenero() == genero) {
            resultado.push_back(serie);
        }
    }
    return resultado;
}

vector<Serie*> Filmoteca::ordenarSeriesPorCalificacion() const {
    vector<Serie*> resultado = series;
    sort(resultado.begin(), resultado.end(), [](Serie* a, Serie* b) {
        return a->getCalificacion() > b->getCalificacion();
    });
    return resultado;
}