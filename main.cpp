// === MAIN DE PRUEBA ===
#include <iostream>
#include <cstdlib>
#include <string>

#include "GestorJson.hpp"
#include "Pelicula.hpp"
#include "Episodio.hpp"
#include "Serie.hpp"
#include "Filmoteca.hpp"

using namespace std;

void handlePeliculas(Filmoteca& filmoteca);
void handleSeries(Filmoteca& filmoteca);
void handleContenido(const Filmoteca& filmoteca);

void print(const string& s) {
    cout << s << endl;
}

int reproducirVideo(int id) {
    print("\nQuieres ver la pelicula?  SI / NO");
    string respuesta;
    cin >> respuesta;
    if (respuesta != "SI" && respuesta != "si") {
        cout << "OK" << endl;
        return 0;
    }

    if (id == 4) {
        cerr << "ID de vídeo inválido. Por ahora no tenemos la 4\n";
        return 1;
    }
    string ruta = "assets/pelicula_" + to_string(id) + ".mp4";
    string cmd = string("open \"") + ruta + "\"";
    int res = system(cmd.c_str());
    if (res != 0) {
        cerr << "Error al abrir el vídeo (código " << res << ")\n";
        return 1;
    }
    return 0;
}

void handleCalificar(Serie* serie) {
    print("\nQuieres calificar la serie?  SI / NO");
    string respuesta;
    cin >> respuesta;
    if (respuesta != "SI" && respuesta != "si") {
        cout << "OK" << endl;
        return;
    } else {
        float nuevaCalificacion;
        cout << "Ingrese una nueva calificación (0-5): ";
        cin >> nuevaCalificacion;
        if (nuevaCalificacion >= 0 && nuevaCalificacion <= 5) {
            serie->calificar(nuevaCalificacion);
        } else {
            cout << "Calificación inválida. Debe estar entre 0 y 5." << endl;
        }
    }
}

void handleCalificar(Pelicula* pelicula) {
    print("\nQuieres calificar la película?  SI / NO");
    string respuesta;
    cin >> respuesta;
    if (respuesta != "SI" && respuesta != "si") {
        cout << "OK" << endl;
        return;
    } else {
        float nuevaCalificacion;
        cout << "Ingrese una nueva calificación (0-5): ";
        cin >> nuevaCalificacion;
        if (nuevaCalificacion >= 0 && nuevaCalificacion <= 5) {
            pelicula->calificar(nuevaCalificacion);
        } else {
            cout << "Calificación inválida. Debe estar entre 0 y 5." << endl;
        }
    }
}

void handlePeliculas(Filmoteca& filmoteca) {
    filmoteca.mostrarPeliculas();
    cout << "\nSeleccione una película para mostrar detalles (1-6): ";
    int idPelicula;
    cin >> idPelicula;
    if (idPelicula >= 1 && idPelicula <= 6) {
        Pelicula* pelicula = filmoteca.buscarPeli(idPelicula);
        if (pelicula) {
            pelicula->mostrarDetalle();
            handleCalificar(pelicula);
            reproducirVideo(idPelicula);
        } else {
            cout << "Película no encontrada." << endl;
        }
    } else {
        cout << "ID de película no válido." << endl;
    }
}

void handleSeries(Filmoteca& filmoteca) {
    filmoteca.mostrarSeries();
    cout << "\nSeleccione una serie para mostrar detalles (1-4): ";
    int idSerie;
    cin >> idSerie;
    idSerie += 6; // Ajustar el rango de series (7-10)
    if (idSerie >= 7 && idSerie <= 10) {
        Serie* serie = filmoteca.buscarSerie(idSerie);
        if (serie) {
            serie->mostrarDetalle();
            serie->mostrarEpisodios();
            handleCalificar(serie);
        } else {
            cout << "Serie no encontrada." << endl;
        }
    } else {
        cout << "ID de serie no válido." << endl;
    }
}

void handleContenido(const Filmoteca& filmoteca) {
    filmoteca.mostrarContenido();
}

int main() {
    // géneros permitidos (drama, acción, misterio).
    Pelicula peli1(1, "Avengers Endgame", 180, "Accion");
    Pelicula peli2(2, "The Dark Knight", 152, "Accion");
    Pelicula peli3(3, "Titanic", 195, "Drama");
    Pelicula peli4(4, "Inception", 148, "Misterio");
    Pelicula peli5(5, "The Godfather", 175, "Drama");
    Pelicula peli6(6, "Interstellar", 169, "Misterio");

    Serie serie1(7, "Serie de Drama", 40, "Drama");
    serie1.agregarEpisodio("Episodio 1");
    serie1.agregarEpisodio("Episodio 2");
    serie1.agregarEpisodio("Episodio 3");
    serie1.agregarEpisodio("Episodio 4");
    serie1.agregarEpisodio("Episodio 5");
    serie1.agregarEpisodio("Episodio 6");
    serie1.agregarEpisodio("Episodio 7");
    serie1.agregarEpisodio("Episodio 8");
    serie1.agregarEpisodio("Episodio 9");
    serie1.agregarEpisodio("Episodio 10");
    serie1.agregarEpisodio("Episodio 11");
    serie1.agregarEpisodio("Episodio 12");

    Serie serie2(8, "Serie de Accion", 50, "Accion");
    serie2.agregarEpisodio("Episodio 1");
    serie2.agregarEpisodio("Episodio 2");
    serie2.agregarEpisodio("Episodio 3");
    serie2.agregarEpisodio("Episodio 4");
    serie2.agregarEpisodio("Episodio 5");

    Serie serie3(9, "Serie de Misterio", 45, "Misterio");
    serie3.agregarEpisodio("Episodio 1");
    serie3.agregarEpisodio("Episodio 2");
    serie3.agregarEpisodio("Episodio 3");

    Serie serie4(10, "Serie de Accion", 55, "Accion");
    serie4.agregarEpisodio("Episodio 1");
    serie4.agregarEpisodio("Episodio 2");
    serie4.agregarEpisodio("Episodio 3");

    Filmoteca filmoteca;
    filmoteca.agregarPelicula(&peli1);
    filmoteca.agregarPelicula(&peli2);
    filmoteca.agregarPelicula(&peli3);
    filmoteca.agregarPelicula(&peli4);
    filmoteca.agregarPelicula(&peli5);
    filmoteca.agregarPelicula(&peli6);
    filmoteca.agregarSerie(&serie1);
    filmoteca.agregarSerie(&serie2);
    filmoteca.agregarSerie(&serie3);
    filmoteca.agregarSerie(&serie4);

    while (true) {
        cout << "\nSeleccione una opción:" << endl;
        cout << "1. Mostrar Películas" << endl;
        cout << "2. Mostrar Series" << endl;
        cout << "3. Mostrar Contenido" << endl;
        cout << "4. Salir" << endl;
        int opcion;
        cin >> opcion;

        if (opcion == 1) {
            handlePeliculas(filmoteca);
        } else if (opcion == 2) {
            handleSeries(filmoteca);
        } else if (opcion == 3) {
            handleContenido(filmoteca);
        } else if (opcion == 4) {
            break;
        } else {
            cout << "Opción no válida, intente de nuevo." << endl;
        }

    }

    return 0;
}
