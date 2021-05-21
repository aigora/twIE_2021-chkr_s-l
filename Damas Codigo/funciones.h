
typedef struct
{
    int x1,y1,x2,y2;
}Cuadrante;

typedef struct
{
    int m,s;
}temp;

void Pintar(int Tipo_ficha [32], int numero_casilla, bool rodear,SDL_Renderer *Render,const Cuadrante dimensiones_casilla [32]);
void fondo (SDL_Window *Ventana,SDL_Renderer *Render, SDL_Texture *Textura, char path[50]);
int pos_raton (const Cuadrante  dim_cas [],int n);
void cerrar (SDL_Window *Ventana, SDL_Texture *Textura, SDL_Renderer *Render);
bool _in(int x, int n);
int puedeMover(int tablero[], int pieza, int movimientosPosibles[]);
int puedeComer(int tablero[], int turno, int comidasPosibles[][3]);
int dondeCome(int tablero[],int turno, int pieza, int comidasPosibles[][2]);
void IA(int tablero[], bool dificil, int turno, int* Pieza, int* Posicion, int comidasPosbles[][3],int nComidasPosibles);
int terminar_partida(int tablero[],int turnos_sin_comidos,int tiempo[2],int pieza,int movimientosPosibles[],int turno,int comidasPosibles[][3],bool tempor);
void coronar(int tablero[]);
