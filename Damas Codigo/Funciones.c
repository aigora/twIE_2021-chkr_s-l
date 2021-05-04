#include <stdio.h>
#include <SDL.h>
#include <stdbool.h>

typedef struct
{
    int x, y;
}punto;

 punto pos_raton();



void fondo (SDL_Window *Ventana,SDL_Surface *Superficepantalla, SDL_Surface *Tablero)
{



            if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
            {
                printf( "SDL no pudo iniciarse: %s\n", SDL_GetError() );

            }

        else
            {

                Ventana = SDL_CreateWindow( "Damas.exe", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_SHOWN );

                    if( Ventana == NULL )
                        {
                            printf( "No se pudo crear la ventana: %s\n", SDL_GetError() );


                        }
                    else
                        {
                            Superficepantalla = SDL_GetWindowSurface( Ventana );
                                    Tablero=SDL_LoadBMP("chekers_blue.bmp");

                                    if (Tablero == NULL)
                                    {
                                        printf("No se pudo iniciar la imagen %s. Error de SDL %s \n ","chekers_blue.bmp",SDL_GetError());

                                    }
                                    else
                                    {
                                        SDL_BlitSurface(Tablero, NULL, Superficepantalla, NULL );
                                        SDL_UpdateWindowSurface( Ventana );
                                    }
                        }
            }


}

void Pintar(int Tipo_ficha [32], int numero_casilla, bool rodear, )
{

    if(rodear==true)
        {
            if(Tipo_ficha[i]==2)
                //dibujar circulo verde
            else
                //dibujar círculo naranja
        }
    else
        {
              switch (Tipo_ficha[i])
                {
                    case 0:

                    break;


                    case 1:

                    break;


                    case 2:

                    break;


                    case 3:

                    break;


                    case 4:

                    break;

                }
        }
}

punto pos_raton ()
{

    punto click;
    click.x=0;
    click.y=0;

    bool funciona=true;
    SDL_Event mouse;

    while(funciona)
    {

        while(SDL_PollEvent(&mouse)!=0)
        {
            switch(mouse.type)
            {
                case SDL_QUIT:
                    funciona = false;
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    click.x = mouse.button.x;
                    click.y = mouse.button.y;
                    printf("x: %i    y: %i\n", click.x, click.y);
                    break;
                return click;

            }
        }
    }

   return click;
}

void cerrar (SDL_Window *Ventana,SDL_Surface *Superficepantalla, SDL_Surface *Tablero)
{
                                         SDL_FreeSurface( Tablero );
                                         Tablero = NULL;


                                         SDL_DestroyWindow( Ventana );
                                         Ventana = NULL;

                                         SDL_Quit();
}
