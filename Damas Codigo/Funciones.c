#include <stdio.h>
#include <SDL.h>
#include <stdbool.h>

//Al usar la librería SDL es importante que el main quede definido de la siguiente forma para que pueda ser portable a todo SO.
//De momento es un archivo de prueba en un futuro se convertirá en función.
bool iniciar()
{

    //Se declara la ventana donde se renderizara y la superficie contenida por la ventana

    SDL_Window* window = NULL;
    SDL_Surface* screenSurface = NULL;
    bool funciona = true;

        if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
            {
                printf( "SDL no pudo iniciarse: %s\n", SDL_GetError() );
                funciona = false;
            }

        else
            {

        //Se crea una ventana centrada con dimensiones 400 x 400 y con el último argumento muestra la ventana

                window = SDL_CreateWindow( "nombre", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 400, 400, SDL_WINDOW_SHOWN );

                    if( window == NULL )
                        {
                            printf( "No se pudo crear la ventana: %s\n", SDL_GetError() );
                            funciona = false;

                        }
                    else
                        {
                            //Se coge la superficie de la ventana para poder colocar elementos en ella
                            screenSurface = SDL_GetWindowSurface( window );

                            //Rellena la superficie de blanco
                            SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );

                            //Actualiza la superficie
                            SDL_UpdateWindowSurface( window );

                            //Espera 2000 milisegundos para que no desaparezca inmediatamente
                            SDL_Delay( 2000 );
                        }
            }
    return funciona;
}




bool in(int x, int n)
{
    int j, i = 0, array[1] = {-1};
    bool respuesta = false;

    switch(n)
    {
    case 0:
        {
            j = 8;
            int array[8] = {0, 1, 2, 3, 4, 12, 20, 28};
            break;
        }
    case 1:
        {
            j = 7;
            int array[7] = {0, 1, 2, 3, 11, 19, 27};
            break;
        }
    case 2:
        {
            j = 7;
            int array[7] = {4, 12, 20, 28, 29, 30, 31};
            break;
        }
    case 3:
        {
            j = 8;
            int array[8] = {3, 11, 19, 27, 28, 29, 30, 31};
            break;
        }
    }

    while (i < j && !respuesta)
    {
        if (x == array[i])
        {
            respuesta = true;
        }
        i++;
    }

    return respuesta;
}

int puedeMover(int tablero[], int pieza, int movimientosPosibles[])
{
    int i, j;

    if ((int)(pieza%8)%2 == 0)
    {
        i = 5;
    }
    else
    {
        i = 4;
    }

    j = -1;
    if (tablero[pieza] != 1)
    {
        if (!in(pieza, 0))
        {
            if (tablero[pieza + i - 9] == 2)
            {
                j++;
                movimientosPosibles[j] = pieza + i - 9;
            }
        }
        if (!in(pieza, 1))
        {
            if (tablero[pieza + i - 8] == 2)
            {
                j++;
                movimientosPosibles[j] = pieza + i - 8;
            }
        }
        if (!in(pieza, 2))
        {
            if (tablero[pieza + i - 1])
            {
                j++;
                movimientosPosibles[j] = pieza + i - 1;
            }
        }
        if (!in(pieza, 3))
        {
            if (tablero[pieza + i])
            {
                j++;
                movimientosPosibles[j] = pieza + i;
            }
        }
    }

    return j;
}

int puedeComer(tablero, turno)
{

}


