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
    case 4:
        {
            j = 18;
            int array[18] = {0, 1, 2, 4, 5, 6, 8, 9, 10, 12, 13, 14, 16, 17, 18, 20, 21, 22};
            break;
        }
    }

    while (i < j && !respuesta)
    {
        printf("%i. ", array[i]);
        if (x == array[i])
        {
            respuesta = true;
        }
        i++;
    }
    printf("%d ", respuesta);
    return respuesta;
}

int puedeMover(int tablero[], int pieza, int movimientosPosibles[])
{
    int i, j;

    if ((int)(pieza%8)%2 == 0)
    {
        j = 5;
    }
    else
    {
        j = 4;
    }

    i = -1;
    if (tablero[pieza] != 1)
    {
        if (!in(pieza, 0))
        {
            if (tablero[pieza + j - 9] == 2)
            {
                i++;
                movimientosPosibles[i] = pieza + j - 9;
            }
        }
        if (!in(pieza, 1))
        {
            if (tablero[pieza + j - 8] == 2)
            {
                i++;
                movimientosPosibles[i] = pieza + j - 8;
            }
        }
        if (!in(pieza, 2))
        {
            if (tablero[pieza + j - 1])
            {
                i++;
                movimientosPosibles[i] = pieza + j - 1;
            }
        }
        if (!in(pieza, 3))
        {
            if (tablero[pieza + j])
            {
                i++;
                movimientosPosibles[i] = pieza + j;
            }
        }
    }

    return i;
}

int puedeComer(int tablero[], int turno, int comidasPosibles[][3])
{
    int i, j, k;

    for (i = 0; i <= 22; i++)
    {
        if (in(i, 4))
        {
            printf("%i ,", i);
            if ((int)(i%8)%2 == 0)
            {
                k = 5;
            }
            else
            {
                k = 4;
            }

            j = -1;
            if (turno % 2 == 0 && (tablero[i + k] == 1 || tablero[i + k] == 4))
            {
                if ((tablero[i + 8] == 0 || tablero[i + 8] == 3) && tablero[i + 1] == 2)
                {
                    j++;
                    comidasPosibles[j][0] = i + 8;
                    comidasPosibles[j][1] = i + k;
                    comidasPosibles[j][2] = i + 1;
                }

                if ((tablero[i + 9] == 0 || tablero[i + 9] == 3) && tablero[i] == 2)
                {
                    j++;
                    comidasPosibles[j][0] = i + 9;
                    comidasPosibles[j][1] = i + k;
                    comidasPosibles[j][2] = i;
                }

                if (tablero[i] == 3 && tablero[i + 9] == 2)
                {
                    j++;
                    comidasPosibles[j][0] = i;
                    comidasPosibles[j][1] = i + k;
                    comidasPosibles[j][2] = i + 9;
                }

                if (tablero[i + 1] == 3 && tablero[i + 8] == 2)
                {
                    j++;
                    comidasPosibles[j][0] = i + 1;
                    comidasPosibles[j][1] = i + k;
                    comidasPosibles[j][2] = i + 8;
                }
            }

            else if (turno % 2 == 1 && (tablero[i + k] == 0 || tablero[i + k] == 3))
            {
                if ((tablero[i] == 1 || tablero[i] == 4) && tablero[i + 9] == 2)
                {
                    j++;
                    comidasPosibles[j][0] = i;
                    comidasPosibles[j][1] = i + k;
                    comidasPosibles[j][2] = i + 9;
                }

                if ((tablero[i + 1] == 1 || tablero[i + 1] == 4) && tablero[i + 8] == 2)
                {
                    j++;
                    comidasPosibles[j][0] = i + 1;
                    comidasPosibles[j][1] = i + k;
                    comidasPosibles[j][2] = i + 8;
                }

                if (tablero[i + 8] == 4 && tablero[i + 1] == 2)
                {
                    j++;
                    comidasPosibles[j][0] = i + 8;
                    comidasPosibles[j][1] = i + k;
                    comidasPosibles[j][2] = i + 1;
                }

                if (tablero[i + 9] == 4 && tablero[i] == 2)
                {
                    j++;
                    comidasPosibles[j][0] = i + 9;
                    comidasPosibles[j][1] = i + k;
                    comidasPosibles[j][2] = i;
                }
            }
        }
    }

    return j;
}


