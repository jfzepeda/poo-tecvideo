 #pragma once

 #include "Contenido.hpp"
 #include "Episodio.hpp"
 #include <vector>

 class Serie : public Contenido {
 public:
     Serie(int id, const std::string& nombre, int duracion, const std::string& genero);
     void mostrarDetalle() const override;
     void mostrarNombre() const override;
     void mostrarEpisodios() const;

     void agregarEpisodio(const std::string& titulo);

 private:
     static constexpr size_t MAX_EPISODIOS = 12;
     static constexpr int EPISODIOS_POR_TEMPORADA = 4;
     std::vector<Episodio> episodios;
 };