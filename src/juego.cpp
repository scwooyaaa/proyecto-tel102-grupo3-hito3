#include "juego.h"

Juego::Juego() : puntaje(0), indicePreguntaActual(0) {}

void Juego::agregarPregunta(const Pregunta& p) {
    preguntas.push_back(p);
}

bool Juego::hayMasPreguntas() const {
    return indicePreguntaActual < preguntas.size();
}

const Pregunta& Juego::obtenerPreguntaActual() const {
    return preguntas[indicePreguntaActual];
}

bool Juego::procesarRespuesta(int indiceSeleccionado) {
    bool esCorrecta = false;
    if (indicePreguntaActual < preguntas.size()) {
        if (preguntas[indicePreguntaActual].getRespuestaCorrecta() == indiceSeleccionado) {
            puntaje += 10; // Sumamos 10 puntos por acierto
            esCorrecta = true;
        }
        indicePreguntaActual++; // Avanzamos a la siguiente
    }
    return esCorrecta;
}

int Juego::getPuntaje() const {
    return puntaje;
}

void Juego::reiniciar() {
    puntaje = 0;
    indicePreguntaActual = 0;
}
