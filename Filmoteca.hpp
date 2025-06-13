 #pragma once

 #include <vector>
 #include "Pelicula.hpp"
 #include "Serie.hpp"
 using namespace std;

 class Filmoteca {
 public:
     Filmoteca() = default;
     void agregarPelicula(Pelicula* pelicula);
     void agregarSerie(Serie* serie);

     void mostrarPeliculas() const;
     void mostrarSeries() const;
     void mostrarContenido() const;

     Pelicula* buscarPeli(int id) const;
    Serie* buscarSerie(int id) const;

    vector<Pelicula*> filtrarPeliculasPorGenero(const string& genero) const;
    vector<Pelicula*> ordenarPeliculasPorCalificacion() const;
    vector<Serie*> filtrarSeriesPorGenero(const string& genero) const;
    vector<Serie*> ordenarSeriesPorCalificacion() const;

 private:
     static constexpr size_t MAX_PELICULAS = 100;
     static constexpr size_t MAX_SERIES = 100;
     vector<Pelicula*> peliculas;
     vector<Serie*> series;
 };