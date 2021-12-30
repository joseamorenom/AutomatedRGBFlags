#include <iostream>
#include <QImage>
#include "matrixfinal.h"
#include <fstream>
#include <Qstring>
#include "sobre.h"

using namespace std;

int main()
{

    int alto,ancho;
    string filename;
    cout<<"Ingrese la direccion del archivo de imagen ";
    getline(cin,filename);
    QImage imagen( filename.c_str());

    MatrixFinal Matriz(imagen);
    alto=Matriz.altoim;
    ancho=Matriz.anchoim;
    if (alto>=16&&ancho>=16){
    string filename;
    cout<<"Ingrese la direccion del archivo de imagen ";
    getline(cin,filename);
    QImage imagen( filename.c_str());
    //SUBMUESTREO
    MatrixFinal Matriz(imagen);
    Matriz.Submuestreo(imagen);
    Matriz.MatrixLista();
    Matriz.Guardar();
    cout<<"La informacion de su imagen ha sido guardada en el archivo final.txt (Submuestreo)";
    }
    else {
        //SOBREMUESTREO
        sobre imagen;
        imagen.redim();
        imagen.MatrixLista();
        imagen.Guardar();
        cout<<"La informacion de su imagen ha sido guardada en el archivo final.txt (Sobremuestreo)";
    }



}



