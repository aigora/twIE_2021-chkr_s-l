#include <stdio.h>
#include <SDL.h>
#include <stdbool.h>
#include"funciones.h"


void fondo (SDL_Window *Ventana,SDL_Renderer *Render, SDL_Texture *Textura, char path[50])
{
        SDL_SetRenderDrawColor( Render, 0xFF, 0xFF, 0xFF, 0xFF ); //Se pone el color del render en blanco


        SDL_Surface *SupCarg = SDL_LoadBMP(path); //Se carga el fondo
            if( SupCarg == NULL ) //Se comprueba si se ha guardado bien el fondo
            {
                printf( "No se pudo cargar la imagen: %s SDL Error: %s\n", path, SDL_GetError() );
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
                            break;


                            case 1: ;
                                SDL_Rect fillRect4 = { dim_cas[i].x1+26.5, dim_cas[i].y1+20, (dim_cas[i].x2-dim_cas[i].x1)-40, (dim_cas[i].y2-dim_cas[i].y1)-40 };
                                SDL_SetRenderDrawColor(  Render, 208, 0x00, 134, 200  );
                                SDL_RenderFillRect( Render, &fillRect4 );
                            break;


                            case 3: ;
                                SDL_Rect fillRect5 = { dim_cas[i].x1+26.5, dim_cas[i].y1+20, (dim_cas[i].x2-dim_cas[i].x1)-40, (dim_cas[i].y2-dim_cas[i].y1)-40 };
                                SDL_SetRenderDrawColor(  Render, 208, 200, 0x00, 0xFF   );
                                SDL_RenderFillRect( Render, &fillRect5 );

                                SDL_Rect fillRect7 = { dim_cas[i].x1+51, dim_cas[i].y1+42, (dim_cas[i].x2-dim_cas[i].x1)-90, (dim_cas[i].y2-dim_cas[i].y1)-85 };
                                SDL_SetRenderDrawColor(  Render, 134, 123, 0x00, 0xFF  );
                                SDL_RenderFillRect( Render, &fillRect7 );
                            break;


                            case 4: ;
                                SDL_Rect fillRect6 = { dim_cas[i].x1+26.5, dim_cas[i].y1+20, (dim_cas[i].x2-dim_cas[i].x1)-40, (dim_cas[i].y2-dim_cas[i].y1)-40 };
                                SDL_SetRenderDrawColor(   Render, 208, 0x00, 200, 0xFF );
                                SDL_RenderFillRect( Render, &fillRect6 );

                                SDL_Rect fillRect8 = { dim_cas[i].x1+51, dim_cas[i].y1+42, (dim_cas[i].x2-dim_cas[i].x1)-90, (dim_cas[i].y2-dim_cas[i].y1)-85 };
                                SDL_SetRenderDrawColor(  Render, 123, 0x00, 134, 0xFF  );
                                SDL_RenderFillRect( Render, &fillRect8 );
                            break;

                        }
                    }
        }
    else
    {
    SDL_Rect fillRect = { dim_cas[i].x1+16.5, dim_cas[i].y1+10, (dim_cas[i].x2-dim_cas[i].x1)-20, (dim_cas[i].y2-dim_cas[i].y1)-20 }; //Llena de blanco la casilla
    SDL_SetRenderDrawColor( Render, 0xFF, 0xFF, 0xFF, 0xFF );
    SDL_RenderFillRect( Render, &fillRect );

       switch (Tipo_ficha[numero_casilla])
                    {
                        case 0: ;
                            SDL_Rect fillRect3 = { dim_cas[i].x1+26.5, dim_cas[i].y1+20, (dim_cas[i].x2-dim_cas[i].x1)-40, (dim_cas[i].y2-dim_cas[i].y1)-40 };
                            SDL_SetRenderDrawColor(  Render, 208, 200, 0x00, 0xFF  );
                            SDL_RenderFillRect( Render, &fillRect3 );
                        break;


                        case 1: ;
                            SDL_Rect fillRect4 = { dim_cas[i].x1+26.5, dim_cas[i].y1+20, (dim_cas[i].x2-dim_cas[i].x1)-40, (dim_cas[i].y2-dim_cas[i].y1)-40 };
                            SDL_SetRenderDrawColor(  Render, 208, 0x00, 134, 200  );
                            SDL_RenderFillRect( Render, &fillRect4 );
                        break;


                        case 3: ;
                            SDL_Rect fillRect5 = { dim_cas[i].x1+26.5, dim_cas[i].y1+20, (dim_cas[i].x2-dim_cas[i].x1)-40, (dim_cas[i].y2-dim_cas[i].y1)-40 };
                            SDL_SetRenderDrawColor(  Render, 208, 200, 0x00, 0xFF   );
                            SDL_RenderFillRect( Render, &fillRect5 );

                            SDL_Rect fillRect7 = { dim_cas[i].x1+51, dim_cas[i].y1+42, (dim_cas[i].x2-dim_cas[i].x1)-90, (dim_cas[i].y2-dim_cas[i].y1)-85 };
                            SDL_SetRenderDrawColor(  Render, 134, 123, 0x00, 0xFF  );
                            SDL_RenderFillRect( Render, &fillRect7 );
                        break;


                        case 4: ;
                            SDL_Rect fillRect6 = { dim_cas[i].x1+26.5, dim_cas[i].y1+20, (dim_cas[i].x2-dim_cas[i].x1)-40, (dim_cas[i].y2-dim_cas[i].y1)-40 };
                            SDL_SetRenderDrawColor(   Render, 208, 0x00, 200, 0xFF );
                            SDL_RenderFillRect( Render, &fillRect6 );

                            SDL_Rect fillRect8 = { dim_cas[i].x1+51, dim_cas[i].y1+42, (dim_cas[i].x2-dim_cas[i].x1)-90, (dim_cas[i].y2-dim_cas[i].y1)-85 };
                            SDL_SetRenderDrawColor(  Render, 123, 0x00, 134, 0xFF  );
                            SDL_RenderFillRect( Render, &fillRect8 );
                        break;
                    }
    }
    SDL_RenderPresent( Render );
}



int pos_raton (const Cuadrante  dim_cas [],int n)
{

    int x,y; //Variables para almacenar las posiciones del mouse
    x=0;
    y=0;

    bool funciona=true; //crear un bucle de ratón para que funcionen los eventos de SDL
    SDL_Event mouse;

    while(funciona)
    {
        int i=0; int k=-1;
        while(SDL_PollEvent(&mouse)!=0) //Detecta clicks ratón
        {
            switch(mouse.type)
            {
            case SDL_QUIT:
                funciona = false;
                break;

            case SDL_MOUSEBUTTONDOWN:
                x = mouse.button.x;
                y = mouse.button.y;

                for (i=0;i<n;i++) //Devuelve la casilla pulsada
                {

                    if((x>=dim_cas[i].x1&&x<=dim_cas[i].x2)&&(y>=dim_cas[i].y1&&y<=dim_cas[i].y2))
                        {
                            if(n==32)
                            {k=i; return k;}
                            else
                                {k=i+1; return k;}
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


bool _in(int x, int n)
{
    int j = 18, i = 0, array[18] = {0, 1, 2, 4, 5, 6, 8, 9, 10, 12, 13, 14, 16, 17, 18, 20, 21, 22};
    bool respuesta = false;

    switch(n)
    {
    case 0:
        {
            j = 8;
            array[0] = 0;
            array[1] = 1;
            array[2] = 2;
            array[3] = 3;
            array[4] = 4;
            array[5] = 12;
            array[6] = 20;
            array[8] = 28;
            break;
        }
    case 1:
        {
            j = 7;
            array[0] = 0;
            array[1] = 1;
            array[2] = 2;
            array[3] = 3;
            array[4] = 11;
            array[5] = 19;
            array[6] = 27;
            break;
        }
    case 2:
        {
            j = 7;
            array[0] = 4;
            array[1] = 12;
            array[2] = 20;
            array[3] = 28;
            array[4] = 29;
            array[5] = 30;
            array[6] = 31;
            break;
        }
    case 3:
        {
            j = 8;
            array[0] = 3;
            array[1] = 11;
            array[2] = 19;
            array[3] = 27;
            array[4] = 28;
            array[5] = 29;
            array[6] = 30;
            array[7] = 31;
            break;
        }
    case 4:
        {
            j = 14;
            array[0] = 0;
            array[1] = 1;
            array[2] = 2;
            array[3] = 3;
            array[4] = 4;
            array[5] = 5;
            array[6] = 6;
            array[7] = 7;
            array[8] = 8;
            array[9] = 12;
            array[10] = 16;
            array[11] = 20;
            array[12] = 24;
            array[13] = 28;
            break;
        }
    case 5:
        {
            j = 14;
            array[0] = 0;
            array[1] = 1;
            array[2] = 2;
            array[3] = 3;
            array[4] = 4;
            array[5] = 5;
            array[6] = 6;
            array[7] = 7;
            array[8] = 11;
            array[9] = 15;
            array[10] = 19;
            array[11] = 23;
            array[12] = 27;
            array[13] = 31;
            break;
        }
    case 6:
        {
            j = 14;
            array[0] = 0;
            array[1] = 4;
            array[2] = 8;
            array[3] = 12;
            array[4] = 16;
            array[5] = 20;
            array[6] = 24;
            array[7] = 25;
            array[8] = 26;
            array[9] = 27;
            array[10] = 28;
            array[11] = 29;
            array[12] = 30;
            array[13] = 31;
            break;
        }
    case 7:
        {
            j = 14;
            array[0] = 3;
            array[1] = 7;
            array[2] = 11;
            array[3] = 15;
            array[4] = 19;
            array[5] = 23;
            array[6] = 24;
            array[7] = 25;
            array[8] = 26;
            array[9] = 27;
            array[10] = 28;
            array[11] = 29;
            array[12] = 30;
            array[13] = 31;
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

    if ((int)(pieza/4)%2 == 0)
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
        if (!_in(pieza, 0))
        {
            if (tablero[pieza + j - 9] == 2)
            {
                i++;
                movimientosPosibles[i] = pieza + j - 9;
            }
        }

        if (!_in(pieza, 1))
        {
            if (tablero[pieza + j - 8] == 2)
            {
                i++;
                movimientosPosibles[i] = pieza + j - 8;
            }
        }
    }

    if (tablero[pieza] != 0)
    {
        if (!_in(pieza, 2))
        {
            if (tablero[pieza + j - 1] == 2)
            {
                i++;
                movimientosPosibles[i] = pieza + j - 1;
            }
        }

        if (!_in(pieza, 3))
        {
            if (tablero[pieza + j] == 2)
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
    int i, j = -1, k;

    for (i = 0; i <= 22; i++)
    {
        if (_in(i, -1))
        {
            if ((int)(i/4)%2 == 0)
            {
                k = 5;
            }
            else
            {
                k = 4;
            }

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

int dondeCome(int tablero[],int turno, int pieza, int comidasPosibles[][2])
{
    int i, j;
    if ((int)(pieza/4)%2 == 0)
    {
        i = 5;
    }
    else
    {
        i = 4;
    }
    j = -1;
    if (tablero[pieza] != 0)
    {
        printf("%i", pieza);
        if ((!_in(pieza, 6) && tablero[pieza + i - 1] == (turno%2) + 1) && tablero[pieza + 7] == 2)
        {
            j++;
            comidasPosibles[j][0] = pieza + i - 1;
            comidasPosibles[j][1] = pieza + 9 - 2;
        }

        if ((!_in(pieza, 7) && tablero[pieza + i] == (turno%2) + 1) && tablero[pieza + 9] == 2)
        {
            j++;
            comidasPosibles[j][0] = pieza + i;
            comidasPosibles[j][1] = pieza + 9;
        }
    }

    if (tablero[pieza] != 1)
    {
        if ((!_in(pieza, 4) && tablero[pieza + i - 9] == (turno%2) + 1) && tablero[pieza - 9] == 2)
        {
            j++;
            comidasPosibles[j][0] = pieza + i - 9;
            comidasPosibles[j][1] = pieza - 9;
        }

        if ((!_in(pieza, 4) && tablero[pieza + i - 8] == (turno%2) + 1) && tablero[pieza - 8] == 2)
        {
            j++;
            comidasPosibles[j][0] = pieza + i - 8;
            comidasPosibles[j][1] = pieza - 8;
        }
    }
    printf("%i", j);
    return j;
}

void IA(int tablero[], bool dificil, int turno, int* Pieza, int* Posicion, int comidasPosibles[][3],int nComidasPosibles)
{
    int rnd = rand(),
        tablero1[32], i, j, n, comidasPosibles1[3][2], comida[6] = {0, -1, -1, -1, -1, -1};
    bool salir;


    if (dificil)
    {
        for (i=0; i<32; i++) { tablero1[i]=tablero[i]; }
        for (i=0; i<=nComidasPosibles; i++)
        {
            n = 0;
            salir = false;
            *Posicion = comidasPosibles[i][0];
            comidasPosibles1[i][0] = comidasPosibles[i][1];
            comidasPosibles1[i][1] = comidasPosibles[i][2];
            do
            {
                for (j=0; j<32; j++)
                {
                    if (*Posicion == j){ tablero1[j] = turno%2; }
                    else if (comidasPosibles1[i][0] == j){ tablero1[j] = 2; }
                    else if (comidasPosibles1[i][1] == j){ tablero1[j] = (turno%2) + 1; }
                    else { tablero1[j]=tablero[j]; }
                }
                *Posicion = comidasPosibles1[i][1];
                comida[n+1] = comidasPosibles1[i][0];
                printf("%i;    ", comidasPosibles1[i][0]);
                n++;
                j = dondeCome(tablero1, turno, *Posicion, comidasPosibles1);
                printf("%i", j);
                if(j != -1 && n > comida[0])
                {
                    comida[0] = n;
                    comida[1] = comidasPosibles1[i][1];
                }
                else{ salir = true; }
            }while (!salir);
        }
        for (i=0; i<6; i++)
        {
            printf("%i, ", comida[i]);
        }
        printf("\n");
    }
    else
    {

    }
}

void coronar(int tablero[])
{
    int n=0;
    while(n<4)
    {
        if (tablero[n]==0)
        {
            tablero[n]=3;
        }
        n+=1;
    }
    n=28;
    while(n<32)
    {
        if (tablero[n]==1)
        {
            tablero[n]=4;
        }
        n+=1;
    }
}

int terminar_partida(int tablero[],int turnos_sin_comidos,int tiempo[2],int pieza,int movimientosPosibles[],int turno,int comidasPosibles[][3])
{
//esta funcion devolverá un 0 si no termina la partida o 1->ganan amarillas 2->ganan moradas 3->empate.
    int n=0,
        moradas=0,
        amarillas=0;

    while(n<32)
    {
        if ((tablero[n]==0)||(tablero[n]==3))
            amarillas+=1;
        if((tablero[n]==1)||(tablero[n]==4))
            moradas+=1;
        n+=1;
    }

    if((moradas==0)||(amarillas==0))
    {
        if(moradas==0)
            return 1;
        if(amarillas==0)
            return 2;
    }

    if (tiempo<=0)//Se quedan sin tiempo amarillas, ganan moradas
    {
       return 2;
    }

     if(tiempo<=0)//Se quedan sin tiempo moradas,ganan amarillas
    {
       return 1;
    }

    if ((turnos_sin_comidos)>=60)
    {
        return 3;
    }
    /*if((puedeMover( tablero,pieza,movimientosPosibles)==-1)&&(puedeComer(tablero,turno,comidasPosibles)==-1))
    {
        return 3;
    }
    */
    return 0;
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

