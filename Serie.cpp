 #include "Serie.hpp"
 #include <iostream>

 Serie::Serie(int id, const std::string& nombre, int duracion, const std::string& genero)
     : Contenido(id, nombre, duracion, genero) {}

 void Serie::mostrarDetalle() const {
     std::cout << "\nID: " << id << std::endl;
     std::cout << "Serie: " << nombre << std::endl;
     std::cout << "Duración: " << (duracion * episodios.size()) << " minutos" << std::endl;
     std::cout << "Género: " << genero << std::endl;
 }

 void Serie::mostrarEpisodios() const {
     std::cout << "Episodios de la serie " << nombre << ":" << std::endl;
     for (const auto& ep : episodios) {
         ep.imprimir();
     }
 }

 void Serie::mostrarNombre() const {
     std::cout << "Serie: " << nombre << std::endl;
 }

 void Serie::agregarEpisodio(const std::string& titulo) {
     if (episodios.size() < MAX_EPISODIOS) {
         int temporada = static_cast<int>(episodios.size()) / EPISODIOS_POR_TEMPORADA + 1;
         episodios.emplace_back(titulo, temporada);
     } else {
         std::cout << "No se pueden agregar más episodios." << std::endl;
     }
 }