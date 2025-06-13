 #include "Episodio.hpp"
 #include <iostream>

 Episodio::Episodio(const std::string& titulo, int temporada)
     : titulo(titulo), temporada(temporada) {}

 void Episodio::imprimir() const {
     std::cout << "T-" << temporada << " : " << titulo << std::endl;
 }