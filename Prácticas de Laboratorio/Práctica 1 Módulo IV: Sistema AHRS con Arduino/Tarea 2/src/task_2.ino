// Questions to answer:

// 1. Connect both BMP280 and GY-85 to Mega2560 following I2C protocol. 
// Because there is an address frame in the I2C protocol, Mega2560 can support 
// multiple slaves and there is no conflict between BMP280 and GY-85 sensors.
// Esquema de conexión sensor MARG GY-85:
// VCC_IN	=>	3.3 V
// GND		=>	GND
// SCL		=>	SCL (PIN 21)
// SDA		=>	SDA (PIN 20)
// Esquema de conexión sensor BMP280 (I2C):
// VCC_IN	=>	3.3 V
// GND		=>	GND
// SCL		=>	SCL (PIN 21)
// SDA		=>	SDA (PIN 20)
// Esquema de conexión sensor BMP280 (SPI):
// VCC_IN	=>	3.3 V
// GND		=>	GND
// SCK		=>	SCK (PIN 52)
// SDO		=>	SDO (PIN 51)
// SDA		=>	SDA (PIN 50)
// CSB		=>	CSB (PIN 53)

// 2. Modify the Arduino sketch “FreeIMU_serial.ino”, so that, when ‘q’ is 
// sent to Mega2560 through the USB port, a string of data (including the 
// quaternion, the temperature, the pressure, and the altitude) are sent to 
// the USB port all together:

// Copy the library files for BMP280 to the same folder that contains 
// “FreeIMU_serial.ino” sketch.
// Incluir la librería al principio del código: #include <Adafruit_BMP280.h>

// Declare a new array baro, which has an array size of 3 to store the 
// temperature, pressure, and altitude.
// float baro[3]; (Temperatura, presión y altitud).

// Declare an object for the barometer Adafruit BMP280 class. Initiate the 
// barometer.
// Adafruit_BMP280 bmp; (Objeto del barómetro BMP280).

// Write the temperature, the pressure, and the altitude into the array baro.
// Send the barometer data to the serial port.
// Función getTempPressureAltitude(float baro[3]);

// 3. Check the outputs in the Serial Monitor.

// 4. Modify the Processing script “FreeIMU_cube.pde” to achieve the 
// visualization as Fig. 2.12:

// Declare a new array baro, which has an array size of 3 to store the 
// temperature, pressure, and altitude.
// float [] baro = new float[3];

// Read/decode the string of data sent from Mega2560 and store the barometer 
// data in the baro array.
// Bloque comentado (MODIFICACIÓN).

// Add the barometer information as text on the visualization screen.
