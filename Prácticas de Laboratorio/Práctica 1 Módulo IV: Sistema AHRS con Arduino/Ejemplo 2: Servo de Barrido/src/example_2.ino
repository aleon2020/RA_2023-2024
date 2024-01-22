// YOUR CODE STARTS HERE

#include <Servo.h>

Servo servo0;
// create a servo object "servo0"

int pos = 0;
// variable to store the servo position

void setup() {
  servo0.attach(12);
  // attach the servo on pin12 to the servo object
}

void loop() {
  for (pos = 0; pos <= 180; pos += 10) {
    // goes from 0 degrees to 180 degrees
    // each step 10 degrees
    servo0.write(pos);
    // tell servo to go to position in variable 'pos'
    delay(100);
    // waits 100ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 10) {
    // goes from 180 degrees to 0 degrees
    servo0.write(pos);
    delay(100);
  }  
}

// YOUR CODE FINISH HERE

// Questions to answer:

// How to include a library in the sketch? What is the difference between 
// #include <xxx.h> and #include ”xxx.h”?
// Utilizando la etiqueta #include.
// La diferencia es que #include <class.h> incluye archivos de encabezado del
// estándar Arduino biblioteca (busca el código fuente en el directorio 
// arduino/), mientras que #incluye "class.h" incluye archivos de encabezado 
// definidos por el programador (busca en el mismo directorio donde se 
// encuentra el código fuente).

// In the sketch, which one is the class of the servo motor? Which is the 
// object of servo motor?
// 'Servo' es la clase y 'servo0' es el objeto.

// In the sketch, how to use one function provided by the class?
// Creando un objeto de dicha clase (Clase objeto;).

// If you need to control several motors, what changes do you need to make for 
// the circuit and for the sketch?
// Necesitaríamos crear más objetos de la misma clase y usar las mismas
// funciones para cada uno de ellos.
