 #pragma once

 #include "Contenido.hpp"
 #include "Episodio.hpp"
 #include <vector>
 using namespace std;

 class Serie : public Contenido {
 public:
     Serie(int id, const string& nombre, int duracion, const string& genero);
     void mostrarDetalle() const override;
     void mostrarNombre() const override;
     void mostrarEpisodios() const;

     void agregarEpisodio(const string& titulo);

 private:
     vector<Episodio> episodios;
 };