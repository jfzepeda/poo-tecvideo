 #pragma once

 #include <vector>
 #include "Pelicula.hpp"
 #include "Serie.hpp"

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

 private:
     static constexpr size_t MAX_PELICULAS = 100;
     static constexpr size_t MAX_SERIES = 100;
     std::vector<Pelicula*> peliculas;
     std::vector<Serie*> series;
 };