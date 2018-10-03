#include stdio.h
#include string.h

#define MAX_NOM 50

typedef struct{
  char nom[MAX_NOM];
  int punts
}Jugador;

typedef struct N{
  Jugador pj;
  struct N *seg;
  struct N* ant;
}NodeORD;

typedef struct{
  NodeORD *pri;
  NodeORD *ant;
  NodeORD *ult;
}LlistaBiOrd;

Node ElementIndefinit();

LlistaBiOrd LLISTABIORD_crea();

void LLISTABIORD_inserirOrdenat(LlistaBiOrd *l, Jugador p);

void LLISTABIORD_vesInici(LlistaBiOrd *l);

void LLISTABIORD_avanca(LlistaBiOrd *l);

void LLISTABIORD_enrera(LlistaBiOrd *l);

Jugador LLISTABIORD_consulta(LlistaBiOrd *l);

void LLISTABIORD_esborra(LlistaBiOrd *l);

void LLISTABIORD_fi(LlistaBiOrd *l);

void LLISTABIORD_buida(LlistaBiOrd *l);

void LLISTABIORD_destrueix(LlistaBiOrd *l);
