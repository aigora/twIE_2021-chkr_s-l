#include <stdio.h>
#include <SDL.h>
#include <stdbool.h>

//SDL_Window* Ventana= NULL;
//SDL_Surface* Superficepantalla = NULL;
//SDL_Surface* Tablero = NULL;
//
//
////Al usar la librería SDL es importante que el main quede definido de la siguiente forma para que pueda ser portable a todo SO.
////De momento es un archivo de prueba en un futuro se convertirá en función.
//bool iniciar()
//{
//
//    //Se declara la ventana donde se renderizara y la superficie contenida por la ventana
//
//
//    bool funciona = true;
//
//        if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
//            {
//                printf( "SDL no pudo iniciarse: %s\n", SDL_GetError() );
//                funciona = false;
//            }
//
//        else
//            {
//
//        //Se crea una ventana centrada con dimensiones 1080 x 1920 y con el último argumento muestra la ventana
//
//                Ventana = SDL_CreateWindow( "Damas.exe", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1920, 1080, SDL_WINDOW_SHOWN );
//
//                    if( Ventana == NULL )
//                        {
//                            printf( "No se pudo crear la ventana: %s\n", SDL_GetError() );
//                            funciona = false;
//
//                        }
//                    else
//                        {
//                            //Se coge la superficie de la ventana para poder colocar elementos en ella
//                            Superficepantalla = SDL_GetWindowSurface( Ventana );
//                        }
//            }
//    return funciona;
//}
//
//bool cargarImagen()
//{
//    bool funciona = true;
//
//    Tablero=SDL_LoadBMP("chekers_blue.bmp");
//
//        if (Tablero == NULL)
//        {
//            printf("No se pudo iniciar la imagen %s. Error de SDL %s \n ","chekers_blue.bmp",SDL_GetError());
//            funciona = false;
//        }
//
// return funciona;
//}
//
//void cerrar()
//{
//
//    SDL_FreeSurface( Tablero );
//    Tablero = NULL;
//
//
//    SDL_DestroyWindow( Ventana );
//    Ventana = NULL;
//
//    //Cerrar SDL
//    SDL_Quit();
//}
