// YOUR CODE STARTS HERE

#include <Servo.h>

Servo myServo;

void setup() {
  Serial.begin(9600); // Initialize serial communication with a baud rate of 9600
  myServo.attach(2);   // Servo connected to pin 2
}

void loop() {
  if (Serial.available() > 0) {
    char receivedChar = Serial.read(); // Read the incoming character

    if (receivedChar == 's') {
      sweepServo(); // Call the function to sweep the servo
    }
  }
}

void sweepServo() {
  for (int angle = 0; angle <= 180; angle += 1) {
    myServo.write(angle);  // Move the servo to the current angle
    delay(15);             // Wait for the servo to reach the position
  }

  for (int angle = 180; angle >= 0; angle -= 1) {
    myServo.write(angle);  // Move the servo to the current angle
    delay(15);             // Wait for the servo to reach the position
  }
}

// YOUR CODE FINISH HERE

// Questions to answer:

// Which library is used for UART communication protocol?
// La librería Serial.

// To use the UART ports, do we need to creat an object from a class?
// No es necesario crear un objeto de una clase, ya que este protocolo de
// comunicación utiliza el objeto global 'Serial', que a su vez es una 
// instancia de la clase 'HardwareSerial', la cual viene ya creada y puede
// utilizarse en cualquier programa.

// There are four sets of serial port in Arduino Mega, to which set is the USB 
// port connected?
// Los cuatro conjuntos de puertos serie del Arduino Mega son 'Serial(0)'
// 'Serial1', 'Serial2' y 'Serial3', de los cuales, el puerto USB está
// conectado en el conjunto 'Serial(0)'.

// How to set up the baud rate so that Arduino Mega and Serial Monitor can 
// communicate successfully using UART protocol?
// Utilizando la instrucción Serial.begin(v), donde v es la velocidad en
// baudios, y comprobando en la parte inferior de la ventana del Serial
// Monitor que dicho número coincide con el de la instrucción anterior.

// Following which convention is the data type char codified and stored as 
// binary data?
// Siguiendo el sistema ASCII, siendo char un tipo de datos que representa 
// un sólo caracter, utilizando su valor en ASCII para representar dicho
// caracter.

// Which of the following function sends data from the Arduino board to the 
// USB port as human-readable ASCII text? Serial.print() or Serial.write()?
// La función que envía datos desde la placa Arduino al puerto USB como texto 
// ASCII legible por humanos es Serial.print(). Esta función convierte los 
// valores numéricos en su representación de texto y los envía como caracteres 
// ASCII, mientras que la función Serial.write() envía datos en su forma 
// binaria, transmitiéndolos byte a byte según están en la memoria.

// What are the binary data sent from Arduino board to the USB by 
// Serial.write(4) and Serial.write(”4”)?
// En el caso de Serial.write(4), se envía como un byte con sus bits en
// binario (00000100) a través del puerto serie, mientras que en 
// Serial.write("4") hace lo mismo, pero en vez de enviar el número 4, lo 
// que se está enviando es el caracter "4" (00110100).

// How does Serial.read() decode and interpret the data arriving at the USB 
// port of Arduino Mega?
// Lee los datos que llegan a través del puerto USB, lo que devuelve el 
// siguiente byte disponible en el buffer de recepción.

// How does the Serial Monitor of Arduino IDE decode and interpret the data 
// arriving at the USB port of the computer?
// En primer lugar, se selecciona el Baud Rate configurado en la función
// Serial.begin(v). Después, muestra los datos que se están enviando cuando 
// se utilice la función Serial.print(), ya sean enteros, caracteres, etc. Y
// por último, configurar el tipo de salto de línea (\n, \r, etc).
