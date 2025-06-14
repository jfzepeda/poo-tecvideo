 #include "Episodio.hpp"
 #include <iostream>
 using namespace std;

 Episodio::Episodio(const string& titulo, int temporada)
     : titulo(titulo), temporada(temporada) {}

 void Episodio::imprimir() const {
     cout << "T-" << temporada << " : " << titulo << endl;
 }