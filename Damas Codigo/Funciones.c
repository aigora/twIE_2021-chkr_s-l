#include <stdio.h>
#include <SDL.h>
#include <stdbool.h>


typedef struct
{
    int x, y;
}punto;

 punto pos_raton();



void fondo (SDL_Window *Ventana,SDL_Surface *Superficepantalla, SDL_Surface *Tablero,SDL_Renderer *Render, SDL_Texture *Textura)
{



            if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
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


                        }
                    else
                        {

                            Render= SDL_CreateRenderer( Ventana, -1, SDL_RENDERER_ACCELERATED );


                            if( Render == NULL )
                                    {
                                        printf( "El render no se pudo crear SDL Error: %s\n", SDL_GetError() );
                                    }
                            else
                                    {
                                        SDL_SetRenderDrawColor( Render, 0xFF, 0xFF, 0xFF, 0xFF );


                                        SDL_Texture *newTexture = NULL;
                                    	SDL_Surface *SupCarg = SDL_LoadBMP("chekers_blue.bmp");
                                                            if( SupCarg == NULL )
                                                            {
                                                                printf( "No se pudo cargar la imagen: chekers_blue.bmp SDL Error: %s\n", SDL_GetError() );
                                                            }
                                                            else
                                                            {

                                                                newTexture = SDL_CreateTextureFromSurface( Render, SupCarg );
                                                                if( newTexture == NULL )
                                                                {
                                                                    printf( "No se pudo cargar crear la textura SDL Error: %s\n", SDL_GetError() );
                                                                }


                                                                SDL_FreeSurface( SupCarg );
                                                                Textura=newTexture;
                                                                  if (Textura == NULL)
                                                                    {
                                                                        printf("Fallo al cargar las texturas\n");

                                                                    }
                                                                else
                                                                {
                                                                    SDL_RenderClear( Render );


                                                                    SDL_RenderCopy( Render, Textura, NULL, NULL );


                                                                    SDL_RenderPresent( Render );
                                                                }
                                                            }

                                        }
                        }

            }
}

/*void Pintar(int Tipo_ficha [32], int numero_casilla, bool rodear, bool rodeados[32],SDL_Window *Ventana,SDL_Surface *Superficepantalla, SDL_Surface *Tablero)
{

    if(rodear==true)
        {
            if(Tipo_ficha[numero_casilla]==2)
                //dibujar circulo verde
            else
                //dibujar círculo naranja
        }
    else
        {
              switch (Tipo_ficha[numero_casilla])
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
}*/

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

void cerrar (SDL_Window *Ventana,SDL_Surface *Superficepantalla, SDL_Surface *Tablero, SDL_Texture *Textura, SDL_Renderer *Render)
            {
                                    SDL_DestroyTexture( Textura );
                                    Textura = NULL;


                                    SDL_DestroyRenderer( Render );
                                    SDL_DestroyWindow( Ventana );
                                    Ventana = NULL;
                                    Render = NULL;

                                    SDL_Quit();
            }
