
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGridLayout>
#include <vector>
#include "juego.h"

class MainWindow : public QMainWindow {
    Q_OBJECT // Necesario para Signals y Slots

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void verificarRespuesta(int indexBoton); // Slot personalizado

private:
    Juego juego; // Instancia de la lógica

    // Elementos de la GUI
    QLabel *labelPregunta;
    QLabel *labelPuntaje;
    std::vector<QPushButton*> botonesOpciones;
    QWidget *centralWidget;


    void configurarInterfaz();
    void cargarPreguntaActual();
    void inicializarDatosJuego();
    void mostrarResultadoFinal();
};

#endif
