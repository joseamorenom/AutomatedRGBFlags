#include "sobre.h"
#include <iostream>
#include <QImage>
#include <fstream>
using namespace std;


sobre::sobre()
{
}

void sobre::redim()
{
    string filename;
    cout<<"Ingrese la direccion del archivo de imagen ";
    getline(cin,filename);
  //  string filename="../otro/colombia.png";
    QImage im( filename.c_str());
    int redimy=ledsmatrix/ancho;  //Cantidad de veces a replicar las filas
    int redimx=ledsmatrix/alto;   //Cantidad de veces a replicar las columnas

    //int contador=0;
    for(int z=0; z<alto;z++){  //Se recorren las columnas de la imagen suministrada
        for(int w=0; w<ancho; w++){ //Se recorren las filas de la imagen suministrada
            //Por cada posición se recorre un número de veces igual a las repeticiones necesarias para
            //completar los espacios que faltan por redimensionar
            for(int x=0+(w*redimx);x<redimx+(w*redimx);x++){
                for(int y=0+(z*redimy); y<redimy+(z*redimy);y++){
//Del color de la posicion del w y z de la imagen suministrada se replica en varias posiciones de la matriz final


                    matrixleds_r[x][y]=im.pixelColor(w,z).red();
                    matrixleds_g[x][y]=im.pixelColor(w,z).green();
                    matrixleds_a[x][y]=im.pixelColor(w,z).blue();

                   // contador++;
                }
            }
        }
    }
}

int sobre::anchoim()
{
    string filename;
    cout<<"Ingrese la direccion del archivo de imagen ";
    getline(cin,filename);
    QImage im( filename.c_str());
    int ancho=im.width();
    return ancho;
}

int sobre::altoim()
{ string filename;
    cout<<"Ingrese la direccion del archivo de imagen ";
    getline(cin,filename);
    QImage im( filename.c_str());
    //string filename="../final/francia2.png";
    int alto=im.height();
    return alto;
}

void sobre::MatrixLista()
{
    for(int a=0;a<16;a++){
        for(int b=0;b<16;b++){
            matrixFinal[a][b][0]=matrixleds_r[a][b];
            matrixFinal[a][b][1]=matrixleds_g[a][b];
            matrixFinal[a][b][2]=matrixleds_a[a][b];
        }
    }
}

void sobre::Guardar()
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
