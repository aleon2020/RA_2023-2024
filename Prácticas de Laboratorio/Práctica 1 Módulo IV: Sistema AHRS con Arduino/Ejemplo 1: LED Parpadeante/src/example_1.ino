// YOUR CODE STARTS HERE

const byte led_pin = 13;
// use the build-in LED attached to pin 13
// byte (8 bit) = unsigned number from 0 to 255

const byte interruptPin = 2 ;
// digital pin 2 as interrupt number 0 of Mega2560

volatile byte state = LOW;
// voltage level at the pin

void setup ( ) {
  pinMode(led_pin, OUTPUT);
  // set led_pin to digital output
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, CHANGE);
  // digital pin 2 as interrupt number 0 of Mega2560
  // the function blink is triggered when
  // a CHANGE of level happens at n_itr
}

void loop() {
  digitalWrite(led_pin, state) ;
  // Write state to led_pin
}

void blink() {
  state =! state ;
  // toggle the state
}

// YOUR CODE FINISH HERE

// Questions to answer:

// What does the blink function do?
// Cambia el estado de la variable state, si está a HIGH se pone a LOW
// y viceversa.

// Why can the variable state be accessed in both loop() and blink()?
// Porque es una variable global.

// What are the three input entries for the attachInterrupt function?
// Teniendo attachInterrupt(digitalPinToInterrupt(pin), ISR, mode):
// interrupt: Número de pin asociado a dicha interrupción.
// ISR: Indica el ISR al que hay que llamar cuando se produce dicha
// interrupción (ISR, Rutina de Servicio de Interrupción).
// mode: Define el momento en que debe activarse la interrupción.
// Se tienen 4 posibles valores válidos:
// - LOW: Activa la interrupción cuando el pin está a LOW.
// - CHANGE: Activa la interrupción cada vez que el pin cambie de valor.
// - RISING: Activa la interrupción cuando el pin pasa de LOW a HIGH.
// - FALLING: Activa la interrupción cuando el pin pasa de HIGH a LOW.
// - HIGH: Activa la interrupción cuando el pin está a HIGH.

// What are these three data types: const? byte?
// const: Especifica que el valor de la variable es contante indicando
// al compilador que no puede modificarse por el programador.

// The resistor is a pull-up or pull-down resistor?
// En este caso, tenemos una resistencia pull-up.
// Diferencias: La resistencia pull-up establece un estado HIGH y la 
// resistencia pull-down establece un estado LOW cuando el pin está en reposo.

// When the button is not pressed, does the digital input pin read HIGH or LOW?
// LOW.

// Try with different interrupt modes (CHANGE, RISING, FALLING). Would the LED
// change its status for pressing or releasing the button?
// Sí.
