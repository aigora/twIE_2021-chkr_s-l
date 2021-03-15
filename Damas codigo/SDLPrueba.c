#include <stdio.h>
#include <SDL2/SDL.h>

//Al usar la librería SDL es importante que el main quede definido de la siguiente forma para que pueda ser portable a todo SO.
//De momento es un archivo de prueba en un futuro se convertirá en función.
int main(int argv, char** args)
{

    //Se declara la ventana donde se renderizara y la superficie contenida por la ventana

    SDL_Window* window = NULL;
    SDL_Surface* screenSurface = NULL;


        if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
            {
                printf( "SDL no pudo iniciarse: %s\n", SDL_GetError() );
            }

        else
            {

        //Se crea una ventana centrada con dimensiones 400 x 400 y con el último argumento muestra la ventana

                window = SDL_CreateWindow( "nombre", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 400, 400, SDL_WINDOW_SHOWN );

                    if( window == NULL )
                        {
                            printf( "No se pudo crear la ventana: %s\n", SDL_GetError() );
                        }



    return 0;
}
