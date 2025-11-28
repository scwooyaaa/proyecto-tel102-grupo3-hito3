# Resumen
- La problemática a tratar a partir de este proyecto es ayudar a solucionar las dificultades de aprendizaje de los estudiantes de enseñanza media al ser insuficientes los recursos entregados por la institución en la que se encuentran, es por esto que se buscó diseñar una aplicación para ayudarlos a practicar sus habilidades de forma más interactiva, es decir que el aprendizaje les resulte más entretenido y se les haga más sencillo.

# Interfaz gráfica
El objetivo principal de la interfaz gráfica es integrar el código del juego a una programa visual e interactivo utilizando widgets de Qt.
Esta interfaz reemplaza la interacción por consola del hito anterior, proporcionando un entorno amigable donde el usuario puede visualizar claramente las preguntas, seleccionar opciones mediante clics y recibir retroalimentación inmediata sobre su desempeño, cumpliendo así con el hecho de separar entre lógica, es decir el código, y presentación, refiriendose a donde se interactúa con la aplicación.

Dentro de los elementos principales que fueron utilizados para un mejor desempeño del programa se encuentran:
- QLabel (labelPregunta): Un área de texto central y prominente que muestra el enunciado de la pregunta actual. Se configuró con ajuste de línea (WordWrap) para facilitar la lectura de enunciados largos.
- QPushButton (botonesOpciones): Un conjunto de 4 botones organizados en una cuadrícula (QGridLayout). Representan las posibles respuestas; el usuario interactúa con ellos haciendo clic para elegir su respuesta.
- QLabel (labelPuntaje): Un indicador visual situado en la parte superior que muestra el puntaje acumulado en tiempo real (ej. "Puntaje: 20"), permitiendo al usuario monitorear su progreso.
- QMessageBox: Ventanas emergentes modales que aparecen tras cada selección para indicar si la respuesta fue "Correcta" o "Incorrecta", y una ventana final que muestra el puntaje total al terminar el juego.
- Layouts (QVBoxLayout y QGridLayout): Elementos invisibles que organizan la estructura visual para que se mantenga ordenada y centrada.

El comportamiento que se espera la aplicación realice al interactuar los usuarios es el siguiente:
- Inicio: Al ejecutar el programa, la ventana principal carga automáticamente la primera pregunta y sus opciones desde la clase lógica Juego.
- Selección: El usuario lee la pregunta y hace clic en uno de los botones de opción.
- Procesamiento (Signal/Slot): Al hacer clic, se emite una señal (clicked) que activa un slot personalizado en MainWindow. Este slot comunica la selección del usuario a la clase Juego (Lógica), la cual verifica si es correcta y actualiza el puntaje interno.
- Feedback: Inmediatamente después del clic, la interfaz bloquea el flujo brevemente con un QMessageBox informando al usuario si acertó o falló.
- Avance: Al cerrar el mensaje de feedback, la interfaz solicita la siguiente pregunta a la lógica y actualiza los textos de los botones y la etiqueta de puntaje.
- Fin del Juego: Si no quedan más preguntas (hayMasPreguntas() retorna falso), se despliega un mensaje final con el puntaje total y la aplicación se cierra o reinicia.

# Uso de signals y slots
El uso de signals y slots es el mecanismo central utilizado dentro del programa, estos ayudan a que la interfaz gráfica responda a las acciones del usuario. Estos actúan principalmente cuando el usuario selecciona una respuesta, es por esto que se utilizan signals dentro de la clase QpushBotton, para avisar cada vez que se selecciona una alternativa. Siguiendole a esta interacción se utiliza un slot como receptor dentro de la clase mainwindow para verificar si la respuesta seleccionada es la correcta. Por otra parte también se utilizan conexiones para la señal clicked y pasar esta como argumento al slot.
Las signals y slots son utilizadas principalmente dentro de la clase mainwindow, ya que esta es la que recibe las interacciones de la interfaz, por lo que su objetivo es traducirlas y pasarlas hacia el resto del programa donde se verifíca lo lógico y si la respuesta seleccionada es la correcta. También son utilizados dentro de la clase juego para procesar las respuestas.
