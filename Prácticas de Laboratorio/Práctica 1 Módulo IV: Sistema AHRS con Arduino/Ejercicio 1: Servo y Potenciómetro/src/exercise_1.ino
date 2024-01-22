// YOUR CODE STARTS HERE

#include <Servo.h>

// Define el pin al que está conectado el potenciómetro
const int potPin = A0;

// Crea un objeto de tipo Servo
Servo miServo;

void setup() {
  Serial.begin(9600); // Initialize serial communication with a baud rate of 9600
  // Inicializa el objeto Servo
  miServo.attach(2);  // El servo está conectado al pin 2

  // Configura el puerto del potenciómetro como entrada
  pinMode(potPin, INPUT);
}

void loop() {
  // Lee el valor del potenciómetro (0 a 1023)
  int valorPot = analogRead(potPin);
  
  //Serial.print(valorPot);
  Serial.print("\n");
  // Mapea el valor leído al rango de 0 a 180 (rango de movimiento del servo)
  int angulo = valorPot*1023/180;
  Serial.print(angulo);
  Serial.print("\n");
  
  // Mueve el servo a la posición correspondiente al valor del potenciómetro
  miServo.write(angulo);

  // Espera un breve momento para evitar cambios rápidos
  delay(15);
}

// YOUR CODE FINISH HERE

// Questions to answer:

// What are the three pins of a potentiometer?
// Los dos pines de los extremos se comportan como una resistencia según el 
// valor de escala del potenciómetro, mientras que el pin central toma valores 
// de la resistencia en función del movimiento realizado.

// What does an analogue input do? Arduino Mega 2560 map voltages between
// ___ into integer values between ___.
// Una entrada analógica (A0-A5) lee valores de tensión de entre 0 y 5 V 
// (0 a 1023 bits).
// Un Arduino Mega 2560 mapea valores en el rango (7-12) V.

// Is there analogue output pin?
// En el caso del Arduino Mega 2560, se tienen 15 pines que actúan como
// salidas PWM de 8 bits (pines 2,3,4,5,6,7,8,9,10,11,12,13,44,45,46).

// How can we imitate an analogue output pin using digital pins?
// En primer lugar, se configura la variable asociada al pin como pin de 
// salida (pinMode(pinSalidaAnalogica, OUTPUT)), y mediante la función 
// analogWrite se asocia un valor entre 0 y 255 a dicho pin.
// for (valorAnalogico = 0; valorAnalogico <= 255; valorAnalogico++) {
//    analogWrite(pinSalidaAnalogica, valorAnalogico);
//    delay(10);
// }

// What are the differences between the data types int and float?
// El tipo de datos float es para números con decimales, mientras que el tipo 
// int es para números enteros.

// What is the problem of the division operation between integers? How can you 
// force the division to perform floating point arithmetic?
// Si se dividen dos números de tipo int, donde el divisor es mayor que el 
// dividendo (50/100), da 0. Por lo tanto, para evitar este problema, habría 
// que declarar dichos números (o variables asociadas a dicho valor) de tipo 
// float.
