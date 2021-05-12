#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include "funciones.h"

int main(int argv, char** args)
{
            //Se inicializan las variables
            //Variables gráficas
            SDL_Window *Ventana= NULL;
            SDL_Renderer *Render = NULL;
            SDL_Texture *Textura = NULL;


            //Variables menú
            int opcion[5];
            char nombre[11];


            //Variables vector estructura usados para las dimensiones de la pantalla
            const Cuadrante  dim_cas [32]={
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

            const Cuadrante  menu_2 [2]={
                                    {11,362,940,837},
                                    {980,362,1909,837}
                                        };

            const Cuadrante  menu_3 [3]={
                                    {44,218,909,627},
                                    {1013,216,1878,625},
                                    {515,660,1380,1069}
                                        };

            const Cuadrante  menu_4 [4]={
                                    {44,218,909,623},
                                    {1013,216,1878,624},
                                    {44,659,909,1064},
                                    {1013,657,1878,1065}
                                        };


// Inicialización de SDL para poder emplear las funciones gráficas, se pondrá en su respectivo sitio en un futuro

    if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ) //Se compureba si se ha iniciado correctamente SDL
        {
            printf( "SDL no pudo iniciarse: %s\n", SDL_GetError() );
        }
    else
        {

               if(!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" )) //Se compureba si la calidad de texturas
               {
                   printf("Aviso: Filtración linear de texturas no disponible");
               }

            Ventana = SDL_CreateWindow( "Damas.exe", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_SHOWN ); //Se crea la ventana
                if( Ventana == NULL ) //Se comprueba si la ventana ha inicializado bien
                    {
                        printf( "No se pudo crear la ventana: %s\n", SDL_GetError() );

                        return -1;
                    }

            Render= SDL_CreateRenderer( Ventana, -1, SDL_RENDERER_ACCELERATED ); //Se crea el render que será donde pintaremos y se le añade aceleración de sowftware
                if( Render == NULL ) //Se comprubea si ha inicializado bien el render
                        {
                            printf( "El render no se pudo crear SDL Error: %s\n", SDL_GetError() );

                            return -1;
                        }


                    do
                        {
                            fondo(Ventana,Render,Textura,"modo_juego.bmp");
                            printf("Elige una opción:\n");
                            printf("\t0. Salir\n");
                            printf("\t1. Modo un jugador\n");
                            printf("\t2. Modo multijador\n");
                            opcion[0]=pos_raton(menu_3,3);

                            if (opcion[0]==3) //Corrección del dato por el uso de la función
                                opcion[0]=0;

                            switch (opcion[0])
                            {
                                case 1: //Modo un jugador
                                {
                                    do
                                        {
                                            printf("\nHas seleccionado el modo un jugador.\n");
                                            //Multijugador(false);            (Nombre de la función)

                                            fondo(Ventana,Render,Textura,"dificultad.bmp");

                                            printf("Seleccione el nivel de dificultad:\n");
                                            printf("\t1. Fácil\n");
                                            printf("\t2. Difícil\n");

                                            opcion[1]=pos_raton(menu_2,2);

                                        }while((opcion[1] != 1) && (opcion[1] != 2));

                                        if (opcion[1] == 1)
                                        {
                                            printf("Has entrado en el modo fácil.\n");

                                            //ModoDificil(false);            (Nombre de la función)
                                        }
                                        else
                                        {
                                            printf("Has entrado en el modo difícil.\n");
                                            //ModoDificil(true);
                                        }

                                    do
                                        {
                                            fondo(Ventana,Render,Textura,"color.bmp");
                                            printf("\nSeleccione color:\n");
                                            printf("\t1. Blanco\n");
                                            printf("\t2. Negro\n");

                                            opcion[2]=pos_raton(menu_2,2);
                                        }while((opcion[2] != 1) && (opcion[2] != 2));

                                        if (opcion[2] == 1)
                                        {
                                            printf("Has elegido el color blanco.\n");

                                            //ColorBlanco(true);            (Nombre de la función)
                                        }
                                        else
                                        {
                                            printf("Has elegido el color negro.\n");
                                            //ColorBlanco(false);
                                        }
                                    do
                                        {
                                            fondo(Ventana,Render,Textura,"temporizador.bmp");
                                            printf("¿Desea usar temporizador?\n");
                                            printf("\t1. Sí\n");
                                            printf("\t2. No\n");

                                            opcion[3]=pos_raton(menu_4,4);
                                        }while((opcion[3] != 1) && (opcion[3] != 2));

                                        if (opcion[3] == 1)
                                        {
                                            int m=0;

                                            //Temporizador(tiempo);            (Nombre de la función)
                                        }
                                    do
                                        {
                                            fondo(Ventana,Render,Textura,"nombre.bmp");
                                            printf("¿Desea guardar su puntuación?\n");
                                            printf("\t1. Sí\n");
                                            printf("\t2. No\n");

                                            opcion[4]=pos_raton(menu_2,2);
                                        }while((opcion[4] != 1) && (opcion[4] != 2));

                                        if (opcion[4] == 1)
                                        {
                                            cerrar(Ventana,Textura,Render);
                                            printf("Introduce un nombre:\n");
                                            scanf("%10s",nombre);

                                            //Guardar(nombre);            (Nombre de la función)

                                            if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ) //Se reinicia SDL porque lo acabamos de cerrar
                                                {
                                                    printf( "SDL no pudo iniciarse: %s\n", SDL_GetError() );
                                                }
                                            else
                                                {

                                                       if(!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ))
                                                       {
                                                           printf("Aviso: Filtración linear de texturas no disponible");
                                                       }

                                                    Ventana = SDL_CreateWindow( "Damas.exe", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_SHOWN );
                                                        if( Ventana == NULL )
                                                            {
                                                                printf( "No se pudo crear la ventana: %s\n", SDL_GetError() );

                                                                return -1;
                                                            }

                                                    Render= SDL_CreateRenderer( Ventana, -1, SDL_RENDERER_ACCELERATED );
                                                        if( Render == NULL )
                                                                {
                                                                    printf( "El render no se pudo crear SDL Error: %s\n", SDL_GetError() );

                                                                    return -1;
                                                                }

                                        }
                                    printf("\n");
                                    break;

                                }
                                case 2: //Modo multijugador

                                    {
                                        printf("\nHas seleccionado el modo multijugador.\n");
                                        //Multijugador(true);

                                        do
                                            {
                                                fondo(Ventana,Render,Textura,"temporizador.bmp");
                                                printf("¿Desea usar temporizador?\n");
                                                printf("\t1. Sí\n");
                                                printf("\t2. No\n");

                                                opcion[3]=pos_raton(menu_4,4);
                                            }while((opcion[3] != 1) && (opcion[3] != 2));

                                            if (opcion[3] == 1)
                                            {
                                                int l=0;

                                                //Temporizador(tiempo);            (Nombre de la función)
                                            }
                                        printf("\n");
                                        break;
                                    }

                                case 0:
                                    {
                                        cerrar(Ventana,Textura,Render);
                                        printf("\nSaliendo...\n\n");
                                        break;
                                    }

                                default:
                                    {
                                        printf("\nNo ha seleccionado un modo válido.\n\n");
                                        break;
                                    }
                            }
                        }


        } while(opcion[0] != 0);
    }

    return 0;

}


