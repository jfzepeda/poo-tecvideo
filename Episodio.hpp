 #pragma once

 #include <string>

 class Episodio {
 private:
     std::string titulo;
     int temporada;

 public:
     Episodio(const std::string& titulo, int temporada);
     void imprimir() const;
 };