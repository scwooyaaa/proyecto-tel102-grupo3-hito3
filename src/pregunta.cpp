#include "pregunta.h"

Pregunta::Pregunta(const std::string& p, const std::vector<std::string>& o, int correcta)
    : pregunta(p), opciones(o), respuestaCorrecta(correcta) {}

std::string Pregunta::getPregunta() const { return pregunta; }
std::vector<std::string> Pregunta::getOpciones() const { return opciones; }
int Pregunta::getRespuestaCorrecta() const { return respuestaCorrecta; }
