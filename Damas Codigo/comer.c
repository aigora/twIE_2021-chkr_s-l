#include <stdio.h>
#include <SDL.h>
#include <stdbool.h>
#include"funciones.h"

int pos_raton (const Cuadrante  dim_cas [32]);
void Pintar(int Tipo_ficha [32], int numero_casilla, bool rodear,SDL_Renderer *Render,const Cuadrante dimensiones_casilla [32]);

 int n = puedeMover(tablero, pieza, movimientosPosibles);
 int m = puedeComer(tablero, turno, comidasPosibles);

int comer(int tablero, int turno, int pos_raton, int comidasposibles){
    // comidasposibles ES UN ENTERO
        // 1 = IZQUIERDA
        // 2 = DERECHA


    // Eliminar la pieza clicada, que va a comer, pasada como parámetro
    // Eliminar la pieza comida del tablero
    // Pintar la pieza anterior en la nueva posición
    tablero[pos_raton] = -1;
    tablero[comidasposibles] = -1;

    // Si la comidasposibles dada como parámetro es 1 -> voy a la izquierda y en el tablero en la posición actual+9 pasará a haber una pieza
    if (comidasposibles == 1){
            tablero[pos_raton+9] = 1;
    }

    // Lo mismo si quiero ir a la derecha
    else if (comidasposibles == 2) {
         tablero[pos_raton+7] = 1;
    }
)

int mover(int tablero, int turno, int pos_raton, int movimientosPosibles){
    // movimientosPosibles ES UN ENTERO
        // 1 = IZQUIERDA
        // 2 = DERECHA


    // Eliminar la pieza clicada, que va a comer, pasada como parámetro
    // Eliminar la pieza comida del tablero
    // Pintar la pieza anterior en la nueva posición
    tablero[pos_raton] = -1;

    // Si  movimientosPosibles dada como parámetro es 1 -> voy a la izquierda y en el tablero en la posición actual+5 pasará a haber una pieza
    if (movimientosPosibles == 1){
            tablero[pos_raton+5] = 1;
    }

    // Lo mismo si quiero ir a la derecha
    else if (movimientosPosibles == 2){
         tablero[pos_raton+4] = 1;
    }
)


//ESTRUCTURA DEL MAIN DEL JUEGO
// Pintar();
// Clico pieza
// Miro si puede comer llamado puedeComer()
// Si puedeComer() == 0 --> no hago nada porque no puedo comer
// Si puedeComer() == 1 --> si es la de la izquierda --> direccion = 0, si es la de la derecha --> direccion = 1
// Si puedeComer() == 2 --> comer(direccion))
