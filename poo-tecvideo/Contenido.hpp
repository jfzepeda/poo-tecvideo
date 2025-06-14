 #pragma once

 #include <string>
 using namespace std;

 class Contenido {
 protected:
     int id;
     string nombre;
     int duracion;
     string genero;
 private:
     float calificacion;

 public:
     Contenido(int id, const string& nombre, int duracion, const string& genero);
     virtual ~Contenido() = default;

     virtual void mostrarDetalle() const = 0;
     virtual void mostrarNombre() const = 0;

     void mostrarCalificacion(bool actualizado = false) const;
     void calificar(float nuevaCalificacion);

    int getId() const noexcept;
    const string& getGenero() const noexcept;
    float getCalificacion() const noexcept;
};