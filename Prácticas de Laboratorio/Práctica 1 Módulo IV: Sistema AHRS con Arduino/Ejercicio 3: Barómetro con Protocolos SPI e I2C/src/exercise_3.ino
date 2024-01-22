// YOUR CODE STARTS HERE

#include <Wire.h>
#include <SPI.h>
#include "Adafruit_Sensor.h"
#include "Adafruit_BMP280.h"

#define BMP_SCK 52
#define BMP_MISO 50
#define BMP_MOSI 51 
#define BMP_CS 53

#define BMP_SDA 21  
#define BMP_SCL 22 

// I2C protocol
Adafruit_BMP280 bme;

// SPI protocol
//Adafruit_BMP280 bme(BMP_CS);
//Adafruit_BMP280 bme(BMP_CS, BMP_MOSI, BMP_MISO,  BMP_SCK);
  
void setup() {
  Serial.begin(9600);
  Serial.println(F("BMP280 test"));
  
  if (!bme.begin()) {  
    Serial.println("Could not find a valid BMP280 sensor, check wiring!");
    while (1);
  }
}
  
void loop() {
    Serial.print("Temperature = ");
    Serial.print(bme.readTemperature());
    Serial.println(" *C");
    
    Serial.print("Pressure = ");
    Serial.print(bme.readPressure());
    Serial.println(" Pa");

    Serial.print("Approx altitude = ");
    Serial.print(bme.readAltitude(1013.25));
    Serial.println(" m");
    
    Serial.println();
    delay(2000);
}

// YOUR CODE FINISH HERE

// Questions to answer:

// What is the difference between #include <xxx.h> and #include ”xxx.h”? Where 
// is the file “bmp280.h” stored?
// La diferencia es que #include <xxx.h> incluye archivos de encabezado del
// estándar Arduino biblioteca (busca el código fuente en el directorio 
// arduino/), mientras que #incluye "xxx.h" incluye archivos de encabezado 
// definidos por el programador (busca en el mismo directorio donde se 
// encuentra el código fuente).
// El fichero bmp280.h contiene funciones e información acerca del sensor 
// BMP280, el cual se encuentra en 'arduino/libraries/BMP280/'.

// - SPI and I2C protocol.

// For each protocol, how many pins are connected?
// Para el protocolo SPI se utilizan 4 pines: 12 (MISO), 11 (MOSI), 13 (SCK) y
// 10 (SS).
// Y para el protocolo I2C se utilizan 2 pines: A4 (SDA) y A5 (SCL).

// What is each pin used for?
// MISO (Master In Slave Out): Lleva los datos desde el esclavo de vuelta al 
// maestro (pin 12).
// MOSI (Master Out Slave In): Lleva los datos desde el maestro al esclavo 
// (pin 11).
// SCK (Serial Clock): Sincroniza la transferencia de datos entre el maestro y 
// el esclavo (pin 13).
// SS (Slave Select): Seleccionar el esclavo con el que el maestro desea 
// comunicarse (pin 10).
// Por otro lado, para el protocolo I2C se utilizan 2 pines:
// SDA (Serial Data Line): Lleva los datos entre los dispositivos conectados 
// al bus I2C (pin A4).
// SCL (Serial Clock Line): Sincroniza la transferencia de datos entre los 
// dispositivos (pin A5).

// Does the protocol support multiple peripherals? Why?
// Ambos protocolos están diseñados para admitir múltiples periféricos,
// ya que ambos utilizan mecanismos de selección única (SS en SPI y 
// direcciones únicas en I2C).

// Does the protocol support multiple controllers? Why?
// Para el protocolo SPI, no es posible tener múltiples controladores, ya que
// éste generalmente opera con un único maestro activo a la vez.
// Mientras que para el protocolo I2C, si es posible tener múltiples
// controladores, siempre y cuando se evite cualquier colisión entre ellos.

// For one-to-one communication, how many data lines are required for this
// protocol? Why?
// Para la comunicación uno-a-uno, el número de líneas de datos depende del
// protocolo de comunicación utilizado.
// Para el protocolo SPI se necesitan al menos 3 líneas de datos: Una para
// el MISO, otra para el MOSI y otra para el SCK, aunque normalmente también
// se utiliza una cuarta línea para el SS.
// Mientras que para el protocolo I2C, se necesitan al menos 2 líneas de
// datos: Una para el SDA y otra para el SCL.

// What is the difference between hardware SPI and software SPI?
// El protocolo SPI es un estándar de comunicación, mientras que el software
// SPI hace referencia a la implementación de dicho protocolo utilizando 
// software en lugar de hardware dedicado.

// How to include the library?
// Con la instrucción #include <SPI.h>

// How to create the object?
// Para esta clase no se crea un objeto específico como se hace con otras
// librerías, sino que se gestiona utilizando las funciones integradas por
// la librería SPI. Por ejemplo:
// #include <SPI.h>
// void setup() {
//   SPI.begin();
// }
// void loop() {
//   byte dataToSend = 0x42;
//   byte receivedData = SPI.transfer(dataToSend);
//   delay(1000);
// }

// How to initiate the barometer?
// #include <Wire.h>
// #include <Adafruit_Sensor.h>
// #include <Adafruit_BMP280.h>
// #define BMP_SDA 20  
// #define BMP_SCL 21  
// Adafruit_BMP280 bmp;
// void setup() {
//   Serial.begin(9600);
//   if (!bmp.begin()) {
//     Serial.println("ERROR DE INICIALIZACIÓN");
//     while (1);
//   }
// }

// How to acquire data from the sensor?
// How to send the data to the USB port?
// void loop() {
//   Serial.print("Temperatura = ");
//   Serial.print(bmp.readTemperature());
//   Serial.println(" *C");
//   Serial.print("Presión = ");
//   Serial.print(bmp.readPressure() / 100.0F);
//   Serial.println(" hPa");
//   Serial.print("Altitud = ");
//   Serial.print(bmp.readAltitude(1013.25));
//   Serial.println(" metros");
//   delay(1000);
// }
