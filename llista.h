#ifndef _LLISTA_ORD_H_
#define _LLISTA_ORD_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_NOMS 30

//Tipus que serveix per crear i modificar el ranking ordenat
typedef struct{
	char nom_j[MAX_NOMS];
	int puntuacio;
}Rank;

typedef struct M {
	Rank jugador;
	struct M *seg;
  struct M *ante;
}NodeORD;

typedef struct{
	NodeORD *pri;
	NodeORD *ant;
  NodeORD *ult;
}LlistaBIORD;

Rank ELEMENT_indefinitORD();

LlistaBIORD LLISTABIORD_crea();

void LLISTABIORD_insereixOrdenat(LlistaBIORD *l, Rank e);

void LLISTABIORD_vesInici(LlistaBIORD *l);

void LLISTABIORD_vesfi(LlistaBIORD *l);

void LLISTABIORD_avanca(LlistaBIORD *l);

void LLISTABIORD_enrera(LlistaBIORD *l);

Rank LLISTABIORD_consulta(LlistaBIORD l);

void LLISTABIORD_esborra(LlistaBIORD *l);

int LLISTABIORD_fi(LlistaBIORD l);

int LLISTABIORD_principi(LlistaBIORD *l);

int LLISTABIORD_buida(LlistaBIORD l);

void LLISTABIORD_destrueix(LlistaBIORD *l);

#endif
