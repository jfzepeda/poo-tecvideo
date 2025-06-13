 #include "GestorJson.hpp"
 #include <fstream>
 #include <iostream>
 #include "libs/json.hpp"

 using json = nlohmann::json;

 bool GestorJson::escribir(int id, float calificacion) {
     try {
         json j;
         std::ifstream inFile("calificaciones.json");
         if (inFile.is_open()) {
             if (inFile.peek() != std::ifstream::traits_type::eof()) {
                 inFile >> j;
             }
             inFile.close();
         }
         std::string id_str = std::to_string(id);
         j[id_str].push_back(calificacion);

         std::ofstream outFile("calificaciones.json");
         if (!outFile.is_open()) {
             std::cout << "Error al abrir el archivo para escribir." << std::endl;
             return false;
         }
         outFile << j.dump(4);
         outFile.close();
         return true;
     } catch (const std::exception& e) {
         std::cerr << "Excepción al escribir en el archivo: " << e.what() << std::endl;
         return false;
     }
 }

 float GestorJson::leer(int id, bool firstGet) {
     try {
         std::ifstream archivo("calificaciones.json");
         if (!archivo.is_open()) {
             std::cerr << "No se pudo abrir el archivo." << std::endl;
             return -1;
         }
         if (archivo.peek() == std::ifstream::traits_type::eof()) {
             archivo.close();
             return 0;
         }
         json j;
         try {
             archivo >> j;
         } catch (const json::parse_error& e) {
             std::cerr << "Error al parsear JSON: " << e.what() << std::endl;
             archivo.close();
             return 0;
         }
         archivo.close();

         std::string key = std::to_string(id);
         if ((!j.contains(key) || !j[key].is_array()) && !firstGet) {
             std::cerr << "No hay calificaciones para el ID proporcionado." << std::endl;
             return -1;
         }
         float suma = 0;
         for (float cal : j[key]) {
             suma += cal;
         }
         float promedio = j[key].size() > 0 ? suma / j[key].size() : 0;
         return promedio;
     } catch (const std::exception& e) {
         std::cerr << "Excepción al leer el archivo: " << e.what() << std::endl;
         return -1;
     }
 }