#include <stdio.h>
#include <SDL.h>
#include <stdbool.h>

typedef struct
{
    int x1,y1,x2,y2;
}Cuadrante;




void fondo (SDL_Window *Ventana,SDL_Renderer *Render, SDL_Texture *Textura)
{
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
                    }
                else
                    {
                        Render= SDL_CreateRenderer( Ventana, -1, SDL_RENDERER_ACCELERATED ); //Se crea el render que será donde pintaremos y se le añade aceleración de sowftware
                        if( Render == NULL ) //Se comprubea si ha inicializado bien el render
                                {
                                    printf( "El render no se pudo crear SDL Error: %s\n", SDL_GetError() );
                                }
                        else
                                {
                                    SDL_SetRenderDrawColor( Render, 0xFF, 0xFF, 0xFF, 0xFF ); //Se pone el color del render en blanco


                                    SDL_Surface *SupCarg = SDL_LoadBMP("chekers_blue.bmp"); //Se carga el fondo
                                        if( SupCarg == NULL ) //Se comprueba si se ha guardado bien el fondo
                                        {
                                            printf( "No se pudo cargar la imagen: chekers_blue.bmp SDL Error: %s\n", SDL_GetError() );
                                        }
                                        else
                                        {
                                            Textura = SDL_CreateTextureFromSurface( Render, SupCarg ); //Se aplica el fondo sobre la textura
                                            if(  Textura == NULL ) //Se compueba si la textura ha cogido el fondo
                                            {
                                                printf( "No se pudo cargar crear la textura SDL Error: %s\n", SDL_GetError() );
                                            }
                                            SDL_FreeSurface( SupCarg );


                                                SDL_RenderCopy( Render, Textura, NULL, NULL ); //Se coloca la textura sobre el render
                                                SDL_RenderPresent( Render ); //Se actualiza el Render


                                        }

                                }
                    }

        }
}

void Pintar(int Tipo_ficha [32], int numero_casilla, bool rodear,SDL_Renderer *Render,const Cuadrante  dim_cas [32])
{
 int i= numero_casilla; //Variable para acortar la longitud en los parámetros al dibujar rectángulos

    if(rodear==true)

        {
            if(Tipo_ficha[numero_casilla]==2) //Rodea una casilla
                    {
                    SDL_Rect fillRect = { dim_cas[i].x1+16.5, dim_cas[i].y1+10, (dim_cas[i].x2-dim_cas[i].x1)-20, (dim_cas[i].y2-dim_cas[i].y1)-20 }; //Todas las funciones de este tipo llenan un rectángulo, luego pintan en él y por último se dibuja el rectángulo en el render
                    SDL_SetRenderDrawColor( Render, 0x00, 0xFF, 0x00, 0xFF );
                    SDL_RenderFillRect( Render, &fillRect );



                    SDL_Rect fillRect2 = { dim_cas[i].x1+20.5, dim_cas[i].y1+14, (dim_cas[i].x2-dim_cas[i].x1)-28, (dim_cas[i].y2-dim_cas[i].y1)-28 };   //Llena lo de dentro de blanco
                    SDL_SetRenderDrawColor( Render, 0xFF, 0xFF, 0xFF, 0xFF );
                    SDL_RenderFillRect( Render, &fillRect2 );


                    SDL_RenderPresent( Render ); //Se actualiza el render
                    }



            else //Rodea una pieza
                    {
                    SDL_Rect fillRect = { dim_cas[i].x1+16.5, dim_cas[i].y1+10, (dim_cas[i].x2-dim_cas[i].x1)-20, (dim_cas[i].y2-dim_cas[i].y1)-20 };
                    SDL_SetRenderDrawColor( Render, 0xFF, 0x00, 0x00, 0xFF );
                    SDL_RenderFillRect( Render, &fillRect );



                    SDL_Rect fillRect2 = { dim_cas[i].x1+20.5, dim_cas[i].y1+14, (dim_cas[i].x2-dim_cas[i].x1)-28, (dim_cas[i].y2-dim_cas[i].y1)-28 };   //Llena lo de dentro de blanco
                    SDL_SetRenderDrawColor( Render, 0xFF, 0xFF, 0xFF, 0xFF );
                    SDL_RenderFillRect( Render, &fillRect2 );


                    SDL_RenderPresent( Render );

                    switch (Tipo_ficha[numero_casilla])
                        {
                            case 0: ;
                                SDL_Rect fillRect3 = { dim_cas[i].x1+26.5, dim_cas[i].y1+20, (dim_cas[i].x2-dim_cas[i].x1)-40, (dim_cas[i].y2-dim_cas[i].y1)-40 };
                                SDL_SetRenderDrawColor(  Render, 208, 200, 0x00, 0xFF  );
                                SDL_RenderFillRect( Render, &fillRect3 );

                                 SDL_RenderPresent( Render );
                            break;


                            case 1: ;
                                SDL_Rect fillRect4 = { dim_cas[i].x1+26.5, dim_cas[i].y1+20, (dim_cas[i].x2-dim_cas[i].x1)-40, (dim_cas[i].y2-dim_cas[i].y1)-40 };
                                SDL_SetRenderDrawColor(  Render, 208, 0x00, 134, 200  );
                                SDL_RenderFillRect( Render, &fillRect4 );

                                SDL_RenderPresent( Render );
                            break;


                            case 3: ;
                                SDL_Rect fillRect5 = { dim_cas[i].x1+26.5, dim_cas[i].y1+20, (dim_cas[i].x2-dim_cas[i].x1)-40, (dim_cas[i].y2-dim_cas[i].y1)-40 };
                                SDL_SetRenderDrawColor(  Render, 208, 200, 0x00, 0xFF   );
                                SDL_RenderFillRect( Render, &fillRect5 );

                                SDL_Rect fillRect7 = { dim_cas[i].x1+51, dim_cas[i].y1+42, (dim_cas[i].x2-dim_cas[i].x1)-90, (dim_cas[i].y2-dim_cas[i].y1)-85 };
                                SDL_SetRenderDrawColor(  Render, 134, 123, 0x00, 0xFF  );
                                SDL_RenderFillRect( Render, &fillRect7 );

                                SDL_RenderPresent( Render );
                            break;


                            case 4: ;
                                SDL_Rect fillRect6 = { dim_cas[i].x1+26.5, dim_cas[i].y1+20, (dim_cas[i].x2-dim_cas[i].x1)-40, (dim_cas[i].y2-dim_cas[i].y1)-40 };
                                SDL_SetRenderDrawColor(   Render, 208, 0x00, 200, 0xFF );
                                SDL_RenderFillRect( Render, &fillRect6 );

                                SDL_Rect fillRect8 = { dim_cas[i].x1+51, dim_cas[i].y1+42, (dim_cas[i].x2-dim_cas[i].x1)-90, (dim_cas[i].y2-dim_cas[i].y1)-85 };
                                SDL_SetRenderDrawColor(  Render, 123, 0x00, 134, 0xFF  );
                                SDL_RenderFillRect( Render, &fillRect8 );

                                SDL_RenderPresent( Render );
                            break;

                        }
                    }

        }

    else
        {
            SDL_Rect fillRect = { dim_cas[i].x1+16.5, dim_cas[i].y1+10, (dim_cas[i].x2-dim_cas[i].x1)-20, (dim_cas[i].y2-dim_cas[i].y1)-20 };
            SDL_SetRenderDrawColor( Render, 0xFF, 0xFF, 0xFF, 0xFF );
            SDL_RenderFillRect( Render, &fillRect );
            SDL_RenderPresent( Render );

              switch (Tipo_ficha[numero_casilla])
                        {
                            case 0: ;
                                SDL_Rect fillRect3 = { dim_cas[i].x1+26.5, dim_cas[i].y1+20, (dim_cas[i].x2-dim_cas[i].x1)-40, (dim_cas[i].y2-dim_cas[i].y1)-40 };
                                SDL_SetRenderDrawColor(  Render, 208, 200, 0x00, 0xFF  );
                                SDL_RenderFillRect( Render, &fillRect3 );

                                 SDL_RenderPresent( Render );
                            break;


                            case 1: ;
                                SDL_Rect fillRect4 = { dim_cas[i].x1+26.5, dim_cas[i].y1+20, (dim_cas[i].x2-dim_cas[i].x1)-40, (dim_cas[i].y2-dim_cas[i].y1)-40 };
                                SDL_SetRenderDrawColor(  Render, 208, 0x00, 134, 200  );
                                SDL_RenderFillRect( Render, &fillRect4 );

                                SDL_RenderPresent( Render );
                            break;


                            case 3: ;
                                SDL_Rect fillRect5 = { dim_cas[i].x1+26.5, dim_cas[i].y1+20, (dim_cas[i].x2-dim_cas[i].x1)-40, (dim_cas[i].y2-dim_cas[i].y1)-40 };
                                SDL_SetRenderDrawColor(  Render, 208, 200, 0x00, 0xFF   );
                                SDL_RenderFillRect( Render, &fillRect5 );

                                SDL_Rect fillRect7 = { dim_cas[i].x1+51, dim_cas[i].y1+42, (dim_cas[i].x2-dim_cas[i].x1)-90, (dim_cas[i].y2-dim_cas[i].y1)-85 };
                                SDL_SetRenderDrawColor(  Render, 134, 123, 0x00, 0xFF  );
                                SDL_RenderFillRect( Render, &fillRect7 );

                                SDL_RenderPresent( Render );
                            break;


                            case 4: ;
                                SDL_Rect fillRect6 = { dim_cas[i].x1+26.5, dim_cas[i].y1+20, (dim_cas[i].x2-dim_cas[i].x1)-40, (dim_cas[i].y2-dim_cas[i].y1)-40 };
                                SDL_SetRenderDrawColor(   Render, 208, 0x00, 200, 0xFF );
                                SDL_RenderFillRect( Render, &fillRect6 );

                                SDL_Rect fillRect8 = { dim_cas[i].x1+51, dim_cas[i].y1+42, (dim_cas[i].x2-dim_cas[i].x1)-90, (dim_cas[i].y2-dim_cas[i].y1)-85 };
                                SDL_SetRenderDrawColor(  Render, 123, 0x00, 134, 0xFF  );
                                SDL_RenderFillRect( Render, &fillRect8 );

                                SDL_RenderPresent( Render );
                            break;

                        }
        }
}



int pos_raton (const Cuadrante  dim_cas [32])
{

    int x,y;
    x=0;
    y=0;

    bool funciona=true;
    SDL_Event mouse;

    while(funciona)
    {
        int i=0; int k=-1;
        while(SDL_PollEvent(&mouse)!=0)
        {
            switch(mouse.type)
            {
                case SDL_QUIT:
                    funciona = false;
                    break;

                case SDL_MOUSEBUTTONDOWN:
                    x = mouse.button.x;
                    y = mouse.button.y;

                    for (i=0;i<32;i++)
                    {

                        if((x>=dim_cas[i].x1&&x<=dim_cas[i].x2)&&(y>=dim_cas[i].y1&&y<=dim_cas[i].y2))
                            {
                                k=i; return k;
                            }


                    }

                    if(k==-1)
                    {
                        return -1;
                    }



                break;



            }
        }
    }


}

void cerrar (SDL_Window *Ventana, SDL_Texture *Textura, SDL_Renderer *Render) //Cierra todas las funciones de SDL y elimina las ventanas en deshuso
{
        SDL_DestroyTexture( Textura );
        Textura = NULL;


        SDL_DestroyRenderer( Render );
        SDL_DestroyWindow( Ventana );
        Ventana = NULL;
        Render = NULL;

        SDL_Quit();
}
