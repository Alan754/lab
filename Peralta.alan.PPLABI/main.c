#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "fecha.h"
#include "moto.h"
#define TAM 5



typedef struct
{
    int id;
    char descripcion[20];
} eTipo;


char menu();



int altaMoto(eMoto altaMotos[], int tam, int id);


int main()
{
    eMoto lista[TAM] ;
    int rta;

    char seguir = 's';
    char confirma;
    int id = 100;
    if( !inicializarMotos(lista,TAM))
    {
        printf("Inicializacion exitosa!!!\n\n");
    }
    else
    {
        printf("Fallo al inicializar......\n");
    }

    do
    {
        switch(menu())
        {

        case 'a':
            if(!altaMoto(lista, TAM, id))
            {
                id++;
                printf("Alta exitosa!!!\n");
            }
            else
            {
                printf("No se pudo realizar el alta...\n");
            }

            break;
        case 'b':
            rta = modificarMoto(lista, TAM);
            if(rta == 0)
            {
                printf("Se realizo la modificacion con exito!!!");
            }
            else if(rta==1)
            {
                printf("Problemas al intentar modificar la moto\n");
            }
            else
            {
                printf("Modificacion cancelada por el usuario");
            }
            break;
        case 'c':
            bajaMoto(lista, TAM);
            rta = bajaMoto(lista, TAM);
            if(rta == 0)
            {
                printf("Se realizo la baja con exito!!!");
            }
            else if(rta == 1)
            {
                printf("Problemas al intentar realizar la baja");
            }
            else
            {
                printf("Baja cancelada por el usuario");
            }
            break;
        case 'd':

            break;
        case 'e':

            break;
        case 'f':

            break;

        case 'g':


            break;

        case 'h':


            break;

        case 'i':

            break;

        case 'j':
            printf("Confirma salida? ingrese s(si)/n(no): ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if(confirma == 's')
            {
                seguir = 'n';
            }

            break;
        default:
            printf("Opcion invalida!!!\n");

        }

        system("pause");

    }
    while( seguir == 's');


    return 0;
}

char menu()
{
    system("cls");

    char opcion;

    printf("\n          ***** ABM MOTOS *****\n");
    printf("          ---------------------\n\n");
    printf("Ingrese algunas de las siguientes opciones\n\n");
    printf("a. Alta\n");
    printf("b. Modificar moto\n");
    printf("c. Baja moto\n");
    printf("d. Lista de motos\n");
    printf("e. Lista de tipo de moto\n");
    printf("f. Lista de colores\n");
    printf("g. Lista de servicios \n");
    printf("h. Alta trabajo\n");
    printf("i. Lista de trabajos\n");
    printf("j. Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    opcion = tolower(getchar());

    return opcion;
}


