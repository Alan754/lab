#ifndef MOTO_H_INCLUDED
#define MOTO_H_INCLUDED
#include "fecha.h"

typedef struct
{
    int id;
    char marca[20];
    int idTipo;
    int idColor;
    int cilindrada;
    eFecha fNac;
    int isEmpty;
} eMoto;

int inicializarMotos(eMoto motos[], int tam);
int mostrarMotos(eMoto motos[], int tam);
void mostrarMoto(eMoto moto);
int buscarMotoLibre(eMoto moto[], int tam);
int altaMoto(eMoto altaMotos[], int tam, int id);
int modificarMoto(eMoto modMoto[], int tam);
int bajaMoto(eMoto bajMoto[], int tam);
int buscarMoto(eMoto busMoto[], int tam, int Id);

#endif // MOTO_H_INCLUDED
