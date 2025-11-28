#ifndef PREGUNTA_H
#define PREGUNTA_H

#include <string>
#include <vector>

class Pregunta {
private:
    std::string pregunta;
    std::vector<std::string> opciones;
    int respuestaCorrecta;

public:
    Pregunta(const std::string& p, const std::vector<std::string>& o, int correcta);

    // Getters necesarios para la GUI
    std::string getPregunta() const;
    std::vector<std::string> getOpciones() const;
    int getRespuestaCorrecta() const;
};

#endif
