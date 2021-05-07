#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct
{
    int x1,y1,x2,y2;
}Cuadrante;




int main(int argv, char** args)
{
            SDL_Window *Ventana= NULL;
            SDL_Renderer *Render = NULL;
            SDL_Texture *Textura = NULL;

            const Cuadrante  dimensiones_casilla [32]={
                                    {585,72,710,189}, //Primera fila
                                    {835,72,960,189},
                                    {1085,72,1210,189},
                                    {1335,72,1460,189},
                                    {460,189,585,306}, //Segunda fila
                                    {710,189,835,306},
                                    {900,189,1085,306},
                                    {1210,189,1335,306},
                                    {585,306,710,423}, //Tercera fila
                                    {835,306,960,423},
                                    {1085,306,1210,423},
                                    {1335,306,1460,423},
                                    {460,423,585,540}, //Cuarta fila
                                    {710,423,835,540},
                                    {900,423,1085,540},
                                    {1210,423,1335,540},
                                    {585,540,710,657}, //Quinta fila
                                    {835,540,960,657},
                                    {1085,540,1210,657},
                                    {1335,540,1460,657},
                                    {460,657,585,774}, //Sexta fila
                                    {710,657,835,774},
                                    {900,657,1085,774},
                                    {1210,657,1335,774},
                                    {585,774,710,891}, //Séptima fila
                                    {835,774,960,891},
                                    {1085,774,1210,891},
                                    {1335,774,1460,891},
                                    {460,891,585,1008}, //Octava fila
                                    {710,891,835,1008},
                                    {900,891,1085,1008},
                                    {1210,891,1335,1008}
                                };


fondo (Ventana,Render, Textura);

        pos_raton ();

cerrar (Ventana, Textura, Render);

//    int opcion[5];
//    double tiempo=0;
//    char nombre[11];
//
//        do
//            {
//                printf("Elige una opción:\n");
//                printf("\t0. Salir\n");
//                printf("\t1. Modo un jugador\n");
//                printf("\t2. Modo multijador\n");
//                scanf("%i", &opcion[0]);
//
//                switch (opcion[0])
//                {
//                    case 1: //Modo un jugador
//                    {
//                        do
//                            {
//                                printf("\nHas seleccionado el modo un jugador.\n");
//                                //Multijugador(false);            (Nombre de la función)
//
//                                printf("Seleccione el nivel de dificultad:\n");
//                                printf("\t1. Fácil\n");
//                                printf("\t2. Difícil\n");
//
//                                scanf("%i", &opcion[1]);
//                            }while((opcion[1] != 1) && (opcion[1] != 2));
//
//                            if (opcion[1] == 1)
//                            {
//                                printf("Has entrado en el modo fácil.\n");
//
//                                //ModoDificil(false);            (Nombre de la función)
//                            }
//                            else
//                            {
//                                printf("Has entrado en el modo difícil.\n");
//                                //ModoDificil(true);
//                            }
//
//                        do
//                            {
//                                printf("\nSeleccione color:\n");
//                                printf("\t1. Blanco\n");
//                                printf("\t2. Negro\n");
//
//                                scanf("%i", &opcion[2]);
//                            }while((opcion[2] != 1) && (opcion[2] != 2));
//
//                            if (opcion[2] == 1)
//                            {
//                                printf("Has elegido el color blanco.\n");
//
//                                //ColorBlanco(true);            (Nombre de la función)
//                            }
//                            else
//                            {
//                                printf("Has elegido el color negro.\n");
//                                //ColorBlanco(false);
//                            }
//                        do
//                            {
//                                printf("¿Desea usar temporizador?\n");
//                                printf("\t1. Sí\n");
//                                printf("\t2. No\n");
//
//                                scanf("%i", &opcion[3]);
//                            }while((opcion[3] != 1) && (opcion[3] != 2));
//
//                            if (opcion[3] == 1)
//                            {
//                                printf("Introduzca el tiempo:\n");
//                                scanf("%lf",&tiempo);
//
//                                //Temporizador(tiempo);            (Nombre de la función)
//                            }
//                        do
//                            {
//                                printf("¿Desea guardar su puntuación?\n");
//                                printf("\t1. Sí\n");
//                                printf("\t2. No\n");
//
//                                scanf("%i", &opcion[4]);
//                            }while((opcion[4] != 1) && (opcion[4] != 2));
//
//                            if (opcion[4] == 1)
//                            {
//                                printf("Introduce un nombre:\n");
//                                scanf("%10s",nombre);
//
//                                //Guardar(nombre);            (Nombre de la función)
//                            }
//                        printf("\n");
//                        break;
//
//                    }
//                    case 2: //Modo multijugador
//
//                        {
//                            printf("\nHas seleccionado el modo multijugador.\n");
//                            //Multijugador(true);
//
//                            do
//                                {
//                                    printf("¿Desea usar temporizador?\n");
//                                    printf("\t1. Sí\n");
//                                    printf("\t2. No\n");
//
//                                    scanf("%i", &opcion[3]);
//                                }while((opcion[3] != 1) && (opcion[3] != 2));
//
//                                if (opcion[3] == 1)
//                                {
//                                    printf("Introduzca el tiempo:\n");
//                                    scanf("%lf",&tiempo);
//
//                                    //Temporizador(tiempo);            (Nombre de la función)
//                                }
//                            printf("\n");
//                            break;
//                        }
//
//                    case 0:
//                        {
//                            printf("\nSaliendo...\n\n");
//                            break;
//                        }
//
//                    default:
//                        {
//                            printf("\nNo ha seleccionado un modo válido.\n\n");
//                            break;
//                        }
//                }
//            }
//
//        while(opcion[0] != 0);

    return 0;
}


