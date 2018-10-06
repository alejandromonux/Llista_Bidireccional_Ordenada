#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOM 50

typedef struct{
  char nom[MAX_NOM];
  int punts;
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

NodeORD elementIndefinit();

LlistaBiOrd LLISTABIORD_crea();

void LLISTABIORD_inserirOrdenat(LlistaBiOrd *l, Jugador p);

void LLISTABIORD_vesInici(LlistaBiOrd *l);

void LLISTABIORD_vesfi(LlistaBiOrd *l);

void LLISTABIORD_avanca(LlistaBiOrd *l);

void LLISTABIORD_enrera(LlistaBiOrd *l);

Jugador LLISTABIORD_consulta(LlistaBiOrd *l);

void LLISTABIORD_esborra(LlistaBiOrd *l);

int LLISTABIORD_fi(LlistaBiOrd *l);

int LLISTABIORD_principi(LlistaBiOrd *l);

int LLISTABIORD_buida(LlistaBiOrd *l);

void LLISTABIORD_destrueix(LlistaBiOrd *l);
