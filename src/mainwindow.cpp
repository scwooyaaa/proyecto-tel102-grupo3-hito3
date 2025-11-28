#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
    configurarInterfaz();
    inicializarDatosJuego();
    cargarPreguntaActual();
}

MainWindow::~MainWindow() {}

void MainWindow::configurarInterfaz() {
    setWindowTitle("Duomath");
    resize(500, 400);

    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    // Etiqueta de puntaje
    labelPuntaje = new QLabel("Puntaje: 0", this);
    labelPuntaje->setAlignment(Qt::AlignRight);
    QFont fontScore = labelPuntaje->font();
    fontScore.setBold(true);
    labelPuntaje->setFont(fontScore);
    mainLayout->addWidget(labelPuntaje);

    // Etiqueta de la pregunta
    labelPregunta = new QLabel("Pregunta", this);
    labelPregunta->setWordWrap(true); // Permitir saltos de línea
    QFont fontPregunta = labelPregunta->font();
    fontPregunta.setPointSize(12);
    labelPregunta->setFont(fontPregunta);
    labelPregunta->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(labelPregunta);

    mainLayout->addSpacing(20);

    // Botones de opciones (creamos 4 botones)
    QGridLayout *gridBotones = new QGridLayout();
    for (int i = 0; i < 4; ++i) {
        QPushButton *btn = new QPushButton(QString("Opción %1").arg(i), this);
        btn->setMinimumHeight(50);
        botonesOpciones.push_back(btn);

        // Conexión Signal-Slot usando una lambda para pasar el índice
        connect(btn, &QPushButton::clicked, this, [this, i]() {
            verificarRespuesta(i);
        });

        gridBotones->addWidget(btn, i / 2, i % 2); // Organizar en 2x2
    }
    mainLayout->addLayout(gridBotones);
}

void MainWindow::inicializarDatosJuego() {
    juego.agregarPregunta(Pregunta(
        "El área de un círculo es 154 cm². Si π=3,14, ¿cuál es su radio aproximado?",
        {"6 cm", "14 cm", "12 cm", "7 cm"}, 3
        ));
    juego.agregarPregunta(Pregunta(
        "La recta y=3x+2 corta al eje x en:",
        {"(0, 2)", "(2/3, 0)", "(-2/3, 0)", "(0, -2)"}, 2
        ));
    juego.agregarPregunta(Pregunta(
        "Si precio inicial $10000, sube 20% y baja 10%. ¿Precio final?",
        {"$10 800", "$10 000", "$10 200", "$11 000"}, 0
        ));
    juego.agregarPregunta(Pregunta(
        "Si f(x)=2x^2-3x+1, entonces f(-2) es:",
        {"15", "19", "11", "9"}, 0
        ));
}

void MainWindow::cargarPreguntaActual() {
    if (juego.hayMasPreguntas()) {
        const Pregunta& p = juego.obtenerPreguntaActual();
        labelPregunta->setText(QString::fromStdString(p.getPregunta()));

        std::vector<std::string> ops = p.getOpciones();
        for (size_t i = 0; i < botonesOpciones.size(); ++i) {
            if (i < ops.size()) {
                botonesOpciones[i]->setText(QString::fromStdString(ops[i]));
                botonesOpciones[i]->setVisible(true);
                botonesOpciones[i]->setEnabled(true); // Reactivar botones
            } else {
                botonesOpciones[i]->setVisible(false);
            }
        }
        labelPuntaje->setText("Puntaje: " + QString::number(juego.getPuntaje()));
    } else {
        mostrarResultadoFinal();
    }
}

void MainWindow::verificarRespuesta(int indexBoton) {
    bool correcta = juego.procesarRespuesta(indexBoton);

    if (!correcta) {
        QMessageBox::warning(this, "Incorrecto", "La respuesta era incorrecta.");
    } else {
        QMessageBox::information(this, "Correcto", "¡Bien hecho!");
    }

    cargarPreguntaActual(); // Cargar la siguiente
}

void MainWindow::mostrarResultadoFinal() {
    QMessageBox::information(this, "Fin del Juego",
                             "Juego Terminado.\nPuntaje Final: " + QString::number(juego.getPuntaje()));
    close(); // Cerrar la aplicación
}
