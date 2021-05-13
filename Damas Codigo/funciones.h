
typedef struct
{
    int x1,y1,x2,y2;
}Cuadrante;

typedef struct
{
    int m,s;
}tiempo;

void Pintar(int Tipo_ficha [32], int numero_casilla, bool rodear,SDL_Renderer *Render,const Cuadrante dimensiones_casilla [32]);
void fondo (SDL_Window *Ventana,SDL_Renderer *Render, SDL_Texture *Textura, char path[50]);
int pos_raton (const Cuadrante  dim_cas [],int n);
void cerrar (SDL_Window *Ventana, SDL_Texture *Textura, SDL_Renderer *Render);
bool _in(int x, int n);
int puedeMover(int tablero[], int pieza, int movimientosPosibles[]);
int puedeComer(int tablero[], int turno, int comidasPosibles[][3]);
