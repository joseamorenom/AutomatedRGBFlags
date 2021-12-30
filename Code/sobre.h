#ifndef SOBRE_H
#define SOBRE_H


class sobre
{
public:
    sobre();
    void redim();
    void MatrixLista();
    void Guardar();

private:
    int anchoim();
    int altoim();
    int ancho=anchoim();
    int alto=altoim();
    int matrixFinal[16][16][3];
    int matrixleds_r[16][16];
    int matrixleds_g[16][16];
    int matrixleds_a[16][16];
    int ledsmatrix = 16;


};

#endif // SOBRE_H
