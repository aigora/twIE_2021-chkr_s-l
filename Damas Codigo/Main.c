#include <SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include<math.h>
#include<string.h>
#include "funciones.h"

int main(int argv, char** args)
{
    //Variables lógica
    int turno_sin_comidos = 0,
        pieza = -1,
        turno = 0,
        fin_partida=0,
        movimientosPosibles[4], comidasPosibles[5][3],
        tablero[32] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  1,  2,  2,  2,  2,  2,  2,  2,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0};
                     //0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31
                     //tablero[32] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,  2,  2,  2,  2,  2,  2,  2,  2,  2,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0}; Tablero con la posición inicial correcta

    int posicion,
        nComidas_posibles,
        nMovimientos_posibles,
        colorBot;

    bool dificil;

    //Variables gráficas
    SDL_Window *Ventana= NULL;
    SDL_Renderer *Render = NULL;
    SDL_Texture *Textura = NULL;


    //Variables auxiliares
    int i, j, n, k;
    bool pasar_turno;


    //Variables menú
    int opcion[5];
    char nombre[11];


    //Variables fichero de texto
    FILE *archivo;
    int fichas_extra, resultado;
    int amarillas=0, moradas=0;
    char color [15];
    char amarillo[]="Amarillo";
    char morado[]="Morado";


    //Variables vector estructura usados para las dimensiones de la pantalla
    const Cuadrante  dim_cas [32]={
                            {585,72,710,189}, //Primera fila
                            {835,72,960,189},
                            {1080,72,1205,189},
                            {1327,72,1452,189},
                            {460,189,585,306}, //Segunda fila
                            {710,189,835,306},
                            {960,189,1085,306},
                            {1205,189,1330,306},
                            {585,306,710,423}, //Tercera fila
                            {835,306,960,423},
                            {1080,306,1205,423},
                            {1327,306,1452,423},
                            {460,423,585,540}, //Cuarta fila
                            {710,423,835,540},
                            {960,423,1085,540},
                            {1205,423,1330,540},
                            {585,540,710,657}, //Quinta fila
                            {835,540,960,657},
                            {1080,540,1205,657},
                            {1327,540,1452,657},
                            {460,657,585,774}, //Sexta fila
                            {710,657,835,774},
                            {960,657,1085,774},
                            {1205,657,1330,774},
                            {585,774,710,891}, //Séptima fila
                            {835,774,960,891},
                            {1080,774,1205,891},
                            {1327,774,1452,891},
                            {460,891,585,1008}, //Octava fila
                            {710,891,835,1008},
                            {960,891,1085,1008},
                            {1205,891,1330,1008}
                        };

    const Cuadrante  menu_2 [2]={
                            {11,362,940,837},
                            {980,362,1909,837}
                                };

    const Cuadrante  menu_3 [3]={
                            {44,218,909,627},
                            {1013,216,1878,625},
                            {515,660,1380,1069}
                                };


// Inicialización de SDL para poder emplear las funciones gráficas, se pondrá en su respectivo sitio en un futuro

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

                return -1;
            }

        Render= SDL_CreateRenderer( Ventana, -1, SDL_RENDERER_ACCELERATED ); //Se crea el render que será donde pintaremos y se le añade aceleración de sowftware
        if( Render == NULL ) //Se comprubea si ha inicializado bien el render
        {
            printf( "El render no se pudo crear SDL Error: %s\n", SDL_GetError() );

            return -1;
        }


        do
        {
            //Después de cada partida es necesario devolver las variables a sus valores iniciales
            turno_sin_comidos = 0;
            pieza = -1;
            turno = 0;
            fin_partida=0;
            amarillas=0;
            moradas=0;

            for (k=0;k<32;k++) //Se reinicia el tablero
                {
                    if(k<=11)
                        tablero[k]=1;
                    else if(k<=19)
                        tablero[k]=2;
                    else if(k<=31)
                        tablero[k]=0;
                }


            fondo(Ventana,Render,Textura,"modo_juego.bmp");
            opcion[0]=pos_raton(menu_3,3);

            switch (opcion[0])
            {
                case 3:
                {
                    cerrar(Ventana,Textura,Render);
                    printf("\nSaliendo...\n\n");
                    break;
                }

                case 1:
                case 2:
                {
                    if (opcion[0]==1)                                                           //Modo un jugador
                    {
                        do
                        {
                            fondo(Ventana,Render,Textura,"dificultad.bmp");
                            opcion[1]=pos_raton(menu_2,2);

                        }while((opcion[1] != 1) && (opcion[1] != 2));

                        if (opcion[1] == 1)
                        {
                            //Modo fácil
                            dificil = false;
                        }
                        else
                        {
                           //Modo difícil
                           dificil = true;
                        }

                        do
                        {
                            fondo(Ventana,Render,Textura,"color.bmp");
                            opcion[2]=pos_raton(menu_2,2);

                        }while((opcion[2] != 1) && (opcion[2] != 2));


                        if (opcion[2] == 1)
                        {
                           colorBot = 1;
                           strcpy(color,amarillo); //Se especifica que el jugador es amarillo para el fichero
                        }
                        else
                        {
                            colorBot = 0;
                            strcpy(color,morado); //Se especifica que el jugador es morado para el fichero
                        }

                    }
                    else if (opcion[0] == 2)                                                                  //Modo Multijugador
                    {
                        colorBot = -1;
                    }


                    //Se inicia la partida

                    fondo(Ventana,Render,Textura,"chekers_blue.bmp"); //Se carga el fondo
                    for (i=0; i<32;i++) //Se dibujan las fichas
                    {
                        Pintar(tablero ,i ,false ,Render ,dim_cas);
                    }




                    nComidas_posibles = puedeComer(tablero,turno,comidasPosibles); //Se inicaliza la matriz de poder comer
                    do
                    {
                        if (colorBot == turno % 2) //Se comprueba si es turno de la IA o en su defecto si esta activada
                        {
                            IA(tablero, dificil, turno, &pieza, &posicion, comidasPosibles, nComidas_posibles);
                        }
                        else
                        {
                            posicion=pos_raton(dim_cas,32);
                            if(posicion!=-1)
                            {
                                if(tablero[posicion]%3==turno%2) //Si la pieza selecciona corresponde al color elegido
                                {
                                    if(pieza!=-1) //Se ha deseleccionado una pieza y se actualiza gráficamente
                                    {
                                        if(nComidas_posibles==-1)
                                        {
                                            for(i=0;i<=nMovimientos_posibles;i++)
                                            {
                                                Pintar(tablero,movimientosPosibles[i],false,Render,dim_cas);
                                            }
                                        }
                                        else
                                        {
                                            for(i=0;i<=nComidas_posibles;i++)
                                            {
                                                if(comidasPosibles[i][0]==pieza)
                                                {
                                                    Pintar(tablero, comidasPosibles[i][2],false,Render,dim_cas);
                                                }
                                            }
                                        }
                                        Pintar(tablero,pieza,false,Render,dim_cas);

                                    }
                                    pieza=posicion; //Se selecciona una pieza y se dibuja en modo seleccionado
                                    nMovimientos_posibles=puedeMover( tablero,pieza,movimientosPosibles);
                                    if(nComidas_posibles==-1)
                                    {
                                        for(i=0;i<=nMovimientos_posibles;i++)
                                        {
                                            Pintar(tablero,movimientosPosibles[i],true,Render,dim_cas);
                                        }
                                    }
                                    else
                                    {
                                        for(i=0;i<=nComidas_posibles;i++)
                                        {
                                            if(comidasPosibles[i][0]==pieza)
                                            {
                                                Pintar(tablero, comidasPosibles[i][2],true,Render,dim_cas);
                                            }
                                        }
                                    }
                                    Pintar(tablero,pieza,true,Render,dim_cas);
                                }
                                else if(pieza!=-1)
                                {
                                    n = -1;
                                    for(i=0;i<=nComidas_posibles;i++)
                                    {
                                        if(pieza==comidasPosibles[i][0]&&posicion==comidasPosibles[i][2])
                                        {
                                            n = i;
                                        }
                                    }
                                    if (n!=-1)
                                    {
                                        tablero[comidasPosibles[n][2]]=tablero[comidasPosibles[n][0]]; //Devuelve el valor en la posición querida
                                        tablero[comidasPosibles[n][0]]=2; //Quita la ficha movida
                                        tablero[comidasPosibles[n][1]]=2; //Quita la ficha comida
                                        coronar(tablero); //Se comprueba si se corona
                                        for(j=0;j<=2;j++)
                                        {
                                             Pintar(tablero,comidasPosibles[n][j],false,Render,dim_cas); //Dibuja las piezas movidas
                                        }
                                        for(j=0; j<=nComidas_posibles; j++)
                                        {
                                            if (pieza==comidasPosibles[j][0])
                                            {
                                                Pintar(tablero,comidasPosibles[j][2],false,Render,dim_cas);
                                            }
                                        }

                                         fin_partida=terminar_partida(tablero,turno_sin_comidos,pieza,movimientosPosibles,turno,comidasPosibles); //Se comprueba si se ha terminado la partida

                                        nComidas_posibles=puedeComer(tablero,turno,comidasPosibles); //Como se puede comer 2 veces seguidas se repite la función
                                        pasar_turno=true;

                                        for(j=0; j<=nComidas_posibles; j++) //Se comprueba si la pieza puede volver a mover
                                        {
                                            if(posicion==comidasPosibles[j][0])
                                            {
                                                pasar_turno=false;
                                            }
                                        }

                                        pieza = -1;
                                        turno_sin_comidos = 0;

                                        if(pasar_turno)
                                        {
                                            turno++;
                                            nComidas_posibles=puedeComer(tablero,turno,comidasPosibles);
                                        }
                                    }
                                    else if(nComidas_posibles==-1) //Si no se puede comer se comprueba se mueve
                                    {
                                        for (i=0; i<=nMovimientos_posibles; i++)
                                        {
                                            if (posicion == movimientosPosibles[i]) //Se analiza si la casilla pulsada es un movimiento posible
                                            {
                                                tablero[posicion] = tablero[pieza];
                                                tablero[pieza] = 2;
                                                coronar(tablero);
                                                Pintar(tablero, pieza, false, Render, dim_cas);

                                                for(j=0; j<=nMovimientos_posibles; j++) //Se corrige la parte gráfica
                                                {
                                                    Pintar(tablero, movimientosPosibles[j], false, Render, dim_cas);
                                                }

                                                fin_partida=terminar_partida(tablero,turno_sin_comidos,pieza,movimientosPosibles,turno,comidasPosibles); //Se comprueba si se ha terminado la partida

                                                resultado=fin_partida; //Usada para el fichero

                                                pieza = -1;
                                                turno_sin_comidos++;

                                                turno++;
                                                nComidas_posibles=puedeComer(tablero, turno, comidasPosibles);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } while(fin_partida==0);

                    if(colorBot==1||colorBot==0) //Solo se genera el fichero si el bot esta activado
                    {
                        do
                        {
                            fondo(Ventana,Render,Textura,"nombre.bmp");

                            opcion[4]=pos_raton(menu_2,2);
                        }while((opcion[4] != 1) && (opcion[4] != 2));

                        if (opcion[4] == 1)
                        {
                            cerrar(Ventana,Textura,Render);
                            printf("Introduce un nombre:\n");
                            scanf("%10s",nombre);

                            for(k=0;k<32;k++) //Contar las fichas extra
                            {
                                if(tablero[k]==0||tablero[k]==3)
                                    amarillas++;

                                if(tablero[k]==1||tablero[k]==4)
                                    moradas++;
                            }

                            fichas_extra=abs(amarillas-moradas);

                            archivo=fopen("Puntuaciones.txt","a");
                            if (archivo==NULL)
                            {
                                printf("Error al abrir el fichero.\n");
                            }


                            else
                            {
                                printf("Archivo abierto correctamente.\n");
                                fprintf(archivo,"\n\nUn 1 equivale a vitoria de amarillas, un 2 a victoria de moradas y un 3 a un empate.\nPartida:\nNombre: %s\nTurnos: %i\nFichas extra sobre las del rival: %i\nResultado: %i\nColor jugador:%s\n",nombre,turno,fichas_extra,resultado,color);
                                fclose(archivo);
                            }



                            if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 ) //Se reinicia SDL porque lo acabamos de cerrar
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

                                        return -1;
                                    }

                                Render= SDL_CreateRenderer( Ventana, -1, SDL_RENDERER_ACCELERATED );
                                if( Render == NULL )
                                        {
                                            printf( "El render no se pudo crear SDL Error: %s\n", SDL_GetError() );

                                            return -1;
                                        }
                            }
                            printf("\n");
                        }
                    }

                    printf("%i", fin_partida);
                                                                        //Aquí acaba el juego en sí
                    break;
                }
            }
        } while(opcion[0] != 3); //Bucle del menú
    }

    return 0;

}


