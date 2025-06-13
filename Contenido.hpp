 #pragma once

 #include <string>

 class Contenido {
 protected:
     int id;
     std::string nombre;
     int duracion;
     std::string genero;
 private:
     float calificacion;

 public:
     Contenido(int id, const std::string& nombre, int duracion, const std::string& genero);
     virtual ~Contenido() = default;

     virtual void mostrarDetalle() const = 0;
     virtual void mostrarNombre() const = 0;

     void mostrarCalificacion(bool actualizado = false) const;
     void calificar(float nuevaCalificacion);

     int getId() const noexcept;
};