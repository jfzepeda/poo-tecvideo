 #pragma once

 #include <string>
 using namespace std;

 class Episodio {
 private:
     string titulo;
     int temporada;

 public:
     Episodio(const string& titulo, int temporada);
     void imprimir() const;
 };