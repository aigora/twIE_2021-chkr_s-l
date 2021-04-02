#include <SDL.h>
#include <stdio.h>

int main(int argv, char** args)
{
    //iniciar();
    int opcion[90];

    do
    {
            printf("Elige una opción:\n");
            printf("0. Salir\n");
            printf("1. Modo un jugador\n");
            printf("2. Modo multijador\n");
            scanf("%i",&opcion);


            switch (opcion[0])
                {
                    case 1:

                        {

                          printf("Has seleccionado el modo un jugador\n");
                          printf("Seleccione el nivel de dificultad:\n");
                          printf("1. Modo un jugador\n");
                          printf("2. Modo multijador\n");

                        }

                    case 2:

                        {
                          printf("Has seleccionado el modo multijugador\n");
                        }

                    case 0:
                        {
                            printf("Saliendo\n");
                            break;
                        }

                    default:
                        {

                           printf("No ha seleccionado un modo válido\n");
                           break;

                        }

                }

    }

    while(opcion[0] != 0);

    return 0;
}

