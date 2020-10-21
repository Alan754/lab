#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "moto.h"
#include "fecha.h"

#define TAM 5


//Inicializo motos
int inicializarMotos(eMoto motos[], int tam)
{
    int error = 1;

    if(motos!=NULL && tam > 0)
    {
        for(int i = 0; i < tam ; i++)
        {
            motos[i].isEmpty = 1;
        }
        error = 0;
    }
    return error;
}

//Mostrar motos
int mostrarMotos(eMoto motos[], int tam)
{
    int error = 1;
    int flag = 0;

    if(motos!= NULL && tam > 0)
    {
        printf("   Id   Marca   IdTipo   IdColor   Cilindrada\n");
        printf(" --------------------------------------------\n");
        for(int i = 0; i < tam; i++)
        {
            if( motos[i].isEmpty == 0)
            {
                mostrarMoto(motos[i]);
                flag=1;
            }
        }
        printf("\n\n");
        if(flag == 0)
        {
            printf(" No hay personas en la lista\n\n");
        }
        error= 0;
    }

    return error;
}
//Mostrar moto
void mostrarMoto(eMoto moto)
{
    printf("   %d  %4s   %4d    %5d    %5d\n",moto.id, moto.marca, moto.idTipo, moto.idColor,moto.cilindrada);
}
//buscar moto libre
int buscarMotoLibre(eMoto moto[], int tam)
{
    int indice = -1;

    for(int i = 0 ; i < tam ; i++)
    {
        if(moto[i].isEmpty)
        {
            indice = i;
            break;
        }
    }
    return indice;

}
// altas de moto
int altaMoto(eMoto altaMotos[], int tam, int id)
{
    int error = 1;
    eMoto nuevaMoto;
    int indice;
    int tipoDMoto;
    int cilindradas;
    char auxMarca[100];

    if(altaMotos != NULL && tam > 0 && id > 0)
    {
        indice = buscarMotoLibre(altaMotos,tam);

        if(indice == -1)
        {
            printf("Sistema completo!!!!\n");
        }
        else
        {
            nuevaMoto.id = id;
            nuevaMoto.isEmpty = 0;

            system("cls");
            printf("           ***   Alta Moto   *** \n");
            printf("           ---------------------- \n\n");

            printf("\nIngrese marca Honda, Suzuki o Kawasaki: ");
            fflush(stdin);
            gets(auxMarca);
            auxMarca[0] = toupper(auxMarca[0]);
            while((strlen(auxMarca) >= 20) && (auxMarca != "Honda" && auxMarca != "Suzuki" && auxMarca != "Kawasaki"))
            {
                printf("Marca demasiada larga o mal ingresada.Reingrese marca: ");
                fflush(stdin);
                gets(auxMarca);
            }
            strcpy(nuevaMoto.marca,auxMarca);

            nuevaMoto.marca[0] = toupper(nuevaMoto.marca[0]);


            system("cls");
            printf("           ***  Tipo de Moto *** \n");
            printf("           ---------------------- \n\n");

            printf("\n1.Enduro\n2.Chopera\n3.Scooter\n4.Ciclomotor\n\n");
            printf("Elija tipo de moto: ");
            scanf("%d", &tipoDMoto);
            while(tipoDMoto != 1 && tipoDMoto != 2 && tipoDMoto != 3 && tipoDMoto != 4)
            {
                printf("\nTipo de motos\n\n1.Enduro\n2.Chopera\n3.Scooter\n4.Ciclomotor\n\n");
                printf("ERROR!!!Por favor elija un tipo valido: ");
                scanf("%d", & tipoDMoto);
            }
            nuevaMoto.idTipo = tipoDMoto;

            system("cls");
            printf("           ***Tipo de Color de Moto *** \n");
            printf("           ----------------------------- \n\n");
            printf("\n1.Gris\n2.Negro\n3.Blanco\n4.Azul\n5.Rojo\n\n");
            printf("Elija tipo de color: ");
            scanf("%d", & nuevaMoto.idColor);
            while(nuevaMoto.idColor != 1 && nuevaMoto.idColor != 2 && nuevaMoto.idColor != 3 && nuevaMoto.idColor != 4 && nuevaMoto.idColor != 5)
            {
                printf("\nTipo de color\n1.Gris\n2.Negro\n3.Blanco\n4.Azul\n5.Rojo\n\n");
                printf("ERROR!!!Por favor elija un tipo valido: ");
                scanf("%d", & nuevaMoto.idColor);
            }

            system("cls");
            printf("           ***Tipo de Cilindrada*** \n");
            printf("           ------------------------- \n\n");
            printf("\n1.50\n2.125\n3.500\n4.600\n5.750\n\n");
            printf("Elija tipo de cilindradas: ");
            scanf("%d", & cilindradas);
            while(cilindradas != 1 && cilindradas != 2 && cilindradas != 3 && cilindradas != 4 && cilindradas != 5)
            {
                printf("\nTipo de cilindrada\n1.50\n2.125\n3.500\n4.600\n5.750\n\n");
                printf("ERROR!!!Por favor elija un tipo valido: ");
                scanf("%d", & cilindradas);
            }
            nuevaMoto.cilindrada = cilindradas;


            altaMotos[indice] = nuevaMoto;

            error = 0;

        }
    }
    return error;
}
//Modificacion de moto
int modificarMoto(eMoto modMoto[], int tam)
{
    int error=1;
    int indice;
    int id;
    int modMarca;
    char confirmar;
    char modificar;
    char sertficacion[20] = {"Honda"};
    char sertficacion2[20] = "Suzuki";
    char sertficacion3[20] = "Kawazaki";

    if(modMoto != NULL && tam > 0)
    {
        system("cls");
        printf("           *** Modificar Moto*** \n");
        printf("           ---------------------- \n\n");
        mostrarMotos(modMoto, tam);
        printf("Ingrese Id de la moto a modificar: ");
        scanf("%d", &id);

        indice = buscarMoto(modMoto, tam, id);

        if(indice == -1)
        {
            printf("No se encontro el id\n\n");
        }
        else
        {
            printf("a. Marca\n");
            printf("b. IdTipo\n");
            printf("c. IdColor\n");
            printf("d. Cilindrada\n");
            printf("Que quiere modificiar ?: ");
            fflush(stdin);
            scanf("%c", &modificar);

            switch(modificar)
            {
            case 'a':
                /*Profe a esto lo realice asi para que el usuario no este ingresando nuevamente cada nombre
                 y cometer errores en la escritura nose si esta bien pero se me ocuurio hacerlo asi*/
                printf("Elija marca por la cual sera modificada\n\n");
                printf("1. Honda\n2. Suzuki\n3. Kawasaki\n");
                printf("Ingrese la nueva marca elegida: ");
                scanf("%d", &modMarca);
                while(modMarca < 0 && modMarca > 3)
                {
                    printf("ERROR!!!Al elegir la marca");
                    printf("1. Honda\n2. Suzuki\n3. Kawasaki\n");
                    printf("Reingrese marca por favor: ");
                    scanf("%d", &modMarca);
                }
                if(modMarca == 1)
                {
                    strcpy(modMoto[indice].marca,sertficacion[20]);
                }
                else
                {
                    if(modMarca == 2)
                    {
                        strcpy(modMoto[indice].marca=sertficacion2[20]);
                    }
                    else
                    {
                        strcpy(modMoto[indice].marca,sertficacion3[20]);
                    }
                }
                break;

            case 'b':
                printf("\nTipo de motos\n\n1.Enduro\n2.Chopera\n3.Scooter\n4.Ciclomotor\n");
                printf("Ingrese nuevo idTipo: ");
                fflush(stdin);
                scanf("%d", &modMarca);
                modMoto[indice].idTipo = modMarca;
                while(modMarca < 0 && modMarca > 4)
                {
                    printf("\nTipo de motos\n\n1.Enduro\n2.Chopera\n3.Scooter\n4.Ciclomotor\n");
                    printf("ERROR!!!Reingrese nuevo idTipo: ");
                    fflush(stdin);
                    scanf("%d", &modMarca);
                    modMoto[indice].idTipo = modMarca;
                }
                break;
            case 'c':

                printf("\nTipo de color\n1.Gris\n2.Negro\n3.Blanco\n4.Azul\n5.Rojo\n\n");
                printf("Ingrese nueva altura: ");
                scanf("%d", &modMarca);
                modMoto[indice].idColor = modMarca;
                while(modMoto[indice].idColor < 0 && modMoto[indice].idColor > 5)
                {
                    printf("\nTipo de color\n1.Gris\n2.Negro\n3.Blanco\n4.Azul\n5.Rojo\n\n");
                    printf("Ingrese nueva altura: ");
                    scanf("%d", &modMarca);
                    modMoto[indice].idColor = modMarca;
                }
                break;

            case 'd':
                printf("\nTipo de cilindrada\n1.50\n2.125\n3.500\n4.600\n5.750\n\n");
                printf("Ingrese nueva cilindrada: ");
                scanf("%d",&modMarca);
                while(modMarca < 0 && modMarca > 5)
                {
                    printf("\nTipo de cilindrada\n1.50\n2.125\n3.500\n4.600\n5.750\n\n");
                    printf("ERROR!!!Reingrese marca: ");
                    scanf("%d",&modMarca);
                }
                modMoto[indice].cilindrada = modMarca;
                break;
            }
            printf("Desea confirmar el cambio s(si)/n(no): ");
            fflush(stdin);
            scanf("%c", &confirmar);
            if(confirmar=='s')
            {
                error=0;
            }
            else
            {
                error=1;
            }
        }
    }
    return error;
}


//baja moto
int bajaMoto(eMoto bajMoto[], int tam)
{
    int error=1;
    int indice;
    int id;
    char confirma;

    if(bajaMoto != NULL && tam > 0)
    {
        system("cls");
        printf("*** Baja de motos ***\n");
        printf("---------------------\n");
        mostrarMotos(bajMoto, tam);
        printf("Ingrese id de la moto que va a ser dada de baja: ");
        scanf("%d", &id);

        indice = buscarMoto(bajMoto, tam, id);

        if(indice == -1)
        {
            printf("No hay ninguna moto con ese Id\n\n");
        }
        else
        {
            mostrarMoto(bajMoto[indice] );
            printf("Deseaeliminar esta moto s(si), n(no)?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            confirma = tolower(confirma);
            if(confirma=='s')
            {
                bajMoto[indice].isEmpty = 1;
                error = 0;
            }
            else
            {
                error = 2;
            }
        }
    }
    return error;
}
//baja moto
int buscarMoto(eMoto busMoto[], int tam, int id)
{

    int indice;

    for(int i = 0; i < tam; i++)
    {
        if(busMoto[i].id == id && busMoto[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
        else
        {
            indice = -1;
        }
    }
    return indice;
}

//ordenar motos
int ordenarMotoTipoOd(eMoto ordenamiento[], int tam, int criterioS, int criterioA)
{
    int error=-1;
    ePersona aux;
    if(altaPersona!= NULL&&tam>0&&criterioS>=0&&criterioS<=1&&criterioA>=0&&criterioA<=1)//verificacion de parametros ingresados
    {
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if(criterioS==0&&altaPersona[i].sexo>altaPersona[j].sexo)
                {
                    aux=altaPersona[i];
                    altaPersona[i]=altaPersona[j];
                    altaPersona[j]=aux;
                }
                else if(criterioS==1&&altaPersona[i].sexo<altaPersona[j].sexo)
                {
                    aux=altaPersona[i];
                    altaPersona[i]=altaPersona[j];
                    altaPersona[j]=aux;
                }
                else if(altaPersona[i].sexo==altaPersona[j].sexo&&altaPersona[i].altura>altaPersona[j].altura&&criterioA==0)
                {
                    aux=altaPersona[i];
                    altaPersona[i]=altaPersona[j];
                    altaPersona[j]=aux;
                }
                else if(altaPersona[i].sexo==altaPersona[j].sexo&&altaPersona[i].altura<altaPersona[j].altura&&criterioA==1)
                {
                    aux=altaPersona[i];
                    altaPersona[i]=altaPersona[j];
                    altaPersona[j]=aux;
                }
            }
        }
        error=0;
    }
    return error;
}
