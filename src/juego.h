#ifndef JUEGO_H
#define JUEGO_H

#include <vector>
#include "pregunta.h"

class Juego {
private:
    std::vector<Pregunta> preguntas;
    int puntaje;
    int indicePreguntaActual;

public:
    Juego();
    void agregarPregunta(const Pregunta& p);

    // Nuevas funciones para controlar el flujo desde la GUI
    bool hayMasPreguntas() const;
    const Pregunta& obtenerPreguntaActual() const;
    bool procesarRespuesta(int indiceSeleccionado); // Devuelve true si acertó
    int getPuntaje() const;
    void reiniciar(); // Para jugar de nuevo
};

#endif // JUEGO_H
