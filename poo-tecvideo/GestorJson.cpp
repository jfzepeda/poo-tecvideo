 #include "GestorJson.hpp"
 #include <fstream>
 #include <iostream>
 #include "libs/json.hpp"
 using namespace std;

 using json = nlohmann::json;

 bool GestorJson::escribir(int id, float calificacion) {
     try {
         json j;
         ifstream inFile("calificaciones.json");
         if (inFile.is_open()) {
             if (inFile.peek() != ifstream::traits_type::eof()) {
                 inFile >> j;
             }
             inFile.close();
         }
         string id_str = to_string(id);
         j[id_str].push_back(calificacion);

         ofstream outFile("calificaciones.json");
         if (!outFile.is_open()) {
             cout << "Error al abrir el archivo para escribir." << endl;
             return false;
         }
         outFile << j.dump(4);
         outFile.close();
         return true;
     } catch (const exception& e) {
         cerr << "Excepción al escribir en el archivo: " << e.what() << endl;
         return false;
     }
 }

 float GestorJson::leer(int id, bool firstGet) {
     try {
         ifstream archivo("calificaciones.json");
         if (!archivo.is_open()) {
             cerr << "No se pudo abrir el archivo." << endl;
             return -1;
         }
         if (archivo.peek() == ifstream::traits_type::eof()) {
             archivo.close();
             return 0;
         }
         json j;
         try {
             archivo >> j;
         } catch (const json::parse_error& e) {
             cerr << "Error al parsear JSON: " << e.what() << endl;
             archivo.close();
             return 0;
         }
         archivo.close();

         string key = to_string(id);
         if ((!j.contains(key) || !j[key].is_array()) && !firstGet) {
             cerr << "No hay calificaciones para el ID proporcionado." << endl;
             return -1;
         }
         float suma = 0;
         for (float cal : j[key]) {
             suma += cal;
         }
         float promedio = j[key].size() > 0 ? suma / j[key].size() : 0;
         return promedio;
     } catch (const exception& e) {
         cerr << "Excepción al leer el archivo: " << e.what() << endl;
         return -1;
     }
 }