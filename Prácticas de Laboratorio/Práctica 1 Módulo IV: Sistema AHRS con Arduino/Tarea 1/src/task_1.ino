// Questions to answer:

// 1. Identify the main components of GY-85.
// - Acelerómetro (ADXL345): Mide la aceleración lineal en 3 ejes, permitiendo
// determinar la orientación y el movimiento lineal del objeto al que está 
// conectado.
// - Giroscopio (ITG3200): Mide la velocidad angular en 3 ejes, además de 
// proporcionar información sobre la tasa de cambio de orientación del objeto.
// - Magnetómetro (HMC5883L): Mide el campo magnético terrestre en 3 ejes, y 
// puede utilizarse para determinar la orientación con respecto al campo
// magnético de la Tierra.

// 2. Connect the Mega2560 with GY-85 following Table.
// VCC_IN	=>	3.3 V
// GND		=>	GND
// SCL		=>	SCL (PIN 21)
// SDA		=>	SDA (PIN 20)

// 3. Upload the Arduino sketch “ARD SKETCH LOC/freeimu/FreeIMU_raw/FreeIMU_ 
// raw.pde” to Mega2560 board. Monitor the transmitted data (from Mega2560 to 
// computer) by using the Serial Monitor. Find out:

// In this Arduino sketch, where is the object of the FreeIMU class created?
// El objeto de la clase FreeIMU se crea en la línea:
// FreeIMU my3IMU = FreeIMU(); (Línea 22)

// What data is Mega2560 acquiring from the sensor? How are these data stored?
// Los datos son adquiridos por el sensor mediante el uso de la función
// getRawValues(), y que después son almacenados en el array 'raw_values', 
// compuesto por 10 o 11 elementos, dpendiendo si el barómetro está o no
// presente.
// Después, los datos del array se formatean en una cadena de caracteres
// mediante la función sprintf() y se almacenan en el array 'str'

// Which function is used to send these data from Mega2560 to the computer by 
// USB port?
// Los datos son enviados al ordenador mediante la función Serial.print() a
// una velocidad de 115200 baudios, tal como se muestra en la línea 25
// del programa (Serial.begin(115200)).

// 4. Upload the Arduino sketch “ARD SKETCH LOC/freeimu/FreeIMU_quaternion/
// FreeIMU_quaternion.pde” to Mega2560 board. Monitor the transmitted data 
// (from Mega2560 to computer) by using the Serial Monitor. Find out:

// What data is Mega2560 acquiring from the sensor? How are these data stored?
// Obtiene los datos del cuaternión del sensor mediante la función getQ(q)
// para después almacenarlos en el array 'q' de longitud 4.

// Which function is used to send these data from Mega2560 to the computer by 
// USB port?
// What is the difference compared to the previous sketch?
// Estos datos son enviados e imprimidos por el Serial Monitor mediante la 
// llamada a la función serialPrintFloatArr(q,4).
// En este sketch se están enviando datos de orientación en forma de 
// cuaternión, mientras que en el anterior se estaban adquiriendo datos
// de los sensores de movimiento (giroscopio, acelerómetro y magnetómetro)
// para después enviarlos al Serial Monitor.

// What is the difference between these two commands “serialPrintFloatArr(q, 
//4)” and “Serial.print(str)”?
// La función serialPrintFloatArr(q,4) imprime los 4 primeros elementos del
// array 'q', mientras que la función Serial.print(str) imprime el contenido 
// de la variable str por el Serial Monitor.

// 5. Upload “ARD SKETCH LOC/freeimu/FreeIMU_serial/FreeIMU_serial.ino” to 
// Mega2560 board. Send different commands from the computer to Mega2560 via 
// Serial Monitor. Read the sketch and understand the differences compared to 
// the previous two sketches.
// * FUNCIONALIDAD GENERAL:
// - FreeIMU_raw.ino: Este sketch se centra en obtener y mostrar los valores 
// brutos de los sensores inerciales conectados a la placa, ya sea con o sin 
// un barómetro (según el compilado).
// - FreeIMU_quaternion.ino: Este sketch está diseñado para obtener y mostrar 
// los valores de cuaternión, que son una forma de representar la orientación 
// espacial.
// - FreeIMU_serial.ino: Este sketch proporciona una interfaz serial para 
// interactuar con la placa y realizar diversas acciones, como obtener 
// valores brutos, cuaterniones, realizar calibraciones y más.
// * SALIDA POR EL SERIAL PORT:
// - FreeIMU_raw.ino: Muestra los valores brutos de los sensores en formato 
// de cadena a través del puerto serial.
// - FreeIMU_quaternion.ino: Muestra los valores del cuaternión en formato de 
// cadena a través del puerto serial.
// - FreeIMU_serial.ino: Responde a comandos específicos enviados a través 
// del puerto serial y realiza acciones como la obtención de valores brutos, 
// cuaterniones, calibración, etc.
// * INTERACCIÓN CON EL SERIAL PORT:
// - FreeIMU_raw.ino y FreeIMU_quaternion.ino: No interactúan activamente con 
// los comandos enviados a través del puerto serial.
// - FreeIMU_serial.ino: Responde a comandos específicos (por ejemplo, 'v', 
// 'r', 'b', 'q', 'C', 'd') enviados a través del puerto serial y realiza 
// acciones correspondientes, como mostrar información de la biblioteca, 
// obtener valores brutos, cuaterniones, calibración, etc.
// * EEPROM:
// - FreeIMU_raw.ino y FreeIMU_quaternion.ino: No contienen funciones 
// relacionadas con la lectura o escritura en la EEPROM.
// - FreeIMU_serial.ino: Contiene funciones que permiten la lectura y 
// escritura de datos en la EEPROM, utilizadas para almacenar información de 
// calibración.
// * BIBLIOTECAS ADICIONALES:
// - FreeIMU_serial.ino: Además de las bibliotecas utilizadas por los otros 
// sketches, incluye bibliotecas adicionales como "CommunicationUtils.h" y 
// funciones relacionadas con la manipulación de la EEPROM.

// 6. Make sure that “FreeIMU_serial.ino” has been uploaded to your Mega2560 
// board before executing the following actions.

// 7. Run the visualization sketch “PROC SKETCH LOC/FreeIMU/FreeIMU_cube/
// FreeIMU_cube.pde” in Processing (choose correct baud rate and serial port 
// in the processing sketch).
// Como se puede ver en la línea 59 de este sketch 
// (myPort = new Serial(this, serialPort, 115200);), la variable serialPort
// corresponde al puerto "/dev/ttyACM0", mientras que el 115200 corresponde
// a la velocidad en baudios a la que se envían los datos.

// 8. Read the Arduino sketch “FreeIMU_serial.ino” and find out:

// If “q” is sent to Mega2560 from the USB port, how are the data transmitted 
// from the sensor, to Mega2560, and then to the computer?
// La respuesta a esto se encuentra dentro del loop(), en primer lugar se
// verifica en todo momento si hay datos disponibles en el Serial Port 
// (if(Serial.available())). 
// En el caso de que haya datos, lee el primer byte disponible 
// (cmd = Serial.read();).
// Después, se compara lo almacenado en la variable cmd con las diferentes
// opciones que hay en el bucle if (v, r, b, q, c, x, C, d).
// v: Imprime información sobre la biblioteca FreeIMU
// (desarrollador, frecuencia, versión de biblioteca e ID del IMU).
// r: Adquiere valores brutos de los sensores y los imprime en la forma %d.
// b: Adquiere datos combinados de acelerómetro, giroscopio y magnetómetro
// para después imprimirlos.
// q: Obtiene los valores del cuaternión 'q' y los imprime a través de la
// función my3imu.getQ() en formato float.
// C: Imprime valores de calibración del acelerómetro y del magnetómetro
// con offsets y escalas.
// c: Almacena datos de calibración en la EEPROM y activa un LED.
// x: Reinicia la calibración de la EEPROM.
// d: Genera salidas de depuración sobre datos de sensores, cuaterniones y 
// ángulos de orientación (yaw, pitch, roll).
// Cada opción realiza diferentes funciones, y los datos de todas ellas
// se envían mediante la instrucción Serial.print().

// 9. Read the Processing sketch “FreeIMU_cube.pde”. In the function block 
// “void serialEvent(Serial p)”, find out:

// Which function is used to read and store the string of data (that was 
// transmitted to the computer by USB) in an array?
// La función p.readStringUntil('\n') (línea 94) lee los datos disponibles
// en el objeto Serial p hasta que encuentre el carácter '\n', lo que termina
// devolviendo la cadena resultante.

// How is the string of data decoded?
// Los datos de decodifican mediante la función decodeFloat() (líneas 99 a 
// 102), tomando una cadena de 8 caracteres en hexadecimal, para después
// convertirla en un array de bytes e interpretar dichos bytes como un float.

// How is the string of data stored in the array for the quaternion q[4]? 
// Where is this array declared?
// El array 'q' almacena cada uno de los valores del cuaternión mediante la 
// función decodeFLoat().
// Este array se declara al principio del sketch con la línea
// float [] q = new float [4]; (línea 37).

// 10. Uncomment the calibration parameters in the file “calibration.h” under 
// “ARD SKETCH LOC/libraries/FreeIMU”, modify the parameters.

// 11. Run again “PROC SKETCH LOC/FreeIMU/FreeIMU_cube/FreeIMU_cube.pde” in 
// Processing and and observe how the performance of orientation 
// determination has changed.

// 12. Run “PROC SKETCH LOC/FreeIMU/Artificial_horizon/
// Artificial_horizon.pde”  in Processing. This Processing sketch 
// simulates a Primary Flight Display, which presents the orientation on an 
// Artificial_Horizon and the heading in a digital compass.
