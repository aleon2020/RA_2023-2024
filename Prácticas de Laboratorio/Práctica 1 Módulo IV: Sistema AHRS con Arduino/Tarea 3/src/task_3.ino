// Questions to answer:

// 1. Understand the lines of code in the block of sub-function 
// buildBoxShape().
// Esta función se encarga de dibujar un cubo en 3D.
// beginShape(QUADS): Define un conjunto de caras y vértices que forman 
// un cubo.
// fill(): Establece el color de cada cara.
// vertex(): Define los vértices.
// endShape(): Finaliza la forma.

// 2. Understand how buildBoxShape() is called by the draw() function, so that 
// the cube is continuously being drawn on the scrren.
// En Processing, draw() es un bucle que se ejecuta contínuamente, y que en
// este caso se encarga de actualizar la pantalla y de llamar a funciones para
// dibujar nuevos elementos sobre ella.
// Además, la función drawCube() se encarga de orientar el cubo según los
// datos que le llegan del sensor, y que a su vez llama a buildBoxShape()
// para dibujar el cubo en la posición y orientación adecuadas.

// 3. Modify buildBoxShape() to add an arrow on the cube. You can use the code 
// lines in this function block as examples, but adding new TRIANGLES and 
// QUADS shapes as in Fig. 2.13. You can look up useful functions in the 
// Processing Language Reference page.
// Bloque de código MODIFICACIÓN
