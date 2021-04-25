#include <stdio.h>
#include <SDL.h>
#include <stdbool.h>

//Al usar la librería SDL es importante que el main quede definido de la siguiente forma para que pueda ser portable a todo SO.
//De momento es un archivo de prueba en un futuro se convertirá en función.
bool iniciar()
{

    //Se declara la ventana donde se renderizara y la superficie contenida por la ventana

    SDL_Window* Ventana= NULL;
    SDL_Surface* Superficepantalla = NULL;
    bool funciona = true;

        if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
            {
                printf( "SDL no pudo iniciarse: %s\n", SDL_GetError() );
                funciona = false;
            }

        else
            {

        //Se crea una ventana centrada con dimensiones 400 x 400 y con el último argumento muestra la ventana

                Ventana = SDL_CreateWindow( "nombre", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 400, 400, SDL_WINDOW_SHOWN );

                    if( Ventana == NULL )
                        {
                            printf( "No se pudo crear la ventana: %s\n", SDL_GetError() );
                            funciona = false;

                        }
                    else
                        {
                            //Se coge la superficie de la ventana para poder colocar elementos en ella
                            Superficepantalla = SDL_GetWindowSurface( Ventana );

                            //Rellena la superficie de blanco
                            SDL_FillRect( Superficepantalla, NULL, SDL_MapRGB( Superficepantalla->format, 0xFF, 0xFF, 0xFF ) );

                            //Actualiza la superficie
                            SDL_UpdateWindowSurface( Ventana );

                            //Espera 2000 milisegundos para que no desaparezca inmediatamente
                            SDL_Delay( 2000 );
                        }
            }
    return funciona;
}

