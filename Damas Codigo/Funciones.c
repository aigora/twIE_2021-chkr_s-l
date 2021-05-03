#include <stdio.h>
#include <SDL.h>
#include <stdbool.h>

void fondo ()
{
            SDL_Window *Ventana= NULL;
            SDL_Surface *Superficepantalla = NULL;
            SDL_Surface *Tablero = NULL;


            if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
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
                                        SDL_Delay( 2000 );


                                         SDL_FreeSurface( Tablero );
                                         Tablero = NULL;


                                         SDL_DestroyWindow( Ventana );
                                         Ventana = NULL;

                                         SDL_Quit();
                                    }
                        }
            }


}
