#ifndef MATRIXFINAL_H
#define MATRIXFINAL_H


#include <QImage>
#include <fstream>
#include <string>

class MatrixFinal
{
public:
   MatrixFinal(QImage im);
   void Submuestreo(QImage im);
   void MatrixLista();
   void Imprimir();
   void Guardar();
   int anchoim;
   int altoim;
private:

   int recorrerx=0,recorrery=0; //Ya que se trabaja con una matriz cuadrada se puede coger el alto o el ancho, en este caso se coge el ancho de la matriz de leds
   int ledsmatrix = 16;
   //int contador=0;
   float promedio_r=0,redimx,redimy,promedio_g=0,promedio_a=0;
   int matrixleds_r[16][16]; //Se simula la matriz de LEDs de Tinkercad
   int matrixleds_g[16][16];
   int matrixleds_a[16][16];
   int matrixFinal[16][16][3];
};

#endif // MATRIXFINAL_H

