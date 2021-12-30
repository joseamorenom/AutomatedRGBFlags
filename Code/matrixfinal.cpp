#include "matrixfinal.h"
#include <QImage>
#include <fstream>
#include <string>

using namespace std;

MatrixFinal::MatrixFinal(QImage im)
{
    anchoim=im.width();
    altoim=im.height();
}

void MatrixFinal::Submuestreo(QImage im)
{
    //Se divide la imagen entre el tamaño de la matriz de leds para saber cuantas
    //redimensiones se necesitan para obtener la dimensión deseada
    //Cuantas veces es necesario redimensionar la imagen, tanto en alto como en ancho
        redimy=anchoim/ledsmatrix; //Cantidad de filas a redimensionar
        redimx=altoim/ledsmatrix; //Cantidad de columnas a redimensionar

        for(int filas=0;filas<ledsmatrix;filas++){ //Recorre el ancho de la matriz de leds
        for(int columnas=0;columnas<ledsmatrix;columnas++){ //Recorre el alto de la matriz de leds
            for(int itery=0, redimfila=recorrery ;itery<redimy;itery++,redimfila++){ //Recorre las filas a redimensionar
                for(int iterx=0, redimcol=recorrerx;iterx<redimx;iterx++,redimcol++){ //Recorre las columnas a redimensionar

                 int  rojo= im.pixelColor(redimfila,redimcol).red();
                 int  azul= im.pixelColor(redimfila,redimcol).blue();
                 int  verde= im.pixelColor(redimfila,redimcol).green();
                    promedio_r = ( promedio_r ) + ( ( rojo) / (redimx*redimy) ) ; //Se saca el promedio de la fila y las columnas a redimensionar
                    promedio_g = ( promedio_g ) + ( ( verde) / (redimx*redimy) ) ;
                    promedio_a = ( promedio_a ) + ( ( azul) / (redimx*redimy) ) ;


                    //Con lo que se obtiene un dato para la matriz ya redimensionada, estos datos se obtienen uno a uno
                    //este promedio debe hacerlo con los 3 colores, Rojo, azul, verde
                }
            }
            recorrerx=recorrerx+redimx;
            matrixleds_r[filas][columnas]=promedio_r; //Se guarda el promedio obtenido en la debida posicion de la matriz de leds
            matrixleds_g[filas][columnas]=promedio_g;
            matrixleds_a[filas][columnas]=promedio_a;
            promedio_r=0;
            promedio_g=0;
            promedio_a=0;

            //este arreglo debe hacerlo con los 3 colores, rojo, azul, verde. Guardando estos colores en matrices, int rojo[tamanioLeds][tamaniosLeds], asi seria el tamanio del arreglo rojo

            // contador++;
        }
            recorrery=recorrery+redimy;
            recorrerx=0;
        }
}

void MatrixFinal::MatrixLista()
{
    for(int a=0;a<16;a++){
        for(int b=0;b<16;b++){
            matrixFinal[a][b][0]=matrixleds_r[a][b];
            matrixFinal[a][b][1]=matrixleds_g[a][b];
            matrixFinal[a][b][2]=matrixleds_a[a][b];
        }
    }
}




void MatrixFinal::Guardar()
{
    string final;

    final+="{\n";
    for(int a=0;a<16;a++){
        final+="{";
        for(int b=0;b<16;b++){
            final+="{";
            final+=to_string(matrixFinal[a][b][0]);
            final+=",";
            final+=to_string(matrixFinal[a][b][1]);
            final+=",";
            final+=to_string(matrixFinal[a][b][2]);
            if(b!=15) final+="},";
            else if(b==15) final+="}";
        }
     if(a!=15) final+="},\n";
     else if(a==15) final+="}\n";
    }
    final+="};";


    ofstream out("final.txt");
    out << final;
    out.close();

}

